#include "MindwaveModule.hpp"

MindwaveModule::MindwaveModule(){
    //ctor
}

MindwaveModule::~MindwaveModule(){
    //dtor
}

MindwaveModule& MindwaveModule::getInstance(){
    static MindwaveModule instance;
    return instance;
}


int MindwaveModule::getAttention(int connectionID){

    int packetsRead = 0;

    do{
        packetsRead = TG_ReadPackets( connectionID, 1 );
         /* If TG_ReadPackets() was able to read a Packet of data... */
        if( packetsRead == 1 ) {

            /* If the Packet contained a new attention wave value... */

            if( TG_GetValueStatus(connectionID, TG_DATA_ATTENTION) != 0 ) {

                cout << "Attention: " << (int)TG_GetValue(connectionID, TG_DATA_ATTENTION) << endl;
                /* Get and return the new attention value */
                return (int)TG_GetValue(connectionID, TG_DATA_ATTENTION);
            }
        }

        else{
            cout << "No packets to read\n";
        }

    }while( packetsRead > 0 );

    return 0;
}

int MindwaveModule::getMeditation(){

}

int MindwaveModule::connect(){
    char *comPortName;

    int   connectionId = -1;

    int   errCode      = 0;

    cout << "Connecting..."  << endl;

    /* Get a connection ID handle to ThinkGear */
    connectionId = TG_GetNewConnectionId();

    if( connectionId < 0 ) {
        cout << "ERROR: TG_GetNewConnectionId() returned " << connectionId << endl;
        return connectionId;
    }

    /* Set/open stream (raw bytes) log file for connection */
    errCode = TG_SetStreamLog( connectionId, "streamLog.txt" );
    if( errCode < 0 ) {
        cout << "ERROR: TG_SetStreamLog() returned " << errCode << endl;
        return connectionId;
    }

    /* Set/open data (ThinkGear values) log file for connection */
    errCode = TG_SetDataLog( connectionId, "dataLog.txt" );
    if( errCode < 0 ) {
        cout << "ERROR: TG_SetDataLog() returned " << errCode << endl;
        return connectionId;
    }

    /* Attempt to connect the connection ID handle to serial port "COM5" */
    /* NOTE: On Windows, COM10 and higher must be preceded by \\.\, as in
     *       "\\\\.\\COM12" (must escape backslashes in strings).  COM9
     *       and lower do not require the \\.\, but are allowed to include
     *       them.  On Mac OS X, COM ports are named like
     *       "/dev/tty.MindSet-DevB-1".
     */
    comPortName = "\\\\.\\COM5";
    errCode = TG_Connect( connectionId,
                         comPortName,
                         TG_BAUD_57600,
                         TG_STREAM_PACKETS );
    if( errCode < 0 ) {
        cout << "ERROR: TG_Connect() returned " << errCode << endl;
        return -1;
    }

    cout << "Connected: " << connectionId << endl;
    return connectionId;
}


void MindwaveModule::disconnect(int connectionID){
    TG_FreeConnection(connectionID);
}
