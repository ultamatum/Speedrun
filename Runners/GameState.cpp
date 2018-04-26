#include "GameState.h"

void GameState::SetCurrentState(State s)
{
	currentState = s;
}

State GameState::GetCurrentState()
{
	return currentState;
}