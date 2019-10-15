#pragma once
#include "Include.h"

BlockManager blockManager;

BlockManager::~BlockManager()
{
	for (int i = 0; i< index; i++)
		delete blockArr[i];
}

void BlockManager::Init(int level, Monster* seal)
{
	index = 0;
	this->level = level;
	if (this->level == 0)
	{
		seal->Init(1, 26 - (level * 6), 1, false);
		for (int j = 0; j < 6; j++)
		{
			for (int i = 0; i < 32; i++)
			{
				if (bottom[j][i] != 0)
				{
					blockArr[index] = new Block;
					blockArr[index++]->Init(bottom[j][i], i, 26 - (6 - j) - (level * 6), 1);
				}
			}
		}
	}
	else if (this->level == 1)
	{
		//bool s = rand() % 2;
		//seal->Init(1, 26 - (level * 6), 1, s);
		seal->Init(1, 26 - (level * 6), 1, false);
		for (int j = 0; j < 6; j++)
		{
			for (int i = 0; i < 32; i++)
			{
				if (floors[3][j][i] != 0)
				{
					blockArr[index] = new Block;
					blockArr[index++]->Init(floors[3][j][i], i, 27 - (6 - j) - (level * 6), 1);
				}
			}
		}
	}
	else
	{
		//srand(unsigned(time(NULL)));
		int select = rand() % 8;
		if (select < 4)
		{
			bool s = rand() % 2;
			seal->Init(1, 26 - (level * 6), 1, s);
		}
		else
			seal->Init(1, 26 - (level * 6), 1, false);
		for (int j = 0; j < 6; j++)
		{
			for (int i = 6; i < 26; i++)
			{
				if (floors[select][j][i] != 0)
				{
					blockArr[index] = new Block;
					blockArr[index++]->Init(floors[select][j][i], i, 27 - (6 - j) - (level * 6), 1);
				}
			}
			for (int i = 26; i < 32; i++)
			{
				if (floors[select][j][i] != 0)
				{
					blockArr[index] = new Block;
					blockArr[index++]->Init(floors[select][j][i], i, 27 - (6 - j) - (level * 6), 1);
				}
			}
			for (int i = 0; i < 6; i++)
			{
				if (floors[select][j][i] != 0)
				{
					blockArr[index] = new Block;
					blockArr[index++]->Init(floors[select][j][i], i, 27 - (6 - j) - (level * 6), 1);
				}
			}
		}
	}
}

