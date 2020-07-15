
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include <mmsystem.h> 
#pragma comment(lib,"Winmm.lib")
# pragma comment(lib, "msimg32.lib")
int tiku_[50];
int xuanti;
IMAGE tiku[50];
int suiji=0;
void jiazaitimu();
int fangchongfu[10]={0};
int fangchong=0;
int dati();
void zuoti();
void kaoshizhong();
void jiemian();
void caozuo();
void shangdian();
void tufashijian();
void anpaimian();
int hongbao1=340,hongbao2=0,hongbao3,	hongbaokaishi=3;
double hongbao4=6;
void hongbao_huitu();
void hongbao_kongzhi();
void hongbao_xuanhuan();
void beijing();
int snm[50][2]={{300,250},{310,250},{320,250},{330,250}};
int snn=4;
int snw=0,snd=0,sna=1,sns=0;
int snp=300,snq=300;

void dian(int ,int);
void dian_(int ,int);
int snfenshu=0;
char snfenshu_[20];
void tanlianai(int n);
void tanlianaixuanhuan();
void xiangqin();
struct xiaojiejie
{
	IMAGE xiaojiejietu;
	char *xiaojiejieming;
	char *xiaojiejiejieshao;
	int success_;
	
	
};

int success;
int chuqianguan=0;

void shiwu()
{
	setbkmode(TRANSPARENT);
	dian(snp,snq);
	settextstyle(30,0,_T("黑体"));
	sprintf(snfenshu_,"%d",snfenshu);
	outtextxy(0,0,snfenshu_);
	srand(unsigned (time(NULL)));
	if((snm[0][0]-snp)*(snm[0][0]-snp)+(snm[0][1]-snq)*(snm[0][1]-snq)<100)
	{
		snfenshu+=10;
		int b[2];
		snn++;
		dian_(snp,snq);
		for(int i=0;i<2;i++)
		{
			b[i]=10*(rand()%19+1)+200;
		}
		snp=b[0];
		snq=b[1];
	}
}



void dian(int x,int y)
{
	setcolor(GREEN);
	setfillcolor(GREEN);
	fillrectangle(x-5,y-5,x+5,y+5);
}
void dian_(int x,int y)
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillrectangle(x-5,y-5,x+5,y+5);
}
void snkongzhi()
{
	char c;
	if(kbhit())
	{
		
		c=getch();
		
		if((c=='w'||c=='W') && sns==0)
		{
			snw=1;
			snd=0;
			sns=0;
			sna=0;
		}
		if((c=='s'||c=='S')&& snw==0)
		{
			snw=0;
			snd=0;
			sns=1;
			sna=0;
		}
		if((c=='A'||c=='a') && snd==0)
		{
			snw=0;
			snd=0;
			sns=0;
			sna=1;
		}
		if((c=='D'||c=='d') && sna==0)
		{
			snw=0;
			snd=1;
			sns=0;
			sna=0;
		}
	}
	
}
void snxuanhuan()
{
	IMAGE background1;
	loadimage(&background1,_T("图片//死宅宿舍.jpg"),690,532,true);
	putimage(0,0,&background1);
	setcolor(WHITE);
	setfillcolor(BLACK);
	fillrectangle(200,200,400,400);
	for(int l=0;l<snn;l++)
	{
		dian(snm[l][0],snm[l][1]);
	}
	Sleep(1000);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	
	int sng=1;
	
	while (snm[0][1]<=395 &&snm[0][1]>=205 &&snm[0][0]<=395 &&snm[0][0]>=205 && sng)
	{
		if(snn>=14)
		{
			break;
		}
		for(int i=0;i<snn;i++)
		{
			snm[snn-i][0]=snm[snn-i-1][0];
			snm[snn-i][1]=snm[snn-i-1][1];
			
		}
		
		
		
		snkongzhi();
		
		
		
		if(snw==1)
		{
			snm[0][1]=snm[0][1]-10;
		}
		if(sns==1)
		{
			snm[0][1]=snm[0][1]+10;
		}
		if(sna==1)
		{
			snm[0][0]=snm[0][0]-10;
		}
		if(snd==1)
		{
			snm[0][0]=snm[0][0]+10;
		}
		
		for(int sno=1;sno<snn;sno++)
		{
			
			int snt;
			snt=(snm[0][0]-snm[sno][0])*(snm[0][0]-snm[sno][0])+(snm[0][1]-snm[sno][1])*(snm[0][1]-snm[sno][1]);
			if(snt<100)
			{
				sng=0;
				break;
				
				
				
			}
		}
		
		
		
        BeginBatchDraw();
		putimage(0,0,&background1);
		setcolor(WHITE);
		setfillcolor(BLACK);
		fillrectangle(200,200,400,400);
		
		
		
		
		shiwu();
		
		
		for(int k=0;k<snn;k++)
		{
			dian(snm[k][0],snm[k][1]);
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		Sleep(100);
		FlushBatchDraw();
		
		cleardevice();
		
		
		
	}
	EndBatchDraw();
	
	
	
}
void rputimage(int x0, int y0, IMAGE* img)
{
	//获得图片尺寸
	int qwidth, qheight;
	qwidth = img->getwidth();
	qheight = img->getheight();
	
	
	//P图为背景图,RS为目标图片
	IMAGE RS(qwidth, qheight);
	
	
	//获取指针，作为透明度计算
	DWORD* M = GetImageBuffer(img);
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
			if((int)GetRValue(M[ij])==255 && (int)GetGValue(M[ij])==255 && (int)GetBValue(M[ij])==255)
			{
				r=0;
				g=0;
				b=0;
			}
			else
			{
				r=255;
				b=255;
				g=255;
			}
			R[ij] = RGB(r, g, b);
		}
	}
	
	
	//贴出图片并释放内存
	putimage(x0, y0, &RS,SRCPAINT);
	putimage(x0,y0,img,SRCAND);
}

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
void zimu(char *p,char *q)
{
	setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(30,0,_T("宋体"));
	outtextxy(60,325,q);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("宋体"));
	settextcolor(BLACK);
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		if(kbhit())
		{
			break;
		}
		
	}
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	settextcolor(WHITE);
	settextstyle(30,0,_T("宋体"));
	outtextxy(60,325,q);
	x=100,y=370;
	settextstyle(20,0,_T("宋体"));
	settextcolor(BLACK);
	for( i=0;i<strlen(a);i++)
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
	}
	
	
}
void zimu3(char *p,char *q)
{
		setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(30,0,_T("宋体"));
	outtextxy(60,325,q);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("宋体"));
	settextcolor(BLACK);
	for(unsigned i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+25;
		if(b[0]=='.'&&b[1]=='.')
		{
			x=x-30;
		}
		else if(b[0]=='.'||b[1]=='.')
		{
			x=x-15;
		}
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		if(kbhit())
		{
			break;
		}
		
	}
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	settextcolor(WHITE);
	settextstyle(30,0,_T("宋体"));
	outtextxy(60,325,q);
	x=100,y=370;
	settextstyle(20,0,_T("宋体"));
	settextcolor(BLACK);
	for( i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+25;
		if(b[0]=='.'&&b[1]=='.')
		{
			x=x-30;
		}
		else if(b[0]=='.'||b[1]=='.')
		{
			x=x-15;
		}
		if(x>550)
		{
			x=100;
			y=y+30;
		}
	}
	
	
}
void zimu1(char *p)
{
		setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	
	setbkmode(TRANSPARENT);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("宋体"));
	settextcolor(BLACK);
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		if(kbhit())
		{
			break;
		}
		
	}
	x=100,y=370;
	
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	settextstyle(20,0,_T("宋体"));
	settextcolor(BLACK);
	for( i=0;i<strlen(a);i++)
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
	}
	
	
	
	
}
void zimu2(char *p,char *q)
{
		setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(30,0,_T("宋体"));
	outtextxy(60,325,q);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("宋体"));
	settextcolor(BLACK);
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		
		
	}
	
	
}
int randrange(int n)
{
	srand(unsigned(time(0)));
	return rand()%n;
}

int key(char anjian)
{
	char anjianzhi;
	if(kbhit())
	{
		anjianzhi=getch();
		if(anjianzhi==anjian)
		{
			return 1;
		}
		else return 0;
		
	}
	else return 0;
}



int h=30;
int timushu=1;
int kaoshifenshu=0;

class sizhai
{
	char name[20];
	
public:
	int tui,zhai,qing,ya,srtp,money;
	sizhai(int a=0,int b=0,int c=0,int d=0,int e=0,int f=500)
	{
		tui=a;
		zhai=b;
		qing=c;
		ya=d;
        srtp=e;
		money=f;
	}
	void getname(char*Name)
	{
		strcpy(name,Name);
	}
	char *returnname()
	{
		return name;
	}
	
	
};
class jineng
{	
	char gaoshu[20];
	char yingyu[20];
	char cyuyan[20];
public:
	int gaoshudengji,gaoshushu;
	int cyuyandengji,cyuyanshu;
    int yingyudengji,yingyushu;
	jineng()
	{
		gaoshudengji=0;
		gaoshushu=0;
		cyuyandengji=0;
		cyuyanshu=0;
		yingyudengji=0;
		yingyushu=0;
	}
	void anpaimian();
	void shengji();
	char *returngaoshu()//高数
	{
		return gaoshu;
	}
	void getgaoshu(char *gaoshu_1)
	{
		strcpy(gaoshu,gaoshu_1);
	}
	char *returncyuyan()//c语言
	{
		return cyuyan;
	}
	void getcyuyan(char *cyuyan_1)
	{
		strcpy(cyuyan,cyuyan_1);
	}
	char *returnyingyu()//英语
	{
		return yingyu;
	}
	void getyingyu(char *yingyu_1)
	{
		strcpy(yingyu,yingyu_1);
	}
	
};
class dashangdian
{
public:
	int wupin[12];
	dashangdian()
	{
		for(int i=0;i<12;i++)
		{
			wupin[i]=1;
		}
	}
	
	void	shangdianchushihua()
	{
		for(int i=0;i<12;i++)
		{
			wupin[i]=1;
		}
	}
	void huizhihang(int a)
	{
		IMAGE dashangdian,dashangdian1,dashangdian2,dashangdian3;
		loadimage(&dashangdian,_T("图片//大商店.jpg"),690,532,true);
		loadimage(&dashangdian1,_T("图片//大商店1.jpg"),690,532,true);
		loadimage(&dashangdian2,_T("图片//大商店2.jpg"),690,532,true);
		loadimage(&dashangdian3,_T("图片//大商店3.jpg"),690,532,true);
		if(a==0)
		{
			putimage(0,0,&dashangdian);
		}
		if(a==1)
		{
			putimage(0,0,&dashangdian1);
		}
        if(a==2)
		{
			putimage(0,0,&dashangdian2);
		}
		if(a==3)
		{
			putimage(0,0,&dashangdian3);
		}
		
	}
	void shoukong()
	{
		setbkmode(OPAQUE);
		setcolor(RED);
		settextstyle(20,0,_T("宋体"));
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
		
	}
	void shuoming(char *p)
	{
		char a[200]={'0'};
		strcpy(a,p);
		setbkmode(TRANSPARENT);
		
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
	}
	
};


jineng B;

