#pragma once
#include<iostream>
#include"Config.h"

using namespace std;
class MarioRun
{

public:

    bool gameOver = false;

    MarioRun() {};

    //��������
    void Setup();

    //��������
    void Draw(HANDLE console);
    
    //����
    void Input();
    
    //������Ӧ
    void Logic();

    //��Ϸ˵��
    void GameInstruction();

    void GetCoins();

};

