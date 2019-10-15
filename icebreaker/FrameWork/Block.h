#pragma once

class Block
{
private:
	//1p
	int						blockKind;			// 해당 박스 객체의 종류
	int						mapX;				// 맵의 x좌표
	int						mapY;				// 맵의 y좌표
	int						dx;					// x 방향 이동량
	bool					onoff;				// 죽었니 살았니
												//D3DXVECTOR3			position[4];		// 박스를 구성하는 버텍스 4개
												//DWORD					color[4];			// 각 버텍스의 고유 색깔
												//FLOAT					tu[4];				// 각 버텍스의 텍스쳐 u 좌표
												//FLOAT					tv[4];				// 각 버텍스의 텍스쳐 v 좌표
	int						blockx, blocky, blockX, blockY;		// 충돌범위 blockx:좌, blockX:우, blocky:상 , blockY:하
	bool					col_v_Up, col_v_Down, col_v_Left, col_v_Right;				// 수직이동 충돌방향
	bool					col_h_Up, col_h_Down, col_h_Left, col_h_Right;				// 수평이동 충돌방향
																						//double speed;
	double					scale;

	//double init_x, init_y;				// 첫 출현위치
	//double x, y;						// 재출현
	//int score;							// 이넘잡으면 먹는점수
	//int pos;							// 향하는 방향
	//double dx, dy, dz, drx, dry, drz;	// 데미지존
	//double w;

	//2p
	bool					col_v_Up2, col_v_Down2, col_v_Left2, col_v_Right2;				// 수직이동 충돌방향
	bool					col_h_Up2, col_h_Down2, col_h_Left2, col_h_Right2;				// 수평이동 충돌방향

	int						player;

public:
	Block(void);
	~Block(void);
	Sprite img, destroy[2];

	int m_Acount, m_Bcount, m_Bulletcount;

	//DWORD FishMoveTime;
	//DWORD FishCountTime;
	DWORD CloudMoveTime;

	//DWORD BoomTime1;
	//bool m_Boom1;
	//int m_BoomCount1;
	//double m_BoomX1;
	//double m_BoomY1;



	//RECT m_rc;
	//double m_Left;
	//double m_High;

	//int m_FishLifeSelect;

	void Init(int boxKind, int mapX, int mapY, double scale);
	void Update();
	void Draw();
	void Destroy(int player);
	void Resen();
	void Reset();
	int Collision_V(int chx, int chX, int chy, int chY);
	int Collision_H(int chx, int chX, int chy, int chY);
	int Collision_V2(int chx, int chX, int chy, int chY);
	int Collision_H2(int chx, int chX, int chy, int chY);
	int getBlockx();
	int getBlockX();
	int getBlocky();
	int getBlockY();
	int getBoxKind();
	bool getOnoff();

	int getPlayer();
	void setPlayer(int player);

	//!
	void Floor(int floorY);
};

extern Block block;