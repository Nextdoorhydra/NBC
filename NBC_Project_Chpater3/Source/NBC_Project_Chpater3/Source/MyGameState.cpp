#include "MyGameState.h"

AMyGameState::AMyGameState()
{
	Score = 0;
}

int32 AMyGameState::GetScore() const
{
	return Score;
}

void AMyGameState::AddScore_Implementation(int32 Amount)
{
	Score += Amount;
}