
/*

*/

#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_
#include "gameInterface.h"
#include "gamePlayer.h"
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
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
    unordered_set<pos> cues; 
    int step; // 记录步数，判断是否结束
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
        PVP模式默认P1先手且P1为PLALTEYER1
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
    /*
        显示当前下棋的玩家
    */
    void getCanPlace();

    void cuePlayer();
    /*
        计算当前哪些地方可以摆放棋子，并修改棋盘在棋盘上显示
        使用unordered_set<pos>容器储存并修改
        容器用来判定玩家下棋是否合法
    */



    bool isLegal(pos); // 判断当前位置是否合法
    pos AIcalculate(); // complex 电脑计算下棋位置并返回
    pos getInput();  //从设备（玩家）获得输入信息

    void showBoard();
    void placeStone(pos);
    void doReverse(pos); // complex
    bool isGameOver(); //int 变量用于记录是否双方都无法继续落子
    gamePlayer getWinner();

    gamePlayer getNextPlayer(gamePlayer);
    void setNextPlayer(gamePlayer);
    bool canPlace(pos);



};

#endif