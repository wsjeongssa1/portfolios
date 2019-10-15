#include "Include.h"

GameManager Gmanager;
static DWORD ALPHATime = GetTickCount();

GameManager::GameManager(void)
{
	GameTime = GetTickCount();
	m_GameSpeed = 1;
	m_Pause = false;

	//m_SysTem.m_Save1 = 100;
	//m_SysTem.m_Save2 = 200;
	//Save();

	m_GameStart = true;
}

GameManager::~GameManager(void)
{
}

void GameManager::Init()
{
	//Menuimg[0].Create("./resource/Effect/menu/1.png",false,D3DCOLOR_XRGB(0,0,0));
	//Menuimg[1].Create("./resource/Effect/menu/2.png",false,D3DCOLOR_XRGB(0,0,0));


	char seps[] = ",\n";
	char *token;

	if ((fp = fopen("C:\\SYSTEM.txt","r"))== NULL)
	{
		return ;
	}
	
	if ((fp = fopen("./Save/save.fss","rb"))== NULL)
	{
		return ;
	}
	
	fread(&m_SysTem,sizeof(SysTem),1,fp);

	fclose(fp);
	
}

void GameManager::Update()
{
	//if(게임 종료시) g_Mng.n_Chap = OVER; 
}
void GameManager::Save()
{
	if ((fp = fopen("./Save/save.fss", "wb")) == NULL)
	{
		return;
	}
	fwrite(&m_SysTem, sizeof(SysTem), 1, fp);
	fclose(fp);

}

void GameManager::Delete()
{
//	sound.g_pSoundManager->drr  

}
 



void GameManager::GameReset(void)  // 여기는 게임상 첨에 한번만  초기화되는 부분만 넣어줌.
{

}


void GameManager::Draw()
{

	//if(m_Alpha == 0) { Menuimg[0].SetColor(255,255, 255, 255);  Menuimg[1].SetColor(255,255, 255, 255);}
	//if(m_Alpha == 1) { Menuimg[0].SetColor(255,255,255,0); Menuimg[1].SetColor(255,255,255,0); }
	

	//map.numimg[5].Draw(50, 53);
	//map.numimg[0].Draw(65, 53);
	//map.numimg[0].Draw(80, 53);
	//map.numimg[0].Draw(95, 53);
	
}
