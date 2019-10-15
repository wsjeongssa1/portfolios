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
	//이동
	pos = RIGHT;					// 향하는 방향
	move_x = 0;
	move_collision_l = false;
	move_collision_r = false;
	move_able_l = true;
	move_able_r = true;
	move_state_l = false;
	move_state_r = false;
	//자동이동
	automove_state = false;
	automove_able = true;
	//중력
	now_fall_speed = 0;				// 현재 떨어지는 속도
	gravity = 1;					// 중력가속도
	fall_state = true;				// 중력제어 true: 떨어짐, false: 안떨어짐
	fall_able = false;
	floor_collision = false;
	floor_collision_temp = false;
	//점프
	jump_state = false;
	jump_able = true;
	jump_collision = false;
	jump_collision_temp = false;
	jump_y = 0;
	jump_y_temp = 0;
	jump_speed = 0;
	//몬스터
	col_mon = false;
	dead = false;
	gameover_y = -80;
	//공격
	attack_state = false;

	StandCountTime = GetTickCount();

	col.chx = (mapchX * 40) - 14;		// 좌
	col.chX = (mapchX * 40) + 14;		// 우
	col.chy = (mapchY * 34) - 80;		// 상
	col.chY = (mapchY * 34);			// 하
	col.chl = col.chx - 4;
	col.chr = col.chX + 4;

	col_temp.chx = col.chx;				// 좌
	col_temp.chX = col.chX;				// 우
	col_temp.chy = col.chy;				// 상
	col_temp.chY = col.chY;				// 하
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
	if (col_temp.chX < chx && ((col_temp.chy > chy && col_temp.chy < chY) || (col_temp.chY > chy && col_temp.chY < chY)))			// 블럭의 왼쪽 방향인 경우
	{
		col_v_Left = true;

		col_v_Right = false;
		col_v_Up = false;
		col_v_Down = false;
		return 7;
	}
	else if (col_temp.chx > chX && ((col_temp.chy > chy && col_temp.chy < chY) || (col_temp.chY > chy && col_temp.chY < chY)))	// 블럭의 오른쪽 방향인 경우
	{
		col_v_Right = true;

		col_v_Left = false;
		col_v_Up = false;
		col_v_Down = false;
		return 7;
	}
	else if (col_temp.chY < chy && ((col_temp.chx > chx && col_temp.chx < chX) || (col_temp.chX > chx && col_temp.chX < chX)))	// 블럭의 위 방향인 경우
	{
		col_v_Up = true;

		col_v_Right = false;
		col_v_Left = false;
		col_v_Down = false;
		return 7;
	}
	else if (col_temp.chy > chY && ((col_temp.chx > chx && col_temp.chx < chX) || (col_temp.chX > chx && col_temp.chX < chX)))	// 블럭의 아래 방향인 경우
	{
		col_v_Down = true;

		col_v_Right = false;
		col_v_Left = false;
		col_v_Up = false;
		return 7;
	}
	else if (((col_temp.chx >= chx && col_temp.chx <= chX) || (col_temp.chX >= chx && col_temp.chX <= chX)) &&					// 블럭과 충돌한경우
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
			return 6;																				// 갑작스런 충돌일때
	}
	else																							// 아무것도아닐때
	{
		col_v_Down = false;
		col_v_Right = false;
		col_v_Left = false;
		col_v_Up = false;
		return 8;
	}																							// off 거나 충돌아니면 5 리턴
}

