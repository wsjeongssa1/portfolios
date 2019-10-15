#pragma once

struct Col
{
	int					chx, chy, chX, chY;			// 충돌범위 chx:좌, chX:우, chy:상 , chY:하
	int					chl, chr;
};

class Character
{
private:

	int						player;					// 1p, 2p

	int						mapchX, mapchY;			// 캐릭터의 맵 초기위치
	Col						col;					// 충돌범위
	Col						col_temp;				// 임시 충돌 범위
	double					scale;					// 텍스처 크기
													// 이동
	int						pos;					// 향하는 방향
	int						move_x;					// 좌 우 이동
	bool					move_collision_l;		// 이동 충돌 좌 true: 충돌, false: 비충돌
	bool					move_collision_r;		// 이동 충돌 우 true: 충돌, false: 비충돌
	bool					move_able_l;			// 이동 가능 좌 true: 가능, false: 불가능
	bool					move_able_r;			// 이동 가능 우 true: 가능, false: 불가능
	bool					move_state_l;			// 이동 상태 좌	true: 가능, false: 불가능
	bool					move_state_r;			// 이동 상태 좌	true: 가능, false: 불가능
													// 자동이동
	bool					automove_state;			// 자동이동중 true: 이동중, false: 이동아님
	bool					automove_able;			// 자동이동가능 true: 가능, false: 불가능
													// 중력
	int						extra_fall_Y;			// 여분의 떨어진 정도
	int						move_y;					// 처음위치에서 떨어진 정도
	int						move_y_temp;			// 임시 떨어진 정도
	int						now_fall_speed;			// 현재 떨어지는 속도
	const int				max_fall_speed = 14;	// 최대 떨어지는 속도
	int						gravity;				// 중력가속도
	bool					fall_state;				// 떨어지는 상태 true: 떨어짐, false: 안떨어짐
	bool					fall_able;				// 떨어짐 가능한 상태 true: 가능, false: 불가능
	bool					floor_collision;		// 바닥 충돌 true: 충돌, false: 비충돌
	bool					floor_collision_temp;	// 바닥 충돌 임시 true: 충돌, false: 비충돌
													// 점프
	int						extra_jump_y;			// 여분의 쩜프뛴 정도
	bool					jump_state;				// 점프 상태 true: 점프중, false: 점프아님
	bool					jump_able;				// 점프 가능 상태 true: 가능, false: 불가능
	bool					jump_collision;			// 점프 충돌 true: 충돌, false: 비충돌
	bool					jump_collision_temp;	// 점프 충돌 임시 true: 충돌, false: 비충돌
	int						jump_y;					// 처음위치에서 점프 정도
	int						jump_y_temp;			// 임시 점프 정도
	int						jump_speed;				// 점프 속도
	bool					zkey_check;				// z 키가 연속으로 눌리는거 방지 true: 눌림, false: 안눌림
													// 캐릭터간 충돌
	bool					col_v_Up, col_v_Down, col_v_Left, col_v_Right;				// 수직이동 충돌방향
	bool					col_h_Up, col_h_Down, col_h_Left, col_h_Right;				// 수평이동 충돌방향
																						// 몬스터 충돌
	bool					col_mon;				// 몬스터
	bool					dead;					// 죽음
	int						gameover_y;				// 게임오버 이동량
													// 공격
	bool					attack_state;			// 공격상태

public:
	Character();
	~Character();

	Sprite stand[2], run[2], jump[2], attack[2], cha_dead[4], gameover;
	DWORD EndCountTime, DeadCountTime, RunCountTime, StandCountTime, JumpCountTime, AttackCountTime;
	int d_count, r_count, s_count, j_count, a_count;

	void Init(int mapchX, int mapchY, double scale, int player);
	void Update();
	void Draw();

	int getPlayer();

	const Col getCol();
	const Col getCol_temp();
	int getPos();

	bool getMove_state_l();
	bool getMove_state_r();
	void setMove_collision_l(bool state);
	void setMove_collision_r(bool state);
	void setMove_x(int a);

	void setAutomove_state(bool state);
	bool getAutomove_state();
	void setAutomove_able(bool state);
	bool getAutomove_able();

	void setFloor_collision(bool state);
	bool getFloor_collision();
	void setFloor_collision_temp(bool state);
	bool getFloor_collision_temp();
	bool getFall_state();
	void setFall_state(bool state);
	bool getFall_able();
	void setFall_able(bool state);
	void setExtra_fall_y(int a);

	void setJump_collision(bool state);
	bool getJump_collision();
	void setJump_collision_temp(bool state);
	bool getJump_state();
	bool getJump_able();
	void setExtra_jump_y(int a);

	bool getAttack_state();
	bool getDead();

	int Collision_V(int chx, int chX, int chy, int chY);
	int Collision_H(int chx, int chX, int chy, int chY);

	int Collision_mon(int monx, int monX, int mony, int monY);


	//!
	void Floor(int floorY);
};


