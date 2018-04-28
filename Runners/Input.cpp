#include "Input.h"

void Input::SetKeyDown(int key)
{
	if (key >= 0)
	{
		keys[key] = true;
	}
}

void Input::SetKeyUp(int key)
{
	if (key >= 0)
	{
		keys[key] = false;
	}
}

bool Input::IsKeyDown(int key)
{
	return keys[key];
}

void Input::SetMouseX(int lx)
{
	mouse.x = lx;
}

void Input::SetMouseY(int ly)
{
	mouse.y = ly;
}

void Input::SetMousePosition(int lx, int ly)
{
	SetMouseX(lx);
	SetMouseY(ly);
}

int Input::GetMouseX()
{
	return mouse.x;
}

int Input::GetMouseY()
{
	return mouse.y;
}

void Input::SetMouseLeftDown(bool down)
{
	mouse.left = down;
}

void Input::SetMouseRightDown(bool down)
{
	mouse.right = down;
}

bool Input::IsMouseLeftDown()
{
	return mouse.left;
}

bool Input::IsMouseRightDown()
{
	return mouse.right;
}