sizhai A;
dashangdian C;
void myshangdian()
{
	cleardevice();
	
	
	
	while(true)
	{
		C.huizhihang(0);
		C.shoukong();
		
		char c=0,c1=0,c2=0;
		c=getch();
		C.shoukong();
		C.shoukong();
		if(c==27)
		{
			break;
		}
		if(c=='1')
		{
			C.huizhihang(1);
			C.shoukong();
			C.shuoming("请选择1 ，2 ，3 ，4");
			while(c1!=27)
			{
				c1=getch();
				if(c1=='1'&&C.wupin[0]==1)			
				{
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("肥宅快乐水，天天快乐减压（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=5)
							{
								A.money-=5;
								C.wupin[0]=0;
								A.ya-=3;
								if(A.ya<0)
								{
									A.ya=0;
								}
								zimu1("压力值-3");
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='1'&&C.wupin[0]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='2'&&C.wupin[1]==1)			
				{
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("辣条一时爽，一直辣条一直爽减压良品（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=8)
							{
								A.money-=8;
								C.wupin[1]=0;
								zimu1("压力值-4");
								A.ya-=4;
								if(A.ya<0)
								{
									A.ya=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='2'&&C.wupin[1]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='3'&&C.wupin[2]==1)			
				{
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("熬夜通宵必备良品，吃了十分快乐（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=12)
							{
								A.money-=12;
								C.wupin[2]=0;
								zimu1("压力值-5");
								A.ya-=5;
								if(A.ya<0)
								{
									A.ya=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='3'&&C.wupin[2]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='4'&&C.wupin[3]==1)			
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("给父母买张贺卡吧，他们会很开心的（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=15)
							{
								A.money-=15;
								C.wupin[3]=0;
								zimu1("情商+2");
								A.qing+=2;
								if(A.qing>100)
								{
									A.qing=100;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='4'&&C.wupin[3]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				
				
				
				
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		else	if(c=='2')
		{
			C.huizhihang(2);
			C.shoukong();
			C.shuoming("请选择1 ，2 ，3 ，4");
			while(c1!=27)
			{
				c1=getch();
				if(c1=='1'&&C.wupin[4]==1)			
				{
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("有新买的耳机，音质好，听起来心情都好（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=50)
							{
								A.money-=50;
								C.wupin[4]=0;
								A.ya-=10;
								if(A.ya<0)
								{
									A.ya=0;
								}
								zimu1("压力值-10");
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='1'&&C.wupin[4]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='2'&&C.wupin[5]==1)			
				{
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("买了手办会很开心，但是同时也会加死宅值（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=60)
							{
								A.money-=60;
								C.wupin[5]=0;
								zimu1("压力值-15 ，死宅值+10");
								A.ya-=15;
								if(A.ya<0)
								{
									A.ya=0;
								}
								if(A.zhai>100)
								{
									A.zhai=100;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='2'&&C.wupin[5]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='3'&&C.wupin[6]==1)			
				{
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("新买了学习用品，可以减少退学率（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=30)
							{
								A.money-=30;
								C.wupin[6]=0;
								zimu1("退学率-7");
								A.ya-=5;
								if(A.tui<0)
								{
									A.tui=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='3'&&C.wupin[6]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='4'&&C.wupin[7]==1)			
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("东南小题是本备考好书，但是会有点难（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=60)
							{
								A.money-=60;
								C.wupin[7]=0;
								zimu1("退学率-15 ，压力+10");
								A.qing+=7;
								if(A.ya>100)
								{
									A.ya=100;
								}
								if(A.tui<0)
								{
									A.tui=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='4'&&C.wupin[7]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				
				
				
				
			}
		}
		
		
		
		
		
		
		
		
		
		
		else if(c=='3')
		{
			C.huizhihang(3);
			C.shoukong();
			C.shuoming("请选择1 ，2 ，3 ，4");
			while(c1!=27)
			{
				c1=getch();
				if(c1=='1'&&C.wupin[8]==1)			
				{
					
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("一入吃鸡深似海，大大减少压力也会增加退学率，慎用（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=98)
							{
								A.money-=98;
								C.wupin[8]=0;
								A.ya-=25;
								A.tui+=15;
								if(A.ya<0)
								{
									A.ya=0;
								}
								if(A.tui>100)
								{
									A.tui=100;
								}
								zimu1("压力值-25 ，退学率+15");
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='1'&&C.wupin[8]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='2'&&C.wupin[9]==1)			
				{
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("参加校级艺术表演，可获得大量SRTP（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=300)
							{
								A.money-=300;
								C.wupin[9]=0;
								zimu1("SRTP+15");
								A.srtp+=15;
								
								if(A.srtp>100)
								{
									A.srtp=100;
								}
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='2'&&C.wupin[9]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='3'&&C.wupin[10]==1)			
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("说话是门艺术，学会说话你懂的（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=100)
							{
								A.money-=100;
								C.wupin[10]=0;
								zimu1("SRTP+3，情商+3");
								A.srtp+=3;
								A.qing+=3;
								if(A.qing>100)
								{
									A.qing=100;
								}
								if(A.srtp>100)
								{
									A.srtp=100;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='3'&&C.wupin[10]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='4'&&C.wupin[11]==1)			
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("购买它将会拥有源源不断的生活费（按Y 购买，按N 取消）");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=200)
							{
								A.money-=200;
								C.wupin[11]=0;
								zimu1("存钱罐个数+1");
								chuqianguan++;
								
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("钱不够，请及时充值");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='4'&&C.wupin[11]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("已售空");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				
				
				
				
			}
		}
		
		
		
	}
	
	
	
	
	
	cleardevice();
	jiemian();
	
	
}



void jiazaitimu()
{
	setbkmode(TRANSPARENT);
    
	
	IMAGE kaoshitu1,kaoshitu2,kaoshitu3;
	loadimage(&tiku[0],_T("题库\\t1.jpg"),300,200,true);
	tiku_[0]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[1],_T("题库\\t2.jpg"),300,200,true);
	tiku_[1]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[2],_T("题库\\t3.jpg"),300,200,true);
	tiku_[2]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[3],_T("题库\\t4.jpg"),300,200,true);
	tiku_[3]=1;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[4],_T("题库\\t5.jpg"),300,200,true);
	tiku_[4]=3;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[5],_T("题库\\t6.jpg"),300,200,true);
	tiku_[5]=4;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[6],_T("题库\\t7.jpg"),300,200,true);
	tiku_[6]=1;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[7],_T("题库\\t8.jpg"),300,200,true);
	tiku_[7]=4;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[8],_T("题库\\t9.jpg"),300,200,true);
	tiku_[8]=4;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[9],_T("题库\\t10.jpg"),300,200,true);
	tiku_[9]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[10],_T("题库\\t11.jpg"),300,200,true);
	tiku_[10]=4;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[11],_T("题库\\t12.jpg"),300,200,true);
	tiku_[11]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[12],_T("题库\\t13.jpg"),300,200,true);
	tiku_[12]=1;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[13],_T("题库\\t14.jpg"),300,200,true);
	tiku_[13]=4;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[14],_T("题库\\t15.jpg"),300,200,true);
	tiku_[14]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[15],_T("题库\\t16.jpg"),300,200,true);
	tiku_[15]=4;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[16],_T("题库\\t17.jpg"),300,200,true);
	tiku_[16]=1;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[17],_T("题库\\t18.jpg"),300,200,true);
	tiku_[17]=3;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[18],_T("题库\\t19.jpg"),300,200,true);
	tiku_[18]=3;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[19],_T("题库\\t20.jpg"),300,200,true);
	tiku_[19]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[20],_T("题库\\t21.jpg"),300,200,true);
	tiku_[20]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[21],_T("题库\\t22.jpg"),300,200,true);
	tiku_[21]=1;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[22],_T("题库\\t23.jpg"),300,200,true);
	tiku_[22]=1;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[23],_T("题库\\t24.jpg"),300,200,true);
	tiku_[23]=2;   //A填1，B填2, C填3, D填4
	
	loadimage(&tiku[24],_T("题库\\t25.jpg"),300,200,true);
	tiku_[24]=2;   //A填1，B填2, C填3, D填4
	
label:xuanti=randrange(25);
	  for(int i=0;i<10;i++)
	  {
		  if(xuanti+1==fangchongfu[i]+1)
		  {
			  goto label;
		  }
		  
	  }
	  fangchongfu[fangchong]=xuanti;
	  fangchong++;
	  loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	  loadimage(&kaoshitu2,_T("图片\\考试图2.jpg"),250,300,true);
	  loadimage(&kaoshitu1,_T("图片\\考试图1.jpg"),380,300,true);
	  putimage(0,0,&kaoshitu3);
	  putimage(10,50,&kaoshitu1);
	  putimage(30,70,&tiku[xuanti]);
	  myputimage(400,50,&kaoshitu2,0.15);
	  char timushu_[20],kaoshifenshu_[20];
	  settextcolor(WHITE);
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
	char c;
	while(true)
	{
		c=getch();
		if(c=='a' || c=='A')
		{
			return 1;
			break;
		}
		if(c=='b'||c=='B')
		{
			return 2;
			break;
		}
		if(c=='c'||c=='C')
		{
			return 3;
			break;
		}
		if(c=='d'||c=='D')
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
	if(m==tiku_[xuanti])
	{
		outtextxy(410,190,"恭喜你答对了");
		Sleep(1000);
		outtextxy(410,300,"真是个小天才呢");
		kaoshifenshu=kaoshifenshu+20;
	}
	else
	{
		outtextxy(410,190,"很遗憾答错了");
		Sleep(500);
		outtextxy(410,300,"正确答案是：");
		Sleep(500);
		if(tiku_[xuanti]==1)
		{
			outtextxy(580,300,"A");
		}
		if(tiku_[xuanti]==2)
		{
			outtextxy(580,300,"B");
		}
		if(tiku_[xuanti]==3)
		{
			outtextxy(580,300,"C");
		}
		if(tiku_[xuanti]==4)
		{
			outtextxy(580,300,"D");
		}
	}
	outtextxy(200,500,"按空格键下一题");
}

void kaoshizhong()
{
	mciSendString(TEXT("stop mysong "),NULL,0,NULL);
	mciSendString(TEXT("open bgm\\考试音乐.mp3 alias mysong1"),NULL,0,NULL);
	mciSendString(TEXT("play mysong1 repeat"),NULL,0,NULL);
	
	
	
	char c;
	zuoti();
	
	while(true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		c=getch();
		if(c==' ')
		{
			if(timushu==5)
			{
				
				break;
			}
			
			timushu++;
			zuoti();
		}
		
	}
	
	
	
	mciSendString(TEXT("close mysong1 "),NULL,0,NULL);
	mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	IMAGE defen1,kaojuan;
	loadimage(&kaojuan,_T("图片\\考卷.jpg"),250,300,true);
	loadimage(&defen1,_T("图片\\考试图3.jpg"),690,532,true);
	putimage(0,0,&defen1);
	setbkmode(TRANSPARENT);
	char kaoshifenshu_1[20];
	sprintf(kaoshifenshu_1,"%d",kaoshifenshu);
	settextcolor(RED);
	settextstyle(30,0,_T("宋体"));
	putimage(100,180,&kaojuan);
	outtextxy(300,200,kaoshifenshu_1);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	
	
	
}
void qizhongkao()
{
	IMAGE kaoshitu3,person2,person_2;
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
	loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	
	char a[]={"这么快就要期中考了吗"};
	char b[]={"都还没预习呢，好慌啊！"};
	char c[]={"要不翘掉考试，（按Y 开始考试，按N 翘掉考试）"};
	char d=0;
	char e[]={"退学率+20 ，压力值+20"};
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(b,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(c,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	while(true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
		d=getch();
		if(d=='y'||d=='Y'||d=='n'||d=='N')
		{
			break;
		}
	}
	if(d=='y'||d=='Y')
				{
		kaoshizhong();
				}
	else 
				{
		putimage(0,0,&kaoshitu3);
		zimu1(e);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.tui+=20;
		A.ya+=20;
		if(A.tui>100)
		{
			A.tui=100;
		}
		if(A.ya>100)
		{
			A.ya=100;
		}
		kaoshifenshu--;
				}
	if(kaoshifenshu<60 && kaoshifenshu>=0)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("退学率+15 ，压力值+15");
		
		A.tui+=15;
		A.ya+=15;
	}
	if(A.tui>100)
	{
		A.tui=100;
	}
	if(A.ya>100)
	{
		A.ya=100;
	}
	if(kaoshifenshu==60)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("退学率-5，压力值-5");
		A.ya-=5;
		A.tui-=5;
	}
	if(kaoshifenshu==80)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("退学率-10 ，压力值-10");
		A.ya-=10;
		A.tui-=10;
	}
	if(kaoshifenshu==100)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("退学率-20 ，压力值-20");
		A.ya-=20;
		A.tui-=20;
	}
	if(A.tui<0)
	{
		A.tui=0;
	}
	if(A.ya<0)
	{
		A.ya=0;
		
	}
	
	timushu=1;
	kaoshifenshu=0;
				
				
				
}
void qimokao()
{
	IMAGE kaoshitu3,person2,person_2;
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
	loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	char a[]={"也许这一次考完，四年也就结束了"};
	char b[]={"好快呀，未来的路该怎么走，我还是十分迷茫"};
	char c[]={"现在也许该给自己的四年交出一份满意的答卷了"};
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(b,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(c,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	kaoshizhong();
				if(kaoshifenshu<60 && kaoshifenshu>=0)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("退学率+15 ，压力值+15");
					
					A.tui+=15;
					A.ya+=15;
				}
				if(A.tui>100)
				{
					A.tui=100;
				}
				if(A.ya>100)
				{
					A.ya=100;
				}
				if(kaoshifenshu==60)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("退学率-5，压力值-5");
					A.ya-=5;
					A.tui-=5;
				}
				if(kaoshifenshu==80)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("退学率-10 ，压力值-10");
					A.ya-=10;
					A.tui-=10;
				}
				if(kaoshifenshu==100)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("退学率-20 ，压力值-20");
					A.ya-=20;
					A.tui-=20;
				}
				if(A.tui<0)
				{
					A.tui=0;
				}
				if(A.ya<0)
				{
					A.ya=0;
					
				}
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				
				
}





void hongbao_kongzhi() 
{
	char c;
	if(kbhit())
	{
		c=getch();
		if(c==' ')
			hongbao2=20;
	}
	if(hongbao2>0 &&hongbaokaishi==-1)
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
	loadimage(&hongbaobeijing,_T("图片\\红包1.jpg"),600,450,true);
	loadimage(&shou,_T("图片\\红包2.jpg"),690,200,true);
	loadimage(&shou_,_T("图片\\红包3.jpg"),690,200,true);
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
	settextstyle(30, 15, _T("黑体"));
	outtextxy(320,100,hongbao4_);
	char a[]={"收下吧，这是阿姨鼓励"};
	char c[]={"你好好学习的"};
	char b[]={"不不不，阿姨我不能要"};
	setcolor(WHITE);
	setfillcolor(WHITE);
	settextstyle(15,0, _T("宋体"));
	settextcolor(BLACK);
	fillellipse(50,170,220,270);
	fillellipse(450,170,620,270);
	outtextxy(60,220,b);
	outtextxy(460,200,a);
	outtextxy(470,240,c);
	
	setbkmode(OPAQUE);
    if(hongbao1>=125 && hongbao1<=575 && hongbao4>0.01)
	{
		FlushBatchDraw();
	}
	else EndBatchDraw();
	
	
}

void hongbao_xuanhuan()
{
	
	setbkcolor(BLACK);
	cleardevice();
	char hongbaokaishi_[20];
	
	for(int i=0;i<4;i++)
	{
		
		sprintf(hongbaokaishi_,"%d",hongbaokaishi);
		hongbao_huizhi();
		settextcolor(WHITE);
		settextstyle(60,0, _T("黑体"));
		outtextxy(320,0,hongbaokaishi_);
		Sleep(1000);
		
		hongbaokaishi--;
	}
	cleardevice();
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
	while(hongbao1>=125 && hongbao1<=575 && hongbao4>0 )
	{
		hongbao_kongzhi();
		hongbao_huizhi();
		Sleep(10);
		hongbao4=hongbao4-0.01;
	}
	mciSendString(TEXT("close mysong1 "),NULL,0,NULL);
	
	settextstyle(30,0,_T("宋体"));
	
	setbkcolor(BLACK);
	cleardevice();
	settextcolor(WHITE);
	if(hongbao1>=300 &&hongbao1<=400)
	{
		outtextxy(200,200,"阿姨，那我收下了");
		A.money=A.money+1000;
		outtextxy(200,450,"按ESC键退出");
		
	}
	else
	{
		
		outtextxy(200,200,A.returnname());
		outtextxy(200,230,"懂事了，钱阿姨先保管着");
		outtextxy(200,450,"按ESC键退出");
	}
	
	char c=0;
	while(c!=27)
	{
		c=getch();
	}
	mciSendString(TEXT("open bgm\\背景音乐.mp3 alias mysong"),NULL,0,NULL);
    mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	
	jiemian();
}
void hongbaolai()
{
	
	IMAGE xiaoyuan,person2,person_2,ayi,ayi_;
	loadimage(&xiaoyuan,_T("图片\\校园.jpg"),690,532,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&ayi,_T("图片\\阿姨.jpg"),180,180,true);
	loadimage(&ayi_,_T("图片\\阿姨屏蔽图.jpg"),180,180,true);
	char a[]={"阿姨来看你了，最近在学校还适应吗，表现好不好"};
	char b[]={"哦哦哦，阿姨好，我带你到学校逛逛"};
	char c[]={"看阿姨给你带来了什么"};
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&ayi_,SRCPAINT);
	putimage(20,170,&ayi,SRCAND);
	zimu(A.returnname(),"阿姨");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&ayi_,SRCPAINT);
	putimage(20,170,&ayi,SRCAND);
	zimu(a,"阿姨");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	zimu(b,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&ayi_,SRCPAINT);
	putimage(20,170,&ayi,SRCAND);
	zimu(c,"阿姨");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	mciSendString(TEXT("stop mysong "),NULL,0,NULL);
	mciSendString(TEXT("open bgm\\抢红包.mp3 alias mysong1"),NULL,0,NULL);
	mciSendString(TEXT("play mysong1 repeat"),NULL,0,NULL);
	
	hongbao_xuanhuan();
	
	
}

void wanyouxi()
{
	IMAGE background1,jiyou,person2,person_2;
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&jiyou,_T("图片\\基友.jpg"),180,180,true);
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("憋读了，快来帮我过这一关","基友");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	zimu("。。。。。。。（按Y 接受，按N 拒绝）",A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	char c;
	while(true)
	{
		c=getch();
		if(c=='Y'||c=='y')
		{
			zimu1("获得100 分即可");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
            getch();
			snxuanhuan();
			if(snn>=14)
			{
				putimage(0,0,&background1);
				rputimage(20,170,&jiyou);
				zimu("真不愧是我的好蛇友，牛牛","基友");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&background1);
				zimu1("情商+10 ，压力-20");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.qing+=10;
				A.ya-=20;
				if(A.qing>100)
				{
					A.qing=100;
				}
				if(A.ya<0)
				{
					A.ya=0;
				}
				
			}
			else 
			{
				putimage(0,0,&background1);
				rputimage(20,170,&jiyou);
				zimu("平常读多了，有点小菜呀","基友");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				
			}
			break;
			
		}
		else if (c=='N'||c=='n')
		{
			putimage(0,0,&background1);
			rputimage(20,170,&jiyou);
			zimu("不跟偷读狗玩了","基友");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background1);
			zimu1("情商-10");
			
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.qing-=10;
			if(A.qing<0)
			{
				A.qing=0;
			}
			
			
			
		}
	}
	
	
	
}
void gaoshud(int n)
{	
	IMAGE kaoshitu3,background1,person2,person_2,person3,person_3,wenjingmeizi;
    loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&person3,_T("图片\\熊猫人3.jpg"),180,180,true);
	loadimage(&person_3,_T("图片\\熊猫人3屏蔽图.jpg"),180,180,true);
	loadimage(&wenjingmeizi,_T("图片\\文静妹子.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"学了一天的高数后，发现整本书都被学完了，觉得每个定理都太简单了"};
		char b[]={"（高喊着）太简单了，我要满绩了，传说中的高数就这点水平吗？可以碾压所有题目了"};
		char c[]={"月考睡过头而错过考试"};
		char d[]={"退学率+15 ，压力值+15"};
        putimage(0,0,&background1);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+15;
		A.tui=A.tui+15;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
		
		
	}
	else if(n==1)
	{
		char a[]={"看似在学习，实则一直玩手机，水过了一天"};
		char b[]={"死宅值+5"};
		putimage(0,0,&background1);
		putimage(200,100,&person_3,SRCPAINT);
		putimage(200,100,&person3,SRCAND);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.zhai+=5;
		if(A.zhai>100)
		{
			A.zhai=100;
		}
	}
	else if(n==2)
	{
		char a[]={"刷了一天的题了，每题都用10种方法做出来"};
		char b[]={"压力值+5，退学率-5"};
		putimage(0,0,&background1);
		putimage(200,100,&person_2,SRCPAINT);
		putimage(200,100,&person2,SRCAND);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	else 
	{
		char a[]={"小哥哥，小哥哥，这道题怎么做鸭"};
		char b[]={"这题鸭，好呀，我教你鸭"};
		char c[]={"。。。。。。"};
		char d[]={"懂了吗？"};
		char e[]={"我再想想。。。。。。好像懂了"};
		char f[]={"情商+15 ，压力值-5"};
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&wenjingmeizi);
		zimu(a,"？？？");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&wenjingmeizi);
		zimu(c,"？？？");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(d,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&wenjingmeizi);
		zimu(e,"？？？");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(f);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya-=5;
		A.qing+=15;
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.qing>100)
		{
			A.qing=100;
		}
		
	}
	
}
void gaoshub(int n)
{
	IMAGE laoshi,kaoshitu3,person2,person_2,jimi,tushuguan,person3,person_3;
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&laoshi,_T("图片\\老师.jpg"),180,180,true);
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&tushuguan,_T("图片\\图书馆.jpg"),690,532,true);
	loadimage(&jimi,_T("图片\\吉米多维奇.jpg"),180,180,true);
	loadimage(&person3,_T("图片\\熊猫人3.jpg"),180,180,true);
	loadimage(&person_3,_T("图片\\熊猫人3屏蔽图.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"你看看，交的都是什么作业，这是什么鬼画弧"};
		char b[]={"这个，这个是不小心睡着画到的"};
		char c[]={"还狡辩，平时分没有了"};
		char d[]={"。。。。。。。。。"};
		char e[]={"退学率+5，压力值+15"};
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(a,"老师");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(c,"老师");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(d,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(e);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
		
		
		
	}
	else if(n==1)
	{
		char a[]={"自学完了高数B ，试着去刷吉米多维奇，突然感觉自己好菜"};
		char b[]={"压力值+15 ，退学率-10"};
		putimage(0,0,&tushuguan);
		putimage(20,170,&jimi);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui-=10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	else if(n==2)
	{
		char a[]={"期中考快到了，发现自己还有好多没有预习的知识点"};
		char b[]={"压力值+15 ，退学率-5"};
		putimage(0,0,&kaoshitu3);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
		
	}
	else 
	{
		char a[]={"在教室读书，看似在学习，实则一直玩手机，水过了一天"};
		char b[]={"死宅值+10"};
		putimage(0,0,&kaoshitu3);
		putimage(200,100,&person_3,SRCPAINT);
		putimage(200,100,&person3,SRCAND);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.zhai+=10;
		if(A.zhai>100)
		{
			A.zhai=100;
		}
		
		
		
	}
	
}
void gaoshua(int n)
{
	IMAGE tushuguan,fubian1,fubian,fubian2,fubian3,xueximeizi;
	loadimage(&tushuguan,_T("图片\\图书馆.jpg"),690,532,true);
	loadimage(&fubian1,_T("图片\\复变函数1.jpg"),150,150,true);
	loadimage(&fubian,_T("图片\\复变函数.jpg"),150,150,true);
	loadimage(&fubian2,_T("图片\\复变2.jpg"),150,150,true);
	loadimage(&fubian3,_T("图片\\复变3.jpg"),150,150,true);
	loadimage(&xueximeizi,_T("图片\\学习妹子.jpg"),100,200,true);
	IMAGE laoshi,kaoshitu3,person2,person_2,jiyou;
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&laoshi,_T("图片\\老师.jpg"),180,180,true);
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&jiyou,_T("图片\\基友.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"因看不懂复变函数，数项级数而自闭了，感觉自己头发掉满地"};
		char b[]={"压力值+15 ，退学率-5"};
		putimage(0,0,&tushuguan);
		zimu1(a);
		putimage(200,150,&fubian);
		Sleep(1000);
		putimage(200,150,&fubian1);
		Sleep(1000);
		putimage(200,150,&fubian2);
		Sleep(1000);
		putimage(200,150,&fubian3);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		A.tui-=5;
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if (n==1)
	{
		char a[100];
		strcpy(a,A.returnname());
		char b[]={"同学考了我们班级第一，大家要好好向他学习"};
		strcat(a,b);
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(a,"老师");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("低调，低调，其实也就是运气好罢了",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1("压力值-5，退学率-10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.tui-=10;
		A.ya-=5;
		if(A.tui<0)
		{
			A.tui=0;
		}
		if(A.ya<0)
		{
			A.ya=0;
		}
	}
	else if(n==2)
	{
		
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(A.returnname(),"老师");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		
		rputimage(20,170,&laoshi);
		zimu("你来回答一下这个问题","老师");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("。。。。。。。。",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1("虽然勉强回答出来的，但因为没之前没预习，被吓到了。压力值+10 ，退学率-5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
		
	}
	else 
	{
        putimage(0,0,&tushuguan);
		rputimage(20,170,&jiyou);
		rputimage(300,100,&xueximeizi);
		zimu("快快，快抬头看看那个那边的妹子","基友");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("啊，啊，啊，哪里哪里",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		rputimage(20,170,&jiyou);
		zimu("看那里，要不要去搭讪搭讪（按Y 前去搭讪，按N 怂了）","基友");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		char a=0;
		while(a!='Y'&&a!='y'&&a!='N'&&a!='n')
		{
			a=getch();
		}
		if(a=='Y'||a=='y')
		{
			putimage(0,0,&tushuguan);
			putimage(20,170,&person_2,SRCPAINT);
			putimage(20,170,&person2,SRCAND);
			zimu("去就去，我可是国民老公",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			rputimage(560,170,&xueximeizi);
			putimage(20,170,&person_2,SRCPAINT);
			putimage(20,170,&person2,SRCAND);
			zimu("小姐姐，小姐姐，你也喜欢看这本书呀，你最喜欢哪个角色。。。诶，你今天穿得真好看",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			rputimage(560,170,&xueximeizi);
			zimu("嗯嗯嗯。。。。。。其实这个情节。。。","小姐姐");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			zimu1("因搭讪成功，内心欣喜，压力值-10 ，但是忘了写作业退学率+5，情商+10");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=10;
			A.tui+=5;
			A.qing+=10;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.tui>100)
			{
				A.tui=100;
			}
			if (A.qing>100)
			{
				A.qing=100;
			}
			
			
			
			
		}
		else 
		{
			putimage(0,0,&tushuguan);
			putimage(20,170,&person_2,SRCPAINT);
			putimage(20,170,&person2,SRCAND);
			zimu("我还是好好写作业吧",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			rputimage(20,170,&jiyou);
			zimu("真怂。。。。。。。","基友");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			zimu1("认真完成了作业，但是被室友觉得很怂，退学率-10 ，情商-5");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.qing-=5;
			A.tui-=10;
			if(A.qing<0)
			{
				A.qing=0;
			}
			if(A.tui<0)
			{
				A.tui=0;
			}
			
			
		}
		
	}
	
	
}
void paocao()
{
	IMAGE background1,jiyou,person2,person_2,paocao;
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&paocao,_T("图片\\跑操.jpg"),690,532,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&jiyou,_T("图片\\基友.jpg"),180,180,true);
	putimage(0,0,&background1);
	zimu("叮当叮当，六点了，懒猪起床，懒猪起床","闹钟");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	
	zimu("烦死了，我还想睡，是真的难受",A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("要不接着睡，反正45次而已（按Y 跑操，按N 接着睡）","基友");
	char c=0;
	while(c!='Y'&&c!='y'&&c!='N'&&c!='n')
	{
		c=getch();
	}
	if(c=='Y'||c=='y')
	{
		putimage(0,0,&paocao);
		zimu1("压力值+5");
		A.ya+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		
	}
	else 
	{
		putimage(0,0,&background1);
		zimu1("退学率+5");
		A.tui+=5;
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	
}
void jiangzuo()
{
	IMAGE background1,jiyou,person2,person_2,paocao,kaoshitu3;
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&jiyou,_T("图片\\基友.jpg"),180,180,true);
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("听说最近有讲座，要不要去听听看","基友");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	
	zimu("关于什么的呀",A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("管他的，反正有SRTP拿，不过好像要排很长的队伍（按Y 去，按N 不去）","基友");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	char c=0;
	while(c!='Y'&&c!='y'&&c!='N'&&c!='n')
	{
		c=getch();
	}
	if(c=='Y'||c=='y')
	{
		putimage(0,0,&background1);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		
		
		zimu("那赶紧去排队呀",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("讲座是真的不错的呢",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		
		putimage(0,0,&kaoshitu3);
		
		
		zimu1("SRTP+5，压力值+10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.srtp+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.srtp>100)
		{
			A.srtp=100;
		}
		
	}
	else 
	{
		putimage(0,0,&background1);
		
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("算了吧，人多的话，我还不如待在宿舍美滋滋",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	
	
	
	
	
	
	
}




void fcyuyan(int n)
{
	IMAGE background1,person1,person2,person3;
	loadimage(&background1,_T("图片\\机房.jpg"),690,532,true);
    loadimage(&person1,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&person3,_T("图片\\文静妹子.jpg"),180,180,true);
	char a[]={"什么愁什么怨, 连59都不给我"};
	char b[]={"退学率+10 ，压力值+5"};
	char d[]={"c++6.0启动！"};
	char c[]={"#include<iostream.h> void main(){cout<<so easy；}"};
	putimage(0,0,&background1);
	putimage(20,170,&person2,SRCPAINT);
	putimage(20,170,&person1,SRCAND);
	zimu(d,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	if(n==0)
	{
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu(a,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui+=10;
		if(A.tui>=100)A.tui=100;
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(n==1)
	{
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu("一堂课下来，发现自己头发掉了不少，但是好歹听明白了",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1("压力值+10 ，退学率-5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.tui-=5;
		if(A.tui<0)A.tui=0;
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(n==2||n==3&&A.qing<20&&A.srtp<30)
		
	{
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu("这。。。还是课下再预习一下吧。",A.returnname());
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1("压力值+5，退学率+5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui+=5;
		if(A.tui>=100)A.tui=100;
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(A.qing>=20&&A.srtp>=30&&n==3)
	{
		putimage(0,0,&background1);
		rputimage(20,170,&person3);
		zimu("同学，你c ++好厉害啊，可以教教我这个嘛？","女同学");
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu("唔姆，让老夫看看，，，，这样啊，，，，只要在这里加上这个，，，，懂了吗？",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		rputimage(20,170,&person3);
		zimu("哇，懂了懂了，你好厉害啊，以后还向你请教。","女同学");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1("情商+5，压力-10 ，死宅值+5，退学率-10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.zhai+=5;
		A.ya-=10;
		A.tui-=10;
		A.qing+=5;
		if(A.zhai>100)
		{
			A.zhai=100;
		}
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
		if(A.qing>100)
		{
			A.qing=100;
		}
		
	}
}
void dcyuyan(int n)
{
	IMAGE background1,person1,person2;
	loadimage(&background1,_T("图片\\高级机房.jpg"),690,532,true);
	loadimage(&person1,_T("图片\\熊猫人2.jpg"),180,180,true);
	loadimage(&person2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	char a[]={"哇，这就是真正的机房吗，机你太美"};
	char b[]={"电类c++ 也不过如此嘛，分分钟编完"};
	char c[]={"一定是我打开方式有问题，不然怎么看不懂这些英文"};
	char d[]={"我不生产代码，我只是代码的搬运工"};
   	putimage(0,0,&background1);
	putimage(20,170,&person2,SRCPAINT);
	putimage(20,170,&person1,SRCAND);
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	if(A.tui<=50)
	{
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
        putimage(0,0,&background1);
		zimu1("压力值-10 , 退学率-5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya-=10;
		A.tui-=5;
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	else if(A.tui>50&&A.tui<=60)
	{
		zimu(d,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
        putimage(0,0,&background1);
		zimu1("压力值+5，退学率+5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	else
	{
		zimu(c,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		zimu1("压力值+10 ，退学率+10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.tui+=10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	
}

void shejiao()
{
	IMAGE person1,person2,person3,person4,person5,person6,person7,person8,b1,b2,b3,b4,b5,b6,kfc;
    loadimage(&b1,_T("图片\\死宅宿舍.jpg"),690,532,true);
    loadimage(&person1,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
    loadimage(&b2,_T("图片\\走廊.jpg"),690,532,true);
    loadimage(&b3,_T("图片\\自习室.jpg"),690,532,true);
    loadimage(&b4,_T("图片\\广场.jpg"),690,532,true);
	loadimage(&b5,_T("图片\\下午茶.jpg"),690,532,true);
	loadimage(&b6,_T("图片\\KTV.jpg"),690,532,true);
    loadimage(&person3,_T("图片\\社交妹子1.jpg"),180,180,true);
	loadimage(&person4,_T("图片\\社交妹子2.jpg"),180,180,true);
	loadimage(&person5,_T("图片\\社交妹子3.jpg"),180,180,true);
	loadimage(&person6,_T("图片\\基友2.jpg"),180,180,true);
	loadimage(&person7,_T("图片\\社交妹子4.jpg"),180,180,true);
	loadimage(&person8,_T("图片\\基友.jpg"),180,180,true);
	loadimage(&kfc,_T("图片\\kfc.jpg"),690,532,true);
	char a[]={"走走走！今儿个放学早，哥几个去外面耍一耍。"};
	char b[]={"不约不约，今天去一下自习室"};
	char c[]={"哇，好热闹。"};
	char d[]={"不约不约，我去茶餐厅看看有没有吃的，没吃午饭肚子饿。"};
	char e[]={"不约不约，我把东西落在教室了，回去拿一下。"};
	char f[]={"不约不约，我去一下广场，那边好像有活动。"};
	char g[]={"约起，约起，去唱K ？"};
	char h[]={"你嫌弃破烂，揉碎了我~~~~"};
	char i[]={"鸡你太美~~~~"};
	char j[]={"诶，诶，诶~~，你看这个面它又大又圆，就像这个碗它又大又圆~~"};
	char k[]={"同学，请问这个位置有人吗？"};
	char l[]={"没有呢，请坐。"};
	char m[]={"小姐姐方便加个微信吗，下次一起约学习啊。"};
	char n[]={"哎呦我u 盘丢哪了，里面可有我珍藏多年的学习资料啊"};
	char o[]={"同学，你是在找这个u 盘吗，我刚刚在教室发现的。"};
	char p[]={"emmm，是的，谢谢你"};
	char q[]={"小姐姐。方便加个微信吗，有空请你吃个饭感谢一下。"};
	char r[]={"好啊，那我顺便带上我男朋友你不介意吧。"};
	putimage(0,0,&b1);
	rputimage(20,170,&person6);
	zimu(a,"室友");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&b1);
	
	zimu1("1.去自习室，2.去教学楼，3.去广场，4.去吃下午茶，5.跟室友出去耍");
	
	char s=0;
	while(s!='1'&&s!='2'&&s!='3'&&s!='4'&&s!='5')
	{
		
		s=getch();
		
		
		if(s=='1')
		{
			putimage(0,0,&b1);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(b,A.returnname());
			
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(k,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			rputimage(20,170,&person3);
			zimu(l,"唐雯雯");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("( 哎呦，这个小姐姐真好看，文静优雅，去要个联系方式) ",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(m,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			rputimage(20,170,&person3);
			zimu("哦，不用了，没空","唐雯雯");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("。。。。。。",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			zimu1("压力值-5，情商+5");
			A.ya-=5;
			A.qing+=5;
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
		}
		if(s=='2')
		{
			putimage(0,0,&b1);
			zimu(e,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(n,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			rputimage(20,170,&person7);
			zimu(o,"莫璃夜");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("( 要是可以得到这个小姐姐的联系方式，我还要什么学习资料。) ",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(p,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(q,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			rputimage(20,170,&person7);
			zimu(r,"莫璃夜");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("。。。。。。",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			zimu1("压力值-7，情商+7");
			A.ya-=7;
			A.qing+=7;
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
		}
		if(s=='3')
		{
			putimage(0,0,&b1);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			
			zimu(f,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(c,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			rputimage(20,170,&person5);
			zimu("同学，舞团了解一下","猫耳小姐姐");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("（卡哇伊，可我这肥宅也扭不起来啊） ",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("好呀，我们加个联系方式吧，方便我联系你",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			rputimage(20,170,&person5);
			zimu("诶，我只是负责发传单的，这里只有男团员，你看","猫耳小姐姐");
			putimage(0,0,&kfc);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("。。。。。。",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			zimu1("压力值-5，情商+5");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=5;
			A.qing+=5;
			if(A.ya>=100)A.ya=100;
			if(A.qing<=0)A.qing=0;
		}
		if(s=='4')
		{
			putimage(0,0,&b1);
			zimu(d,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("下午的人不是特别多呢，我来看看吃什么好呢。。。",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			rputimage(20,170,&person4);
			zimu("不。。不好意思同学，可以帮我付一下款吗，我校园卡没钱了，回头转给你","少女");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("（长得不错，挺可爱的，那就帮帮她吧）",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("好吧。。。付好了",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			rputimage(20,170,&person4);
			zimu("谢谢你，我用微信转给你","少女");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("（这是春天要来了吗，小姐姐微信送上门，嘿嘿。）",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			rputimage(20,170,&person4);
			zimu("啊，我男朋友来了，darling~我在这里。","少女");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("。。。。。。",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			zimu1("压力-5，情商+5");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=5;
			A.qing+=5;
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
		}
		if(s=='5')
		{
			putimage(0,0,&b1);
			zimu(g,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b1);
			rputimage(20,170,&person6);
			zimu("好，走起","室友");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(h,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			rputimage(20,170,&person6);
			zimu(i,"舍友");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			rputimage(20,170,&person8);
			zimu(j,"基友");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			zimu1("虽说玩的爽，但是消费也高啊。");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			zimu1("压力值-10 ，情商+5，零钱-200");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.money-=200;
			A.ya-=10;
			A.qing+=5;	
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
			if(A.money<=0)A.money=0;
		}
	}
}



void bilibili()
{
	IMAGE background1,person1,person2,background2,background3,background4,jiyou;
	loadimage(&background1,_T("图片\\b站.jpg"),690,532,true);
	loadimage(&person1,_T("图片\\熊猫人2.jpg"),180,180,true);
	loadimage(&person2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&background2,_T("图片\\b站学习.jpg"),690,532,true);
	loadimage(&background3,_T("图片\\初音.jpg"),690,532,true);
	loadimage(&background4,_T("图片\\鬼畜.jpg"),690,532,true);
	loadimage(&jiyou,_T("图片\\基友.jpg"),180,180,true);
	char a[]={"上了一天学, 刷会儿b 站放松一会儿, 找两个鬼畜看看"};
	char b[]={"闲着也是闲着，不然在b 站找点课来看。"};
	char c[]={"咕嘿嘿~~，公主殿下真漂亮，再多看会儿。"};
	char d[]={"让我看看b 站上今天有什么好玩的玩意儿。"};
    putimage(0,0,&background1);
	putimage(20,170,&person2,SRCPAINT);
	putimage(20,170,&person1,SRCAND);
	zimu(d,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	 putimage(0,0,&background1);
	zimu1("1.看网课，2.看鬼畜，3.看小姐姐");
	char e='0';
	while(e!='1'&&e!='2'&&e!='3')
	{
		e=getch();
		if(e=='1')
		{
			putimage(0,0,&background2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(b,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background2);
			rputimage(20,170,&jiyou);
			zimu("诶，你居然在偷偷学习，这也太读狗吧。","基友");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background1);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("啊？没。。。没有了。",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background1);
			zimu1("压力值-5，退学率-10 ，情商-10");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=5;
			A.qing-=10;
			A.tui-=10;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.qing<0)
			{
				A.qing=0;
			}
			if(A.tui<0)
			{
				A.tui=0;
			}
			
		}
		if(e=='2')
		{ 
			putimage(0,0,&background4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(a,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background4);
			zimu1("压力值-15 ，退学率+10 ，死宅值+10 ，情商-10");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=10;
			A.tui+=10;
			A.zhai+=10;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.qing<0)
			{
				A.qing=0;
			}
			if(A.tui>100)
			{
				A.tui=100;
			}
			if(A.zhai>100)
			{
				A.zhai=100;
				
			}
			
		}
		if(e=='3')
		{
			putimage(0,0,&background3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(c,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background3);
			zimu1("压力值-20 ，退学率+10 ，死宅值+15 ");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=20;
			A.tui+=10;
			A.zhai+=15;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.tui>100)
			{
				A.tui=100;
			}
			if(A.zhai>100)
			{
				A.zhai=100;
				
			}
			
		}
	}
	
}




void yingyu2(int n)
{
    IMAGE  kaoshitu3,background2,yingyu,background1,person2,person_2,person3,person_3,xueximeizi,dongda,wenlur,yingyuls,yingyujiao;
    loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&background2,_T("图片\\死宅宿舍4399.jpg"),690,532,true);
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&person3,_T("图片\\熊猫人3.jpg"),180,180,true);
	loadimage(&person_3,_T("图片\\熊猫人3屏蔽图.jpg"),180,180,true);
	loadimage(&yingyu,_T("图片\\英语角.jpg"),690,532,true);
	loadimage(&xueximeizi,_T("图片\\学习妹子.jpg"),180,180,true);
	loadimage(&dongda,_T("图片\\东大.jpg"),690,532,true);
	loadimage(&wenlur,_T("图片\\问路人.jpg"),180,180,true);
	loadimage(&yingyuls,_T("图片\\英语老师.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"因为看不懂英文游戏的设置而努力学习一段时间后"};
		char b[]={"哈，这些游戏的剧情可真别致"};
		char c[]={"后因游戏过多而日益颓废"};
		char d[]={"退学率+15,压力值-5"};
		putimage(0,0,&yingyu);
		zimu1(a);
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background2);
		putimage(500,170,&person_2,SRCPAINT);
		putimage(500,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background2);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		getch();
		putimage(0,0,&background2);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		getch();
		A.ya=A.ya-5;
		A.tui=A.tui+15;
		if(A.tui>100)
		{
			A.tui=100;
		}
		if(A.ya<0)
		{
			A.ya=0;
		}
	}
	else if(n==1)
	{
		char a[]={"Hello I am lost. Where is Gangju Gymnasium（钢菊体育馆）?"};
		char b[]={"Go straight along Nangong Road and turn right at the first crossing to see it.（在这不是闭着眼睛都找得到）"};
		char c[]={"Thanks for you help"};
		char d[]={"压力值-10 ，退学率-10"};
		putimage(0,0,&dongda);
		rputimage(20,170,&wenlur);
		zimu3(a,"路人");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dongda);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu3(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dongda);
		rputimage(20,170,&wenlur);
		zimu3(c,"路人");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dongda);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya-10;
		A.tui =A.tui-10;
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.tui<0)
		{
			A.tui =0;
		}
		
	}
	else if(n==2)
	{
		char a[]="打开英语书，发了发呆，发现什么都比学习有意思，玩玩笔，挠挠头。。。。。";
		char b[]="时间在消磨中慢慢过去，结果什么都没有记住";
		char c[]="退学率+10,  压力值+10";
		putimage(0,0,&kaoshitu3);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya =A.ya +10;
		A.tui=A.tui +10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	else
	{
		char a[]={"你认认真真的完成了老师的作业，并在课堂上积极讨论，收获很多"};
		char b[]={"作业完成的不错，继续加油哦"};
		char c[]={"你听了很高兴，并期待期末考出一个好成绩"};
		char d[]={"压力值+5，退学率-10"};
		putimage(0,0,&yingyu);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		rputimage(20,170,&yingyuls);
		zimu(b,"英语老师");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyujiao);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui-=10;
		if (A.ya >100)
		{
			A.ya=100;
		}
		if (A.tui<0)
		{
			A.tui=0;
		}
	}
}
void yingyu3(int n)
{
	IMAGE yingyu,background1,background2,yingyu2,yyztxx,yingyuls,person2,person_2,yingyuxs,kaoshitu3,person3,person_3;
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&yingyu2,_T("图片\\英语角2.jpg"),690,532,true);
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&person3,_T("图片\\熊猫人3.jpg"),180,180,true);
	loadimage(&person_3,_T("图片\\熊猫人3屏蔽图.jpg"),180,180,true);
	loadimage(&yingyu,_T("图片\\英语角.jpg"),690,532,true);
	loadimage(&yingyuxs,_T("图片\\英语学生.jpg"),180,180,true);
	loadimage(&yingyuls,_T("图片\\英语老师.jpg"),180,180,true);
	loadimage(&yyztxx,_T("图片\\言叶之庭学习图.jpg"),690,532,true);
	if(n==0)
	{
		char a[]={"你好啊，上课时你的发音真好听"};
		char b[]={"你想学的话我们可以一起练"};
		char c[]={"在一起学习的时间里，你收获了知识和友情，但也有了要担负起他人的期待的压力"};
		char d[]={"退学率-5, 压力值+5"};
		putimage(0,0,&yingyu);
		rputimage(20,170,&yingyuxs);
		zimu(a,"亮儿");
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu2);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+5;
		A.tui=A.tui-5;
		if(A.ya>0)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if(n==1)
	{
		char a[]={"？，我来自一个什么什么，要去做什么什么···"};
		char b[]={"你的嘴里念叨着一些不知意思的英文单词，并艰难翻译"};
		char c[]={"压力值+10,  退学率-5"};
		putimage(0,0,&background1);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+10;
		A.tui=A.tui-10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if(n==2)
	{
		char a[]={"因为下雨天的原因，所以发呆了两节课"};
		char b[]={"压力值+10,  退学率+5"};
		putimage(0,0,&yyztxx);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yyztxx);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+10;
		A.tui=A.tui+5;
	}
}
void yingyu4(int n)
{
	IMAGE yingyu,background1,background2,yingyust,yingyu2,yingyuls,zhuijutu,person2,person_2,yingyuxs,kaoshitu3,person3,person_3;
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&yingyu2,_T("图片\\英语角2.jpg"),690,532,true);
	loadimage(&kaoshitu3,_T("图片\\考试图3.jpg"),690,532,true);
	loadimage(&person3,_T("图片\\熊猫人3.jpg"),180,180,true);
	loadimage(&person_3,_T("图片\\熊猫人3屏蔽图.jpg"),180,180,true);
	loadimage(&yingyu,_T("图片\\英语角.jpg"),690,532,true);
	loadimage(&yingyuxs,_T("图片\\英语学生.jpg"),180,180,true);
	loadimage(&zhuijutu,_T("图片\\追剧图片.jpg"),690,532,true);
	loadimage(&yingyust,_T("图片\\英语试题.jpg"),180,180,true);
	
	if (n==0)
	{
		char a[]={"四级考试就快到了，害怕自己不能考过，十分焦虑"};
		char b[]={"压力值+10,  退学率-5"};
		putimage(0,0,&background1);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
        A.ya=A.ya+10;
		A.tui=A.tui-5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if(n==1)
	{
		char a[]={"为了提升英语水平，选择追美剧"};
		char b[]={"然而，追剧时只记住了剧情"};
		char c[]={"退学率+5, 压力值+5"};
		putimage(0,0,&zhuijutu);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&zhuijutu);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&zhuijutu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+5;
		A.tui=A.tui+5;
		if(A.tui>100)
		{
			A.tui=100;
		}
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(n==2)
	{
		char a[]={"认真的学习，刷了几套四级真题"};
		char b[]={"压力值+10,  退学率-10"};
		putimage(0,0,&background1);
		putimage(20,170,&yingyust);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+10;
		A.tui=A.tui-10;
		if (A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
}
void dagong(int n)
{
	
	IMAGE dgxiwantu,dgrw,ss,p2,p_2,dgfuwuyuantu,dagongsyy,yaoqianr,jifei,dagongtx,lb,guke,baoli,laodongfa,bangongs;
	loadimage(&laodongfa,_T("图片\\劳动法.jpg"),180,180,true);
	loadimage(&yaoqianr,_T("图片\\要钱人.jpg"),180,180,true);
	loadimage(&jifei,_T("图片\\击飞图.jpg"),690,532,true);
	loadimage(&bangongs,_T("图片\\办公室.jpg"),690,532,true);
	loadimage(&p2,_T("图片\\熊猫人2.jpg"),180,180,true);
	loadimage(&baoli,_T("图片\\暴力解决.jpg"),690,532,true);
    loadimage(&p_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
    loadimage(&dgxiwantu,_T("图片\\打工洗碗图.jpg"),690,532,true);
	loadimage(&dgfuwuyuantu,_T("图片\\打工服务员.jpg"),690,532,true);
	loadimage(&dgrw,_T("图片\\打工人.jpg"),180,180,true);
	loadimage(&dagongsyy,_T("图片\\收银员.jpg"),690,532,true);
	loadimage(&lb,_T("图片\\老板图.jpg"),180,180,true);
	loadimage(&dagongtx,_T("图片\\打工的同学.jpg"),180,180,true);
	loadimage(&guke,_T("图片\\顾客.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"你到了一家小餐馆做洗碗工的兼职"};
		char b[]={"你正在认真洗碗时，突然想到了一个新的洗碗方法，似乎很高效，（按y 键采用，按n 键放弃）"};
		char c[]={"洗刷刷，洗刷刷，正当你采用新的洗碗方法时，碗飞了出去"};
		char d[]={"不得不说这个新的方法还挺不错，工作效率提高不少"};
        char e[]={"你放弃了这个想法，并继续认真洗碗"};
		char f[]={"生活费+150, 退学率+5"};
		char g[]={"压力值+1，退学率+5，生活费+80"};
		putimage(0,0,&dgxiwantu);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dgxiwantu);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				int a1;
				a1=randrange(2);
				if(a1==1)
				{
					putimage(0,0,&dgxiwantu);
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                    getch();
					putimage(0,0,&dgxiwantu);
					zimu1(g);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                    getch();
					
					A.money=A.money+80;
					A.ya=A.ya+1;
					A.tui=A.tui+5;
					if(A.ya>100)
					{
						A.ya=100;
					}
					if(A.tui>100)
					{
						A.tui=100;
					}
					
				}
				else if(a1==0)
				{
					putimage(0,0,&dgxiwantu);
					zimu1(d);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                    getch();
					putimage(0,0,&dgxiwantu);
					zimu1(f);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					
					A.money =A.money +150;
					A.tui =A.tui+5;
					if(A.tui>100)
					{
						A.tui =100;
					}
				}
				break;
				
			}
			else if (i=='N'||i=='n')
			{
				putimage(0,0,&dgxiwantu);
				zimu1(e);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dgxiwantu);
				zimu1("生活费+100，退学率+5");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money =A.money+100;
				A.tui=A.tui+5;
				if (A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			
		}
	}
	else if(n==1)
	{
		char a[]={"你来到一家小店当收营员"};
		char b[]={"（呆呆脸状）来几份特价便当"};
		char c[]={"好的，你转身去取了几份便当"};
		char d[]={"你看着便当，心里想是不是要坑这个呆呆脸的家伙（坑按y,不坑按n)"};
		char e[]={"欺诈被他发现了，崩，接着你被一拳击飞"};
		char f[]={"生活费-50,  退学率+5"};
		char g[]={"你正常的完成了交易"};
		char h[]={"生活费+100，退学率+5"};
		putimage(0,0,&dagongsyy);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dagongsyy);
		rputimage(20,170,&guke);
        zimu(b,"琦玉老师");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dagongsyy);
		putimage(20,170,&p_2,SRCPAINT);
		putimage(20,170,&p2,SRCAND);
		zimu(c,A.returnname());
		putimage(0,0,&dagongsyy);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				putimage(0,0,&dagongsyy);
				zimu1(e);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&jifei);
				zimu1(f);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money =A.money-50;
				A.tui =A.tui+5;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			else if (i=='N'||i=='n')
			{
				putimage(0,0,&dagongsyy);
				zimu1(g);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dagongsyy);
				zimu1(h);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money=A.money+100;
				A.tui=A.tui+5;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			
			
		}
	}
	else if(n==2)
	{
		char a[]={"看你的校徽，你也是南某大的学生啊"};
		char b[]={"是的，这里居然也有校友"};
		char c[]={"你们聊了聊，互相觉得有意思"};
		char d[]={"但是你看了看时间，似乎还有些工作没有做。（聊下去按Y,  工作按N ）"};
		char e[]={"你们继续聊了下去，时间不知不觉过去了···"};
		char f[]={"情商+10,  退学率+10"};
		char g[]={"你快速结束了话题，继续工作"};
		char h[]={"生活费+100，退学率+5"};
		putimage(0,0,&dgfuwuyuantu);
		rputimage(20,170,&dagongtx);
		zimu(a,"校友");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dgfuwuyuantu);
		rputimage(20,170,&dgrw);
		zimu(b,A.returnname ());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dgfuwuyuantu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dgfuwuyuantu);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				putimage(0,0,&dgfuwuyuantu);
				zimu1(e);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dgfuwuyuantu);
				zimu1(f);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.qing=A.qing+10;
				A.tui =A.tui+10;
				if(A.qing >100)
				{
					A.qing=100;
				}
				break;
			}
			
			else if (i=='N'||i=='n')
			{
				putimage(0,0,&dgfuwuyuantu);
				zimu1(g);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dgfuwuyuantu);
				zimu1(h);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money=A.money+100;
				A.tui=A.tui+5;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			
		}
	}
	else if(n==3)
	{
		char a[]={"你完成了一天的工作，来到了老板的办公室"};
		char b[]={"这是你的工资，收着"};
		char c[]={"你看了看工资，似乎数目不对（出声质疑按Y,  默默离开按 N )"};
		char d1[]={"这个工资数目不对啊"};
		char e1[]={"你今天*&……%￥#@！@#￥%……&*（貌似有理，但总有些奇怪）"};
		char f[]={"你考虑了一下，是否要反驳他（反驳按Y,  离开按 N )"};
		char g1[]={"拳头反驳按Y ，劳动法反驳按 N"};
		char h1[]={"他被胖揍了一顿，你也被带走了···"};
		char h2[]={"他支支吾吾说不出话来，只好拿出来少付的工资"};
		char g2[]={"你被他说服了，但回头时总觉得他在不怀好意的笑着"};
		char d2[]={"你想不过是一天的工资而已，不值得争论，于是离开了"};
		char zm1[]={"生活费-100，压力值-5，退学率+10"};
		char zm2[]={"生活费+200，退学率+5"};
		char zm3[]={"生活费+70 ，退学率+10"};
		putimage(0,0,&bangongs);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&bangongs);
		rputimage(20,170,&lb);
		zimu(b,"老板");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&bangongs);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				putimage(0,0,&bangongs);
				rputimage(20,170,&yaoqianr);
				zimu(d1,A.returnname ());
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&bangongs);
				rputimage(20,170,&lb);
				zimu(e1,"老板");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&bangongs);
				zimu1(f);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                char j=0;
				while(true)
				{
					j=getch();
					if(j=='Y'||j=='y')
					{
						putimage(0,0,&bangongs);
						zimu1(g1);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
						char z=0;
						while(true)
						{
							z=getch();
							if(z=='y'||z=='Y')
							{
								putimage(0,0,&baoli);
								zimu1(h1);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                                getch();
								putimage(0,0,&baoli);
								zimu1(zm1);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
								getch();
								A.money=A.money-50;
								A.ya=A.ya-5;
								A.tui=A.tui+10;
								if(A.ya<0)
								{
									A.ya=0;
								}
								if(A.tui>100)
								{
									A.tui=100;
								}
								break;
								
								
							}
							else if(z=='n'||z=='N')
							{
								putimage(0,0,&bangongs);
								putimage(250,170,&laodongfa);
								zimu1(h2);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
								getch();
								putimage(0,0,&bangongs);
								zimu1(zm2);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
								getch();
								A.money=A.money+200;
								A.tui=A.tui +5;
								if(A.tui>100)
								{
									A.tui=100;
								}
								break;
								
							}
							
							
							
							
						}
						break;
						
					}
					else if(j=='n'||j=='N')
					{
						putimage(0,0,&bangongs);
						zimu1(g2);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						getch();
						putimage(0,0,&bangongs);
						zimu1(zm3);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						getch();
						A.tui=A.tui+10;
						A.money=A.money+70;
						if(A.tui>100)
						{
							A.tui=100;
						}
						break;
					}
					
				}
				break;
				
				
				
			}
			else if(i=='n'||i=='N')
			{
				putimage(0,0,&bangongs);
				zimu1(d2);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				getch();
				zimu1(zm3);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				getch();
				A.tui=A.tui+10;
				A.money=A.money+70;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
		}
		
		
	}
}







void jiewei()
{
	IMAGE background1,jiewei1,jiewei2,chengxuyuan,shangren,gongren,kexuejia,yingyulaoshi,fenxishi,chuguo,yishujia;
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&jiewei1,_T("图片\\结尾1.jpg"),690,532,true);
	loadimage(&jiewei2,_T("图片\\结尾2.jpg"),690,532,true);
	loadimage(&chengxuyuan,_T("图片\\程序员.jpg"),690,532,true);
	loadimage(&shangren,_T("图片\\商人.jpg"),690,532,true);
	loadimage(&fenxishi,_T("图片\\分析师.jpg"),690,532,true);
	loadimage(&gongren,_T("图片\\工人.jpg"),690,532,true);
	loadimage(&kexuejia,_T("图片\\科学家.jpg"),690,532,true);
	loadimage(&yingyulaoshi,_T("图片\\职业英语老师.jpg"),690,532,true);
	loadimage(&chuguo,_T("图片\\出国.jpg"),690,532,true);
    loadimage(&yishujia,_T("图片\\艺术家.jpg"),690,532,true);
	char a[]={"四年如此亦然如此悄无声息，这四年，我好想也没做过什么大事，就这么过去了，曾经与我一起疯，一起闹得室友已经考研，出国了，而我呢？"};
	char b[]={"当我最后离开时，宿舍恢复了来前的平静，一切都像极了重来没发生过一样。毕业论文也已经交了，是时候改为未来打算一下了"};
	char c[]={"离开了那个生活了四年的城市，我来到了一个没有你的城市，这里高楼林立，然而哪里才是我的家"};
	char d[]={"我奔波于大街小巷，为寻找工作而疲惫不堪，我时常想起刚刚到大学的那一天，回想起大学的那群人。。。。。。"};
	putimage(0,0,&background1);
	zimu2(a,"回忆君");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	zimu2(b,"回忆君");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&jiewei1);
	zimu2(c,"回忆君");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&jiewei2);
	zimu2(d,"回忆君");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	cleardevice();
	B.gaoshushu=B.gaoshushu+B.gaoshudengji*3;
	B.yingyushu=B.yingyushu+B.yingyudengji*3;
	B.cyuyanshu=B.cyuyanshu+B.cyuyandengji*3;
	if(A.srtp<30)
	{
		putimage(0,0,&gongren);
		zimu2("虽然奔波了好久，但仍然没找到合适的工作，没办法，为了生计，我只好进入工厂成为一名工人，或许这就是命吧","回忆君");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&gongren);
		zimu2("每天重复的工作让我身心俱疲，或许该试着去相个亲","回忆君");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		
		
	}
	else 
	{
		if(B.gaoshushu>B.yingyushu &&B.gaoshushu>B.cyuyanshu)
		{
			if(A.qing>70)
			{
				putimage(0,0,&shangren);
				zimu2("我进入了商业圈，因为能力还算不差，我升职得很快，没过多久就已经是一个区的总经理了","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&shangren);
				zimu2("越在高处，我越感觉到孤独，似乎没什么人能理解我，我见过形形色色的女孩子，也许是时候为自己找个合适的伴侣了","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.money=A.money+10000;
				
			}
			else 
			{
				putimage(0,0,&fenxishi);
				zimu2("我自己学习了股票投资，进入了上海证券交易所，业绩也还行，算是小康了吧","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&fenxishi);
				zimu2("但是日子还是挺平淡的 ，或许我需要为自己找个伴侣","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.money+=8501;
			}
			
			
		}
		else 	if(B.cyuyanshu>B.yingyushu && B.cyuyanshu>B.yingyushu)
		{
			if(A.srtp>70)
			{
				putimage(0,0,&chengxuyuan);
				zimu2("终于，我找到工作了，是一个程序员，虽然我头发掉得很快，也是一个996 的工作，但是工资待遇还算不错","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&chengxuyuan);
				zimu2("唯一遗憾的是，在茫茫人海中，我总感受孤独，趁着我还有头发，我得赶紧找一个她来相伴","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
			}
			else
			{
				putimage(0,0,&yishujia);
				zimu2("虽然我没有找到像程序员那么高工资的工作，但凭借着自己电脑的基础，我也成立了一家动画制作艺术工作室，日子还算开心，没有那么大的压力","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&yishujia);
				zimu2("我好希望能找到一起喜欢艺术的小姐姐","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.zhai=100;
				
			}
			
		}
		
		else	if(B.yingyushu>B.gaoshushu &&B.yingyushu>B.cyuyanshu)
		{
			if(A.srtp>70 && A.qing>60)
			{
				putimage(0,0,&chuguo);
				zimu2("因没找到工作，我决定去深造，自学了雅思，考了9 分，上了英国的剑桥大学，现在生活真是美滋滋呢","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&chuguo);
				zimu2("在这里我认识了，一些同样留学的小姐姐，我应该试着去相处一下","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				
			}
			else
			{
				putimage(0,0,&yingyulaoshi);
				zimu2("凭借着自己biu 准的四级口音，我应聘了高中英语教师，还是怀念当年高中的生活呀","回忆君");
				
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&yingyulaoshi);
				zimu2("然而家里总是在催我找女朋友，也许该去试试相亲了","回忆君");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
			}
			
		}
		else
		{
			putimage(0,0,&kexuejia);
			zimu2("因找不到工作，我决定回去深造，经过多年的努力，我进入中科院研究所，我也挺热爱现在的工作的","回忆君");
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			zimu2("然而，我还是得考虑一下我的终身大事，物理所都是男的，只好去相亲了","回忆君");
			
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			
			
			
		}
		
		
		
	}
	
	
	
	
	
	cleardevice();
	xiangqin();
	
	
}
void tuixuele()
{
	IMAGE tuixue1;
	loadimage(&tuixue1,_T("图片\\退学.jpg"),690,532,true);
	putimage(0,0,&tuixue1);
	zimu2("我成绩不高，挂了很多科，在老师和家长的双重压力下，我逐渐自闭，最后我决定离开学校，或许这是一种解脱吧","回忆君");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&tuixue1);
	
	while(true)
	{
		
		
		
	}
	
	
}













void xiangqinshuchu(char *p,int m,int n)
{
	settextstyle(20,0,_T("宋体"));
	char a[200];
	int x=m,y=n;
	strcpy(a,p);
	
	for( unsigned i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+20;
		if(b[0]==' '&&b[1]==' ')
		{
			x=x-20;
		}
		else if(b[0]==' '||b[1]==' ')
		{
			x=x-10;
		}
		if(x>=100+m)
		{
			x=m;
			y=y+30;
		}
	}
	
	
}
int chachong(int b[3],int i)
{
	for(int k=0;k<i;k++)
	{
		if(b[k]==b[i])
		{
			
			break;
		}
	}
	if (k==i)
	{
		return 1;
	}
	return 0;
	
}
void xiangqin()
{
	setbkmode(TRANSPARENT);
	int b[3]={0};
	srand(unsigned (time(NULL)));
	int i=0;
	while(i<3)
	{
		b[i]=rand()%6;
		if(chachong(b,i))
		{
			i++;
		}
	}
	
	
	xiaojiejie a[6];
	IMAGE xiangqinbeijing,xiao1,xiao2,xiao3,xiao4,xiao5,xiao6;
	loadimage(&xiangqinbeijing,_T("图片\\相亲背景.jpg"),690,532,true);
	
	loadimage(&xiao1,_T("图片\\小姐姐1.jpg"),100,330,true);
	loadimage(&xiao2,_T("图片\\小姐姐2.jpg"),100,330,true);
	loadimage(&xiao3,_T("图片\\小姐姐3.jpg"),100,330,true);
	loadimage(&xiao4,_T("图片\\小姐姐4.jpg"),100,330,true);
	loadimage(&xiao5,_T("图片\\小姐姐5.jpg"),100,330,true);
	loadimage(&xiao6,_T("图片\\小姐姐6.jpg"),100,330,true);
	a[0].xiaojiejietu=xiao1;
	a[0].xiaojiejieming="凌冰颖";
	a[0].xiaojiejiejieshao="这个小姐姐在大学时期就是学生会会长，人美能力强，但是有点高冷，只有SRTP够高才有成功的可能性";
	if(A.srtp>=80 &&A.tui<=70)
	{
		a[0].success_=1;
	}
	else a[0].success_=0;
	
	
	a[1].xiaojiejietu=xiao2;
	a[1].xiaojiejieming="伊涵诺";
	a[1].xiaojiejiejieshao="这个小姐姐是一名护士，爱卖萌，十分可爱，喜欢cos 和二次元，死宅值足够高的话成功率高点";
	if(A.zhai>=60 &&A.qing>=30)
	{
		a[1].success_=1;
		
	}
	else a[1].success_=0;
	
	a[2].xiaojiejietu=xiao3;
	a[2].xiaojiejieming="夏晗沫";
	a[2].xiaojiejiejieshao="这是一个非常有少女心得小姐姐，如果你是又帅情商又高的，非你莫属";
	if(A.qing>=60)
	{
		a[2].success_=1;
	}
	else a[2].success_=0;
	
	a[3].xiaojiejietu=xiao4;
	a[3].xiaojiejieming="沐晴羽";
	a[3].xiaojiejiejieshao="这是一个能力很强的小姐姐，在大城市里忙忙碌碌，喜欢事业心强的男生";
	if(A.money>10000)
	{
		a[3].success_=1;
	}
	else a[3].success_=0;
	
	a[4].xiaojiejietu=xiao5;
	a[4].xiaojiejieming="任若璃";
	a[4].xiaojiejiejieshao="这是一个爱古风的小姐姐，有点高冷，也许你需要情商高一点才可以去触碰";
	if(A.qing>=70)
	{
		a[4].success_=1;
	}
	else a[4].success_=0;
	
	a[5].xiaojiejietu=xiao6;
	a[5].xiaojiejieming="夏唯安";
	a[5].xiaojiejiejieshao="这是一个十分可爱的小萝莉，你只要多花点心思就可以让她感受到你的关心";
	if(A.qing>20)
	{
		a[5].success_=1;
	}
	else a[5].success_=0;
	putimage(0,0,&xiangqinbeijing);
	setcolor(BLACK);
    setfillcolor(RGB(255,228,196));
	putimage(10,100,&a[b[0]].xiaojiejietu);
	fillrectangle(110,100,230,130);
	settextstyle(15,0,_T("黑体"));
	outtextxy(125,105,a[b[0]].xiaojiejieming);
	fillrectangle(110,130,230,430);
	xiangqinshuchu(a[b[0]].xiaojiejiejieshao,125,135);//
	
	
	setfillcolor(RGB(255,228,196));
	putimage(240,100,&a[b[1]].xiaojiejietu);
	fillrectangle(340,100,470,130);
	settextstyle(15,0,_T("黑体"));
	outtextxy(345,105,a[b[1]].xiaojiejieming);
	fillrectangle(340,130,470,430);
	xiangqinshuchu(a[b[1]].xiaojiejiejieshao,345,135);//
	
	
	setfillcolor(RGB(255,228,196));
	putimage(480,100,&a[b[2]].xiaojiejietu);
	fillrectangle(580,100,690,130);
	settextstyle(15,0,_T("黑体"));
	outtextxy(585,105,a[b[2]].xiaojiejieming);
	fillrectangle(580,130,690,430);
	xiangqinshuchu(a[b[2]].xiaojiejiejieshao,585,135);//
	char c;
	while(true)
	{
		c=getch();
		if(c=='1')
		{
			success=a[b[0]].success_;
			break;
		}
		if(c=='2')
		{
			success=a[b[1]].success_;
			break;
		}
		if(c=='3')
		{
			success=a[b[1]].success_;
			break;
		}
		
		
	}
	setbkcolor(BLACK);
	cleardevice();
	tanlianaixuanhuan();
	
}





void tanlianai(int n)
{
	
	
	setcolor(BLACK);
	
	
	
	IMAGE tan1,tan2,tan3,tan4,tan5;
	loadimage(&tan1,_T("图片\\谈恋爱1.jpg"),280,200,true);
	loadimage(&tan2,_T("图片\\谈恋爱2.jpg"),280,200,true);
	loadimage(&tan3,_T("图片\\谈恋爱3.jpg"),280,200,true);	
	loadimage(&tan4,_T("图片\\谈恋爱4.jpg"),280,200,true);	
	loadimage(&tan5,_T("图片\\谈恋爱5.jpg"),280,200,true);	
	
	
	setfillcolor(WHITE);
	if(n<=60 &&n>=0)
	{
		putimage(210,100,&tan1);
	}
	else if(n>60 && n<=120)
	{
		putimage(210,100,&tan2);
	}
	else if(n>120 && n<=180)
	{
		putimage(210,100,&tan3);
	}
	else if(n>180 && n<=240)
	{
		putimage(210,100,&tan4);
	}
	else if(n>240 && n<=300)
	{
		putimage(210,100,&tan5);
	}
	fillrectangle(200,350,500,360);
	setfillcolor(RGB(255,165,0));
	fillrectangle(200,350,n+200,360);
	settextstyle(30,0,_T("黑体"));
	settextcolor(RGB(255,165,0));
	outtextxy(280,380,"恋爱进行中");
	
}
void tanlianaixuanhuan()
{
	
	IMAGE tan6,tan7;
	loadimage(&tan6,_T("图片\\谈恋爱6.jpg"),450,350,true);	
	loadimage(&tan7,_T("图片\\谈恋爱7.jpg"),450,350,true);	
	int n=0;
	while(n<=300)
	{
		n++;
		tanlianai(n);
		Sleep(10);
	}
	if(success==1)
	{
		cleardevice();
		putimage(100,100,&tan6);
		
	}
	else if(success==0)
	{
		cleardevice();
		putimage(100,100,&tan7);
		
	}
	while(true)
	{
	}
}





void beijing()
{
	
	IMAGE gushi2,gushi3,gushi1;
	suiji=randrange(4);	
	IMAGE background1,jiyou,person2,person_2,kaixue;
	loadimage(&kaixue,_T("图片\\开学.jpg"),690,532,true);
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	loadimage(&jiyou,_T("图片\\基友.jpg"),180,180,true);
	loadimage(&gushi2,_T("图片\\背景故事2.jpg"),690,532,true);
	loadimage(&gushi3,_T("图片\\背景故事3.jpg"),690,532,true);
	loadimage(&gushi1,_T("图片\\背景故事1.jpg"),690,532,true);
	putimage(0,0,&gushi2);
	getch();
    char name[20];
	InputBox(name, 10, "是个小男孩啊，不如就叫","爸爸爱你");
	putimage(0,0,&gushi3);
	A.getname (name);
	char s1[]="高考那天";
	char ss1[]="一切都是那么平静";
	char sss1[]="我淡然的离开那个生活了三年的校园";
	char ssss1[]="不知道未来的路会怎样";
	settextstyle(30, 0, _T("黑体"));    
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(200,125,s1);
    Sleep(1000);
	outtextxy(50,80,ss1);
    Sleep(1000);
	outtextxy(150,200,sss1);
    Sleep(1000);
	outtextxy(100,250,ssss1);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	settextstyle(20, 0, _T("黑体")); 
	setbkcolor(WHITE);
	cleardevice();
	settextcolor(BLACK);
	outtextxy(300,280,name);
	putimage(0,0,&gushi1,SRCAND);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	cleardevice();
	mciSendString(TEXT("open bgm\\背景音乐.mp3 alias mysong"),NULL,0,NULL);
	mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	putimage(0,0,&kaixue);
	Sleep(3000);
	
	
	char a[]={"终于上大学了，终于解放了，听说这个学校的妹子还挺多"};
	char b[]={"别做梦了，你找不到妹子的，你只有你室友，还是好好读书吧"};
	char c[]={"其实吧，妹子就是看看，搞基才是真爱"};
	char d[]={"说得有道理，赶紧开始你的大学生活吧"};
	putimage(0,0,&background1);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu(b,"基友");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
	getch();
	putimage(0,0,&background1);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	zimu(c,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu(d,"基友");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
	getch();
	
	jiemian();
	
	
}
void jiemian()
{
	if(A.tui==100)
	{
		cleardevice();
		mciSendString(TEXT("close mysong "),NULL,0,NULL);
		mciSendString(TEXT("open bgm\\淘汰音乐.mp3 alias tmysong"),NULL,0,NULL);
		mciSendString(TEXT("play tmysong repeat"),NULL,0,NULL);
		
		
		
		tuixuele();
		
	}
	setbkcolor(BLACK);
	setbkmode(OPAQUE);
	cleardevice();
	IMAGE background1,person1,person_1,kaichong,shangdian,dudu;
	loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&person1,_T("图片\\熊猫人1.jpg"),0,0,true);	
    loadimage(&person_1,_T("图片\\熊猫人1屏蔽图.jpg"),0,0,true);
	loadimage(&kaichong,_T("图片\\开冲.jpg"),180,60,true);
	loadimage(&shangdian,_T("图片\\商店.jpg"),120,45,true);
	loadimage(&dudu,_T("图片\\读读.jpg"),120,45,true);
	setcolor(BLACK);
	putimage(0,0,&background1);
	putimage(0,0,&person_1,SRCPAINT);
	putimage(0,0,&person1,SRCAND);
    setbkmode(TRANSPARENT);
	putimage(0,450,&kaichong);
	putimage(550,470,&shangdian);
	putimage(550,410,&dudu);
    setfillcolor(RGB(227,168,105));
	fillrectangle(270,400,500,530);
	setfillcolor(WHITE);
	fillrectangle(300,515,400,525);
	setfillcolor(RGB(255,0,255));
	solidrectangle(300,515,A.qing+300,525);
	settextstyle(15, 10, _T("黑体"));
	settextcolor(WHITE);
	outtextxy(420,515,"情商");
    setfillcolor(WHITE);
	fillrectangle(300,500,400,510);
	setfillcolor(RGB(160,32,240));
	solidrectangle(300,500,A.zhai+300,510);    
	outtextxy(420,500,"死宅值");
    setfillcolor(WHITE);
	fillrectangle(300,485,400,495);
	setfillcolor(RED);
	solidrectangle(300,485,A.tui+300,495);    
	outtextxy(420,485,"退学率");
	setfillcolor(WHITE);
	fillrectangle(300,470,400,480);
	setfillcolor(GREEN);
	solidrectangle(300,470,A.ya+300,480);    
	outtextxy(420,470,"压力值");
	setfillcolor(WHITE);
	fillrectangle(300,455,400,465);
	setfillcolor(BLUE);
	solidrectangle(300,455,A.srtp+300,465);
	outtextxy(420,455,"SRTP");
	char money_[20],huihe_[20];
	sprintf(money_,"%d",A.money);
	sprintf(huihe_,"%d",h);
	outtextxy(420,410,"生活费");
	outtextxy(425,430,money_);
	setfillcolor(RGB(227,168,105));
	fillrectangle(10,410,140,440);
    setbkmode(TRANSPARENT);
	settextstyle(30,15, _T("黑体"));
	settextcolor(BLACK);
	outtextxy(300,410,A.returnname()); 
	settextstyle(15, 10, _T("黑体"));
	outtextxy(20,420,"还剩  回合");
	outtextxy(60,420,huihe_);
	setbkmode(OPAQUE);
	
	char c2=0;
	while (true)
	{
		c2=getch();
		if (c2=='W'||c2=='w')
		{
			B.anpaimian();
		}
		else if(c2=='l'||c2=='L')
		{
			
			B.shengji();
			
		}
		else if(c2=='s'||c2=='S')
		{
			myshangdian();
			
		}	
	}
	
	
	
	
	
}
void jineng::anpaimian()
{
    cleardevice();
	IMAGE person2,person_2,background2;
	loadimage(&background2,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	putimage(0,0,&background2);
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
	setbkmode(TRANSPARENT);
	settextcolor(RGB(102,51,0));
	outtextxy(260,90,B.returngaoshu());
	outtextxy(260,130,B.returncyuyan());
	outtextxy(260,170,B.returnyingyu());
	outtextxy(260,210,"B站  ④");
	outtextxy(260,250,"社交  ⑤");
	outtextxy(260,290,"打工  ⑥");
	char c2=0;
	while(true)
	{
		setbkcolor(WHITE);
		c2=getch();
		if(c2==27)
		{
			break;
			
		}
		
		else if(c2=='1'&&B.gaoshudengji==1)
		{
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			gaoshud((h+suiji)%4);
			B.gaoshushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='1'&&B.gaoshudengji==2)
		{
			
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			gaoshub((h+suiji)%4);
			B.gaoshushu++;
			h--;
			tufashijian();
			break;
		}
		else if(c2=='1'&&B.gaoshudengji==3)
		{
			
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			gaoshua((h+suiji)%4);
			B.gaoshushu++;
			h--;
			tufashijian();
			
			break;
		}
		else if(c2=='2'&&B.cyuyandengji==1)
		{
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			fcyuyan((h+suiji)%4);
			B.cyuyanshu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='2'&&B.cyuyandengji==2)
		{
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			dcyuyan((h+suiji)%4);
			B.cyuyanshu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='3'&&B.yingyudengji==1)
		{
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			yingyu2((h+suiji)%4);
			B.yingyushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='3'&&B.yingyudengji==2)
		{
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			yingyu3((h+suiji)%3);
			B.yingyushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='3'&&B.yingyudengji==3)
		{
			if(A.ya>=70)
			{
				zimu1("对不起您的压力值太高了，不适合继续进行学习，请去减减压");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				getch();
				break;
				
				
			}
			cleardevice();
			yingyu4((h+suiji)%3);
			B.yingyushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		
		
		else if(c2=='4')
		{
			cleardevice();
			bilibili();
			h--;
			tufashijian();
			break;
		}
		else if(c2=='5' &&A.zhai<70)
		{
			cleardevice();
			shejiao();
			h--;
			tufashijian();
			break;
		}
		else if(c2=='5'&&A.zhai>=70)
		{
			zimu1("死宅值太高了，不想出宿舍，无法社交");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
			getch();
			break;
			
			
		}
		else if(c2=='6')
		{
			cleardevice();
			dagong((h+suiji)%4);
			h--;
			tufashijian();
			break;
			
			
		}
		
	}
	
	
	
	cleardevice();
	
	
	
	jiemian();
    
	
}
void jineng::shengji()
{
	cleardevice();
	IMAGE person2,person_2,background2;
	loadimage(&background2,_T("图片\\死宅宿舍.jpg"),0,0,true);
	loadimage(&person2,_T("图片\\熊猫人2.jpg"),180,180,true);
    loadimage(&person_2,_T("图片\\熊猫人2屏蔽图.jpg"),180,180,true);
	
	putimage(0,0,&background2);
	putimage(20,350,&person_2,SRCPAINT);
	putimage(20,350,&person2,SRCAND);
	setcolor(RGB(238,197,145));
	setfillcolor(RGB(238,197,145));
	fillrectangle(250,10,650,520);
	char shengji[20]="快来偷读";
	setbkcolor(RGB(238,194,145));
	settextstyle(30, 15, _T("宋体"));    
	settextcolor(BLACK);
	outtextxy(350,20,shengji);
	char *gaodengshuxue[3]={"高等数学D  ①","高等数学B  ①","高等数学A  ①"};
	char *ccyuyan[2]={"C++非电类  ②","C++电类  ②"};
	char *daxueyingyu[3]={"英语二级  ③","英语三级  ③","英语四级  ③"};
	if(B.gaoshudengji<3)
	{
		outtextxy(300,50,gaodengshuxue[B.gaoshudengji]);
	}
	if(B.cyuyandengji<2)
	{
		outtextxy(300,90,ccyuyan[B.cyuyandengji]);
	}
	if(B.yingyudengji<3)
	{
		outtextxy(300,130,daxueyingyu[B.yingyudengji]);
	}
	char c3=0;
	while(true)
	{
		c3=getch();
		if(c3==27)
		{
			break;
		}
		else if(c3=='1'&&B.gaoshudengji<3)
		{
			char a[]={"升级该技能需要消耗200 元，是否继续升级（Y 是）（N 否）"};
			char b[]={"升级成功，SRTP+7，快去安排吧"};
			char c[]={"金币不足，快去赚钱吧"};
			char d=0;
			zimu1(a);
			
			while(true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				d=getch();
				if(d=='y'||d=='Y'||d=='n'||d=='N')
				{
					break;
				}
			}
			if(d=='y'||d=='Y')
			{
				if(A.money>=200)
				{
					B.getgaoshu(gaodengshuxue[B.gaoshudengji]);
					B.gaoshudengji++;
					A.srtp+=7;
					A.money-=200;
					if(A.srtp>100)
					{
						A.srtp=100;
					}
					zimu1(b);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
					getch();
					break;
					
				}
				else 
				{
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
					getch();
					break;
					
				}
			}
			else 
			{
				B.shengji();
			}
		}
		else if(c3=='2'&&B.cyuyandengji<2)
		{
			char a[]={"升级该技能需要消耗200 元，是否继续升级（Y 是）（N 否）"};
			char b[]={"升级成功，SRTP+7，快去安排吧"};
			char c[]={"金币不足，快去赚钱吧"};
			char d=0;
			zimu1(a);
			
			while(true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				d=getch();
				if(d=='y'||d=='Y'||d=='n'||d=='N')
				{
					break;
				}
			}
			if(d=='y'||d=='Y')
			{
				if(A.money>=200)
				{
					B.getcyuyan(ccyuyan[B.cyuyandengji]);
					B.cyuyandengji++;
					A.srtp+=7;
					A.money-=200;
					if(A.srtp>100)
					{
						A.srtp=100;
					}
					zimu1(b);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
					getch();
					break;
					
				}
				else 
				{
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
					getch();
					break;
					
				}
			}
			else 
			{
				B.shengji();
			}
			
			
		}
		else if(c3=='3'&&B.yingyudengji<3)
		{
			char a[]={"升级该技能需要消耗200 元，是否继续升级（Y 是）（N 否）"};
			char b[]={"升级成功，SRTP+7，快去安排吧"};
			char c[]={"金币不足，快去赚钱吧"};
			char d=0;
			zimu1(a);
			
			while(true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
				d=getch();
				if(d=='y'||d=='Y'||d=='n'||d=='N')
				{
					break;
				}
			}
			if(d=='y'||d=='Y')
			{
				if(A.money>=200)
				{
					B.getyingyu(daxueyingyu[B.yingyudengji]);
					B.yingyudengji++;
					A.srtp+=7;
					A.money-=200;
					if(A.srtp>100)
					{
						A.srtp=100;
					}
					zimu1(b);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
					getch();
					break;
					
				}
				else 
				{
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
					getch();
					break;
					
				}
			}
			else 
			{
				B.shengji();
			}
			
			
		}
	}
	cleardevice();
	jiemian();
	
}
void tufashijian()
{
	C.shangdianchushihua();
	
	if(h==15)
	{
		cleardevice();
		qizhongkao();
	}
	if(h==20)
	{
		cleardevice();
		hongbaolai();
	}
	if(h==10)
	{
		cleardevice();
		wanyouxi();
		
		
	}
	if(h==5)
	{
		cleardevice();
		qimokao();
	}
	if(h%3==0)
	{
		cleardevice();
		paocao();
	}
	if(h==22)
	{
		cleardevice();
		jiangzuo();
	}
	if(h==13)
	{
		cleardevice();
		jiangzuo();
	}
	if(chuqianguan!=0)
	{
		A.money=(int)(A.money*(1+0.05*chuqianguan));
		int i=(int)(0.05*A.money*chuqianguan);
		char a[20]={0};
		sprintf(a,"%d",i);
		char b[]={"拥有储钱罐，生活费+ "};
		strcat(b,a);
		IMAGE background1;
		loadimage(&background1,_T("图片\\死宅宿舍.jpg"),0,0,true);
		putimage(0,0,&background1);
		
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
		getch();
		
	}
	if(h==-1)
	{
		setbkcolor(WHITE);
		cleardevice();
		IMAGE kaixue;
		loadimage(&kaixue,_T("图片\\开学.jpg"),690,532,true);
		
		mciSendString(TEXT("close mysong "),NULL,0,NULL);
		mciSendString(TEXT("open bgm\\结尾音乐.mp3 alias jieweimusic"),NULL,0,NULL);
		mciSendString(TEXT("play jieweimusic repeat"),NULL,0,NULL);
		
		
		putimage(0,0,&kaixue);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //清空键盘区缓存
		getch();
		
		jiewei();
		
	}
	cleardevice();
}



void main()
{
	initgraph(690,532);
	beijing();    
}