void BlockManager::Reset(Monster* seal)
{
	index = 0;
	this->level = 6;

	//srand(unsigned(time(NULL)));
	int select = rand() % 12;
	if (select < 4)
	{
		bool s = rand() % 2;
		seal->Init(1, 26 - (level * 6), 1, s);
	}
	else
		seal->Init(1, 26 - (level * 6), 1, false);
	for (int j = 0; j < 6; j++)
	{
		for (int i = 6; i < 26; i++)
		{
			if (floors[select][j][i] != 0)
			{
				blockArr[index] = new Block;
				blockArr[index++]->Init(floors[select][j][i], i, 27 - (6 - j) - (level * 6), 1);
			}
		}
		for (int i = 26; i < 32; i++)
		{
			if (floors[select][j][i] != 0)
			{
				blockArr[index] = new Block;
				blockArr[index++]->Init(floors[select][j][i], i, 27 - (6 - j) - (level * 6), 1);
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (floors[select][j][i] != 0)
			{
				blockArr[index] = new Block;
				blockArr[index++]->Init(floors[select][j][i], i, 27 - (6 - j) - (level * 6), 1);
			}
		}
	}

}

void BlockManager::Update()
{
	for (int i = 0; i < index; i++)
	{
		blockArr[i]->Update();
	}
}

void BlockManager::Draw()
{
	for (int i = 0; i < index; i++)
	{
		blockArr[i]->Draw();
	}
}

void BlockManager::Floor(int floorY)
{
	for (int i = 0; i < index; i++)
	{
		blockArr[i]->Floor(floorY);
	}
}

void BlockManager::Collision(Character* cha, Character* cha2)
{
	// 1p
	Col ch_temp = cha->getCol_temp();
	Col ch = cha->getCol();
	Col ch_temp2 = cha2->getCol_temp();
	Col ch2 = cha2->getCol();
	for (int i = 0; i < index; i++)
	{
		// 떨어지는중
		if (!cha->getJump_state())
		{
			int check = blockArr[i]->Collision_V(ch_temp.chx, ch_temp.chX, ch_temp.chy, ch_temp.chY);
			if (check == UP || check == 6)		// 무언가의 윗부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 3 || kind == 4 || kind == 5)		// 구름이나 스피드 블럭에 착지시 이동적용
				{
					cha->setAutomove_state(true);
				}
				cha->setFloor_collision_temp(true);
				cha->setExtra_fall_y(abs(blockArr[i]->getBlocky() - ch.chY));
			}
			if (cha->getAutomove_state())						// 이전 블럭들중 자동이동 있었으면
			{
				for (int j = 0; j < index; j++)				// 처음부터 싹 뒤지면서
				{
					int check2 = blockArr[j]->Collision_H(ch.chx - 4, ch.chX, ch.chy + 1, ch.chY - 1);
					if (check2 == RIGHT || check2 == 6)		// 무언가의 오른쪽부분에 충돌
						cha->setAutomove_state(false);

				}
				int check3 = cha->Collision_H(ch2.chx, ch2.chX + 14, ch2.chy + 1, ch2.chY - 1);
				if (check3 == RIGHT || check3 == 6)		// 무언가의 오른쪽부분에 충돌
					cha->setAutomove_state(false);
			}
		}
		else// 점프 중									
		{
			if (blockArr[i]->Collision_V(ch_temp.chx, ch_temp.chX, ch_temp.chy, ch_temp.chY) == DOWN)		// 무언가의 아래부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 1 || kind == 3)		// 일반블럭 스피드블럭
				{
					sound.m_HitIce->Play(0, NULL);
					blockArr[i]->Destroy(cha->getPlayer());													// 파괴
					playdata.p1_block_count++;
				}
				else if (kind == 2 || kind == 4 || kind == 5) {
					sound.m_HitHard->Play(0, NULL);
				}
				cha->setJump_collision_temp(true);
				cha->setExtra_jump_y(-abs(blockArr[i]->getBlockY() - ch.chy));
			}
		}
		// 우로 이동중
		if (cha->getMove_state_r())
		{
			int check = blockArr[i]->Collision_H(ch.chx, ch.chX + 4, ch.chy + 1, ch.chY - 1);
			if (check == LEFT || check == 6)		// 무언가의 왼쪽부분에 충돌
			{
				cha->setMove_collision_r(true);
			}
		}
		// 좌로 이동중
		if (cha->getMove_state_l())
		{
			int check = blockArr[i]->Collision_H(ch.chx - 4, ch.chX, ch.chy + 1, ch.chY - 1);
			if (check == RIGHT || check == 6)		// 무언가의 오른쪽부분에 충돌
			{
				cha->setMove_collision_l(true);
			}
		}
	}

	// 2p
	for (int i = 0; i < index; i++)
	{
		// 떨어지는중
		if (!cha2->getJump_state())
		{
			int check = blockArr[i]->Collision_V2(ch_temp2.chx, ch_temp2.chX, ch_temp2.chy, ch_temp2.chY);
			if (check == UP || check == 6)		// 무언가의 윗부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 3 || kind == 4 || kind == 5)		// 구름이나 스피드 블럭에 착지시 이동적용
				{
					cha2->setAutomove_state(true);
				}
				cha2->setFloor_collision_temp(true);
				cha2->setExtra_fall_y(abs(blockArr[i]->getBlocky() - ch2.chY));
			}
			if (cha2->getAutomove_state())						// 이전 블럭들중 자동이동 있었으면
			{
				for (int j = 0; j < index; j++)				// 처음부터 싹 뒤지면서
				{
					int check2 = blockArr[j]->Collision_H2(ch2.chx - 4, ch2.chX, ch2.chy + 1, ch2.chY - 1);
					if (check2 == RIGHT || check2 == 6)		// 무언가의 오른쪽부분에 충돌
						cha2->setAutomove_state(false);
				}
				int check3 = cha2->Collision_H(ch.chx, ch.chX + 14, ch.chy + 1, ch.chY - 1);
				if (check3 == RIGHT || check3 == 6)		// 무언가의 오른쪽부분에 충돌
					cha2->setAutomove_state(false);
			}
		}
		else// 점프 중									
		{
			if (blockArr[i]->Collision_V2(ch_temp2.chx, ch_temp2.chX, ch_temp2.chy, ch_temp2.chY) == DOWN)		// 무언가의 아래부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 1 || kind == 3)		// 일반블럭 스피드블럭
				{
					sound.m_HitIce->Play(0, NULL);
					blockArr[i]->Destroy(cha2->getPlayer());													// 파괴
					playdata.p2_block_count++;
				}
				else if (kind == 2 || kind == 4 || kind == 5) {
					sound.m_HitHard->Play(0, NULL);
				}
				cha2->setJump_collision_temp(true);
				cha2->setExtra_jump_y(-abs(blockArr[i]->getBlockY() - ch.chy));
			}
		}
		// 우로 이동중
		if (cha2->getMove_state_r())
		{
			int check = blockArr[i]->Collision_H2(ch2.chx, ch2.chX + 4, ch2.chy + 1, ch2.chY - 1);
			if (check == LEFT || check == 6)		// 무언가의 왼쪽부분에 충돌
			{
				cha2->setMove_collision_r(true);
			}
		}
		// 좌로 이동중
		if (cha2->getMove_state_l())
		{
			int check = blockArr[i]->Collision_H2(ch2.chx - 4, ch2.chX, ch2.chy + 1, ch2.chY - 1);
			if (check == RIGHT || check == 6)		// 무언가의 오른쪽부분에 충돌
			{
				cha2->setMove_collision_l(true);
			}
		}
	}
}

