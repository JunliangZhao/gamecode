#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
void main()
{

	IMAGE background1,person1,person_1,kaichong,shangdian,dudu;
	loadimage(&background1,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\死宅宿舍.jpg",0,0,true);
	loadimage(&person1,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\熊猫人1.jpg",0,0,true);	
    loadimage(&person_1,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\熊猫人1屏蔽图.jpg",0,0,true);
	loadimage(&kaichong,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\开冲.jpg",180,60,true);
	loadimage(&shangdian,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\商店.jpg",120,45,true);
	loadimage(&dudu,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\读读.jpg",120,45,true);
	int width=background1.getwidth();
	int height=background1.getheight();
	char qingshang[20]="情商",
		tuixuelv[20]="退学率",
		srtp[20]="SRTP",
	    yalizhi[20]="压力值",
		zhaizhi[20]="死宅值",
		money[20]="生活费";
	initgraph(width,height);
	putimage(0,0,&background1);
	putimage(0,0,&person_1,SRCPAINT);
	putimage(0,0,&person1,SRCAND);
	putimage(0,450,&kaichong);
	putimage(550,470,&shangdian);
	putimage(550,410,&dudu);
	setcolor(RGB(227,168,105));	
    setfillcolor(RGB(227,168,105));
	fillrectangle(270,400,500,530);
	setcolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(300,515,400,525);
	setfillcolor(RGB(255,0,255));
	solidrectangle(300,515,350,525);
	settextstyle(15, 10, _T("黑体"));    
	settextcolor(WHITE);
	outtextxy(420,515,qingshang);
	setcolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(300,500,400,510);
	setfillcolor(RGB(160,32,240));
	solidrectangle(300,500,350,510);
	settextstyle(15, 10, _T("黑体"));    
	settextcolor(WHITE);
	outtextxy(420,500,zhaizhi);
	setcolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(300,485,400,495);
	setfillcolor(RED);
	solidrectangle(300,485,350,495);
	settextstyle(15, 10, _T("黑体"));    
	settextcolor(WHITE);
	outtextxy(420,485,tuixuelv);
	setcolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(300,470,400,480);
	setfillcolor(GREEN);
	solidrectangle(300,470,350,480);
	settextstyle(15, 10, _T("黑体"));    
	settextcolor(WHITE);
	outtextxy(420,470,yalizhi);
	setcolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(300,455,400,465);
	setfillcolor(BLUE);
	solidrectangle(300,455,350,465);
	settextstyle(15, 10, _T("黑体"));    
	settextcolor(WHITE);
	outtextxy(420,455,srtp);
	

	


	getch();
	
	
	
	
}
