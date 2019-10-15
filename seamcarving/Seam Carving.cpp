#include <opencv2\opencv.hpp>
int H;
int W;
struct seams
{
	int direct;
	float energy;
};
void seamCarvingX(IplImage* src)
{
	///////////////////저장공간 생성
	seams **E = new seams*[W];
	for(int w=0;w<W;w++)	
		E[w] = new seams[H];
	///////////////////에너지 및 방향 저장
	for(int y=0; y<H; y++)
		for(int x=0; x<W; x++)
		{
			float e;
			CvScalar g = cvGet2D(src,y,x);
			CvScalar f1;
			CvScalar f2;

			if(x<W-1&&y<H-1)
			{
				f1 = cvGet2D(src,y,x+1);
				f2 = cvGet2D(src,y+1,x);
			}
			else if(x==W-1&&y!=H-1)
			{
				f1 = cvGet2D(src,y,x-1);
				f2 = cvGet2D(src,y+1,x);
			}
			else if(x!=W-1&&y==H-1)
			{
				f1 = cvGet2D(src,y,x+1);
				f2 = cvGet2D(src,y-1,x);
			}
			else if(x==W-1&&y==H-1)
			{
				f1 = cvGet2D(src,y,x-1);
				f2 = cvGet2D(src,y-1,x);
			}
			float d1 = fabs(f1.val[0]-g.val[0])
						+fabs(f1.val[1]-g.val[1])
						+fabs(f1.val[2]-g.val[2]);
			
			float d2 = fabs(f2.val[0]-g.val[0])
						+fabs(f2.val[1]-g.val[1])
						+fabs(f2.val[2]-g.val[2]);
			
			e = d1 + d2;
			
			float mine = 0;
			if(y!=0)
			{
				if(x!=0&&x!=W-1)
				{
					if(E[x-1][y-1].energy<=E[x][y-1].energy)
					{
						if(E[x-1][y-1].energy<=E[x+1][y-1].energy)
						{
							mine = E[x-1][y-1].energy;
							E[x][y].direct = x-1;
						}
						else
						{
							mine = E[x+1][y-1].energy;
							E[x][y].direct = x+1;
						}
					}
					else
					{
						if(E[x][y-1].energy<=E[x+1][y-1].energy)
						{
							mine = E[x][y-1].energy;
							E[x][y].direct = x;
						}
						else
						{
							mine = E[x+1][y-1].energy;
							E[x][y].direct = x+1;
						}
					}
				}
				else if(x==0)
				{
					if(E[x][y-1].energy<=E[x+1][y-1].energy)
					{
						mine = E[x][y-1].energy;
						E[x][y].direct = x;
					}
					else
					{
						mine = E[x+1][y-1].energy;
						E[x][y].direct = x+1;
					}
				}
				else if(x==W-1)
				{
					if(E[x-1][y-1].energy<=E[x][y-1].energy)
					{
						mine = E[x-1][y-1].energy;
						E[x][y].direct = x-1;
					}
					else
					{
						mine = E[x][y-1].energy;
						E[x][y].direct = x;
					}
				}
			}
			E[x][y].energy = e + mine;
		}
	////////////////최소에너지찾기
	int minx = 0;
	for(int x=0; x<W; x++)
	{
		if(E[minx][H-1].energy>E[x][H-1].energy)
			minx = x;
	}
	///////////////////최소 에너지 seam 보여줌
	int minxp = minx;
	for(int y=H-1; y>=0; y--)
	{
		cvSet2D(src,y,minxp,cvScalar(0,0,255));
		minxp = E[minxp][y].direct;
	}
	cvShowImage("hw8", src);
	cvWaitKey();
	///////////////////최소 에너지 seam 제거
	for(int y=H-1; y>=0; y--)
	{
		for(int x=minx; x<W; x++)
		{
			if(x==W-1)
			{
				cvSet2D(src,y,x,cvScalar(0,0,0));
				continue;
			}
			cvSet2D(src,y,x,cvGet2D(src,y,x+1));
		}
		printf("%f\n",E[minx][y].energy);
		minx = E[minx][y].direct;
	}
	//////////////////저장공간 삭제
	for(int w=0;w<W;w++)
	{
		delete [] E[w];
	}
	delete [] E;
	W--;
}
void seamCarvingY(IplImage* src)
{
	///////////////////저장공간 생성
	seams **E = new seams*[W];
	for(int w=0;w<W;w++)	
		E[w] = new seams[H];
	///////////////////에너지 및 방향 저장
	for(int x=0; x<W; x++)
		for(int y=0; y<H; y++)
		{
			float e;
			CvScalar g = cvGet2D(src,y,x);
			CvScalar f1;
			CvScalar f2;

			if(x<W-1&&y<H-1)
			{
				f1 = cvGet2D(src,y,x+1);
				f2 = cvGet2D(src,y+1,x);
			}
			else if(x==W-1&&y!=H-1)
			{
				f1 = cvGet2D(src,y,x-1);
				f2 = cvGet2D(src,y+1,x);
			}
			else if(x!=W-1&&y==H-1)
			{
				f1 = cvGet2D(src,y,x+1);
				f2 = cvGet2D(src,y-1,x);
			}
			else if(x==W-1&&y==H-1)
			{
				f1 = cvGet2D(src,y,x-1);
				f2 = cvGet2D(src,y-1,x);
			}
			float d1 = fabs(f1.val[0]-g.val[0])
						+fabs(f1.val[1]-g.val[1])
						+fabs(f1.val[2]-g.val[2]);
			
			float d2 = fabs(f2.val[0]-g.val[0])
						+fabs(f2.val[1]-g.val[1])
						+fabs(f2.val[2]-g.val[2]);
			
			e = d1 + d2;
			
			
			float mine = 0;
			if(x!=0)
			{
				if(y!=0&&y!=H-1)
				{
					if(E[x-1][y-1].energy<E[x-1][y].energy)
					{
						if(E[x-1][y-1].energy<E[x-1][y+1].energy)
						{
							mine = E[x-1][y-1].energy;
							E[x][y].direct = y-1;
						}
						else
						{
							mine = E[x-1][y+1].energy;
							E[x][y].direct = y+1;
						}
					}
					else
					{
						if(E[x-1][y].energy<E[x-1][y+1].energy)
						{
							mine = E[x-1][y].energy;
							E[x][y].direct = y;
						}
						else
						{
							mine = E[x-1][y+1].energy;
							E[x][y].direct = y+1;
						}
					}
				}
				else if(y==0)
				{
					if(E[x-1][y].energy<E[x-1][y+1].energy)
					{
						mine = E[x-1][y].energy;
						E[x][y].direct = y;
					}
					else
					{
						mine = E[x-1][y+1].energy;
						E[x][y].direct = y+1;
					}
				}
				else if(y==H-1)
				{
					if(E[x-1][y].energy<E[x-1][y-1].energy)
					{
						mine = E[x-1][y].energy;
						E[x][y].direct = y;
					}
					else
					{
						mine = E[x-1][y-1].energy;
						E[x][y].direct = y-1;
					}
				}
			}
			E[x][y].energy = e + mine;
		}
	////////////////최소에너지찾기
	int miny = 0;
	for(int y=0; y<H; y++)
	{
		if(E[W-1][miny].energy>E[W-1][y].energy)
			miny = y;
	}
	///////////////////최소 에너지 seam 보여줌
	int minyp = miny;
	for(int x=W-1; x>=0; x--)
	{
		cvSet2D(src,minyp,x,cvScalar(0,0,255));
		minyp = E[x][minyp].direct;
	}
	cvShowImage("hw8", src);
	cvWaitKey();
	///////////////////최소 에너지 seam 제거
	for(int x=W-1; x>=0; x--)
	{
		for(int y=miny; y<H; y++)
		{
			if(y==H-1)
			{
				cvSet2D(src,y,x,cvScalar(0,0,0));
				continue;
			}
			cvSet2D(src,y,x,cvGet2D(src,y+1,x));
		}
		miny = E[x][miny].direct;
	}
	//////////////////저장공간 삭제
	for(int w=0;w<W;w++)
	{
		delete [] E[w];
	}
	delete [] E;
	H--;
}
void imageEnlarging(IplImage* src, int m)
{
	///////////////////저장공간 생성
	seams **E = new seams*[W];
	for(int w=0;w<W;w++)	
		E[w] = new seams[H];
	///////////////////에너지 및 방향 저장
	for(int y=0; y<H; y++)
		for(int x=0; x<W; x++)
		{
			float e;
			CvScalar g = cvGet2D(src,y,x);
			CvScalar f1;
			CvScalar f2;

			if(x<W-1&&y<H-1)
			{
				f1 = cvGet2D(src,y,x+1);
				f2 = cvGet2D(src,y+1,x);
			}
			else if(x==W-1&&y!=H-1)
			{
				f1 = cvGet2D(src,y,x-1);
				f2 = cvGet2D(src,y+1,x);
			}
			else if(x!=W-1&&y==H-1)
			{
				f1 = cvGet2D(src,y,x+1);
				f2 = cvGet2D(src,y-1,x);
			}
			else if(x==W-1&&y==H-1)
			{
				f1 = cvGet2D(src,y,x-1);
				f2 = cvGet2D(src,y-1,x);
			}
			float d1 = fabs(f1.val[0]-g.val[0])
						+fabs(f1.val[1]-g.val[1])
						+fabs(f1.val[2]-g.val[2]);
			
			float d2 = fabs(f2.val[0]-g.val[0])
						+fabs(f2.val[1]-g.val[1])
						+fabs(f2.val[2]-g.val[2]);
			
			e = d1 + d2;
			
			
			float mine = 0;
			if(y!=0)
			{
				if(x!=0&&x!=W-1)
				{
					if(E[x-1][y-1].energy<E[x][y-1].energy)
					{
						if(E[x-1][y-1].energy<E[x+1][y-1].energy)
						{
							mine = E[x-1][y-1].energy;
							E[x][y].direct = x-1;
						}
						else
						{
							mine = E[x+1][y-1].energy;
							E[x][y].direct = x+1;
						}
					}
					else
					{
						if(E[x][y-1].energy<E[x+1][y-1].energy)
						{
							mine = E[x][y-1].energy;
							E[x][y].direct = x;
						}
						else
						{
							mine = E[x+1][y-1].energy;
							E[x][y].direct = x+1;
						}
					}
				}
				else if(x==0)
				{
					if(E[x][y-1].energy<E[x+1][y-1].energy)
					{
						mine = E[x][y-1].energy;
						E[x][y].direct = x;
					}
					else
					{
						mine = E[x+1][y-1].energy;
						E[x][y].direct = x+1;
					}
				}
				else if(x==W-1)
				{
					if(E[x-1][y-1].energy<E[x][y-1].energy)
					{
						mine = E[x-1][y-1].energy;
						E[x][y].direct = x-1;
					}
					else
					{
						mine = E[x][y-1].energy;
						E[x][y].direct = x;
					}
				}
			}
			E[x][y].energy = e + mine;
		}
	////////////////최소에너지 찾기
	int minx[50];
	for(int k=0; k<m; k++)
	{
		minx[k] = 0;
		for(int x=0; x<W; x++)
		{
			bool check = true;
			for(int l=0; l<k; l++)
				if(minx[l] == x) check = false;
			if(!check) continue;
			if(E[minx[k]][H-1].energy>E[x][H-1].energy)
				minx[k] = x;
		}
		printf("%d\n",minx[k]);
	}
	///////////////////선택된 seams 보여줌
	int minxp[50];
	for(int k=0; k<m; k++)
	{
		minxp[k] = minx[k];
		for(int y=H-1; y>=0; y--)
		{
			cvSet2D(src,y,minxp[k],cvScalar(0,0,255));
			minxp[k] = E[minxp[k]][y].direct;
		}
	}
	cvShowImage("hw8", src);
	cvWaitKey();
	/////////////////// seams 복사
	//k=0~m까지
	//y=H-1~0까지
	//minx[k]
	//한칸씩 밀면서 색,에너지,방향 저장
	//seam 복사
	//if(minx[k]-1의 방향>=minx[k]의 방향) minx[k]-1의 방향+1;


	//////////////////저장공간 삭제
	for(int w=0;w<W;w++)
	{
		delete [] E[w];
	}
	delete [] E;
	W--;
}
int main()
{	
	IplImage *src = cvLoadImage("C:\\Users\\우성\\Desktop\\사진\\IMG_20150221_221751_301.jpg");
	
	cvShowImage("window", src);
	H = src->height;
	W = src->width;
	while(true)
	{
		int k = cvWaitKey();
		if(k==27) break;
		if(k==2490368)//위
			seamCarvingY(src);
		else if(k==2621440)//아래
			seamCarvingX(src);
		else if(k==2424832)//왼쪽
			seamCarvingX(src);
		else if(k==2555904)//오른쪽
			seamCarvingX(src);
		
		//int m=50;
		//imageEnlarging(src,m);
		cvShowImage("window", src);
	}
	cvWaitKey();
	
	cvReleaseImage(&src);
	
	return 0;
}
