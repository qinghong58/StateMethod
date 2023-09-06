#pragma once
#include<iostream>
#include"MarioState.h"
#include"Singleton.h"
class CapeMario:public MarioState, public Singleton<CapeMario>
{
public:
    void GotMushroom(shared_ptr<Mario> mario);
    void GotFireFlower(shared_ptr<Mario> mario);
    void GotFeather(shared_ptr<Mario> mario);
};

