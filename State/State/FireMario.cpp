#include "FireMario.h"
#include"CapeMario.h"
void FireMario::GotMushroom(shared_ptr<Mario> mario)
{
	mario->SetCoin(100);
}

void FireMario::GotFireFlower(shared_ptr<Mario> mario)
{
	mario->SetCoin(300);
}

void FireMario::GotFeather(shared_ptr<Mario> mario)
{
	mario->SetCoin(500);
	mario->SetState(CapeMario::GetInstance());
}
