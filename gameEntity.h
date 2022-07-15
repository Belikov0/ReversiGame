
/*

*/
#include "gameInterface.h"
#include "gamePlayer.h"
#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pos;
enum gameMode {PVP, PVE};

class gameEntity{
private:
    vector<vector<char> > board;
    stack<pos> regrets;
    gameMode mode;
    gamePlayer P1, P2;
    gamePlayer curr;
public:
    gameEntity();
    ~gameEntity();

    gamePlayer gameOpen();

    void setGameMode(gameMode);
    gameMode getGameMode();

    void setCurrentPlayer(gamePlayer);
    gamePlayer getCurrentPlayer();

    void setLeader(who);
    void recordLastStep(pos);

    bool isAI(gamePlayer);

    void showCurrentPlayer();
    void cuePlayer();

    bool isLegal(pos);
    pos AIcalculate();
    pos getInput();

    void showBoard();
    void placeStone(pos);
    void doReverse(pos);
    bool isGameOver();
    gamePlayer getWinner();
    gamePlayer getNextPlayer(gamePlayer);
    void setNextPlayer(gamePlayer);
    bool canPlace();

};

#endif