#pragma once
#include "Include.h"

Key key;

Key::Key(void)
{

	
}

Key::~Key(void)
{
}


void Key::Update()
{




	if(KeyDown('1'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			//map.m_Stage = 1;
			KeyTime = GetTickCount();
		}
	}

	if(KeyDown('2'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			//map.m_Stage = 2;
			KeyTime = GetTickCount();
		}
		
	}

	if(KeyDown('3'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			//Gmanager.m_Collision = true;
			KeyTime = GetTickCount();
		}
		
	}
	
	if(KeyDown('4'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			//monster.Reset();
			KeyTime = GetTickCount();
		}
		
	}

	if(KeyDown('5'))
	{
		if(GetTickCount() - KeyTime > 200)
		{

			KeyTime = GetTickCount();
		}
	
	}
	
	if(KeyDown('6'))
	{
		if(GetTickCount() - KeyTime > 200)
		{

			KeyTime = GetTickCount();
		}
	}



	if(KeyDown('7'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
		
	}



	
	

	if(KeyDown('8'))
	{
		if(GetTickCount() - KeyTime > 200)
		{

		}
		
	}

	if(KeyDown('9'))
	{
		if(GetTickCount() - KeyTime > 200)
		{

			KeyTime = GetTickCount();
		}
		
	}


	if(KeyDown('0'))
	{
		if(GetTickCount() - KeyTime > 200)
		{

			KeyTime = GetTickCount();
		}
		
	}






	if(KeyDown(VK_F1))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F2))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F3))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F4))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F5))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F6))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F7))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
		
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F8))
	{
		if(GetTickCount() - KeyTime > 200)
		{		
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F9))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F10))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F11))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	
	}

	
	if(KeyDown(VK_F12))
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
	
	}

	


	if(KeyDown(VK_SPACE) ) 
	{
		
		if(GetTickCount() - KeyTime2 > 200)
		{
		
			KeyTime2 = GetTickCount();
		}
		
	}



	if(KeyDown(VK_LEFT))
	{
		if(GetTickCount() - KeyTime1 > 10)
		{

			KeyTime1 = GetTickCount();
		}
	}

	if(KeyDown(VK_RIGHT))
	{

		if(GetTickCount() - KeyTime1 > 10)
		{
			KeyTime1 = GetTickCount();
		}
		
	}

	
	if(KeyDown(VK_UP))
	{
		if(GetTickCount() - KeyTime3 > 10)
		{	
			KeyTime3 = GetTickCount();
		}
		
	}

	if(KeyDown(VK_DOWN))
	{

		if(GetTickCount() - KeyTime3 > 10)
		{
			KeyTime3 = GetTickCount();
		}
		
	}


	if(KeyDown('C') )
	{
		if(GetTickCount() - KeyTime1 > 200)
		{	
			KeyTime1 = GetTickCount();
		}
	}




	
	if(KeyDown('N'))
	{
		
		if(GetTickCount() - KeyTime > 200)
		{			
			KeyTime = GetTickCount();
		}
	}

	
	if(KeyDown('A'))
	{
		if(GetTickCount() - KeyTime > 200)
		{
			KeyTime = GetTickCount();
		}
	}




	if(KeyDown('W') )
	{
		if(GetTickCount() - KeyTime > 200)
		{
			
			KeyTime = GetTickCount(); 
		}

	}


	if(KeyDown('E')  )
	{
		if(GetTickCount() - KeyTime > 200)
		{	
			KeyTime = GetTickCount();
		}
		
	}


	if(KeyDown('R') )
	{
		if(GetTickCount() - KeyTime > 200)
		{

			KeyTime = GetTickCount();
		}
	}


	if(KeyDown('S') )
	{
		if(GetTickCount() - KeyTime > 200)
		{
	
			KeyTime = GetTickCount();
		}
	}


	if(KeyDown('D') )
	{
		if(GetTickCount() - KeyTime > 200)
		{
			
			KeyTime = GetTickCount();
		}
	}


	if(KeyDown(VK_RETURN) ) 
	{
		
		if(GetTickCount() - KeyTime1 > 200)
		{

			KeyTime1 = GetTickCount();
		}
		
	}


}