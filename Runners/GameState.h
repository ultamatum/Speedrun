#pragma once
enum class State { MENU, LEVEL, PAUSE, HELP, GAMEOVER };

//Class used to manage gamestates
class GameState
{
public:
	void SetCurrentState(State s);
	State GetCurrentState();

	enum GState { MENU, LEVEL, PAUSE, HELP, GAMEOVER };

protected:
	State currentState;
};