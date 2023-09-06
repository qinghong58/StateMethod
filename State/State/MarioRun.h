#pragma once
#include<iostream>
#include"Config.h"

using namespace std;
class MarioRun
{

public:

    bool gameOver = false;

    MarioRun() {};

    //基础设置
    void Setup();

    //制作画面
    void Draw(HANDLE console);
    
    //输入
    void Input();
    
    //输入响应
    void Logic();

    //游戏说明
    void GameInstruction();

    void GetCoins();

};

