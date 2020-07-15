#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
class jineng
{
public:
	void anpaimian();
	void xuanze();
	void gaoshu();
	void cyuyan();
	void yingyu();
};
void jineng::anpaimian()
{
	initgraph(690,532);
	IMAGE person2,person_2,background1;
	loadimage(&background1,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\死宅宿舍.jpg",0,0,true);
	loadimage(&person2,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\熊猫人2.jpg",180,180,true);
    loadimage(&person_2,"C:\\Users\\zjl\\Desktop\\常规课堂\\c++死宅养成计划\\熊猫人2屏蔽图.jpg",180,180,true);
	putimage(0,0,&background1);
	putimage(20,350,&person_2,SRCPAINT);
	putimage(20,350,&person2,SRCAND);
	setcolor(RGB(238,197,145));
	setfillcolor(RGB(238,197,145));
	fillrectangle(250,10,650,520);
	char anpaimian[20]="时间不多了";
	char anpaimian1[20]="快安排";
	setbkcolor(RGB(238,194,145));
	settextstyle(30, 15, _T("宋体"));    
	settextcolor(BLACK);
	outtextxy(350,20,anpaimian);
	outtextxy(375,50,anpaimian1);


}
void main()
{
	jineng B;
	B.anpaimian();
	getch();
}

	


