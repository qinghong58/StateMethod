#include "SmallMario.h"
#include"SuperMario.h"
#include"FireMario.h"
#include"CapeMario.h"

void SmallMario::GotMushroom(shared_ptr<Mario> mario)
{
	mario->SetCoin(100);
	
	mario->SetState(SuperMario::GetInstance());
}

void SmallMario::GotFireFlower(shared_ptr<Mario> mario)
{
	mario->SetCoin(200);
    mario->SetState(FireMario::GetInstance());
}

void SmallMario::GotFeather(shared_ptr<Mario> mario)
{
	mario->SetCoin(300);
	mario->SetState(CapeMario::GetInstance());
}
