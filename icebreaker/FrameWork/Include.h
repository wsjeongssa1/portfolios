#pragma once

/* ---------------------------------------------------
///////////////// ���α׷� ���� //////////////////////

		���̺귯���� �ʿ��� �����Դϴ�.
		����� �ȵſ�~~^^;

//////////////////////////////////////////////////////
-----------------------------------------------------*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dsound.lib")
//����Ÿ ���̽�//////
//#include <winsock2.h>
//#include <mysql.h>
//#pragma comment(lib, "libmySQL.lib")
/////////////////////
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <iostream>
using namespace std;

#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>
#include "DXUTsound.h"

#include <windows.h>
#include "Define.h"
#include "DeviceFont.h"
#include "Sprite.h"
#include "Chap.h"


/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		���� Ŭ���� ���� �� ����
		��������� �߰��� �ּ���~

//////////////////////////////////////////////////////
-----------------------------------------------------*/
#include "Game.h"
#include "Logo.h"
#include "Menu.h"
#include "Over.h"
#include "CMng.h"

//#include "Night.h"

#include "Data.h"

#include "Map.h"

#include "Monster.h"
#include "Block.h"
#include "Character.h"
#include "BlockManager.h"
#include "MapManager.h"

#include "Key.h"
#include "Sound.h"
#include "GameManager.h"

// ����Ÿ���̽�////////////////
//#include "mysql.h"

/* ---------------------------------------------------
///////////////// ����� �߰� ���� ///////////////////

		Ű �Է� ó�� �Լ��Դϴ�.

//////////////////////////////////////////////////////
-----------------------------------------------------*/

inline int KeyDown	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 1:0 ); 
}

inline int KeyUp	( int vk ) 
{ 
	return ( (GetAsyncKeyState(vk) & 0x8000) ? 0:1 ); 
}