bool BlockManager::Collision3(Character * cha, Character * cha2)
{
	bool floorcheck = false;
	// 1p
	Col ch_temp = cha->getCol_temp();
	Col ch = cha->getCol();
	Col ch_temp2 = cha2->getCol_temp();
	Col ch2 = cha2->getCol();
	for (int i = 0; i < index; i++)
	{
		// 떨어지는중
		if (!cha->getJump_state())
		{
			int check = blockArr[i]->Collision_V(ch_temp.chx, ch_temp.chX, ch_temp.chy, ch_temp.chY);
			if (check == UP || check == 6)		// 무언가의 윗부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 3 || kind == 4 || kind == 5)		// 구름이나 스피드 블럭에 착지시 이동적용
				{
					cha->setAutomove_state(true);
				}
				cha->setFloor_collision_temp(true);
				cha->setExtra_fall_y(abs(blockArr[i]->getBlocky() - ch.chY));
			}
			if (check == UP)
			{
				floorcheck = true;
			}
			if (cha->getAutomove_state())						// 이전 블럭들중 자동이동 있었으면
			{
				for (int j = 0; j < index; j++)				// 처음부터 싹 뒤지면서
				{
					int check2 = blockArr[j]->Collision_H(ch.chx - 4, ch.chX, ch.chy + 1, ch.chY - 1);
					if (check2 == RIGHT || check2 == 6)		// 무언가의 오른쪽부분에 충돌
						cha->setAutomove_state(false);
				}
				int check3 = cha->Collision_H(ch2.chx, ch2.chX + 14, ch2.chy + 1, ch2.chY - 1);
				if (check3 == RIGHT || check3 == 6)		// 무언가의 오른쪽부분에 충돌
					cha->setAutomove_state(false);
			}
		}
		else// 점프 중									
		{
			if (blockArr[i]->Collision_V(ch_temp.chx, ch_temp.chX, ch_temp.chy, ch_temp.chY) == DOWN)		// 무언가의 아래부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 1 || kind == 3)		// 일반블럭 스피드블럭
				{
					sound.m_HitIce->Play(0, NULL);
					blockArr[i]->Destroy(cha->getPlayer());													// 파괴
					playdata.p1_block_count++;
				}
				else if (kind == 2 || kind == 4 || kind == 5) {
					sound.m_HitHard->Play(0, NULL);
				}
				cha->setJump_collision_temp(true);
				cha->setExtra_jump_y(-abs(blockArr[i]->getBlockY() - ch.chy));
			}
		}
		// 우로 이동중
		if (cha->getMove_state_r())
		{
			int check = blockArr[i]->Collision_H(ch.chx, ch.chX + 4, ch.chy + 1, ch.chY - 1);
			if (check == LEFT || check == 6)		// 무언가의 왼쪽부분에 충돌
			{
				cha->setMove_collision_r(true);
			}
		}
		// 좌로 이동중
		if (cha->getMove_state_l())
		{
			int check = blockArr[i]->Collision_H(ch.chx - 4, ch.chX, ch.chy + 1, ch.chY - 1);
			if (check == RIGHT || check == 6)		// 무언가의 오른쪽부분에 충돌
			{
				cha->setMove_collision_l(true);
			}
		}
	}

	// 2p
	for (int i = 0; i < index; i++)
	{
		// 떨어지는중
		if (!cha2->getJump_state())
		{
			int check = blockArr[i]->Collision_V2(ch_temp2.chx, ch_temp2.chX, ch_temp2.chy, ch_temp2.chY);
			if (check == UP || check == 6)		// 무언가의 윗부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 3 || kind == 4 || kind == 5)		// 구름이나 스피드 블럭에 착지시 이동적용
				{
					cha2->setAutomove_state(true);
				}
				cha2->setFloor_collision_temp(true);
				cha2->setExtra_fall_y(abs(blockArr[i]->getBlocky() - ch2.chY));
			}
			if (check == UP)
			{
				floorcheck = true;
			}
			if (cha2->getAutomove_state())						// 이전 블럭들중 자동이동 있었으면
			{
				for (int j = 0; j < index; j++)				// 처음부터 싹 뒤지면서
				{
					int check2 = blockArr[j]->Collision_H2(ch2.chx - 4, ch2.chX, ch2.chy + 1, ch2.chY - 1);
					if (check2 == RIGHT || check2 == 6)		// 무언가의 오른쪽부분에 충돌
						cha2->setAutomove_state(false);
				}
				int check3 = cha2->Collision_H(ch.chx, ch.chX + 14, ch.chy + 1, ch.chY - 1);
				if (check3 == RIGHT || check3 == 6)		// 무언가의 오른쪽부분에 충돌
					cha2->setAutomove_state(false);
			}
		}
		else// 점프 중									
		{
			if (blockArr[i]->Collision_V2(ch_temp2.chx, ch_temp2.chX, ch_temp2.chy, ch_temp2.chY) == DOWN)		// 무언가의 아래부분에 충돌
			{
				int kind = blockArr[i]->getBoxKind();
				if (kind == 1 || kind == 3)		// 일반블럭 스피드블럭
				{
					sound.m_HitIce->Play(0, NULL);
					blockArr[i]->Destroy(cha2->getPlayer());													// 파괴
					playdata.p2_block_count++;
				}
				else if (kind == 2 || kind == 4 || kind == 5) {
					sound.m_HitHard->Play(0, NULL);
				}
				cha2->setJump_collision_temp(true);
				cha2->setExtra_jump_y(-abs(blockArr[i]->getBlockY() - ch.chy));
			}
		}
		// 우로 이동중
		if (cha2->getMove_state_r())
		{
			int check = blockArr[i]->Collision_H2(ch2.chx, ch2.chX + 4, ch2.chy + 1, ch2.chY - 1);
			if (check == LEFT || check == 6)		// 무언가의 왼쪽부분에 충돌
			{
				cha2->setMove_collision_r(true);
			}
		}
		// 좌로 이동중
		if (cha2->getMove_state_l())
		{
			int check = blockArr[i]->Collision_H2(ch2.chx - 4, ch2.chX, ch2.chy + 1, ch2.chY - 1);
			if (check == RIGHT || check == 6)		// 무언가의 오른쪽부분에 충돌
			{
				cha2->setMove_collision_l(true);
			}
		}
	}
	return floorcheck;
}

