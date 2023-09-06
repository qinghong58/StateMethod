#pragma once
#include<iostream>
#include<memory>
#include"MarioState.h"

using namespace std;
//ǰ������������໥����
class MarioState;
class Mario:
	public std::enable_shared_from_this<Mario>
{
private:
	    shared_ptr<MarioState>state;
	    int coin;
	
public:
	    Mario();
	    void SetState(shared_ptr<MarioState>state);

	    void SetCoin(int numberOfCoins);
	    void ReportCoin();
	

	    void GotMushroom();
	    void GotFireFlower();
		void GotFeather();


};

