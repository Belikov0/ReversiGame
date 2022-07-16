#include <iostream>
#include "gameInterface.h"
#include "gamePlayer.h"
#include "gameEntity.h"
using namespace std;

gamePlayer gameEntity::gameOpen(){
    initBoard();
    while (1){
        bool res = isAI(getCurrentPlayer());
        getCanPlace();
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

        gamePlayer next = getNextPlayer(curr);
        setNextPlayer(next);
        if (isGameOver()){
            return getWinner();
        }
    }

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

void gameEntity::recordLastStep(pos _pos){

}

bool gameEntity::isAI(gamePlayer _player){
    return (_player.getPlayer() == AI);
}

void gameEntity::showCurrentPlayer(){
    string s;
    if (getCurrentPlayer() == P1)
        s = "P1 PLAYER";
    else    
        s = "P2 PLAYER";

    cout << "Current Player: " << s << endl;
} 

void gameEntity::getCanPlace(){
    cues.clear();
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (canPlace({i, j})){
                cues.insert({i,j});
                board[i][j] = '*';
            }
        }
    }
}

void gameEntity::cuePlayer(){
    for (auto it = cues.begin(); it != cues.end(); it++){
        pos _pos = (*it);
        board[_pos.first][_pos.second] = '*';
    }
}

void gameEntity::showBoard(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void gameEntity::placeStone(pos _pos){
    char st = (P1 == getCurrentPlayer()) ? 'B' : 'W';
    board[_pos.first][_pos.second] = st;
    step++;
    //消除提示
    if (curr.getPlayer() != AI){
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
}

void gameEntity::doReverse(pos _pos){

}

bool gameEntity::isGameOver(){
    bool ans1 = true; //检测是否已满
    if (step < 60)
        ans1 = false;

    bool ans2 = false; //检测是否双方都不能下
    if (cues.empty()){
        gamePlayer temp = curr;
        setNextPlayer(getNextPlayer(curr));
        getCanPlace();
        if (cues.empty())
            ans2 = true;
        setNextPlayer(temp);
    }

    return (ans1 || ans2);
}

