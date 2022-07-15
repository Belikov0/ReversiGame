#include <iostream>
#include "gameInterface.h"
#include "gamePlayer.h"
#include "gameEntity.h"
using namespace std;

gamePlayer gameEntity::gameOpen(){
    initBoard();

    while (1){
        /*
            如果是AI
        */
        bool res = isAI(getCurrentPlayer());
        if (!res){
            showCurrentPlayer();
            cuePlayer();
        }
        showBoard();
        pos _pos;
        if (res){
            _pos = AIcalculate();
        }else{
            _pos = getInput();
        }
        placeStone(_pos);
        doReverse(_pos);
        if (isGameOver()){
            return getWinner();
        }else{
            gamePlayer next = getNextPlayer(curr);
            setNextPlayer(next);
        }
    }

    gamePlayer winner;
    return winner;
}

void gameEntity::initBoard(){
    board.resize(8);
    for (int i = 0; i < 8; i++){
        board[i].resize(8);
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            board[i][j] = 'O';
        }
    }
    board[3][3] = 'B';
    board[4][3] = 'B';
    board[3][4] = 'W';
    board[4][4] = 'W';
}

void gameEntity::setGameMode(gameMode _mode){
    mode = _mode;
}

gameMode gameEntity::getGameMode(){
    return mode;
}

void gameEntity::setCurrentPlayer(gamePlayer _curr){
    curr = _curr;
}

gamePlayer gameEntity::getCurrentPlayer(){
    return curr;
}

void gameEntity::setP1(who _player){
    P1.setPlayer(_player);
}

who gameEntity::getP1(){
    return P1.getPlayer();
}

void gameEntity::setP2(who _player){
    P2.setPlayer(_player);
}

who gameEntity::getP2(){
    return P2.getPlayer();
}

void gameEntity::setLeader(who _leader){
    P1.setPlayer(_leader);
    if (getGameMode() == PVE){
        who _player2 = (_leader == AI) ?  PLAYER1 : AI;
        P2.setPlayer(_player2);
    }else{
        P2.setPlayer(PLAYER2);
    }
    setCurrentPlayer(P1);
}
