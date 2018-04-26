#pragma once
enum class State { MENU, LEVEL, PAUSE, CREDITS };

class GameState
{
public:
	void SetCurrentState(State s);
	State GetCurrentState();

	enum GState { MENU, LEVEL, PAUSE, CREDITS };

protected:
	State currentState;
};