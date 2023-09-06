#pragma once
#include<iostream>
#include"Mario.h"
#include"Singleton.h"
#include"MarioState.h"
#include"SmallMario.h"
#include"SuperMario.h"

using namespace std;

class FireMario:public MarioState, public Singleton<FireMario>
{
	public:
    void GotMushroom(shared_ptr<Mario>mario);
    void GotFireFlower(shared_ptr<Mario>mario);
    void GotFeather(shared_ptr<Mario>mario);
};

