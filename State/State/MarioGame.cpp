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
#include <mmsystem.h> // mci��ͷ�ļ�
#pragma comment(lib,"Winmm.lib")

using namespace std;

MarioRun mario_run;

int GameStart()
{
    //�������������
    mciSendString(_T("open Mario.mp3 alias bkmusic"), NULL, 0, NULL);//��������
    mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//ѭ������ 

    mario_run.Setup();
    ////˫���弼��
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = false; // ���ؿ���̨���
    SetConsoleCursorInfo(console, &cursorInfo);

    while (!mario_run.gameOver) {
        mario_run.Draw(console);
        mario_run.Input();
        mario_run.Logic();
        Sleep(50); // ������Ϸ֡��

    }
    system("cls");
    cout << "Game Over!" << endl;
    mciSendString(_T("close bkmusic"), NULL, 0, NULL);//ֹͣ����

    return 0;
}
void Worning()
{
    cout << "���Ұ�����" << endl;
}

void GameMenu()
{
    int flag = 0;
    system("cls");
    cout << "��ӭ���������С��Ϸ" << endl;
    cout << "---------------------------------" << endl;
    cout << "1.��ʼ��Ϸ" << endl;
    cout << "2.��Ϸ˵��" << endl;
    cout << "---------------------------------" << endl;
    cout << "��������ѡ�����ţ�";
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