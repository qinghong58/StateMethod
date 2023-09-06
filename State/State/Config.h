#pragma once
#include<iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include<unordered_map>
#include<functional>

using namespace std;

const int width = 40;
const int height = 20;
static int x, y; // 玛丽的坐标
static vector<vector<int>> ground; // 地面砖块数组
static enum Direction { STOP = 0, LEFT, RIGHT, JUMP, DOWN };

static Direction dir; // 玛丽的移动方向
static bool onGround; // 判断是否在地面
static bool isSuper; // 超级玛丽
static bool isFire; // 喷火玛丽
static bool isCape; // 飞行玛丽

static int flowerCount; // 小花数量
static int featherCount; // 羽毛数量
static int mushroomCount; // 蘑菇数量
static int Coins;//金币数量



static unordered_map<int, function<void()>>GameMenuMap;