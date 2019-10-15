#pragma once
#include "Include.h"

Map map;


Map::Map()
{
	m_Stage = 1;
}

Map::~Map()
{
}

void Map::Init()
{
	int i,j;
	char FileName[256];
	sprintf_s(FileName, "./resource/Img/ice/background.png");
	background.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	
}

void Map::Update(double frame)
{
}

void Map::Draw()
{
	background.Render(0, 0, 0, 1, 1);

}
