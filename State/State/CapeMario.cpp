#include "CapeMario.h"

void CapeMario::GotMushroom(shared_ptr<Mario>mario)
{
	mario->SetCoin(200);
}

void CapeMario::GotFireFlower(shared_ptr<Mario>mario)
{
	mario->SetCoin(500);
}

void CapeMario::GotFeather(shared_ptr<Mario>mario)
{
	mario->SetCoin(1000);
}
