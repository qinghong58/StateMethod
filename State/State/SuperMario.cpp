#include "SuperMario.h"
#include"FireMario.h"
#include"CapeMario.h"

void SuperMario::GotMushroom(shared_ptr<Mario>mario)
{
	mario->SetCoin(100);
}

void SuperMario::GotFireFlower(shared_ptr<Mario>mario)
{
	mario->SetCoin(250);
    mario->SetState(FireMario::GetInstance());
}

void SuperMario::GotFeather(shared_ptr<Mario>mario)
{
	mario->SetCoin(400);
	mario->SetState(CapeMario::GetInstance());
}
