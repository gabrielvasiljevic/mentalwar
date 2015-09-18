#ifndef MINDWAVEMODULE_H
#define MINDWAVEMODULE_H

#include <thinkgear.h>
#include <iostream>
using namespace std;

#ifndef mindwaveModule
#define mindwaveModule MindwaveModule::getInstance()
#endif

class MindwaveModule{
    public:
        MindwaveModule();
        virtual ~MindwaveModule();
        static MindwaveModule& getInstance();

        int getAttention(int connectionID);
        int getMeditation();

        int connect();
        void disconnect(int connectionID);
    protected:
    private:
        static MindwaveModule* instance;
};

#endif // MINDWAVEMODULE_H
