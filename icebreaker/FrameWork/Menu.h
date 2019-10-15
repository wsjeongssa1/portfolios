#ifndef __Menu_H__
#define __Menu_H__

class Menu : public Chap
{
	Sprite menuimg;

public:
	Menu();
	~Menu();
	int count;
	int index;
	int cnt;
	bool Mwind;
	bool Rwind;		//!!!!! ·©Å·Ã¢ 
	bool nameset1;
	bool nameset2;

	bool select;
	bool center;
	int cen;
	bool left;
	bool right;
	bool center2;
	int cen2;
	bool left2;
	bool right2;
	int cha1X = 450, cha2X = 550;
	Sprite background;
	Sprite mback;
	Sprite rback;
	Sprite hammer[2];
	Sprite nameback;
	Sprite alp[29];
	Sprite charac1;
	Sprite charac2;
	Sprite charac1run[2];
	Sprite charac2run[2];

	DWORD KeyTime;
	DWORD KeyTime2;
	DWORD KeyTime3;
	DWORD KeyTime4;

	DWORD HamTime;

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

};

#endif