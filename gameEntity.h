
/*

*/

#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_
#include "gameInterface.h"
#include "gamePlayer.h"
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
    gamePlayer P1, P2;// default: P1 play first
    gamePlayer curr;
    vector<pos> cues;
public:
    gameEntity();
    ~gameEntity();

    gamePlayer gameOpen();
    void initBoard(); // init game board

    //setter & getter
    void setGameMode(gameMode);
    gameMode getGameMode();

    void setCurrentPlayer(gamePlayer);
    gamePlayer getCurrentPlayer();

    void setP1(who);
    who getP1();

    void setP2(who);
    who getP2();

    void setLeader(who);
    /*
        根据选择的先手是电脑还是玩家，设置P1为先手
    */
    void recordLastStep(pos);
    /*
        使用栈储存每一步的位置信息用于悔棋
    */

    // game procedure
    bool isAI(gamePlayer);
    /*
        判断当前下棋的玩家是否是AI
    */

    void showCurrentPlayer();
    void cuePlayer();
    /*
        计算当前哪些地方可以摆放棋子，并修改棋盘在棋盘上显示
        使用vector<pos>容器储存并修改
    */

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