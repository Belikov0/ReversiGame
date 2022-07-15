#include "gameInterface.h"
#ifndef _GAME_PLAYER_H_
#define _GAME_PLAYER_H_

enum who {PLAYER1, PLATER2, AI, HIKIWAKE};

class gamePlayer
{
private:
    who player;
public:
    gamePlayer();
    ~gamePlayer();

    void setPlayer(who);
    who getPlayer();

    void regret(); 
    

};


#endif