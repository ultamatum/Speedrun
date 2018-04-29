#pragma once
enum class Type { PLAYER, MAP, COLLECTABLE };

class SpriteType
{
public:
	void SetType(Type t);
	Type GetType();

	enum SType { Player, Map, Collectable };

protected:
	Type spriteType;
};

