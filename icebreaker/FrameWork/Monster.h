#pragma once
//#include "Include.h"

class Monster
{
	int						monKind;			// �ش� �ڽ� ��ü�� ����
	int						mapX;				// ���� x��ǥ
	int						mapY;				// ���� y��ǥ
	double					scale;


	int						pos;				// ���ϴ� ����
	int						move_x;				// �� �� �̵�
	bool					create;
	bool					onoff;				// �׾��� ��Ҵ�
	bool					boom;				// ����

	int						monx, mony, monX, monY;		// �浹���� blockx:��, blockX:��, blocky:�� , blockY:��


														//������ȯ
	bool					col_fornt_turn, col_down_turn;								// �պκ� �浹, �� �ٴںκ� �浹
																						//�ٴ�
	bool					col_floor;													// �ٴ� ����� ���� �浹����
																						//1p
	bool					col_h_Up, col_h_Down, col_h_Left, col_h_Right;				// 1�÷��̾� ��ġ ���� �浹����																		
																						//2p
	bool					col_h_Up2, col_h_Down2, col_h_Left2, col_h_Right2;			// 2�÷��̾� ��ġ ���� �浹����

public:
	Monster(void);

	~Monster(void);

	DWORD MonMoveTime, MonCountTime, AttCountTime, RezCountTime;
	Sprite seal_walk[2], seal_attacked[4], bird_fly[2], bird_attacked;
	int m_count, a_count;

	void Init(int monKind, int mapY, double scale, bool start);

	void Reset();

	void Update();

	void Boom();

	void Draw();

	int Collision_turn(int blockx, int blockX, int blocky, int blockY, bool onoff);		// �ٴ� �浹
	int Collision_floor(int blockx, int blockX, int blocky, int blockY, bool onoff);	// �¿� �浹
	int Collision_attacked(int chax, int chaX, int chay, int chaY, int pos);

	int getMonx();
	int getMonX();
	int getMony();
	int getMonY();
	bool getCreate();
	bool getOnoff();
	bool getBoom();


	void setCol_fornt_turn(bool state);
	void setCol_down_turn(bool state);
	void setCol_floor(bool state);

	//!
	void Floor(int floorY);
};

extern Monster seal;
extern Monster bird;