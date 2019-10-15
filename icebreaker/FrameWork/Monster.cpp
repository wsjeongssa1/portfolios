#pragma once
#include "Include.h"


Monster seal;
Monster bird;



Monster::Monster(void)
{
}

Monster::~Monster(void)
{
}

void Monster::Init(int monKind, int mapY, double scale, bool start)
{
	MonMoveTime = GetTickCount();
	MonCountTime = GetTickCount();
	AttCountTime = GetTickCount();
	create = start;
	onoff = true;
	boom = false;

	this->monKind = monKind;
	this->mapY = mapY;
	this->scale = scale;
	srand((unsigned)time(NULL) + mapY);
	pos = rand() % 2;
	if (pos == 0)
		this->mapX = 15;
	else if (pos == 1)
		this->mapX = 15;


	monx = (mapX * 40) - 28;			// 좌
	monX = (mapX * 40) + 28;			// 우
	mony = (mapY * 34) - 74;			// 상
	monY = (mapY * 34);				// 하

	col_fornt_turn = false;
	col_down_turn = false;

	char FileName[256];

	for (int i = 0; i<2; i++)
	{
		sprintf_s(FileName, "./resource/Img/mon/seal_walk%d.png", i + 1);
		seal_walk[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

		sprintf_s(FileName, "./resource/Img/mon/bird_fly%d.png", i + 1);
		bird_fly[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int i = 0; i<4; i++)
	{
		sprintf_s(FileName, "./resource/Img/mon/attackEffect%d.png", i + 1);
		seal_attacked[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	sprintf_s(FileName, "./resource/Img/mon/bird_attacked.png");
	bird_attacked.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}



void Monster::Reset()	// 다시 출현하기위해 위치 재설정
{
	MonMoveTime = GetTickCount();
	MonCountTime = GetTickCount();
	AttCountTime = GetTickCount();
	onoff = true;
	boom = false;

	srand((unsigned)time(NULL) + mapY);
	int pos_t = rand() % 2;
	if (pos_t == pos)
		pos_t = rand() % 2;
	pos = pos_t;
	if (pos == 0)
		this->mapX = 28;
	else if (pos == 1)
		this->mapX = 4;

	move_x = 0;
	monx = (mapX * 40) - 28;			// 좌
	monX = (mapX * 40) + 28;			// 우
}

void Monster::Update()
{
	if (Gmanager.m_GameStart == true && create)
	{
		if (onoff && !boom)	// 살았을때
		{
			// 이동
			if (GetTickCount() - MonMoveTime > 10)
			{
				if (pos == 0)
				{
					move_x -= 2;
					monx -= 2;
					monX -= 2;
					if (monx < 20)// 맵 끝까지 가면 리셋
						onoff = false;
				}
				else if (pos == 1)
				{
					move_x += 2;
					monx += 2;
					monX += 2;
					if (monX > 1260)// 맵 끝까지 가면 리셋
						onoff = false;
				}
				MonMoveTime = GetTickCount();
			}
			// 스프라이트
			if (GetTickCount() - MonCountTime > 200)
			{
				m_count++;

				if (m_count > 1)	m_count = 0;

				MonCountTime = GetTickCount();
			}
			// 충돌
			// 정면 충돌(벽에 부딫히면 || 바닥없으면 방향전환)
			if (col_fornt_turn || col_down_turn)
			{
				// 방향 전환
				pos = (pos + 1) % 2;
				// 상태 전환
				col_fornt_turn = false;
				col_down_turn = false;
			}
			// 바닥 사라짐
			if (col_floor)
			{
				//sound.m_Impact->Play(0, NULL);
				onoff = false;
				boom = true;
				col_floor = false;
			}
		}
		else if (!onoff && boom)	// 맞았을때
		{
			// 스프라이트
			if (GetTickCount() - AttCountTime > 200)
			{
				a_count++;

				if (a_count > 3) {
					a_count = 0;
					boom = false;
					RezCountTime = GetTickCount();
				}

				AttCountTime = GetTickCount();
			}
		}
		else			// 리젠중
		{
			// 리젠쿨타임
			if (GetTickCount() - RezCountTime > 1000)
			{
				Reset();
			}
		}
	}
}

void Monster::Boom()
{

	//if(target.m_Life == true)
	//target.m_Life = false;
}



void Monster::Draw()
{
	//fishimg1[m_Acount].SetColor(255, 255, 255, 255); 안먹힘
	//fishimg1[m_Acount].Render(300+(137*5), 100, D3DX_PI/180, -5, 5); // 반전시 이미지 크기 만큼 이동
	if (Gmanager.m_GameStart == true && create)
	{
		if (onoff && !boom)		// 살았을때
		{
			if (pos == LEFT)
				seal_walk[m_count].Render((mapX * 40) - 38 + move_x, (mapY * 34) - 74, 0, scale, scale);
			else
				seal_walk[m_count].Render((mapX * 40) + 38 + move_x, (mapY * 34) - 74, 0, -scale, scale);
		}
		else if (!onoff && boom) {		// 맞았을때
			if (pos == LEFT)
				seal_attacked[a_count].Render((mapX * 40) - 38 + move_x, (mapY * 34) - 74, 0, scale, scale);
			else
				seal_attacked[a_count].Render((mapX * 40) + 38 + move_x, (mapY * 34) - 74, 0, -scale, scale);
		}
	}
}

void Monster::Floor(int floorY)
{
	if (Gmanager.m_GameStart == true && create)
	{
		if (onoff && !boom)		// 살았을때
		{
			if (pos == LEFT)
				seal_walk[m_count].Render((mapX * 40) - 38 + move_x, (mapY * 34) - 74 + (floorY), 0, scale, scale);
			else
				seal_walk[m_count].Render((mapX * 40) + 38 + move_x, (mapY * 34) - 74 + (floorY), 0, -scale, scale);
		}
		else if (!onoff && boom) {		// 맞았을때
			if (pos == LEFT)
				seal_attacked[a_count].Render((mapX * 40) - 38 + move_x, (mapY * 34) - 74 + (floorY), 0, scale, scale);
			else
				seal_attacked[a_count].Render((mapX * 40) + 38 + move_x, (mapY * 34) - 74 + (floorY), 0, -scale, scale);
		}
		if (floorY >= 204)
		{
			mapY += 6;
			mony = (mapY * 34) - 74;			// 상
			monY = (mapY * 34);				// 하
		}
	}
}


int Monster::Collision_turn(int blockx, int blockX, int blocky, int blockY, bool onoff)
{
	if (pos == RIGHT)
	{
		if ((monX + 5 >= blockx && monX + 5 <= blockX) &&
			(monY - 10 >= blocky && mony - 10 <= blockY))
			return 1;
		if (monX + 10 >= blockx &&
			monX + 10 <= blockX &&
			monY + 17 >= blocky &&
			monY + 17 <= blockY &&
			!onoff)
			return 2;
		return 0;
	}
	else if (pos == LEFT)
	{
		if ((monx - 5 >= blockx && monx - 5 <= blockX) &&
			(monY - 10 >= blocky && mony - 10 <= blockY))
			return 1;
		if (monx - 10 >= blockx &&
			monx - 10 <= blockX &&
			monY + 17 >= blocky &&
			monY + 17 <= blockY &&
			!onoff)
			return 2;
		return 0;
	}
}

int Monster::Collision_floor(int blockx, int blockX, int blocky, int blockY, bool onoff)
{
	if (((monx + 7 >= blockx && monx + 7 <= blockX) || (monX - 7 >= blockx && monX - 7 <= blockX)) &&
		(monY + 17 >= blocky && monY + 17 <= blockY) &&
		!onoff)
	{
		return 1;
	}
	return 0;
}

int Monster::Collision_attacked(int chax, int chaX, int chay, int chaY, int pos)
{
	if (pos == LEFT)
	{
		chaX = chax;
		chax -= 45;
	}
	else
	{
		chax = chaX;
		chaX += 45;
	}
	if (((monx >= chax && monx <= chaX) || (monX >= chax && monX <= chaX)) &&
		((mony >= chay - 10 && mony <= chaY + 10) || (monY >= chay - 10 && monY <= chaY + 10)))
	{
		sound.m_Impact->Play(0, NULL);
		onoff = false;
		boom = true;
		return 1;
	}
	return 0;
}

int Monster::getMonx()
{
	return monx;
}

int Monster::getMonX()
{
	return monX;
}

int Monster::getMony()
{
	return mony;
}

int Monster::getMonY()
{
	return monY;
}

bool Monster::getCreate()
{
	return create;
}

bool Monster::getOnoff()
{
	return onoff;
}

bool Monster::getBoom()
{
	return boom;
}

void Monster::setCol_fornt_turn(bool state)
{
	col_fornt_turn = state;
}

void Monster::setCol_down_turn(bool state)
{
	col_down_turn = state;
}

void Monster::setCol_floor(bool state)
{
	col_floor = state;
}

