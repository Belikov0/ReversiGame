#include "gameInterface.h"
#include "gamePlayer.h"
#include "gameEntity.h"
#include <conio.h>
#include <iostream>
using namespace std;

void gameInterface::gameStart(){
    HEAD:
    gameEntity entity;
    
    //startMenu logic
    int choice = startMenu();
    if (choice == 2){
        return; // exit game
    }

    //modeMenu logic
    gameMode mode = modeMenu();
    entity.setGameMode(mode);

    //whoLeadsMenu logic
    if (entity.getGameMode() == PVE){
        who leader = whoLeadsMenu();
        entity.setLeader(leader);
    }else{
        entity.setLeader(PLAYER1);
    }

    // gameInitiate
    who winner = entity.gameOpen().getPlayer();


    // gameOverMenu logic
    gameOverMenu(winner);
    goto HEAD;
}

int gameInterface::startMenu(){
    cout << "Welcome!" << endl;
    cout << "1.Start" << endl;
    cout << "2.Exit" << endl;
    cout << "------------" << endl;
    cout << "Input a number to choose: ";
    int res;
    return res;
}

gameMode gameInterface::modeMenu(){
    cout << "Choose your game mode" << endl;
    cout << "1.Play with player" << endl;
    cout << "2.Play with AI" << endl;
    cout << "--------------" << endl;
    cout << "Input a number to choose: ";
    int choice;
    cin >> choice;
    gameMode mode;
    if (choice == 1)
        mode = PVP;
    else if (choice == 2)
        mode = PVE;

    return mode;
}

who gameInterface::whoLeadsMenu(){
    cout << "Choose who to play first" << endl;
    cout << "Player" << endl;
    cout << "AI" << endl;
    cout << "-------------" << endl;
    cout << "Input a number to choose: " << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
        return PLAYER1;
    else
        return AI;
}

void gameInterface::gameOverMenu(who winner){
    string _winner;
    switch(winner){
        case 0 : _winner = "PLAYER1";
                    break;
        case 1 : _winner = "PLAYER2";
                    break;
        case 2 : _winner = "AI";
                    break;
        default : _winner = "HIKIWAKE";
                    break;
    }

    if (winner == HIKIWAKE)
        cout << _winner << endl;
    else
        cout << "The winner is: " << _winner << "!" << endl;
    
    cout << "Press any key to continue..." << endl;
    char* ch = new char;
    (*ch) = getch();
    delete ch;
    return;


}