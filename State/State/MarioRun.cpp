#include<iostream>
#include "MarioRun.h"
#include"Config.h"
#include"CapeMario.h"
#include"Mario.h"
#include"FireMario.h"
#include"SuperMario.h"

using namespace std;

shared_ptr<Mario>mario = make_shared<Mario>();
shared_ptr<SuperMario>supermario = make_shared<SuperMario>();
shared_ptr<FireMario>firemario = make_shared<FireMario>();
shared_ptr<CapeMario>capemario = make_shared<CapeMario>();

void MarioRun::Setup()
{

    dir = STOP;
    x = width / 2;
    y = height - 1;
    onGround = true;
    isSuper = false;
    isFire = false;
    isCape = false;
    flowerCount = 10; // ��ʼ��С��
    featherCount = 10; // ��ʼ����ë
    mushroomCount = 10; // ��ʼ��Ģ��
    Coins = 0;//��ʼ��

    // ��ʼ������ש������
    ground.resize(width, vector<int>(height, 0));
    for (int i = 0; i < height; i++) {
        ground[0][i] = 1; // �������һ��Ϊ����
        ground[1][i] = 1; // ���ÿ������ĵڶ���Ϊ����
        ground[width - 1][i] = 1; // �����Ҳ�һ��Ϊ����
        ground[width - 2][i] = 1; // ���ÿ����Ҳ�ĵڶ���Ϊ����
        if (i > 1 && i < height - 1) {
            for (int j = 2; j < width - 2; j++) {
                ground[j][i] = 0; 
            }
        }
    }

}

void MarioRun::Draw(HANDLE console)
{
    COORD cursorPos;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(console, cursorPos); // ������ƶ�������̨�����Ͻ�

    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {

            bool isPlayer = false;
            if (x == j && y == i) {
                isPlayer = true;
            }
            //����ש��
            if (ground[j][i] == 1) {
                cout << "="; 
            }
            else if (isPlayer) {
                //��������
                if (isSuper==true) {
                    cout << "S";             
                }
                //�������
                else if (isFire==true) {
                    cout << "F"; 

                }
                //��������
                else if (isCape==true) {
                    cout << "W";
                }
                //С����
                else {
                    cout << "M";
                }
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }






    mario->ReportCoin();

    cout << "Super: " << (isSuper ? "Yes" : "No") << endl;
    cout << "Fire: " << (isFire ? "Yes" : "No") << endl;
    cout << "Cape: " << (isCape ? "Yes" : "No") << endl;
    cout << "Has Flower: " << (flowerCount > 0 ? "Yes" : "No") << " (" << flowerCount << ")" << endl;
    cout << "Has Feather: " << (featherCount > 0 ? "Yes" : "No") << " (" << featherCount << ")" << endl;
    cout << "Has Mushroom: " << (mushroomCount > 0 ? "Yes" : "No") << " (" << mushroomCount << ")" << endl;
    cout << "  ";
    cout << "����f������Ϊ�������F   " ;
    cout << "����r������Ϊ��������W   " ;
    cout << "����v������Ϊ��������S   " ;
    cout << "����x���˳���Ϸ   ";
    cout << "��������Ķ�Ӧ������Ʒ���ͻ��ö�Ӧ�Ľ�ң����๦���ڲ��Խ׶�   ";
}
void MarioRun::Input()
{
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = JUMP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'f':
            // ����Ϊ�������
            if (flowerCount > 0) {

                isFire = true;
                //isSuper = false;
                //isCape = false;

                if (isFire )
                {
                    flowerCount--;
                    firemario->GotFireFlower(mario);
                }
                else if (isFire && isSuper)
                {
                    flowerCount--;
                    supermario->GotFireFlower(mario);
                }
                else if (isFire && isCape)
                {
                    flowerCount--;
                    capemario->GotFireFlower(mario);
                }
            }
            break;
        case 'r':
            // ���������ƶ�
            if (featherCount > 0) {
                isCape = true;
                if (isCape)
                {
                    featherCount--;
                    capemario->GotFeather(mario);
                }
                if (isCape&&isFire)
                {
                    featherCount--;
                    firemario->GotFeather(mario);
                }
                if (isCape && isSuper)
                {
                    featherCount--;
                    supermario->GotFeather(mario);
                }
            }
            break;
        case 'v':
            // ʹ��Ģ�������S
            if (mushroomCount > 0) {
                isSuper = true;
                if (isSuper)
                {
                    mushroomCount--;
                    supermario->GotMushroom(mario);
                }
                else if (isSuper && isFire)
                {
                    mushroomCount--;
                    firemario->GotMushroom(mario);
                }
                else if (isSuper && isCape)
                {
                    mushroomCount--;
                    capemario->GotMushroom(mario);
                }
            }
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void MarioRun::Logic()
{
        switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case JUMP:
            if (onGround) {
                y = y - 3;
                onGround = false;
            }
            break;
        }
        if (y < height - 1 && ground[x][y + 1] == 0) {
            y++;
            onGround = false;
        }
        else {
            onGround = true;
        }
    
        // ����Զ��½�
        if (!onGround && dir != JUMP) {
            y++;
        }
        if (x >= width || x < 0 || y >= height || y < 0) {
            gameOver = true;
        }
}



void MarioRun::GameInstruction()
{
    cout << "              ��Ϸ˵��              " << endl;
    cout << "  " << endl;
    cout << "  " << endl;
    cout << "SmallMario��Ģ����Coin+100�����SuperMario" << endl;
    cout << "  " << endl;
    cout << "SmallMario��С����Coin+200�����FireMario" << endl;
    cout << "  " << endl;
    cout << "SmallMario����ë��Coin+300�����CapeMario" << endl;
    cout << "  " << endl;
    cout << "FireMario��Ģ����Coin+100������ı�" << endl;
    cout << "  " << endl;
    cout << "FireMario��С����Coin+300������ı�" << endl;
    cout << "  " << endl;
    cout << "FireMario����ë��Coin+500�����CapeMario" << endl;
    cout << "  " << endl;
    cout << "SuperMario��Ģ����Coin+100������ı�" << endl;
    cout << "  " << endl;
    cout << "SuperMario��С����Coin+250�����FireMario" << endl;
    cout << "  " << endl;
    cout << "SuperMario����ë��Coin+400�����CapeMario" << endl;
    cout << "  " << endl;
    cout << "CapeMario��Ģ����Coin+200������ı�" << endl;
    cout << "  " << endl;
    cout << "CapeMario��С����Coin+500������ı�" << endl;
    cout << "  " << endl;
    cout << "CapeMario����ë��Coin+1000������ı�" << endl;
}



