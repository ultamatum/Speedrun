#pragma once
enum class State { MENU, LEVEL, PAUSE, HELP };

class GameState
{
public:
	void SetCurrentState(State s);
	State GetCurrentState();

	enum GState { MENU, LEVEL, PAUSE, HELP };

protected:
	State currentState;
};