void BlockManager::Collision_seal(Monster * mon)
{
	for (int i = 0; i < index; i++)
	{
		int check = mon->Collision_floor(blockArr[i]->getBlockx(), blockArr[i]->getBlockX(), blockArr[i]->getBlocky(), blockArr[i]->getBlockY(), blockArr[i]->getOnoff());
		if (check == 1)
		{
			if (blockArr[i]->getPlayer() == PLAYER1)
			{
				blockArr[i]->setPlayer(0);
				playdata.p1_seal_count++;
			}
			else if (blockArr[i]->getPlayer() == PLAYER2)
			{
				blockArr[i]->setPlayer(0);
				playdata.p2_seal_count++;
			}
			mon->setCol_floor(true);
			return;
		}
	}
	for (int i = 0; i < index; i++)
	{
		int check = mon->Collision_turn(blockArr[i]->getBlockx(), blockArr[i]->getBlockX(), blockArr[i]->getBlocky(), blockArr[i]->getBlockY(), blockArr[i]->getOnoff());
		if (check == 1)
		{
			mon->setCol_fornt_turn(true);
			return;
		}
		else if (check == 2)
		{
			mon->setCol_down_turn(true);
			return;
		}
	}
}
/*
void BlockManager::Collision2(Character* cha)
{
Col ch_temp = cha->getCol_temp();
Col ch = cha->getCol();
for (int i = 0; i < index; i++)
{
// 떨어지는중
if (!cha->getJump_state())
{
int check = blockArr[i]->Collision_V2(ch_temp.chx, ch_temp.chX, ch_temp.chy, ch_temp.chY);
if (check == UP || check == 6)		// 무언가의 윗부분에 충돌
{
int kind = blockArr[i]->getBoxKind();
if (kind == 3 || kind == 4 || kind == 5)		// 구름이나 스피드 블럭에 착지시 이동적용
{
cha->setAutomove_state(true);
}
cha->setFloor_collision_temp(true);
cha->setExtra_fall_y(abs(blockArr[i]->getBlocky() - ch.chY));
}
if (cha->getAutomove_state())						// 이전 블럭들중 자동이동 있었으면
{
for (int j = 0; j < index; j++)				// 처음부터 싹 뒤지면서
{
int check2 = blockArr[j]->Collision_H2(ch.chx - 4, ch.chX, ch.chy + 1, ch.chY - 1);
if (check2 == RIGHT || check2 == 6)		// 무언가의 오른쪽부분에 충돌
cha->setAutomove_state(false);
}
}
}
else// 점프 중
{
if (blockArr[i]->Collision_V2(ch_temp.chx, ch_temp.chX, ch_temp.chy, ch_temp.chY) == DOWN)		// 무언가의 아래부분에 충돌
{
int kind = blockArr[i]->getBoxKind();
if (kind == 1 || kind == 3)		// 일반블럭 스피드블럭
blockArr[i]->Destroy();													// 파괴

cha->setJump_collision_temp(true);
cha->setExtra_jump_y(-abs(blockArr[i]->getBlockY() - ch.chy));
}
}
// 우로 이동중
if (cha->getMove_state_r())
{
int check = blockArr[i]->Collision_H2(ch.chx, ch.chX + 4, ch.chy + 1, ch.chY - 1);
if (check == LEFT || check == 6)		// 무언가의 왼쪽부분에 충돌
{
cha->setMove_collision_r(true);
}
}
// 좌로 이동중
if (cha->getMove_state_l())
{
int check = blockArr[i]->Collision_H2(ch.chx - 4, ch.chX, ch.chy + 1, ch.chY - 1);
if (check == RIGHT || check == 6)		// 무언가의 오른쪽부분에 충돌
{
cha->setMove_collision_l(true);
}
}
}
}*/