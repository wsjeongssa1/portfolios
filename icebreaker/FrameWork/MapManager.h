#pragma once
#include"BoundCheckArray.h"

class MapManager
{
private:
	BoundCheckArray<BlockManager*> blockMap;
	Character* cha;
	Character* cha2;
	BoundCheckArray<Monster*> seal;

public:
	int floorY;
	bool floor_move;
	int floor_move_now, floor_skip_1, floor_skip_2;

	MapManager();
	~MapManager();

	void Init();
	void Update();
	void Draw();
	void Collision();
};

extern MapManager mapManager;