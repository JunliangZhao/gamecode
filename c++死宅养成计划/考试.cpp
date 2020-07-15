#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include<string.h>
int tiku_[50];
IMAGE tiku[50];
int timushu=1;
int kaoshifenshu=0;
int i=0;
int randrange(int n)
{
	srand(unsigned(time(0)));
	return rand()%n;
}
void myputimage(int x0, int y0, IMAGE* img, double f)
{
//获得图片尺寸
int qwidth, qheight;
qwidth = img->getwidth();
qheight = img->getheight();


//P图为背景图,RS为目标图片
static IMAGE RS(qwidth, qheight);
static IMAGE P(qwidth, qheight);


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
void jiazaitimu()
{
	setbkmode(TRANSPARENT);


	IMAGE kaoshitu1,kaoshitu2,kaoshitu3;
	loadimage(&tiku[0],_T("题库\\t1.jpg"),300,200,true);
	tiku_[0]=3;
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&kaoshitu2,_T("图片\\考试图2.jpg"),250,300,true);
	loadimage(&kaoshitu1,_T("图片\\考试图1.jpg"),380,300,true);
	putimage(0,0,&kaoshitu3);
	putimage(10,50,&kaoshitu1);
	putimage(30,70,&tiku[0]);
	myputimage(400,50,&kaoshitu2,0.15);
	char timushu_[20],kaoshifenshu_[20];
	settextstyle(20,0,_T("黑体"));
	sprintf(timushu_,"%d",timushu);
	outtextxy(0,10,"已作答");
	outtextxy(70,10,timushu_);
	outtextxy(80,10,"/5");
	outtextxy(120,10,"得分");
	sprintf(kaoshifenshu_,"%d",kaoshifenshu);
	outtextxy(170,10,kaoshifenshu_);



	
}	
int dati()
{
	
	while(true)
	{
	if(GetKeyState(65)&0x8000 || GetKeyState(97)&0x8000)
	{
		return 1;
		break;
	}
	if(GetKeyState(66)&0x8000 || GetKeyState(98)&0x8000)
	{
		return 2;
		break;
	}
	if(GetKeyState(67)&0x8000 || GetKeyState(99)&0x8000)
	{
		return 3;
		break;
	}
	if(GetKeyState(68)&0x8000 || GetKeyState(100)&0x8000)
	{
		return 4;
		break;
	}
	}
}



void zuoti()
{

	jiazaitimu();
	int m;
	m=dati();
    settextstyle(30,0,_T("黑体"));
	setbkmode(TRANSPARENT);
	if(m==1)
	{
		outtextxy(410,60,"你的答案是A");
	}
	if(m==2)
	{
		outtextxy(410,60,"你的答案是B");
	}
	if(m==3)
	{
		outtextxy(410,60,"你的答案是C");
	}
		if(m==4)
	{
		outtextxy(410,60,"你的答案是D");
	}
		Sleep(1000);
	if(m==tiku_[0])
	{
		outtextxy(410,190,"恭喜你答对了");
		Sleep(1000);
		outtextxy(410,300,"真是个小天才呢");
		kaoshifenshu=kaoshifenshu+20;
	}
	else
	{
		outtextxy(410,190,"很遗憾答错了");
		Sleep(1000);
		outtextxy(410,300,"正确答案是：");
		Sleep(1000);
		if(tiku_[0]==1)
		{
			outtextxy(580,300,"A");
		}
		if(tiku_[0]==2)
		{
			outtextxy(580,300,"B");
		}
		if(tiku_[0]==3)
		{
			outtextxy(580,300,"C");
		}
		if(tiku_[0]==4)
		{
			outtextxy(580,300,"D");
		}
	}
	outtextxy(200,500,"按空格键下一题");
}

void kaoshizhong()
{
	initgraph(690,532);
	zuoti();
	
	while(true)
	{
		if(GetKeyState(32)&0x8000)
		{
		    if(timushu==5)
		{
			
			break;
		}

			timushu=randrange(10);
			zuoti();

		}

	}
	IMAGE defen1;
	loadimage(&defen1,_T("图片\\考试图3.jpg"),690,532,true);
	putimage(0,0,&defen1);
	setbkmode(TRANSPARENT);
	char kaoshifenshu_1[20];
	kaoshifenshu=kaoshifenshu;
	sprintf(kaoshifenshu_1,"%d",kaoshifenshu);
	settextcolor(RED);
	settextstyle(30,0,_T("黑体"));
	outtextxy(300,200,kaoshifenshu_1);
	while(true)
	{
		if(GetKeyState(27)&0x8000)
		{
			break;
		}
	}


	


}
void main()
{
	kaoshizhong();


}
			
