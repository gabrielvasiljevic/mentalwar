#include "artificialPlayer.hpp"

ArtificialPlayer::ArtificialPlayer()
{
    //ctor
}

ArtificialPlayer::~ArtificialPlayer()
{
    //dtor
}

void ArtificialPlayer::update(){
    if(changeClock.getElapsedTime().asSeconds() > 2){
        srand(time(NULL));
        this->force = initialForce + rand()%10;
    }
}

void ArtificialPlayer::setInitialForce(int _force){
    initialForce = _force;
    force = _force;
}
