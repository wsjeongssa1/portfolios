#pragma once
//#include "Include.h"

class Monster
{
	int						monKind;			// 해당 박스 객체의 종류
	int						mapX;				// 맵의 x좌표
	int						mapY;				// 맵의 y좌표
	double					scale;


	int						pos;				// 향하는 방향
	int						move_x;				// 좌 우 이동
	bool					create;
	bool					onoff;				// 죽었니 살았니
	bool					boom;				// 터짐

	int						monx, mony, monX, monY;		// 충돌범위 blockx:좌, blockX:우, blocky:상 , blockY:하


														//방향전환
	bool					col_fornt_turn, col_down_turn;								// 앞부분 충돌, 앞 바닥부분 충돌
																						//바닥
	bool					col_floor;													// 바닥 사라짐 수직 충돌방향
																						//1p
	bool					col_h_Up, col_h_Down, col_h_Left, col_h_Right;				// 1플레이어 망치 수평 충돌방향																		
																						//2p
	bool					col_h_Up2, col_h_Down2, col_h_Left2, col_h_Right2;			// 2플레이어 망치 수평 충돌방향

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

	int Collision_turn(int blockx, int blockX, int blocky, int blockY, bool onoff);		// 바닥 충돌
	int Collision_floor(int blockx, int blockX, int blocky, int blockY, bool onoff);	// 좌우 충돌
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