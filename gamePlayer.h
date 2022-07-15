
#ifndef _GAME_PLAYER_H_
#define _GAME_PLAYER_H_
#include "gameInterface.h"
#include "gameEntity.h"

enum who {PLAYER1, PLAYER2, AI, HIKIWAKE};

class gamePlayer
{
private:
    who player;
public:
    gamePlayer();
    ~gamePlayer();

    void setPlayer(who);
    who getPlayer();

};


#endif