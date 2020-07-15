#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int hongbao1=340,hongbao2,hongbao3;
double hongbao4=5;
void hongbao_huitu();
void hongbao_kongzhi();
void hongbao_xuanhuan();
void hongbao_kongzhi() 
{
	if(GetKeyState(32)&0x8000)
	{
		hongbao2=20;
	}
	if(hongbao2>0)
	{
		hongbao1=hongbao1+hongbao2;
		hongbao2--;
	}
	hongbao1=hongbao1-10;
	hongbao3=(int)(hongbao1-125)/10;
}
void hongbao_huizhi()
{
	IMAGE hongbaobeijing,shou,shou_;
	loadimage(&hongbaobeijing,_T("Í¼Æ¬\\ºì°ü1.jpg"),600,450,true);
	loadimage(&shou,_T("Í¼Æ¬\\ºì°ü2.jpg"),690,200,true);
	loadimage(&shou_,_T("Í¼Æ¬\\ºì°ü3.jpg"),690,200,true);
    BeginBatchDraw();
	putimage(45,80,&hongbaobeijing);
	setfillcolor(BLACK);
	fillrectangle(120,450,580,500);
	 setcolor(BLUE);
	setfillcolor(BLUE);
	fillrectangle(300,450,400,500);

	setcolor(GREEN);
	line(hongbao1,440,hongbao1,510);
	putimage(hongbao3,200,&shou,SRCAND);
	putimage(hongbao3,200,&shou_,SRCPAINT);
	setcolor(BLACK);
	setfillcolor(BLACK);
    fillrectangle(0,200,40,400);
    fillrectangle(645,200,690,400);
	char hongbao4_[20];
	sprintf(hongbao4_,"%.2f",hongbao4);
	setbkmode(TRANSPARENT);
	settextstyle(30, 15, _T("ºÚÌå"));
	outtextxy(320,100,hongbao4_);
	setbkmode(OPAQUE);
    EndBatchDraw();

}
void hongbao_xuanhuan()
{

	
	while(hongbao1>=125 && hongbao1<=575 && hongbao4>0)
	{
		hongbao_kongzhi();
		hongbao_huizhi();
		Sleep(10);
		hongbao4=hongbao4-0.01;
	}

	char hongbaoshengli[20]={"±ÏÀÏÒ¯ÍòËê"};
	char hongbaoshibai[20]={"Òü×ÎÎÄÊÇ¹Â¶ù"};
	setbkcolor(BLACK);
	cleardevice();
	settextcolor(WHITE);
	if(hongbao1>=300 &&hongbao1<=400)
	{
		outtextxy(200,200,hongbaoshengli);
	}
	else outtextxy(200,200,hongbaoshibai);

	char c=0;
	while(c!=27)
	{
		c=getch();
	}

	

}
void shab()
{
	if(GetKeyState(27)&0x8000);
	outtextxy(100,100,"00");
	Sleep(10000);
}

void wanyouxi()
{

		hongbao_xuanhuan();
		shab();

}
void main()
{
	initgraph(690,532);  
	char name[20];
	InputBox(name, 10, "ÊÇ¸öÐ¡ÄÐº¢°¡£¬²»Èç¾Í½Ð","°Ö°Ö°®Äã");
	wanyouxi();
	
}





 







