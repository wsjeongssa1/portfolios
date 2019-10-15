#pragma once
#include "Include.h"

Block block;

Block::Block(void)
{
	CloudMoveTime = GetTickCount();
	dx = 0;
}

Block::~Block(void)
{
}

void Block::Destroy(int player)
{
	onoff = false;
	this->player = player;
}

void Block::Resen()
{
	onoff = true;

}

void Block::Init(int boxKind, int mapX, int mapY, double scale)
{
	this->blockKind = boxKind;
	this->mapX = mapX;
	this->mapY = mapY;
	this->scale = scale;
	player = 0;
	onoff = true;
	blockx = (mapX * 40);			// ��
	blockX = (mapX * 40) + 40;			// ��
	blocky = (mapY * 34);			// ��	
	blockY = (mapY * 34) + 34;			// ��
	if (blockKind == 4)
	{
		blockx = (mapX * 40);			// ��
		blockX = (mapX * 40) + 80;			// ��
		blocky = (mapY * 34);			// ��	
		blockY = (mapY * 34) + 34;			// ��
	}
	else if (blockKind == 5)
	{
		blockx = (mapX * 40);			// ��
		blockX = (mapX * 40) + 120;			// ��
		blocky = (mapY * 34);			// ��	
		blockY = (mapY * 34) + 34;			// ��
	}
	else if (blockKind == 8 || blockKind == 9)
	{
		blockx = (mapX * 40);			// ��
		blockX = (mapX * 40) + (40 * 6);			// ��
		blocky = (mapY * 34);			// ��	
		blockY = (mapY * 34) + (34 * 5);			// ��
	}
	col_v_Up = false;
	col_v_Down = false;
	col_v_Left = false;
	col_v_Right = false;

	char FileName[256];
	if (boxKind == ICE) {
		sprintf_s(FileName, "./resource/Img/ice/ice1.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == HARDICE) {
		sprintf_s(FileName, "./resource/Img/ice/hardIce1.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == SPEEDICE) {
		sprintf_s(FileName, "./resource/Img/ice/speedBlock1.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == CLOUD1) {
		sprintf_s(FileName, "./resource/Img/ice/cloud1.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == CLOUD2) {
		sprintf_s(FileName, "./resource/Img/ice/cloud2.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == ROCKL) {
		sprintf_s(FileName, "./resource/Img/ice/rock1l.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == ROCKR) {
		sprintf_s(FileName, "./resource/Img/ice/rock1r.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == ROCK2L) {
		sprintf_s(FileName, "./resource/Img/ice/rock2l.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == ROCK2R) {
		sprintf_s(FileName, "./resource/Img/ice/rock2r.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	else if (boxKind == BOTTOM) {
		sprintf_s(FileName, "./resource/Img/ice/bottom.png");
		img.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
	for (int i = 0; i<2; i++)
	{
		sprintf_s(FileName, "./resource/Img/Monster/2/fish_002_00%02d.png", i);
		destroy[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}


void Block::Reset()
{



}

int Block::Collision_V(int chx, int chX, int chy, int chY)
{
	if (onoff
		&& blockKind != 6 && blockKind != 7 && blockKind != 20)		// ���� �� ���� �����ϰ��
	{
		if (chX < blockx && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))			// ���� ���� ������ ���
		{
			col_v_Left = true;

			col_v_Right = false;
			col_v_Up = false;
			col_v_Down = false;
			return 7;
		}
		else if (chx > blockX && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))	// ���� ������ ������ ���
		{
			col_v_Right = true;

			col_v_Left = false;
			col_v_Up = false;
			col_v_Down = false;
			return 7;
		}
		else if (chY < blocky && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �� ������ ���
		{
			col_v_Up = true;

			col_v_Right = false;
			col_v_Left = false;
			col_v_Down = false;
			return 7;
		}
		else if (chy > blockY && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �Ʒ� ������ ���
		{
			col_v_Down = true;

			col_v_Right = false;
			col_v_Left = false;
			col_v_Up = false;
			return 7;
		}
		else if (((chx >= blockx && chx <= blockX) || (chX >= blockx && chX <= blockX)) &&					// ���� �浹�Ѱ��
			((chy >= blocky && chy <= blockY) || (chY >= blocky && chY <= blockY)))
		{
			if (col_v_Up)
			{
				col_v_Up = false;
				return UP;
			}
			else if (col_v_Down)
			{
				col_v_Down = false;
				return DOWN;
			}
			else if (col_v_Left)
			{
				col_v_Left = false;
				return LEFT;
			}
			else if (col_v_Right)
			{
				col_v_Right = false;
				return RIGHT;
			}
			else
				return 6;																				// ���۽��� �浹�϶�
		}
		else																							// �ƹ��͵��ƴҶ�
		{
			col_v_Down = false;
			col_v_Right = false;
			col_v_Left = false;
			col_v_Up = false;
			return 8;
		}
	}
	return 5;																							// off �ų� �浹�ƴϸ� 5 ����
}

int Block::Collision_H(int chx, int chX, int chy, int chY)
{
	if (onoff
		&& blockKind != 6 && blockKind != 7 && blockKind != 20)		// ���� �� ���� �����ϰ��
	{
		if (chX < blockx && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))			// ���� ���� ������ ���
		{
			col_h_Left = true;

			col_h_Right = false;
			col_h_Up = false;
			col_h_Down = false;
			return 7;
		}
		else if (chx > blockX && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))	// ���� ������ ������ ���
		{
			col_h_Right = true;

			col_h_Left = false;
			col_h_Up = false;
			col_h_Down = false;
			return 7;
		}
		else if (chY < blocky && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �� ������ ���
		{
			col_h_Up = true;

			col_h_Right = false;
			col_h_Left = false;
			col_h_Down = false;
			return 7;
		}
		else if (chy > blockY && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �Ʒ� ������ ���
		{
			col_h_Down = true;

			col_h_Right = false;
			col_h_Left = false;
			col_h_Up = false;
			return 7;
		}
		else if (((chx >= blockx && chx <= blockX) || (chX >= blockx && chX <= blockX)) &&					// ���� �浹�Ѱ��
			((chy >= blocky && chy <= blockY) || (chY >= blocky && chY <= blockY)))
		{
			if (col_h_Up)
			{
				col_h_Up = false;
				return UP;
			}
			else if (col_h_Down)
			{
				col_h_Down = false;
				return DOWN;
			}
			else if (col_h_Left)
			{
				col_h_Left = false;
				return LEFT;
			}
			else if (col_h_Right)
			{
				col_h_Right = false;
				return RIGHT;
			}
			else
				return 6;																				// ���۽��� �浹�϶�
		}
		else																							// �ƹ��͵��ƴҶ�
		{
			col_h_Down = false;
			col_h_Right = false;
			col_h_Left = false;
			col_h_Up = false;
			return 8;
		}
	}
	return 5;																							// off �ų� �浹�ƴϸ� 5 ����
}

int Block::Collision_V2(int chx, int chX, int chy, int chY)
{
	if (onoff
		&& blockKind != 6 && blockKind != 7 && blockKind != 20)		// ���� �� ���� �����ϰ��
	{
		if (chX < blockx && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))			// ���� ���� ������ ���
		{
			col_v_Left2 = true;

			col_v_Right2 = false;
			col_v_Up2 = false;
			col_v_Down2 = false;
			return 7;
		}
		else if (chx > blockX && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))	// ���� ������ ������ ���
		{
			col_v_Right2 = true;

			col_v_Left2 = false;
			col_v_Up2 = false;
			col_v_Down2 = false;
			return 7;
		}
		else if (chY < blocky && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �� ������ ���
		{
			col_v_Up2 = true;

			col_v_Right2 = false;
			col_v_Left2 = false;
			col_v_Down2 = false;
			return 7;
		}
		else if (chy > blockY && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �Ʒ� ������ ���
		{
			col_v_Down2 = true;

			col_v_Right2 = false;
			col_v_Left2 = false;
			col_v_Up2 = false;
			return 7;
		}
		else if (((chx >= blockx && chx <= blockX) || (chX >= blockx && chX <= blockX)) &&					// ���� �浹�Ѱ��
			((chy >= blocky && chy <= blockY) || (chY >= blocky && chY <= blockY)))
		{
			if (col_v_Up2)
			{
				col_v_Up2 = false;
				return UP;
			}
			else if (col_v_Down2)
			{
				col_v_Down2 = false;
				return DOWN;
			}
			else if (col_v_Left2)
			{
				col_v_Left2 = false;
				return LEFT;
			}
			else if (col_v_Right2)
			{
				col_v_Right2 = false;
				return RIGHT;
			}
			else
				return 6;																				// ���۽��� �浹�϶�
		}
		else																							// �ƹ��͵��ƴҶ�
		{
			col_v_Down2 = false;
			col_v_Right2 = false;
			col_v_Left2 = false;
			col_v_Up2 = false;
			return 8;
		}
	}
	return 5;																							// off �ų� �浹�ƴϸ� 5 ����
}

int Block::Collision_H2(int chx, int chX, int chy, int chY)
{
	if (onoff
		&& blockKind != 6 && blockKind != 7 && blockKind != 20)		// ���� �� ���� �����ϰ��
	{
		if (chX < blockx && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))			// ���� ���� ������ ���
		{
			col_h_Left2 = true;

			col_h_Right2 = false;
			col_h_Up2 = false;
			col_h_Down2 = false;
			return 7;
		}
		else if (chx > blockX && ((chy > blocky && chy < blockY) || (chY > blocky && chY < blockY)))	// ���� ������ ������ ���
		{
			col_h_Right2 = true;

			col_h_Left2 = false;
			col_h_Up2 = false;
			col_h_Down2 = false;
			return 7;
		}
		else if (chY < blocky && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �� ������ ���
		{
			col_h_Up2 = true;

			col_h_Right2 = false;
			col_h_Left2 = false;
			col_h_Down2 = false;
			return 7;
		}
		else if (chy > blockY && ((chx > blockx && chx < blockX) || (chX > blockx && chX < blockX)))	// ���� �Ʒ� ������ ���
		{
			col_h_Down2 = true;

			col_h_Right2 = false;
			col_h_Left2 = false;
			col_h_Up2 = false;
			return 7;
		}
		else if (((chx >= blockx && chx <= blockX) || (chX >= blockx && chX <= blockX)) &&					// ���� �浹�Ѱ��
			((chy >= blocky && chy <= blockY) || (chY >= blocky && chY <= blockY)))
		{
			if (col_h_Up2)
			{
				col_h_Up2 = false;
				return UP;
			}
			else if (col_h_Down2)
			{
				col_h_Down2 = false;
				return DOWN;
			}
			else if (col_h_Left2)
			{
				col_h_Left2 = false;
				return LEFT;
			}
			else if (col_h_Right2)
			{
				col_h_Right2 = false;
				return RIGHT;
			}
			else
				return 6;																				// ���۽��� �浹�϶�
		}
		else																							// �ƹ��͵��ƴҶ�
		{
			col_h_Down2 = false;
			col_h_Right2 = false;
			col_h_Left2 = false;
			col_h_Up2 = false;
			return 8;
		}
	}
	return 5;																							// off �ų� �浹�ƴϸ� 5 ����
}

int Block::getBlockx()
{
	return blockx;
}

int Block::getBlockX()
{
	return blockX;
}

int Block::getBlocky()
{
	return blocky;
}

int Block::getBlockY()
{
	return blockY;
}

int Block::getBoxKind()
{
	return blockKind;
}

bool Block::getOnoff()
{
	return onoff;
}

int Block::getPlayer()
{
	return player;
}

void Block::setPlayer(int player)
{
	this->player = player;
}

void Block::Update()
{
	if (Gmanager.m_GameStart == true)
	{
		if (onoff == true)
		{
			if (blockKind == 4 || blockKind == 5)
			{
				if (GetTickCount() - CloudMoveTime > 10)
				{
					dx -= 2;
					blockx -= 2;
					blockX -= 2;

					if (mapX * 40 + dx < 80)
					{
						dx = (30 - mapX) * 40;
						blockx = 30 * 40;
						blockX = blockx + 80;
						if (blockKind == 5)
							blockX += 40;
					}
					CloudMoveTime = GetTickCount();
				}
			}
		}
	}
}


void Block::Draw()
{
	//fishimg1[m_Acount].SetColor(255, 255, 255, 255); �ȸ���
	//fishimg1[m_Acount].Render(300+(137*5), 100, D3DX_PI/180, -5, 5); // ������ �̹��� ũ�� ��ŭ �̵�

	if (Gmanager.m_GameStart == true)
	{
		if (onoff == true)
		{
			if (blockKind != 4 && blockKind != 5)
			{
				img.Render(mapX * 40, mapY * 34, 0, scale, scale);
			}
			else if (blockKind == 4 || blockKind == 5)
			{
				img.Render(mapX * 40 + dx, mapY * 34, 0, scale, scale);
			}
		}
	}
}

void Block::Floor(int floorY)
{
	//fishimg1[m_Acount].SetColor(255, 255, 255, 255); �ȸ���
	//fishimg1[m_Acount].Render(300+(137*5), 100, D3DX_PI/180, -5, 5); // ������ �̹��� ũ�� ��ŭ �̵�

	if (Gmanager.m_GameStart == true)
	{
		if (onoff == true)
		{
			if (blockKind != 4 && blockKind != 5)
			{
				img.Render(mapX * 40, mapY * 34 + (floorY), 0, scale, scale);
			}
			else if (blockKind == 4 || blockKind == 5)
			{
				img.Render(mapX * 40 + dx, mapY * 34 + (floorY), 0, scale, scale);
			}
		}
		if (floorY >= 204)
		{
			mapY += 6;

			if (blockKind == 8 || blockKind == 9)
			{
				blocky += (6 * 34);					// ��
				blockY += (6 * 34);					// ��
			}
			else
			{
				blocky += (6 * 34);					// ��
				blockY += (6 * 34);					// ��
			}
		}
	}
}