#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
void myputimage(int x0, int y0, IMAGE* img, double f)
{
	//获得图片尺寸
	int qwidth, qheight;
	qwidth = img->getwidth();
	qheight = img->getheight();
	
	
	//P图为背景图,RS为目标图片
	IMAGE RS(qwidth, qheight);
	IMAGE P(qwidth, qheight);
	
	
	//背景图的绘制
	getimage(&P, x0, y0, qwidth, qheight);
	
	
	//获取指针，作为透明度计算
	DWORD* M = GetImageBuffer(&P);
	DWORD* N = GetImageBuffer(img);
	DWORD* R = GetImageBuffer(&RS);
	
	
	// 开启批量绘图模式，解决闪烁问题
	
	
	//计算与赋值
	int i, j;
	for (i = 0; i < qheight; i++) {
		for (j = 0; j < qwidth; j++) {
			int r, g, b;
			int ij;
			//计算
			ij = i*qwidth + j;
			r = (int)((GetRValue(N[ij])) * (1 - f) + GetRValue(M[ij]) * f);
			g = (int)((GetGValue(N[ij])) * (1 - f) + GetGValue(M[ij]) * f);
			b = (int)((GetBValue(N[ij])) * (1 - f) + GetBValue(M[ij]) * f);
			R[ij] = RGB(r, g, b);
		}
	}
	
	
	//贴出图片并释放内存
	putimage(x0, y0, &RS);
	
}


void main()
{
	
	IMAGE a,b;
	loadimage(&a,_T("图片//打工人.jpg"),150,200,true);
	loadimage(&b,_T("图片//考试图3.jpg"),690,532,true);
	initgraph(690,532);
	putimage(0,0,&b);
	myputimage(0,300,&a,0.5);
	getch();
}
