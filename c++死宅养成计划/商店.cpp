#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
void main()
{
IMAGE dashangdian;
int wupin[12]={0};
initgraph(690,532);
loadimage(&dashangdian,"图片\\大商店.jpg",690,532,true);
putimage(0,0,&dashangdian);
setcolor(RED);
settextstyle(20,0,_T("宋体"));
wupin[4]=0;
if(wupin[0]==0)
{
outtextxy(360,120,"售空");
}
if(wupin[1]==0)
{
outtextxy(450,120,"售空");
}
if(wupin[2]==0)
{
outtextxy(540,120,"售空");
}
if(wupin[3]==0)
{
outtextxy(630,120,"售空");
}
if(wupin[4]==0)
{
outtextxy(360,250,"售空");
}
if(wupin[5]==0)
{
outtextxy(450,250,"售空");
}
if(wupin[6]==0)
{
outtextxy(540,250,"售空");
}
if(wupin[7]==0)
{
outtextxy(630,250,"售空");
}

if(wupin[8]==0)
{
outtextxy(270,420,"售空");
}
if(wupin[9]==0)
{
outtextxy(350,420,"售空");
}


if(wupin[10]==0)
{
outtextxy(470,420,"售空");
}
if(wupin[11]==0)
{
outtextxy(550,420,"售空");
}
setbkmode(TRANSPARENT);
char a[]={"尼玛必死你"};

	int x=70,y=50;
	settextstyle(20,0,_T("宋体"));
	settextcolor(WHITE);
	for(unsigned i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+25;
		if(b[0]==' '&&b[1]==' ')
		{
			x=x-30;
		}
		else if(b[0]==' '||b[1]==' ')
		{
			x=x-15;
		}
		if(x>220)
		{
			x=70;
			y=y+30;
		}
	}
	clearrectangle(70,50,240,100);
getch();

}