#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();
	Sprite test;
	bool tests;

	Sprite background;

	int m_Stage;

	void Init();
	void Update(double frame);
	void Draw();
};

extern Map map;