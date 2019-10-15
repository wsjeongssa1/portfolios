#pragma once

struct Col
{
	int					chx, chy, chX, chY;			// �浹���� chx:��, chX:��, chy:�� , chY:��
	int					chl, chr;
};

class Character
{
private:

	int						player;					// 1p, 2p

	int						mapchX, mapchY;			// ĳ������ �� �ʱ���ġ
	Col						col;					// �浹����
	Col						col_temp;				// �ӽ� �浹 ����
	double					scale;					// �ؽ�ó ũ��
													// �̵�
	int						pos;					// ���ϴ� ����
	int						move_x;					// �� �� �̵�
	bool					move_collision_l;		// �̵� �浹 �� true: �浹, false: ���浹
	bool					move_collision_r;		// �̵� �浹 �� true: �浹, false: ���浹
	bool					move_able_l;			// �̵� ���� �� true: ����, false: �Ұ���
	bool					move_able_r;			// �̵� ���� �� true: ����, false: �Ұ���
	bool					move_state_l;			// �̵� ���� ��	true: ����, false: �Ұ���
	bool					move_state_r;			// �̵� ���� ��	true: ����, false: �Ұ���
													// �ڵ��̵�
	bool					automove_state;			// �ڵ��̵��� true: �̵���, false: �̵��ƴ�
	bool					automove_able;			// �ڵ��̵����� true: ����, false: �Ұ���
													// �߷�
	int						extra_fall_Y;			// ������ ������ ����
	int						move_y;					// ó����ġ���� ������ ����
	int						move_y_temp;			// �ӽ� ������ ����
	int						now_fall_speed;			// ���� �������� �ӵ�
	const int				max_fall_speed = 14;	// �ִ� �������� �ӵ�
	int						gravity;				// �߷°��ӵ�
	bool					fall_state;				// �������� ���� true: ������, false: �ȶ�����
	bool					fall_able;				// ������ ������ ���� true: ����, false: �Ұ���
	bool					floor_collision;		// �ٴ� �浹 true: �浹, false: ���浹
	bool					floor_collision_temp;	// �ٴ� �浹 �ӽ� true: �浹, false: ���浹
													// ����
	int						extra_jump_y;			// ������ ������ ����
	bool					jump_state;				// ���� ���� true: ������, false: �����ƴ�
	bool					jump_able;				// ���� ���� ���� true: ����, false: �Ұ���
	bool					jump_collision;			// ���� �浹 true: �浹, false: ���浹
	bool					jump_collision_temp;	// ���� �浹 �ӽ� true: �浹, false: ���浹
	int						jump_y;					// ó����ġ���� ���� ����
	int						jump_y_temp;			// �ӽ� ���� ����
	int						jump_speed;				// ���� �ӵ�
	bool					zkey_check;				// z Ű�� �������� �����°� ���� true: ����, false: �ȴ���
													// ĳ���Ͱ� �浹
	bool					col_v_Up, col_v_Down, col_v_Left, col_v_Right;				// �����̵� �浹����
	bool					col_h_Up, col_h_Down, col_h_Left, col_h_Right;				// �����̵� �浹����
																						// ���� �浹
	bool					col_mon;				// ����
	bool					dead;					// ����
	int						gameover_y;				// ���ӿ��� �̵���
													// ����
	bool					attack_state;			// ���ݻ���

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