int Character::Collision_H(int chx, int chX, int chy, int chY)
{
	col.chy++;
	col.chY--;
	if (col.chX < chx && ((col.chy > chy && col.chy < chY) || (col.chY > chy && col.chY < chY)))			// 블럭의 왼쪽 방향인 경우
	{
		col_h_Left = true;

		col_h_Right = false;
		col_h_Up = false;
		col_h_Down = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (col.chx > chX && ((col.chy > chy && col.chy < chY) || (col.chY > chy && col.chY < chY)))	// 블럭의 오른쪽 방향인 경우
	{
		col_h_Right = true;

		col_h_Left = false;
		col_h_Up = false;
		col_h_Down = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (col.chY < chy && ((col.chx > chx && col.chx < chX) || (col.chX > chx && col.chX < chX)))	// 블럭의 위 방향인 경우
	{
		col_h_Up = true;

		col_h_Right = false;
		col_h_Left = false;
		col_h_Down = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (col.chy > chY && ((col.chx > chx && col.chx < chX) || (col.chX > chx && col.chX < chX)))	// 블럭의 아래 방향인 경우
	{
		col_h_Down = true;

		col_h_Right = false;
		col_h_Left = false;
		col_h_Up = false;
		col.chy--;
		col.chY++;
		return 7;
	}
	else if (((col.chx >= chx && col.chx <= chX) || (col.chX >= chx && col.chX <= chX)) &&					// 블럭과 충돌한경우
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
			return 6;																				// 갑작스런 충돌일때
		}
	}
	else																							// 아무것도아닐때
	{
		col_h_Down = false;
		col_h_Right = false;
		col_h_Left = false;
		col_h_Up = false;

		col.chy--;
		col.chY++;
		return 8;
	}																						// off 거나 충돌아니면 5 리턴
}

int Character::Collision_mon(int monx, int monX, int mony, int monY)
{
	if ((mapchX * 40) + (move_x) < 220 || (mapchX * 40) + (move_x) > 1060)		// 몬스터가 숨으면 충돌안함
		return 0;
	if (!col_mon)
		if (((col.chx >= monx && col.chx <= monX) || (col.chX >= monx && col.chX <= monX)) &&					// 몬스터와 충돌한경우
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
		// 스프라이트
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
		// 스프라이트
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
			if (!floor_collision_temp)		// 바닥충돌도 아니고 임시 바닥충돌도 아닐때
			{
				if (now_fall_speed < max_fall_speed)
				{
					now_fall_speed += gravity;
				}
				// 이전거 저장
				move_y = move_y_temp;
				col.chy = col_temp.chy;
				col.chY = col_temp.chY;
				// 임시이동
				move_y_temp += now_fall_speed;
				col_temp.chy += now_fall_speed;
				col_temp.chY += now_fall_speed;
				attack_state = false;
				jump_able = false;
			}
			else if (floor_collision_temp)	// 임시 바닥충돌 했을때
			{
				// 여분만큼 적용
				move_y += extra_fall_Y;
				col.chy += extra_fall_Y;
				col.chY += extra_fall_Y;
				// 임시위치도 적용
				move_y_temp = move_y;
				col_temp.chy = col.chy;
				col_temp.chY = col.chY;
				//초기화
				now_fall_speed = 0;
				extra_fall_Y = 0;
				//상태변환
				//fall_state = false;					// 떨어지지 않는상태
				//fall_able = true;						// 떨어질수 있는 상태
				jump_able = true;						// 일단 한번 바닥에 착지하면 점프가능 상태
				floor_collision_temp = false;			// 바닥 임시충돌을 끄면 다시 충돌검사가 가능
			}
		}
		if (player == PLAYER1)
		{
			if (KeyDown('X') && jump_able)				// 바닥에있는 상태에서
			{
				// 스프라이트
				if (GetTickCount() - AttackCountTime > 200)
				{
					a_count++;

					if (a_count > 1) {
						a_count = 0;
					}
					AttackCountTime = GetTickCount();
				}
				// 상태 전환
				attack_state = true;
			}
			if (KeyUp('X'))
			{
				// 상태 전환
				attack_state = false;
			}
			if (KeyUp('Z'))
			{
				zkey_check = false;
			}
			if (KeyDown('Z') && jump_able && !zkey_check)		// z키 다운중 && 점프가 가능할때 && 이전에 z 키가 눌린적 없으면
			{
				sound.m_Jump->Play(0, NULL);
				JumpCountTime = GetTickCount();
				j_count = 0;

				// 상태 전환
				zkey_check = true;								// z 키가 눌렸던 적이 있다
				jump_able = false;								// 더이상 점프는 불가능하다
				jump_state = true;								// 점프 상태로 전환
				attack_state = false;
				//floor_collision = false;						// 바닥충돌도 아니다
				// 초기화
				jump_speed = -22;
			}
			// 스프라이트
			if (GetTickCount() - JumpCountTime > 75 && jump_state)		// 일정시간 지나면 변화
			{
				j_count = 1;
			}
			if (KeyUp('H') && !attack_state)						// 키가 올라갔을때
			{
				//상태변환
				move_state_r = false;					// 우로 이통 키가 안눌림
			}
			if (KeyDown('H') && !attack_state)		// 키가 눌러지고 움직일 수 있을때
			{
				// 스프라이트
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// 상태변환
				move_state_r = true;					// 우로 이동 키가 눌림
				pos = RIGHT;

				int move = 4;
				if (move_collision_r)
				{
					move = 0;
					move_collision_r = false;
				}
				move_x += move;				// 좌 우 이동
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
			if (KeyUp('F') && !attack_state)						// 키가 올라갔을때
			{
				//상태변환
				move_state_l = false;					// 우로 이통 키가 안눌림
			}
			if (KeyDown('F') && !attack_state)
			{
				// 스프라이트
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// 상태변환
				move_state_l = true;					// 우로 이동 키가 눌림
				pos = LEFT;

				int move = -4;
				if (move_collision_l)
				{
					move = 0;
					move_collision_l = false;
				}
				move_x += move;				// 좌 우 이동
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
			if (KeyDown('P') && jump_able)				// 바닥에있는상태에서
			{
				// 스프라이트
				if (GetTickCount() - AttackCountTime > 200)
				{
					a_count++;

					if (a_count > 1) {
						a_count = 0;
					}
					AttackCountTime = GetTickCount();
				}
				// 상태 전환
				attack_state = true;
			}
			if (KeyUp('P'))
			{
				// 상태 전환
				attack_state = false;
			}
			if (KeyUp('O'))
			{
				zkey_check = false;
			}
			if (KeyDown('O') && jump_able && !zkey_check)		// z키 다운중 && 점프가 가능할때 && 이전에 z 키가 눌린적 없으면
			{
				sound.m_Jump->Play(0, NULL);
				JumpCountTime = GetTickCount();
				j_count = 0;

				// 상태 전환
				zkey_check = true;								// z 키가 눌렸던 적이 있다
				jump_able = false;								// 더이상 점프는 불가능하다
				jump_state = true;								// 점프 상태로 전환
																//floor_collision = false;						// 바닥충돌도 아니다
																// 초기화
				jump_speed = -22;
			}
			// 스프라이트
			if (GetTickCount() - JumpCountTime > 75 && jump_state)		// 일정시간 지나면 변화
			{
				j_count = 1;
			}
			if (KeyUp(VK_RIGHT) && !attack_state)						// 키가 올라갔을때
			{
				//상태변환
				move_state_r = false;					// 우로 이통 키가 안눌림
			}
			if (KeyDown(VK_RIGHT) && !attack_state)		// 키가 눌러지고 움직일 수 있을때
			{
				// 스프라이트
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// 상태변환
				move_state_r = true;					// 우로 이동 키가 눌림
				pos = RIGHT;

				int move = 4;
				if (move_collision_r)
				{
					move = 0;
					move_collision_r = false;
				}
				move_x += move;				// 좌 우 이동
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
			if (KeyUp(VK_LEFT) && !attack_state)						// 키가 올라갔을때
			{
				//상태변환
				move_state_l = false;					// 우로 이통 키가 안눌림
			}
			if (KeyDown(VK_LEFT) && !attack_state)
			{
				// 스프라이트
				if (GetTickCount() - RunCountTime > 100)
				{
					r_count++;

					if (r_count > 1) {
						r_count = 0;
					}
					RunCountTime = GetTickCount();
				}
				// 상태변환
				move_state_l = true;					// 우로 이동 키가 눌림
				pos = LEFT;

				int move = -4;
				if (move_collision_l)
				{
					move = 0;
					move_collision_l = false;
				}
				move_x += move;				// 좌 우 이동
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

		if (jump_collision_temp)						// 머리맞으면 
		{
			// 상태 전환
			jump_state = false;							// 떨어지는 상태로 전환
			jump_collision_temp = false;				// 임시는 꺼둠
														// 남은양 적용
														//move_y += extra_jump_y;
														//col.chy += extra_jump_y;
														//col.chY += extra_jump_y;
														// 임시위치 적용
			move_y_temp = move_y;
			col_temp.chy = col.chy;
			col_temp.chY = col.chY;
			//초기화
			extra_jump_y = 0;
			//now_fall_speed = -jump_speed/2;
			jump_speed = 0;
			//jump_collision = true;						// 점프충돌은 했던상태로
		}
		else if (jump_state)							// 머리안맞고 점프중일때
		{
			jump_speed += gravity;
			// 이전거 저장
			move_y = move_y_temp;
			col.chy = col_temp.chy;
			col.chY = col_temp.chY;
			// 임시로 이동
			move_y_temp += jump_speed;
			col_temp.chy += jump_speed;
			col_temp.chY += jump_speed;

			if (jump_speed >= 0)						// 점프가 최대일경우
			{
				jump_collision_temp = true;				// 머리맞은것으로 판정
			}
		}

		if (automove_state)			// 자동이동
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

			col.chy += (6 * 34);		// 상
			col.chY += (6 * 34);			// 하

			col_temp.chy += (6 * 34);				// 상
			col_temp.chY += (6 * 34);			// 하
		}
	}
}


int Character::getPlayer()
{
	return player;
}
