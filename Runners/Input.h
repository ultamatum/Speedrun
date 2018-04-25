#pragma once
class Input
{
private:
	// Structure to represent Mouse
	struct Mouse
	{
		int x, y;
		bool left;
		bool right;
	};
public:
	void SetKeyDown(int key);
	void SetKeyUp(int key);
	bool IsKeyDown(int key);
	void SetMouseX(int lx);
	void SetMouseY(int ly);
	void SetMousePosition(int lx, int ly);
	int GetMouseX();
	int GetMouseY();
	void SetMouseLeftDown(bool down);
	void SetMouseRightDown(bool down);
	bool IsMouseLeftDown();
	bool IsMouseRightDown();

private:
	bool keys[256]{ false };
	Mouse mouse;
};