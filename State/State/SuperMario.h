#pragma once
#include<iostream>
#include"Mario.h"
#include"Singleton.h"
using namespace std;
class SuperMario :public MarioState, public Singleton<SuperMario>
{
	public:
    void GotMushroom(shared_ptr<Mario>mario);
    void GotFireFlower(shared_ptr<Mario> mario);
    void GotFeather(shared_ptr<Mario> mario);
};

