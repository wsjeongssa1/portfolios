#pragma once
#include"BoundCheckArray.h"

class BlockManager
{
private:
	BoundCheckArray<Block*> blockArr;
	int level;
	//static int index;
	int index;
public:
	~BlockManager();

	void Init(int level, Monster* seal);
	void Reset(Monster* seal);
	void Update();
	void Draw();
	void Collision(Character* cha, Character* cha2);
	bool Collision3(Character* cha, Character* cha2);
	void Collision_seal(Monster* mon);
	//void Collision2(Character* cha);

	//!
	void Floor(int floorY);
};

extern BlockManager blockManager;