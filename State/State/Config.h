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
static int x, y; // ����������
static vector<vector<int>> ground; // ����ש������
static enum Direction { STOP = 0, LEFT, RIGHT, JUMP, DOWN };

static Direction dir; // �������ƶ�����
static bool onGround; // �ж��Ƿ��ڵ���
static bool isSuper; // ��������
static bool isFire; // �������
static bool isCape; // ��������

static int flowerCount; // С������
static int featherCount; // ��ë����
static int mushroomCount; // Ģ������
static int Coins;//�������



static unordered_map<int, function<void()>>GameMenuMap;