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
	///////////////////������� ����
	seams **E = new seams*[W];
	for(int w=0;w<W;w++)	
		E[w] = new seams[H];
	///////////////////������ �� ���� ����
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
	////////////////�ּҿ�����ã��
	int minx = 0;
	for(int x=0; x<W; x++)
	{
		if(E[minx][H-1].energy>E[x][H-1].energy)
			minx = x;
	}
	///////////////////�ּ� ������ seam ������
	int minxp = minx;
	for(int y=H-1; y>=0; y--)
	{
		cvSet2D(src,y,minxp,cvScalar(0,0,255));
		minxp = E[minxp][y].direct;
	}
	cvShowImage("hw8", src);
	cvWaitKey();
	///////////////////�ּ� ������ seam ����
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
	//////////////////������� ����
	for(int w=0;w<W;w++)
	{
		delete [] E[w];
	}
	delete [] E;
	W--;
}
void seamCarvingY(IplImage* src)
{
	///////////////////������� ����
	seams **E = new seams*[W];
	for(int w=0;w<W;w++)	
		E[w] = new seams[H];
	///////////////////������ �� ���� ����
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
	////////////////�ּҿ�����ã��
	int miny = 0;
	for(int y=0; y<H; y++)
	{
		if(E[W-1][miny].energy>E[W-1][y].energy)
			miny = y;
	}
	///////////////////�ּ� ������ seam ������
	int minyp = miny;
	for(int x=W-1; x>=0; x--)
	{
		cvSet2D(src,minyp,x,cvScalar(0,0,255));
		minyp = E[x][minyp].direct;
	}
	cvShowImage("hw8", src);
	cvWaitKey();
	///////////////////�ּ� ������ seam ����
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
	//////////////////������� ����
	for(int w=0;w<W;w++)
	{
		delete [] E[w];
	}
	delete [] E;
	H--;
}
void imageEnlarging(IplImage* src, int m)
{
	///////////////////������� ����
	seams **E = new seams*[W];
	for(int w=0;w<W;w++)	
		E[w] = new seams[H];
	///////////////////������ �� ���� ����
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
	////////////////�ּҿ����� ã��
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
	///////////////////���õ� seams ������
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
	/////////////////// seams ����
	//k=0~m����
	//y=H-1~0����
	//minx[k]
	//��ĭ�� �и鼭 ��,������,���� ����
	//seam ����
	//if(minx[k]-1�� ����>=minx[k]�� ����) minx[k]-1�� ����+1;


	//////////////////������� ����
	for(int w=0;w<W;w++)
	{
		delete [] E[w];
	}
	delete [] E;
	W--;
}
int main()
{	
	IplImage *src = cvLoadImage("C:\\Users\\�켺\\Desktop\\����\\IMG_20150221_221751_301.jpg");
	
	cvShowImage("window", src);
	H = src->height;
	W = src->width;
	while(true)
	{
		int k = cvWaitKey();
		if(k==27) break;
		if(k==2490368)//��
			seamCarvingY(src);
		else if(k==2621440)//�Ʒ�
			seamCarvingX(src);
		else if(k==2424832)//����
			seamCarvingX(src);
		else if(k==2555904)//������
			seamCarvingX(src);
		
		//int m=50;
		//imageEnlarging(src,m);
		cvShowImage("window", src);
	}
	cvWaitKey();
	
	cvReleaseImage(&src);
	
	return 0;
}
