#pragma once
#include<iostream>
#include"Mario.h"
#include"Singleton.h"

using namespace std;

class SmallMario : public MarioState, public Singleton<SmallMario>
{
	public:

    void GotMushroom(shared_ptr<Mario>mario) override;
    void GotFireFlower(shared_ptr<Mario>mario) override;
    void GotFeather(shared_ptr<Mario>mario) override;
};

