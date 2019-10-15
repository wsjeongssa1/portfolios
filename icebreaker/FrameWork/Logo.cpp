#pragma once

#include "Include.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Init()
{
	
	//speed = 2000;
	alpha = 255;

	loadimg.Create("./resource/Img/logo/logo.png", false, D3DCOLOR_XRGB(0, 0, 0));

	//// mysql ����ü ���� �ʱ�ȭ
	//mysql_init(&sql.conn);

	//// ip, ���� id , pass, ����Ÿ ���̽���, ��Ʈ��ȣ ������ ����
	//sql.connection = mysql_real_connect(&sql.conn, DB_HOST,
	//	DB_USER, DB_PASS,
	//	DB_NAME, 3306,
	//	(char *)NULL, 0);

	//// ���� ���ӿ� �����ϸ� ���� ����
	//if (sql.connection == NULL)
	//{
	//	sprintf_s(sql.state, "Mysql connection error : %s", mysql_error(&sql.conn));
	//	sql.mysql_Success = false;
	//}
	//else // �ƴϸ�...
	//{
	//	sql.mysql_Success = true;
	//}

}

void Logo::Update(double frame)
{
	Draw();
	//if (KeyDown('S')) {
		alpha_ = true;
	//}
	if (alpha_ == true) {
		alpha--;
	}
	/*alpha += speed * frame / 3000;
	if (alpha >= 255)
	{
		alpha = 255;
		speed = -1000;

	}*/
	if (alpha <= 0) {
		g_Mng.n_Chap = MENU;
		g_Mng.chap[g_Mng.n_Chap]->Init();
		//sound.m_Loadbg->Reset();
		//sound.m_Loadbg->Stop();
		sound.m_Menubg->Play(0, DSBPLAY_LOOPING);
	}
}

void Logo::Draw()
{
	if (playdata.load_ == true) {
		//sound.m_Loadbg->Play(0, DSBPLAY_LOOPING);
		playdata.load_ = false;
	}
	loadimg.SetColor(255, 255, 255, alpha);  // ���� ����
	loadimg.Draw(0, 0);  //�̹������

}

void Logo::OnMessage(MSG* msg)
{
	switch (msg->message)
	{
	case WM_LBUTTONDOWN:
		MessageBox(NULL, "", "", 0);
		break;
	}

}