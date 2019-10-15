#pragma once

#include "Include.h"


Over::Over()
{
}

Over::~Over()
{
}

void Over::Init()
{
	char FileName[256];
	sprintf_s(FileName, "./resource/Img/over/background.png");
	background.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/over/1p_bg.png");
	p1.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/over/2p_bg.png");
	p2.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/over/win_tex.png");
	win.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	sprintf_s(FileName, "./resource/Img/over/loss_tex.png");
	lose.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	for (int i = 0; i < 10; i++) {
		sprintf_s(FileName, "./resource/Img/number/number_%d.png",i);
		num[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

}

void Over::Update(double frame)
{
	if (KeyDown('A'))
	{
		//sql.save();
		g_Mng.n_Chap = MENU;
		sound.m_overbg->Reset();
		sound.m_overbg->Stop();
		sound.m_Menubg->Play(0, DSBPLAY_LOOPING);
		g_Mng.chap[g_Mng.n_Chap]->Init();
		playdata.namecheck1 = false;
		playdata.namecheck2 = false;
	}
}

void Over::Draw()
{
	background.Render(0, 0, 0, 1, 1);
	dv_font.DrawString("Press 'A' : Save and Restart.", 0, 0);
	p1.Render(150, 50, 0, 1, 1);
	p2.Render(650, 50, 0, 1, 1);
	char aa[200];
	int bonus = 3000;
	playdata.p1_total_score = (playdata.p1_block_count * 10) + (playdata.p1_seal_count * 500);
	playdata.p2_total_score = (playdata.p2_block_count * 10) + (playdata.p2_seal_count * 500);
	
	if (playdata.winner == 1) {
		playdata.p1_total_score += bonus;
		sprintf_s(aa, "%d", bonus);
		dv_font.DrawString(aa, 400, 540);
		win.Render(330, 70, 0, 1.6, 1.6);
		lose.Render(832, 83, 0, 1.1, 1.1);
	}
	else if (playdata.winner == 2) {
		playdata.p2_total_score += bonus;
		sprintf_s(aa, "%d",bonus);
		dv_font.DrawString(aa, 900, 540);
		win.Render(830, 70, 0, 1.6, 1.6);
		lose.Render(332, 83, 0, 1.1, 1.1);
	}

	sprintf_s(aa, "%d", playdata.p1_block_count);
	dv_font.DrawString(aa, 465, 341);
	sprintf_s(aa, "%d", playdata.p1_seal_count);
	dv_font.DrawString(aa, 465, 435);
	sprintf_s(aa, "%d", playdata.p1_total_score);
	dv_font.DrawString(aa, 400, 618);

	sprintf_s(aa, "%d", playdata.p2_block_count);
	dv_font.DrawString(aa, 965, 341);
	sprintf_s(aa, "%d", playdata.p2_seal_count);
	dv_font.DrawString(aa, 965, 435);
	sprintf_s(aa, "%d", playdata.p2_total_score);
	dv_font.DrawString(aa, 900, 618);
}

void Over::OnMessage(MSG* msg)
{

}