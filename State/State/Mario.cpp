#include<memory>
#include "Mario.h"
#include"SmallMario.h"

using namespace std;



Mario::Mario()
{
	coin = 0;
    this->state = SmallMario::GetInstance();
}

void Mario::SetState(shared_ptr<MarioState>state)
{
	this->state = state;
}

void Mario::SetCoin(int numberOfCoins)
{
	std::cout << "Got Coins: " << numberOfCoins << std::endl;
    coin += numberOfCoins;
}

void Mario::ReportCoin()
{
	std::cout << "Total Coin: " << coin << std::endl;
}

void Mario::GotMushroom()
{
	this->state->GotMushroom(shared_from_this());
}

void Mario::GotFireFlower()
{
	this->state->GotFireFlower(shared_from_this());
}

//³ÔÓðÃ«
void Mario::GotFeather()
{
	this->state->GotFeather(shared_from_this());
}


