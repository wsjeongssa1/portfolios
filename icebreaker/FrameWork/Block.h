#pragma once

class Block
{
private:
	//1p
	int						blockKind;			// �ش� �ڽ� ��ü�� ����
	int						mapX;				// ���� x��ǥ
	int						mapY;				// ���� y��ǥ
	int						dx;					// x ���� �̵���
	bool					onoff;				// �׾��� ��Ҵ�
												//D3DXVECTOR3			position[4];		// �ڽ��� �����ϴ� ���ؽ� 4��
												//DWORD					color[4];			// �� ���ؽ��� ���� ����
												//FLOAT					tu[4];				// �� ���ؽ��� �ؽ��� u ��ǥ
												//FLOAT					tv[4];				// �� ���ؽ��� �ؽ��� v ��ǥ
	int						blockx, blocky, blockX, blockY;		// �浹���� blockx:��, blockX:��, blocky:�� , blockY:��
	bool					col_v_Up, col_v_Down, col_v_Left, col_v_Right;				// �����̵� �浹����
	bool					col_h_Up, col_h_Down, col_h_Left, col_h_Right;				// �����̵� �浹����
																						//double speed;
	double					scale;

	//double init_x, init_y;				// ù ������ġ
	//double x, y;						// ������
	//int score;							// �̳������� �Դ�����
	//int pos;							// ���ϴ� ����
	//double dx, dy, dz, drx, dry, drz;	// ��������
	//double w;

	//2p
	bool					col_v_Up2, col_v_Down2, col_v_Left2, col_v_Right2;				// �����̵� �浹����
	bool					col_h_Up2, col_h_Down2, col_h_Left2, col_h_Right2;				// �����̵� �浹����

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