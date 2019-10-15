#pragma once

#include "Include.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	//// mysql ����ü ���� �ʱ�ȭ
	//mysql_init(&sql.conn);

	//// ip, ���� id , pass, ����Ÿ ���̽���, ��Ʈ��ȣ ������ ����
	//sql.connection = mysql_real_connect(&sql.conn, DB_HOST,
	//	DB_USER, DB_PASS,
	//	DB_NAME, 3306,
	//	(char *)NULL, 0);

	char FileName[256];
	sprintf_s(FileName, "./resource/Img/town/bg_town.png");
	background.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/UI/bubble_bg.png");
	mback.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/UI/ranking_.png");
	rback.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/UI/name_bg.png");
	nameback.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	for (int i = 0; i < 2; i++) {
		sprintf_s(FileName, "./resource/Img/UI/hammer_%d.png", i+1);
		hammer[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int i = 0; i < 29; i++) {
		sprintf_s(FileName, "./resource/Img/alp/ranking_%02d.png",i+1);
		alp[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	sprintf_s(FileName, "./resource/Img/char/1player_stand1.png");
	charac1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	for (int i = 0; i < 2; i++) {
		sprintf_s(FileName, "./resource/Img/char/1player_run%d.png", i + 1);
		charac1run[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	sprintf_s(FileName, "./resource/Img/char/2player_stand1.png");
	charac2.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	for (int i = 0; i < 2; i++) {
		sprintf_s(FileName, "./resource/Img/char/2player_run%d.png", i + 1);
		charac2run[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Menu::Update(double frame)
{
	// ��������Ʈ
	if (GetTickCount() - HamTime > 250) {
		count++;
		if (count > 1) {
			count = 0;
		}
		HamTime = GetTickCount();
	}

	if (cha1X < 10 && cha2X < 10
			&& playdata.namecheck1 == true && playdata.namecheck2 == true) {

		sound.m_Menubg->Reset();
		sound.m_Menubg->Stop();
		playdata.Reset();
		g_Mng.n_Chap = GAME;
		g_Mng.chap[g_Mng.n_Chap]->Init();
		sound.m_Bk1->Play(0, DSBPLAY_LOOPING);
		sound.m_Gamebg->Play(0, DSBPLAY_LOOPING);
	}
}

void Menu::Draw()
{
	background.Render(0, 0, 0, 1, 1); //�̹������
	dv_font.DrawString("1P : ����_T,F,G,H/ ����_Z/ ����_X/ ����_SPACE", 0, 0);
	dv_font.DrawString("2P : ����_����Ű/ ����_O/ ����_P/ ����_ENTER", 0, 50);

	if (KeyDown('F') && !nameset2 && !Mwind && !Rwind) {
		if (GetTickCount() - KeyTime > 10) {
			left = true;
			right = false;
			center = false;
			cen = 1;
			cha1X <= -10? cha1X = -10: cha1X -= 4;
			KeyTime = GetTickCount();
		}
	}
	if (KeyUp('F') && !nameset2 && !Mwind && !Rwind) {
		left = false;
		center = true;
	}
	if (left == true) {
		charac1run[count].Render(cha1X, 555, 0, 1, 1);
	}
	if (KeyDown('H') && !nameset2 && !Mwind && !Rwind) {
		if (GetTickCount() - KeyTime > 10) {
			left = false;
			right = true;
			center = false;
			cen = 0;
			cha1X >= 1180? cha1X = 1180 : cha1X += 4;
			KeyTime = GetTickCount();
		}
	}
	if (KeyUp('H') && !nameset2 && !Mwind && !Rwind) {
		right = false;
		center = true;
	}
	if (right == true) {
		charac1run[count].Render(cha1X + 118, 555, 0, -1, 1);
	}
	if (center == true && !KeyDown('F') && !KeyDown('H')) {
		cen == 1 ? charac1.Render(cha1X, 555, 0, 1, 1): charac1.Render(cha1X+118, 555, 0, -1, 1);
	}

	if (KeyDown(VK_LEFT) && !nameset1 && !Mwind && !Rwind) {
		if (GetTickCount() - KeyTime2 > 10) {
			left2 = true;
			right2 = false;
			center2 = false;
			cen2 = 1;
			cha2X <= -10? cha2X = -10 : cha2X -= 4;
			KeyTime2 = GetTickCount();
		}
	}
	if (KeyUp(VK_LEFT) && !nameset1 && !Mwind && !Rwind) {
		left2 = false;
		center2 = true;
	}
	if (left2 == true) {
		charac2run[count].Render(cha2X, 555, 0, 1, 1);
	}
	if (KeyDown(VK_RIGHT) && !nameset1 && !Mwind && !Rwind) {
		if (GetTickCount() - KeyTime2 > 10) {
			left2 = false;
			right2 = true;
			center2 = false;
			cen2 = 0;
			cha2X >= 1180? cha2X = 1180 : cha2X += 4;
			KeyTime2 = GetTickCount();
		}
	}
	if (KeyUp(VK_RIGHT) && !nameset1 && !Mwind && !Rwind) {
		right2 = false;
		center2 = true;
	}
	if (right2 == true) {
		charac2run[count].Render(cha2X + 118, 555, 0, -1, 1);
	}
	if (center2 == true && !KeyDown(VK_LEFT) && !KeyDown(VK_RIGHT)) {
		cen2 == 1 ? charac2.Render(cha2X, 555, 0, 1, 1) : charac2.Render(cha2X + 118, 555, 0, -1, 1);
	}

	//npc ��ó���� ���ɱ� 1p
	if (cha1X > 100 && cha1X < 200) {
		if (!nameset1 && !nameset2 && !Mwind && !Rwind) {
			dv_font.DrawString("Press 'X'", cha1X + 90, 540);
		}
		if (KeyDown('X')&& !nameset1 && !nameset2
			&& !Mwind && !Rwind) {
			sound.Select3->Play(0, NULL);
			Mwind = true;
			select = true;
		}
		if (Mwind == true) {
			mback.Render(240, 200, 0, 1, 1);
			select == true ? hammer[count].Render(290, 295, 0, 1, 1) : hammer[count].Render(295, 415, 0, 1, 1);
			if (KeyDown('T') || KeyDown('G')) {
				if (GetTickCount() - KeyTime3 > 200) {
					sound.Select->Play(0, NULL);
					select == true ? select = false : select = true;
					KeyTime3 = GetTickCount();
				}
			}
			// 1p
			if (KeyDown(VK_SPACE) && select == true) {
				if (GetTickCount() - KeyTime3 > 300) {
					sound.Select2->Play(0, NULL);
					nameset1 = true;
					KeyTime3 = GetTickCount();
				}
				Mwind = false;
			}
			else if (KeyDown(VK_SPACE) && select == false) {
				if (GetTickCount() - KeyTime3 > 200) {
					sound.Select2->Play(0, NULL);
					Rwind = true;
					KeyTime3 = GetTickCount();
				}
				Mwind = false;
			}
		}
	}
	//npc ��ó���� ���ɱ� 2p
	if (cha2X > 100 && cha2X < 200) {
		if (!nameset1 && !nameset2 && !Mwind && !Rwind) {
			dv_font.DrawString("Press 'P'", cha2X + 90, 540);
		}
		if (KeyDown('P') && !nameset1 && !nameset2
			&& !Mwind && !Rwind) {
			sound.Select3->Play(0, NULL);
			Mwind = true;
			select = true;
		}
		if (Mwind == true) {
			mback.Render(240, 200, 0, 1, 1);
			select == true ? hammer[count].Render(290, 295, 0, 1, 1) : hammer[count].Render(295, 415, 0, 1, 1);
			if (KeyDown(VK_UP) || KeyDown(VK_DOWN)) {
				if (GetTickCount() - KeyTime4 > 200) {
					sound.Select->Play(0, NULL);
					select == true ? select = false : select = true;
					KeyTime4 = GetTickCount();
				}
			}
			if (KeyDown(VK_RETURN) && select == true) {
				if (GetTickCount() - KeyTime4 > 200) {
					sound.Select2->Play(0, NULL);
					nameset2 = true;
					KeyTime4 = GetTickCount();
				}
				Mwind = false;
			}
			else if (KeyDown(VK_RETURN) && select == false) {
				if (GetTickCount() - KeyTime4 > 200) {
					sound.Select2->Play(0, NULL);
					Rwind = true;
					KeyTime4 = GetTickCount();
				}
				Mwind = false;
			}
		}
	}

	//1p name
	if (nameset1 == true) {
		int x = 370;
		nameback.Render(240, 200, 0, 1, 1);
		if (cnt == 0) {									//ù��° �̴ϼ�
			alp[index].Render(x, 370, 0, 1, 1);
		}
		else if (cnt == 1) {								//�ι�° �̴ϼ�
			alp[playdata.p1_name[0]].Render(x, 370, 0, 1, 1);
			alp[index].Render(x + 80, 370, 0, 1, 1);
		}
		else if (cnt == 2) {									//����° �̴ϼ�
			alp[playdata.p1_name[0]].Render(x, 370, 0, 1, 1);
			alp[playdata.p1_name[1]].Render(x + 80, 370, 0, 1, 1);
			alp[index].Render(x + 160, 370, 0, 1, 1);
		}
		else if (cnt == 3 ) {									//��ü Ȯ��
			alp[playdata.p1_name[0]].Render(x, 370, 0, 1, 1);
			alp[playdata.p1_name[1]].Render(x + 80, 370, 0, 1, 1);
			alp[playdata.p1_name[2]].Render(x + 160, 370, 0, 1, 1);
		}
		if (KeyDown('T')) {		//�̴ϼ� ���� �������� �̵�
			if (GetTickCount() - KeyTime > 200)	{
				index < 28 ? index++ : index = 0;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown('G')) {		//�̴ϼ� ���� �������� �̵�
			if (GetTickCount() - KeyTime > 200) {
				index > 0 ? index-- : index = 28;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_SPACE)) {	// �̴ϼ� ����
			if (GetTickCount() - KeyTime3 > 200) {
				if (index == 28) {
					cnt <= 1 ? (cnt == 0 ? (playdata.p1_name[cnt] = 26, playdata.p1_name[cnt+1] = 26, cnt = 2)
							: (playdata.p1_name[cnt] = 26, cnt = 2 )): cnt = 2;
					index = 26;
				}
				else if (index == 27) {
					index = playdata.p1_name[cnt-2];
					cnt -= 2;
				}
				playdata.p1_name[cnt] = index;
				cnt < 3 ? cnt++ : (sound.Select3->Play(0, NULL),nameset1 = false,cnt = 0,playdata.namecheck1 = true);
				index = 0;
				KeyTime3 = GetTickCount();
			}
		}
	}
	//2p name
	if (nameset2 == true) {
		int x = 370;
		nameback.Render(240, 200, 0, 1, 1);
		if (cnt == 0) {
			alp[index].Render(x, 370, 0, 1, 1);
		}
		else if (cnt == 1) {
			alp[playdata.p2_name[0]].Render(x, 370, 0, 1, 1);
			alp[index].Render(x + 80, 370, 0, 1, 1);
		}
		else if (cnt == 2) {
			alp[playdata.p2_name[0]].Render(x, 370, 0, 1, 1);
			alp[playdata.p2_name[1]].Render(x + 80, 370, 0, 1, 1);
			alp[index].Render(x + 160, 370, 0, 1, 1);
		}
		else if (cnt == 3) {
			alp[playdata.p2_name[0]].Render(x, 370, 0, 1, 1);
			alp[playdata.p2_name[1]].Render(x + 80, 370, 0, 1, 1);
			alp[playdata.p2_name[2]].Render(x + 160, 370, 0, 1, 1);
		}
		if (KeyDown(VK_UP)) {
			if (GetTickCount() - KeyTime > 200) {
				index < 28 ? index++ : index = 0;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_DOWN)) {
			if (GetTickCount() - KeyTime > 200) {
				index > 0 ? index-- : index = 28;
				KeyTime = GetTickCount();
			}
		}
		if (KeyDown(VK_RETURN)) {
			if (GetTickCount() - KeyTime4 > 200) {
				if (index == 28) {
					cnt <= 1 ? (cnt == 0 ? (playdata.p2_name[cnt] = 26, playdata.p2_name[cnt + 1] = 26, cnt = 2)
						: (playdata.p2_name[cnt] = 26, cnt = 2)) : cnt = 2;
					index = 26;
				}
				else if (index == 27) {
					index = playdata.p2_name[cnt - 2];
					cnt -= 2;
				}
				playdata.p2_name[cnt] = index;
				cnt < 3 ? cnt++ : (sound.Select3->Play(0, NULL),nameset2 = false, cnt = 0,playdata.namecheck2 = true);
				index = 0;
				KeyTime4 = GetTickCount();
			}
		}
	}

	//// ��ŷ Ȯ�� 
	//int count1 = 0;
	if (Rwind == true){
		rback.Render(150, 20, 0, 1, 1);
		//// score���� �������� ���ķ� �ҷ�����
		//sql.query_start = mysql_query(sql.connection, "select * from rank order by score desc");
		//sql.sql_result = mysql_store_result(sql.connection);
		//while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
		//{
		//	// ���� ����� ������ ���ڵ� ���� ����������... where id = ? ? ������ Ư�� ����� ���� ����������...
		//	// ��ü ����Ÿ�� �ʿ��� ���� �迭�� ������ ó������....
		//	// sql.sql_row[0] �ε����� �ش� Į��(��,�ʵ�)�� ������
		//		sprintf_s(sql.ranking[count1].first, 10, "%s", sql.sql_row[0]);
		//		sprintf_s(sql.ranking[count1].middle, 10, "%s", sql.sql_row[1]);
		//		sprintf_s(sql.ranking[count1].last, 10, "%s", sql.sql_row[2]);
		//		sprintf_s(sql.ranking[count1].score, 10, "%s", sql.sql_row[3]);
		//	// ���ڵ� ����ŭ ����... 
		//	count1++;
		//	if (count1 == 8) {
		//		break;
		//	}
		//}
		//// sql.sql_result �� ����
		//mysql_free_result(sql.sql_result);
		//int first;
		//int middle;
		//int last;
		//for (int i = 0; i < count1; i++) {
		//	first = atoi(sql.ranking[i].first);
		//	middle = atoi(sql.ranking[i].middle);
		//	last = atoi(sql.ranking[i].last);
		//	alp[first].Render(330, 135 + (i * 68), 0, 1, 1);
		//	alp[middle].Render(393, 135 + (i * 68), 0, 1, 1);
		//	alp[last].Render(456, 135 + (i * 68), 0, 1, 1);
		//	dv_font.DrawString(sql.ranking[i].score, 580, 145 +(i*68));
		//}

		if (KeyDown(VK_SPACE)) {
			if (GetTickCount() - KeyTime3 > 200) {
				sound.Select3->Play(0, NULL);
				Rwind = false;
				KeyTime3 = GetTickCount();
			}
		}
		if(KeyDown(VK_RETURN)){
			if (GetTickCount() - KeyTime4 > 200) {
				sound.Select3->Play(0, NULL);
				Rwind = false;
				KeyTime4 = GetTickCount();
			}
		}
	}
}

void Menu::OnMessage(MSG* msg)
{

}