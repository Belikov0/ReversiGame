#include <iostream>
#include "gameInterface.h"
#include "gamePlayer.h"
#include "gameEntity.h"
using namespace std;

gamePlayer gameEntity::gameOpen(){
    while (1){
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

void gameEntity::showBoard(){

}

