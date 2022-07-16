
#ifndef _GAME_INTERFACE_H_
#define _GAME_INTERFACE_H_

class gameInterface{

public:
    void gameStart();
    /*
        main()函数中调用表示启动游戏
    */

    int startMenu();
    /*
        显示开始菜单,接收并返回选项，返回表示
    */

    gameMode modeMenu();
    /*
        选择模式，PVP或者PVE
    */

    who whoLeadsMenu();
    /*
        当为PVE时，选择先手方
        将选择的先手方返回给选择先手方逻辑，设置entity中的先手方
    */

    void gameOverMenu(who);
    /*

    */

};

#endif