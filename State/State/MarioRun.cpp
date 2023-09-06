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
    flowerCount = 10; // 初始化小花
    featherCount = 10; // 初始化羽毛
    mushroomCount = 10; // 初始化蘑菇
    Coins = 0;//初始化

    // 初始化地面砖块数组
    ground.resize(width, vector<int>(height, 0));
    for (int i = 0; i < height; i++) {
        ground[0][i] = 1; // 设置左侧一列为地面
        ground[1][i] = 1; // 设置靠近左侧的第二列为地面
        ground[width - 1][i] = 1; // 设置右侧一列为地面
        ground[width - 2][i] = 1; // 设置靠近右侧的第二列为地面
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
    SetConsoleCursorPosition(console, cursorPos); // 将光标移动到控制台的左上角

    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {

            bool isPlayer = false;
            if (x == j && y == i) {
                isPlayer = true;
            }
            //地面砖块
            if (ground[j][i] == 1) {
                cout << "="; 
            }
            else if (isPlayer) {
                //超级玛丽
                if (isSuper==true) {
                    cout << "S";             
                }
                //喷火玛丽
                else if (isFire==true) {
                    cout << "F"; 

                }
                //飞行玛丽
                else if (isCape==true) {
                    cout << "W";
                }
                //小玛丽
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
    cout << "按（f）变身为喷火玛丽F   " ;
    cout << "按（r）变身为飞行玛丽W   " ;
    cout << "按（v）变身为超级玛丽S   " ;
    cout << "按（x）退出游戏   ";
    cout << "变身后消耗对应的消耗品，就会获得对应的金币，其余功能在测试阶段   ";
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
            // 变身为喷火玛丽
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
            // 可以随意移动
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
            // 使用蘑菇，变成S
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
    
        // 添加自动下降
        if (!onGround && dir != JUMP) {
            y++;
        }
        if (x >= width || x < 0 || y >= height || y < 0) {
            gameOver = true;
        }
}



void MarioRun::GameInstruction()
{
    cout << "              游戏说明              " << endl;
    cout << "  " << endl;
    cout << "  " << endl;
    cout << "SmallMario吃蘑菇，Coin+100，变成SuperMario" << endl;
    cout << "  " << endl;
    cout << "SmallMario吃小花，Coin+200，变成FireMario" << endl;
    cout << "  " << endl;
    cout << "SmallMario吃羽毛，Coin+300，变成CapeMario" << endl;
    cout << "  " << endl;
    cout << "FireMario吃蘑菇，Coin+100，不会改变" << endl;
    cout << "  " << endl;
    cout << "FireMario吃小花，Coin+300，不会改变" << endl;
    cout << "  " << endl;
    cout << "FireMario吃羽毛，Coin+500，变成CapeMario" << endl;
    cout << "  " << endl;
    cout << "SuperMario吃蘑菇，Coin+100，不会改变" << endl;
    cout << "  " << endl;
    cout << "SuperMario吃小花，Coin+250，变成FireMario" << endl;
    cout << "  " << endl;
    cout << "SuperMario吃羽毛，Coin+400，变成CapeMario" << endl;
    cout << "  " << endl;
    cout << "CapeMario吃蘑菇，Coin+200，不会改变" << endl;
    cout << "  " << endl;
    cout << "CapeMario吃小花，Coin+500，不会改变" << endl;
    cout << "  " << endl;
    cout << "CapeMario吃羽毛，Coin+1000，不会改变" << endl;
}



