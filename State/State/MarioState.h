#pragma once
#include<iostream>
#include<memory>
#include"Mario.h"

using namespace std;

//前向声明，解决相互依赖问题
class Mario;
class MarioState {
public:
    virtual void GotMushroom(shared_ptr<Mario>mario) = 0;
    virtual void GotFireFlower(shared_ptr<Mario>mario) = 0;
    virtual void GotFeather(shared_ptr<Mario>mario) = 0;
};