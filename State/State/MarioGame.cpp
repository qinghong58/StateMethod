#include <stdio.h>
#include <graphics.h>
#include <iostream>
#include<memory>
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"Mario.h"
#include"SmallMario.h"
#include"MarioRun.h"
#include"SuperMario.h"
#include"FireMario.h"
#include"CapeMario.h"
#include <mmsystem.h> // mci库头文件
#pragma comment(lib,"Winmm.lib")

using namespace std;

MarioRun mario_run;

int GameStart()
{
    //请配带耳机游玩
    mciSendString(_T("open Mario.mp3 alias bkmusic"), NULL, 0, NULL);//播放音乐
    mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//循环播放 

    mario_run.Setup();
    ////双缓冲技术
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = false; // 隐藏控制台光标
    SetConsoleCursorInfo(console, &cursorInfo);

    while (!mario_run.gameOver) {
        mario_run.Draw(console);
        mario_run.Input();
        mario_run.Logic();
        Sleep(50); // 控制游戏帧率

    }
    system("cls");
    cout << "Game Over!" << endl;
    mciSendString(_T("close bkmusic"), NULL, 0, NULL);//停止播放

    return 0;
}
void Worning()
{
    cout << "别乱按啊！" << endl;
}

void GameMenu()
{
    int flag = 0;
    system("cls");
    cout << "欢迎来到马里奥小游戏" << endl;
    cout << "---------------------------------" << endl;
    cout << "1.开始游戏" << endl;
    cout << "2.游戏说明" << endl;
    cout << "---------------------------------" << endl;
    cout << "请输入你选择的序号：";
    cin >> flag;
    if (flag==1)
    {
        GameStart();
    }
    else if (flag==2)
    {
        mario_run.GameInstruction();
        Sleep(3000);
        GameMenu();
    }
    else
    {
        Worning();
        Sleep(2000);

        system("cls");
        GameMenu();
    }

}


int main() {

    GameMenu();

    return 0;
}