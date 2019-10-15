#pragma once
#include"Include.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::Init(int mapchX, int mapchY, double scale, int player)
{
	this->player = player;

	this->scale = scale;
	this->mapchX = mapchX;
	this->mapchY = mapchY;
	//�̵�
	pos = RIGHT;					// ���ϴ� ����
	move_x = 0;
	move_collision_l = false;
	move_collision_r = false;
	move_able_l = true;
	move_able_r = true;
	move_state_l = false;
	move_state_r = false;
	//�ڵ��̵�
	automove_state = false;
	automove_able = true;
	//�߷�
	now_fall_speed = 0;				// ���� �������� �ӵ�
	gravity = 1;					// �߷°��ӵ�
	fall_state = true;				// �߷����� true: ������, false: �ȶ�����
	fall_able = false;
	floor_collision = false;
	floor_collision_temp = false;
	//����
	jump_state = false;
	jump_able = true;
	jump_collision = false;
	jump_collision_temp = false;
	jump_y = 0;
	jump_y_temp = 0;
	jump_speed = 0;
	//����
	col_mon = false;
	dead = false;
	gameover_y = -80;
	//����
	attack_state = false;

	StandCountTime = GetTickCount();

	col.chx = (mapchX * 40) - 14;		// ��
	col.chX = (mapchX * 40) + 14;		// ��
	col.chy = (mapchY * 34) - 80;		// ��
	col.chY = (mapchY * 34);			// ��
	col.chl = col.chx - 4;
	col.chr = col.chX + 4;

	col_temp.chx = col.chx;				// ��
	col_temp.chX = col.chX;				// ��
	col_temp.chy = col.chy;				// ��
	col_temp.chY = col.chY;				// ��
	col_temp.chl = col_temp.chx - 4;
	col_temp.chr = col_temp.chX + 4;

	char FileName[256];

	for (int i = 0; i < 2; i++)
	{
		sprintf_s(FileName, "./resource/Img/char/%dplayer_run%d.png", this->player, i + 1);
		run[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

		sprintf_s(FileName, "./resource/Img/char/%dplayer_stand%d.png", this->player, i + 1);
		stand[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

		sprintf_s(FileName, "./resource/Img/char/%dplayer_jump%d.png", this->player, i + 1);
		jump[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

		sprintf_s(FileName, "./resource/Img/char/%dplayer_attack%d.png", this->player, i + 1);
		attack[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}


	for (int i = 0; i<4; i++)
	{
		sprintf_s(FileName, "./resource/Img/mon/attackEffect%d.png", i + 1);
		cha_dead[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	sprintf_s(FileName, "./resource/Img/char/gameover.png");
	gameover.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

const Col Character::getCol()
{
	Col a = col;
	return a;
}

const Col Character::getCol_temp()
{
	Col a = col_temp;
	return a;
}

int Character::getPos()
{
	return pos;
}

bool Character::getMove_state_l()
{
	return move_state_l;
}

bool Character::getMove_state_r()
{
	return move_state_r;
}

void Character::setMove_collision_l(bool state)
{
	move_collision_l = state;
}

void Character::setMove_collision_r(bool state)
{
	move_collision_r = state;
}

void Character::setMove_x(int move)
{
	move_x += move;
	col.chx += move;
	col.chX += move;
	col_temp.chx += move;
	col_temp.chX += move;

	if ((mapchX * 40) + (move_x) >= 1276)
	{
		move_x = 1 - (mapchX * 40);
		col.chx = 1 - 14;
		col.chX = 1 + 14;
		col_temp.chx = 1 - 14;
		col_temp.chX = 1 + 14;
	}
	else if ((mapchX * 40) + (move_x) <= 4)
	{
		move_x = 1279 - (mapchX * 40);
		col.chx = 1279 - 14;
		col.chX = 1279 + 14;
		col_temp.chx = 1279 - 14;
		col_temp.chX = 1279 + 14;
	}
}

void Character::setAutomove_state(bool state)
{
	automove_state = state;
}

bool Character::getAutomove_state()
{
	return automove_state;
}

void Character::setAutomove_able(bool state)
{
	automove_able = state;
}

bool Character::getAutomove_able()
{
	return automove_able;
}

void Character::setFloor_collision(bool state)
{
	floor_collision = state;
}

bool Character::getFloor_collision()
{
	return floor_collision;
}

void Character::setFloor_collision_temp(bool state)
{
	floor_collision_temp = state;
}

bool Character::getFloor_collision_temp()
{
	return floor_collision_temp;
}

bool Character::getFall_state()
{
	return fall_state;
}

void Character::setFall_state(bool state)
{
	fall_state = state;
}

bool Character::getFall_able()
{
	return fall_able;
}

void Character::setFall_able(bool state)
{
	fall_able = state;
}

void Character::setJump_collision(bool state)
{
	jump_collision = state;
}

bool Character::getJump_collision()
{
	return jump_collision;
}

void Character::setJump_collision_temp(bool state)
{
	jump_collision_temp = state;
}

bool Character::getJump_state()
{
	return jump_state;
}

bool Character::getJump_able()
{
	return jump_able;
}

void Character::setExtra_fall_y(int a)
{
	extra_fall_Y = a;
}

void Character::setExtra_jump_y(int a)
{
	extra_jump_y = a;
}

bool Character::getAttack_state()
{
	return attack_state;
}

bool Character::getDead()
{
	return dead;
}

int Character::Collision_V(int chx, int chX, int chy, int chY)
{
	if (col_temp.chX < chx && ((col_temp.chy > chy && col_temp.chy < chY) || (col_temp.chY > chy && col_temp.chY < chY)))			// ���� ���� ������ ���
	{
		col_v_Left = true;

		col_v_Right = false;
		col_v_Up = false;
		col_v_Down = false;
		return 7;
	}
	else if (col_temp.chx > chX && ((col_temp.chy > chy && col_temp.chy < chY) || (col_temp.chY > chy && col_temp.chY < chY)))	// ���� ������ ������ ���
	{
		col_v_Right = true;

		col_v_Left = false;
		col_v_Up = false;
		col_v_Down = false;
		return 7;
	}
	else if (col_temp.chY < chy && ((col_temp.chx > chx && col_temp.chx < chX) || (col_temp.chX > chx && col_temp.chX < chX)))	// ���� �� ������ ���
	{
		col_v_Up = true;

		col_v_Right = false;
		col_v_Left = false;
		col_v_Down = false;
		return 7;
	}
	else if (col_temp.chy > chY && ((col_temp.chx > chx && col_temp.chx < chX) || (col_temp.chX > chx && col_temp.chX < chX)))	// ���� �Ʒ� ������ ���
	{
		col_v_Down = true;

		col_v_Right = false;
		col_v_Left = false;
		col_v_Up = false;
		return 7;
	}
	else if (((col_temp.chx >= chx && col_temp.chx <= chX) || (col_temp.chX >= chx && col_temp.chX <= chX)) &&					// ���� �浹�Ѱ��
		((col_temp.chy >= chy && col_temp.chy <= chY) || (col_temp.chY >= chy && col_temp.chY <= chY)))
	{
		if (col_v_Up)
		{
			col_v_Up = false;
			return UP;
		}
		else if (col_v_Down)
		{
			col_v_Down = false;
			return DOWN;
		}
		else if (col_v_Left)
		{
			col_v_Left = false;
			return LEFT;
		}
		else if (col_v_Right)
		{
			col_v_Right = false;
			return RIGHT;
		}
		else
			return 6;																				// ���۽��� �浹�϶�
	}
	else																							// �ƹ��͵��ƴҶ�
	{
		col_v_Down = false;
		col_v_Right = false;
		col_v_Left = false;
		col_v_Up = false;
		return 8;
	}																							// off �ų� �浹�ƴϸ� 5 ����
}

int Character::Collision_H(int chx, int chX, int chy, int chY)
{
	col.chy++;
	col.chY--;
	if (col.chX < chx && ((col.chy > chy && col.chy < chY) || (col.chY > chy && col.chY < chY)))			// ���� ���� ������ ���
	{
		col_h_Left = true;

		col_h_Right = false;
		col_h_Up = false;
		col_h_Down = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (col.chx > chX && ((col.chy > chy && col.chy < chY) || (col.chY > chy && col.chY < chY)))	// ���� ������ ������ ���
	{
		col_h_Right = true;

		col_h_Left = false;
		col_h_Up = false;
		col_h_Down = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (col.chY < chy && ((col.chx > chx && col.chx < chX) || (col.chX > chx && col.chX < chX)))	// ���� �� ������ ���
	{
		col_h_Up = true;

		col_h_Right = false;
		col_h_Left = false;
		col_h_Down = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (col.chy > chY && ((col.chx > chx && col.chx < chX) || (col.chX > chx && col.chX < chX)))	// ���� �Ʒ� ������ ���
	{
		col_h_Down = true;

		col_h_Right = false;
		col_h_Left = false;
		col_h_Up = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (((col.chx >= chx && col.chx <= chX) || (col.chX >= chx && col.chX <= chX)) &&					// ���� �浹�Ѱ��
		((col.chy >= chy && col.chy <= chY) || (col.chY >= chy && col.chY <= chY)))
	{
		if (col_h_Up)
		{
			col.chy--;
			col.chY++;
			col_h_Up = false;
			return UP;
		}
		else if (col_h_Down)
		{
			col.chy--;
			col.chY++;
			col_h_Down = false;
			return DOWN;
		}
		else if (col_h_Left)
		{
			col.chy--;
			col.chY++;
			col_h_Left = false;
			return LEFT;
		}
		else if (col_h_Right)
		{
			col.chy--;
			col.chY++;
			col_h_Right = false;
			return RIGHT;
		}
		else
		{
			col.chy--;
			col.chY++;
			return 6;																				// ���۽��� �浹�϶�
		}
	}
	else																							// �ƹ��͵��ƴҶ�
	{
		col_h_Down = false;
		col_h_Right = false;
		col_h_Left = false;
		col_h_Up = false;

		col.chy--;
		col.chY++;
		return 8;
	}																						// off �ų� �浹�ƴϸ� 5 ����
}

int Character::Collision_mon(int monx, int monX, int mony, int monY)
{
	if ((mapchX * 40) + (move_x) < 220 || (mapchX * 40) + (move_x) > 1060)		// ���Ͱ� ������ �浹����
		return 0;
	if (!col_mon)
		if (((col.chx >= monx && col.chx <= monX) || (col.chX >= monx && col.chX <= monX)) &&					// ���Ϳ� �浹�Ѱ��
			((col.chy >= mony && col.chy <= monY) || (col.chY >= mony && col.chY <= monY)))
		{
			sound.m_Death->Play(0, NULL);
			col_mon = true;
			dead = true;
			DeadCountTime = GetTickCount();
			EndCountTime = GetTickCount();
			return 1;
		}
	return 0;
}


void Character::Update()
{
	if (!col_mon && col.chy > 768)
	{
		sound.m_Death->Play(0, NULL);
		col_mon = true;
		dead = true;
		attack_state = false;
		DeadCountTime = GetTickCount();
		EndCountTime = GetTickCount();
	}
	if (col_mon)
	{
		attack_state = false;
		if ((mapchY * 34) - 114 + (move_y)+(jump_y)+(gameover_y) > 60)
			gameover_y -= 2;
		if (GetTickCount() - EndCountTime > 4000)
		{
			sound.m_overbg->Play(0, DSBPLAY_LOOPING);
			sound.m_Bk1->Reset();
			sound.m_Bk1->Stop();
			sound.m_Gamebg->Reset();
			sound.m_Gamebg->Stop();
			g_Mng.n_Chap = OVER;
			g_Mng.chap[g_Mng.n_Chap]->Init();
		}
		// ��������Ʈ
		if (GetTickCount() - DeadCountTime > 200 && dead)
		{
			d_count++;

			if (d_count > 3) {
				d_count = 0;
				dead = false;
			}
			DeadCountTime = GetTickCount();
		}
	}
	else
	{
		// ��������Ʈ
		if (GetTickCount() - StandCountTime > 800)
		{
			s_count++;

			if (s_count > 1) {
				s_count = 0;
			}
			StandCountTime = GetTickCount();
		}
		if (!jump_state)
		{
			if (!floor_collision_temp)		// �ٴ��浹�� �ƴϰ� �ӽ� �ٴ��浹�� �ƴҶ�
			{
				if (now_fall_speed < max_fall_speed)
				{
					now_fall_speed += gravity;
				}
				// ������ ����
				move_y = move_y_temp;
				col.chy = col_temp.chy;
				col.chY = col_temp.chY;
				// �ӽ��̵�
				move_y_temp += now_fall_speed;
				col_temp.chy += now_fall_speed;
				col_temp.chY += now_fall_speed;
				attack_state = false;
				jump_able = false;
			}
			else if (floor_collision_temp)	// �ӽ� �ٴ��浹 ������
			{
				// ���и�ŭ ����
				move_y += extra_fall_Y;
				col.chy += extra_fall_Y;
				col.chY += extra_fall_Y;
				// �ӽ���ġ�� ����
				move_y_temp = move_y;
				col_temp.chy = col.chy;
				col_temp.chY = col.chY;
				//�ʱ�ȭ
				now_fall_speed = 0;
				extra_fall_Y = 0;
				//���º�ȯ
				//fall_state = false;					// �������� �ʴ»���
				//fall_able = true;						// �������� �ִ� ����
				jump_able = true;						// �ϴ� �ѹ� �ٴڿ� �����ϸ� �������� ����
				floor_collision_temp = false;			// �ٴ� �ӽ��浹�� ���� �ٽ� �浹�˻簡 ����
			}
		}
		if (player == PLAYER1)
		{
			if (KeyDown('X') && jump_able)				// �ٴڿ��ִ� ���¿���
			{
				// ��������Ʈ
				if (GetTickCount() - AttackCountTime > 200)
				{
					a_count++;

					if (a_count > 1) {
						a_count = 0;
					}
					AttackCountTime = GetTickCount();
				}
				// ���� ��ȯ
				attack_state = true;
			}
			if (KeyUp('X'))
			{
				// ���� ��ȯ
				attack_state = false;
			}
			if (KeyUp('Z'))
			{
				zkey_check = false;
			}
			if (KeyDown('Z') && jump_able && !zkey_check)		// zŰ �ٿ��� && ������ �����Ҷ� && ������ z Ű�� ������ ������
			{
				sound.m_Jump->Play(0, NULL);
				JumpCountTime = GetTickCount();
				j_count = 0;

				// ���� ��ȯ
				zkey_check = true;								// z Ű�� ���ȴ� ���� �ִ�
				jump_able = false;								// ���̻� ������ �Ұ����ϴ�
				jump_state = true;								// ���� ���·� ��ȯ
				attack_state = false;
				//floor_collision = false;						// �ٴ��浹�� �ƴϴ�
				// �ʱ�ȭ
				jump_speed = -22;
			}
			// ��������Ʈ
			if (GetTickCount() - JumpCountTime > 75 && jump_state)		// �����ð� ������ ��ȭ
			{
				j_count = 1;
			}
			if (KeyUp('H') && !attack_state)						// Ű�� �ö�����
			{
				//���º�ȯ
				move_state_r = false;					// ��� ���� Ű�� �ȴ���
			}
			if (KeyDown('H') && !attack_state)		// Ű�� �������� ������ �� ������
			{
				// ��������Ʈ
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// ���º�ȯ
				move_state_r = true;					// ��� �̵� Ű�� ����
				pos = RIGHT;

				int move = 4;
				if (move_collision_r)
				{
					move = 0;
					move_collision_r = false;
				}
				move_x += move;				// �� �� �̵�
				col.chx += move;
				col.chX += move;
				col_temp.chx += move;
				col_temp.chX += move;

				if ((mapchX * 40) + (move_x) >= 1276)
				{
					move_x = 1 - (mapchX * 40);
					col.chx = 1 - 14;
					col.chX = 1 + 14;
					col_temp.chx = 1 - 14;
					col_temp.chX = 1 + 14;
				}
			}
			if (KeyUp('F') && !attack_state)						// Ű�� �ö�����
			{
				//���º�ȯ
				move_state_l = false;					// ��� ���� Ű�� �ȴ���
			}
			if (KeyDown('F') && !attack_state)
			{
				// ��������Ʈ
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// ���º�ȯ
				move_state_l = true;					// ��� �̵� Ű�� ����
				pos = LEFT;

				int move = -4;
				if (move_collision_l)
				{
					move = 0;
					move_collision_l = false;
				}
				move_x += move;				// �� �� �̵�
				col.chx += move;
				col.chX += move;
				col_temp.chx += move;
				col_temp.chX += move;

				if ((mapchX * 40) + (move_x) <= 4)
				{
					move_x = 1279 - (mapchX * 40);
					col.chx = 1279 - 14;
					col.chX = 1279 + 14;
					col_temp.chx = 1279 - 14;
					col_temp.chX = 1279 + 14;
				}
			}
		}
		else
		{
			if (KeyDown('P') && jump_able)				// �ٴڿ��ִ»��¿���
			{
				// ��������Ʈ
				if (GetTickCount() - AttackCountTime > 200)
				{
					a_count++;

					if (a_count > 1) {
						a_count = 0;
					}
					AttackCountTime = GetTickCount();
				}
				// ���� ��ȯ
				attack_state = true;
			}
			if (KeyUp('P'))
			{
				// ���� ��ȯ
				attack_state = false;
			}
			if (KeyUp('O'))
			{
				zkey_check = false;
			}
			if (KeyDown('O') && jump_able && !zkey_check)		// zŰ �ٿ��� && ������ �����Ҷ� && ������ z Ű�� ������ ������
			{
				sound.m_Jump->Play(0, NULL);
				JumpCountTime = GetTickCount();
				j_count = 0;

				// ���� ��ȯ
				zkey_check = true;								// z Ű�� ���ȴ� ���� �ִ�
				jump_able = false;								// ���̻� ������ �Ұ����ϴ�
				jump_state = true;								// ���� ���·� ��ȯ
																//floor_collision = false;						// �ٴ��浹�� �ƴϴ�
																// �ʱ�ȭ
				jump_speed = -22;
			}
			// ��������Ʈ
			if (GetTickCount() - JumpCountTime > 75 && jump_state)		// �����ð� ������ ��ȭ
			{
				j_count = 1;
			}
			if (KeyUp(VK_RIGHT) && !attack_state)						// Ű�� �ö�����
			{
				//���º�ȯ
				move_state_r = false;					// ��� ���� Ű�� �ȴ���
			}
			if (KeyDown(VK_RIGHT) && !attack_state)		// Ű�� �������� ������ �� ������
			{
				// ��������Ʈ
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// ���º�ȯ
				move_state_r = true;					// ��� �̵� Ű�� ����
				pos = RIGHT;

				int move = 4;
				if (move_collision_r)
				{
					move = 0;
					move_collision_r = false;
				}
				move_x += move;				// �� �� �̵�
				col.chx += move;
				col.chX += move;
				col_temp.chx += move;
				col_temp.chX += move;

				if ((mapchX * 40) + (move_x) >= 1276)
				{
					move_x = 1 - (mapchX * 40);
					col.chx = 1 - 14;
					col.chX = 1 + 14;
					col_temp.chx = 1 - 14;
					col_temp.chX = 1 + 14;
				}
			}
			if (KeyUp(VK_LEFT) && !attack_state)						// Ű�� �ö�����
			{
				//���º�ȯ
				move_state_l = false;					// ��� ���� Ű�� �ȴ���
			}
			if (KeyDown(VK_LEFT) && !attack_state)
			{
				// ��������Ʈ
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// ���º�ȯ
				move_state_l = true;					// ��� �̵� Ű�� ����
				pos = LEFT;

				int move = -4;
				if (move_collision_l)
				{
					move = 0;
					move_collision_l = false;
				}
				move_x += move;				// �� �� �̵�
				col.chx += move;
				col.chX += move;
				col_temp.chx += move;
				col_temp.chX += move;

				if ((mapchX * 40) + (move_x) <= 4)
				{
					move_x = 1279 - (mapchX * 40);
					col.chx = 1279 - 14;
					col.chX = 1279 + 14;
					col_temp.chx = 1279 - 14;
					col_temp.chX = 1279 + 14;
				}
			}
		}

		if (jump_collision_temp)						// �Ӹ������� 
		{
			// ���� ��ȯ
			jump_state = false;							// �������� ���·� ��ȯ
			jump_collision_temp = false;				// �ӽô� ����
														// ������ ����
														//move_y += extra_jump_y;
														//col.chy += extra_jump_y;
														//col.chY += extra_jump_y;
														// �ӽ���ġ ����
			move_y_temp = move_y;
			col_temp.chy = col.chy;
			col_temp.chY = col.chY;
			//�ʱ�ȭ
			extra_jump_y = 0;
			//now_fall_speed = -jump_speed/2;
			jump_speed = 0;
			//jump_collision = true;						// �����浹�� �ߴ����·�
		}
		else if (jump_state)							// �Ӹ��ȸ°� �������϶�
		{
			jump_speed += gravity;
			// ������ ����
			move_y = move_y_temp;
			col.chy = col_temp.chy;
			col.chY = col_temp.chY;
			// �ӽ÷� �̵�
			move_y_temp += jump_speed;
			col_temp.chy += jump_speed;
			col_temp.chY += jump_speed;

			if (jump_speed >= 0)						// ������ �ִ��ϰ��
			{
				jump_collision_temp = true;				// �Ӹ����������� ����
			}
		}

		if (automove_state)			// �ڵ��̵�
		{
			automove_state = false;
			move_x -= 2;
			col.chx -= 2;
			col.chX -= 2;
			col_temp.chx -= 2;
			col_temp.chX -= 2;

			if ((mapchX * 40) + (move_x) >= 1276)
			{
				move_x = 1 - (mapchX * 40);
				col.chx = 1 - 14;
				col.chX = 1 + 14;
				col_temp.chx = 1 - 14;
				col_temp.chX = 1 + 14;
			}
			else if ((mapchX * 40) + (move_x) <= 4)
			{
				move_x = 1279 - (mapchX * 40);
				col.chx = 1279 - 14;
				col.chX = 1279 + 14;
				col_temp.chx = 1279 - 14;
				col_temp.chX = 1279 + 14;
			}
		}
	}
}

void Character::Draw()
{
	if (Gmanager.m_GameStart == true)
	{
		if (dead)
		{
			cha_dead[d_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, 1.2, 1.2);
			gameover.Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(gameover_y), 0, 1, 1);
		}
		else if (col_mon)
		{
			gameover.Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(gameover_y), 0, 1, 1);
		}
		else if (!col_mon)
		{
			if (pos == RIGHT)
			{
				if (attack_state)
					attack[a_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, -scale, scale);
				else if (jump_state)
					jump[j_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, -scale, scale);
				else if (!jump_able)
					jump[j_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, -scale, scale);
				else if (move_state_r)
					run[r_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, -scale, scale);
				else
					stand[s_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, -scale, scale);

			}
			else if (pos == LEFT)
			{
				if (attack_state)
					attack[a_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, scale, scale);
				else if (jump_state)
					jump[j_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, scale, scale);
				else if (!jump_able)
					jump[j_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, scale, scale);
				else if (move_state_l)
					run[r_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, scale, scale);
				else
					stand[s_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y), 0, scale, scale);
			}
		}
	}
}
//!
void Character::Floor(int floorY)
{

	if (Gmanager.m_GameStart == true)
	{
		if (dead)
		{
			cha_dead[d_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, 1.2, 1.2);
			gameover.Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(gameover_y)+(floorY), 0, 1, 1);
		}
		else if (col_mon)
		{
			gameover.Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(gameover_y)+(floorY), 0, 1, 1);
		}
		else if (!col_mon)
		{
			if (pos == RIGHT)
			{
				if (attack_state)
					attack[a_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, -scale, scale);
				else if (jump_state)
					jump[j_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, -scale, scale);
				else if (!jump_able)
					jump[j_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, -scale, scale);
				else if (move_state_r)
					run[r_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, -scale, scale);
				else
					stand[s_count].Render((mapchX * 40) + 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, -scale, scale);

			}
			else if (pos == LEFT)
			{
				if (attack_state)
					attack[a_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, scale, scale);
				else if (jump_state)
					jump[j_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, scale, scale);
				else if (!jump_able)
					jump[j_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, scale, scale);
				else if (move_state_l)
					run[r_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, scale, scale);
				else
					stand[s_count].Render((mapchX * 40) - 59 + (move_x), (mapchY * 34) - 114 + (move_y)+(jump_y)+(floorY), 0, scale, scale);
			}
		}
		if (floorY >= 204)
		{
			mapchY += 6;

			col.chy += (6 * 34);		// ��
			col.chY += (6 * 34);			// ��

			col_temp.chy += (6 * 34);				// ��
			col_temp.chY += (6 * 34);			// ��
		}
	}
}


int Character::getPlayer()
{
	return player;
}
