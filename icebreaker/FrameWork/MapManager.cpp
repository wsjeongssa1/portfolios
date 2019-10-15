#pragma once
#include"Include.h"


MapManager mapManager;

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
	for (int i = 0; i < 6; i++)
	{
		delete seal[i];
		delete blockMap[i];
	}
	delete cha;
	delete cha2;
}

void MapManager::Init()
{
	floor_move_now = 3;
	floor_skip_1 = 0;
	floor_skip_2 = 5;
	floorY = 0;
	floor_move = false;
	for (int i = 0; i < 6; i++)
	{
		seal[i] = new Monster;
		blockMap[i] = new BlockManager;
		blockMap[i]->Init(i, seal[i]);
	}
	cha = new Character;
	cha2 = new Character;
	cha->Init(5, 18, 1, PLAYER1);
	cha2->Init(28, 18, 1, PLAYER2);
}

void MapManager::Update()
{
	//!
	if (playdata.winner == 0) {
		if (cha->getDead())
		{
			playdata.winner = PLAYER2;
		}
		else if (cha2->getDead())
		{
			playdata.winner = PLAYER1;
		}
	}
	if (floor_move)
	{

	}
	else {
		for (int i = 0; i < 6; i++)
		{
			seal[i]->Update();
			blockMap[i]->Update();
		}
		cha->Update();
		cha2->Update();
	}
}

void MapManager::Draw()
{
	//!
	if (floor_move)
	{
		for (int i = 0; i < 6; i++)
		{
			seal[i]->Floor(floorY);
			blockMap[i]->Floor(floorY);
		}
		cha->Floor(floorY);
		cha2->Floor(floorY);
		floorY += 4;
		if (floorY > 204)
		{
			floorY = 0;
			floor_move = false;
		}
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			seal[i]->Draw();
			blockMap[i]->Draw();
		}
		cha->Draw();
		cha2->Draw();
	}
}

void MapManager::Collision()
{
	if (!floor_move)
	{
		//ĳ���Ͱ� �浹
		Col ch_temp = cha->getCol_temp();
		Col ch = cha->getCol();
		Col ch_temp2 = cha2->getCol_temp();
		Col ch2 = cha2->getCol();

		//1p
		// ����������
		if (!cha->getJump_state())
		{
			int check = cha->Collision_V(ch2.chx, ch2.chX, ch2.chy, ch2.chY);
			if (check == UP || check == 6)		// 2p�� ���κп� �浹
			{
				cha->setFloor_collision_temp(true);
				cha->setExtra_fall_y(abs(ch2.chy - ch.chY));
			}
		}
		else// ���� ��									
		{
			if (cha->Collision_V(ch2.chx, ch2.chX, ch2.chy, ch2.chY) == DOWN)		// ������ �Ʒ��κп� �浹
			{
				cha->setJump_collision_temp(true);
				cha->setExtra_jump_y(-abs(ch2.chY - ch.chy));
			}
		}

		// ��� �̵���
		if (cha->getMove_state_r())
		{
			int check = cha->Collision_H(ch2.chx - 14, ch2.chX, ch2.chy, ch2.chY);
			if (check == LEFT || check == 6)		// ������ ���ʺκп� �浹
			{
				cha->setMove_collision_r(true);
			}
		}
		// �·� �̵���
		if (cha->getMove_state_l())
		{
			int check = cha->Collision_H(ch2.chx, ch2.chX + 14, ch2.chy, ch2.chY);
			if (check == RIGHT || check == 6)		// ������ �����ʺκп� �浹
			{
				cha->setMove_collision_l(true);
			}
		}

		//2p
		// ����������
		if (!cha2->getJump_state())
		{
			int check = cha2->Collision_V(ch.chx, ch.chX, ch.chy - 10, ch.chY);
			if (check == UP || check == 6)		// 2p�� ���κп� �浹
			{
				cha2->setFloor_collision_temp(true);
				cha2->setExtra_fall_y(abs(ch.chy - ch2.chY));
			}
		}
		else// ���� ��									
		{
			if (cha2->Collision_V(ch.chx, ch.chX, ch.chy, ch.chY + 10) == DOWN)		// ������ �Ʒ��κп� �浹
			{
				cha2->setJump_collision_temp(true);
				cha2->setExtra_jump_y(-abs(ch.chY - ch2.chy));
			}
		}

		// ��� �̵���
		if (cha2->getMove_state_r())
		{
			int check = cha2->Collision_H(ch.chx - 14, ch.chX, ch.chy, ch.chY);
			if (check == LEFT || check == 6)		// ������ ���ʺκп� �浹
			{
				cha2->setMove_collision_r(true);
			}
		}
		// �·� �̵���
		if (cha2->getMove_state_l())
		{
			int check = cha2->Collision_H(ch.chx, ch.chX + 14, ch.chy, ch.chY);
			if (check == RIGHT || check == 6)		// ������ �����ʺκп� �浹
			{
				cha2->setMove_collision_l(true);
			}
		}
		//ĳ���� ���Ͱ� �浹
		for (int i = 0; i < 6; i++)
		{
			//if (i == floor_skip_1 || i == floor_skip_2)
			//	continue;
			if (seal[i]->getBoom() || !seal[i]->getCreate() || !seal[i]->getOnoff())
				continue;
			if (cha->Collision_mon(seal[i]->getMonx(), seal[i]->getMonX(), seal[i]->getMony(), seal[i]->getMonY()) == 1)
			{
				playdata.winner = PLAYER2;
				break;
			}
			if (cha2->Collision_mon(seal[i]->getMonx(), seal[i]->getMonX(), seal[i]->getMony(), seal[i]->getMonY()) == 1)
			{
				playdata.winner = PLAYER1;
				break;
			}
			if (cha->getAttack_state())
			{
				if (seal[i]->Collision_attacked(cha->getCol().chx, cha->getCol().chX, cha->getCol().chy, cha->getCol().chY, cha->getPos()) == 1)
				{
					playdata.p1_seal_count++;																					// ���� ���� �� ����
					continue;
				}
			}
			if (cha2->getAttack_state())
			{
				if (seal[i]->Collision_attacked(cha2->getCol().chx, cha2->getCol().chX, cha2->getCol().chy, cha2->getCol().chY, cha2->getPos()) == 1)
				{
					playdata.p2_seal_count++;																					// ���� ���� �� ����
					continue;
				}
			}
		}
		//////////////////////////////////////////////////////////////
		// ���� ������Ʈ�� �浹
		for (int i = 0; i < 6; i++)
		{
			//!
			//if (i == floor_skip_1 || i == floor_skip_2)
			//	continue;
			if (i == floor_move_now)
			{
				if (blockMap[i]->Collision3(cha, cha2))
				{
					floor_move = true;							// 3���� �ѹ��̶� �ٴ������ϸ� ���̵� ����
					floor_move_now = (floor_move_now + 1) % 6;
					floor_skip_1 = (floor_skip_1 + 1) % 6;
					floor_skip_2 = (floor_skip_2 + 1) % 6;
				}
			}
			else
				blockMap[i]->Collision(cha, cha2);
			blockMap[i]->Collision_seal(seal[i]);
		}
		if (floor_move)		// ���̵��� �� ��� �ѹ��� �����
		{
			delete seal[(floor_skip_1 + 5) % 6];
			seal[(floor_skip_1 + 5) % 6] = new Monster;
			blockMap[(floor_skip_1 + 5) % 6]->Reset(seal[(floor_skip_1 + 5) % 6]);
		}
		///////////////////////////////////////////////////////////////
	}
}
