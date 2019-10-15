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

	//// mysql 구조체 변수 초기화
	//mysql_init(&sql.conn);

	//// ip, 접속 id , pass, 데이타 베이스명, 포트번호 등으로 접속
	//sql.connection = mysql_real_connect(&sql.conn, DB_HOST,
	//	DB_USER, DB_PASS,
	//	DB_NAME, 3306,
	//	(char *)NULL, 0);

	//// 만약 접속에 실패하면 다음 실행
	//if (sql.connection == NULL)
	//{
	//	sprintf_s(sql.state, "Mysql connection error : %s", mysql_error(&sql.conn));
	//	sql.mysql_Success = false;
	//}
	//else // 아니면...
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
	loadimg.SetColor(255, 255, 255, alpha);  // 색상 변경
	loadimg.Draw(0, 0);  //이미지출력

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