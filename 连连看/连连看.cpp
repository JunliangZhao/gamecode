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
int graph[100][100];
int n=10;
int m=14;
struct Node
{
	int x;
	int y;//这边的x y指代的是行和列  并不是实际坐标  并且和实际坐标是相反的
};
struct record
{
	int time;//剩余时间
	int mark;//分数
};
IMAGE mybk,mybk1;
float mytime=360;//时间
int succeed=0;//是否结束
int score;//得分
int find=0;//目前找到的个数
int lasttime=360;
int music=0;
int washtime=1;
int remindtime=2;
Node start,end;//记录
Node remind1,remind2;//提示记录1 记录2
IMAGE jpg[14];
int choicenum=0;//判定选中的个数
int judge();//判定是否可以消除
int remind();//提示函数
void remindfun();//找提示
void washcard();//手动洗牌
void washcard()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<14;j++)
		{
			int tempflag=0;
			for(int k=i;k<10;k++)//随机洗牌交换位置
			{
				for(int l=j+1;l<14;l++)
				{
					if(graph[k][l]!=0)
					{
						int temp=graph[k][l];
						graph[k][l]=graph[i][j];
						graph[i][j]=temp;
						tempflag=1;
						break;
						
					}
					
				}
				if(tempflag==1)
				{
					break;
				}
			}
		}
	}
}
void putbutton(int x,int y,int w,int h,char s[25])
{
	setcolor(BLACK);
	settextcolor(BLACK);
	settextstyle(20,0,_T("宋体"));
	rectangle(x,y,x+w,y+h);
	outtextxy(x+10,y+10,s);
}
void init()//初始化数据
{
	settextstyle(20,0,_T("宋体"));//设置字体
	int tempjpg[14]={0};
	srand(unsigned(time(0)));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			graph[i][j]=rand()%13+1;
		}
	}
	for(i=0;i<n;i++)//保证10组以上偶数
	{
		if(i%2==0)
		{
			continue;
		}
		for(int j=0;j<m;j++)
		{
			if(j%3!=0)
			{
				continue;
			}
			int tempi=rand()%2;
			if(tempi==0)
			{
				graph[i-1][j]=graph[i][j];
			}
			else 
			{
				graph[i][j+1]=graph[i][j];
			}
			
		}
	}
	for( i=0;i<n;i++)//统计地图上各种数字的数量
	{
		for(int j=0;j<m;j++)
		{
			tempjpg[graph[i][j]]++;
		}
	}
	for(i=1;i<=13;i++)//对奇数个的数量进行修改成偶数个
	{
		if(tempjpg[i]%2!=0)
		{
			for(int j=i+1;j<=13;j++)
			{
				if(tempjpg[j]%2!=0)
				{
					tempjpg[i]--;
					tempjpg[j]++;
					int tempflag=0;
					for(int x=0;x<n;x++)
					{
						for(int y=0;y<m;y++)
						{
							if(graph[x][y]==i)
							{
								graph[x][y]=j;
								tempflag=1;
								break;
								
							}
						}
						if(tempflag)
						{
							break;
						}
					}
					
				}
			}
		}
	}
	for(i=1;i<=13;i++)
	{	
		char tempname[20]="a.JPG";
		tempname[0]=i+96;
		loadimage(&jpg[i],_T(tempname),40,40,true);
	}
	remind1.x=-100;
	remind1.y=-100;
	remind2.x=-100;
	remind2.y=-100;
	mytime=360;
	succeed=0;
	score;
	find=0;
	choicenum=0;
	lasttime=360;
	washtime=1;
	remindtime=2;
	
}

void draw()//批量绘制函数  每一帧地图的绘制
{
	BeginBatchDraw();
	char s[50];
	char ss[50];
	char sss[50];
	char ssss[50];
	cleardevice();
	putimage(0,0,&mybk1);
	setbkmode(TRANSPARENT);
	int temptime=mytime;

	settextstyle(25,0,_T("黑体"));
	sprintf(s,"时间：%d",temptime);
	sprintf(ss,"得分：%d",score);
	settextstyle(20,0,_T("黑体"));
	sprintf(sss,"提示次数%d",remindtime);
	sprintf(ssss,"洗牌次数%d",washtime);
	putbutton(200,10,100,40,"提示");
	putbutton(350,10,100,40,"洗牌");
	putbutton(500,10,100,40,"退出");
	settextcolor(BLACK);
	outtextxy(10,10,s);
	outtextxy(10,30,ss);
	outtextxy(10,50,sss);
	outtextxy(10,70,ssss);
	setcolor(RED);
	setfillcolor(RED);
	fillrectangle(195,95,905,605);
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillrectangle(200,100,900,600);
	setfillcolor(GREEN);
	fillrectangle(50*remind1.y+200,50*remind1.x+100,50*remind1.y+250,50*remind1.x+150);
	fillrectangle(50*remind2.y+200,50*remind2.x+100,50*remind2.y+250,50*remind2.x+150);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			if(graph[i][j]==0)
			{
				setcolor(WHITE);
				setfillcolor(WHITE);
				fillrectangle(50*j+205,50*i+105,50*j+245,50*i+145);
			}
			else 
			{
				
				if((start.x==i && start.y==j &&choicenum>=1))
				{
					
					putimage(50*j+200,50*i+100,&jpg[graph[i][j]]);
					continue;
				}

				if((end.x==i &&end.y==j && choicenum>=2))
				{
					putimage(50*j+200,50*i+100,&jpg[graph[i][j]]);
					continue;
				}
				
				putimage(50*j+205,50*i+105,&jpg[graph[i][j]]);
			}
		}
	}
	
	
	FlushBatchDraw();
}
void choice()//鼠标控制函数
{
	MOUSEMSG m;
	if(MouseHit())
	{
		m=GetMouseMsg();//获取鼠标信息
		//比对鼠标信息确定功能
		if(m.uMsg==WM_LBUTTONDOWN && m.x>=205 && m.x<=895 && m.y>=105 && m.y<=595)
		{
			
			
			if(choicenum==0)
			{
				
				start.x=(m.y-105)/50;
				start.y=(m.x-205)/50;
				choicenum++;
			}
			else if(choicenum==1)
			{
				if(!(start.x==(m.y-105)/50 && start.y==(m.x-205)/50))
				{
					end.x=(m.y-105)/50;
					end.y=(m.x-205)/50;
					choicenum++;
				}
				else
				{
					choicenum--;
				}
				
				
				
			}
			else if((m.y-105)/50==start.x && start.y==(m.x-205)/50)
			{
				choicenum=0;
			}
			else if((m.y-105)/50==end.x&& end.y==(m.x-205)/50)
			{
				choicenum--;
			}
			if(graph[start.x][start.y]==0)
			{
				choicenum--;
			}
			
			
			
			
		}
		if(m.uMsg==WM_LBUTTONDOWN && m.x>=200 && m.x<=300 && m.y>=10 && m.y<=50 && remindtime>0)//提示
		{
			remindfun();
			remindtime--;
		}
		if(m.uMsg==WM_LBUTTONDOWN && m.x>=350 && m.x<=450 && m.y>=10 && m.y<=50 && remindtime>0)//洗牌
		{
			washcard();
			washtime--;
		}
		
		if(m.uMsg==WM_LBUTTONDOWN && m.x>=500 && m.x<=600 && m.y>=10 && m.y<=50)//退出
		{
			succeed=1;
		}
		FlushMouseMsgBuffer();
		
	}
}

void draw(int temp[100][100])
{
	setfillcolor(RED);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(temp[i][j]!=-1)
			{
				fillrectangle(50*j+205,50*i+105,50*j+245,50*i+145);
			}
		}
	}
	FlushBatchDraw();
	char c=getch();
	
}
int judge()//进行广度
{
	int i=0;
	
	int temp[100][100];
	for(i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			temp[i][j]=-1;
		}
	}
	temp[end.x][end.y]=0;
	int tempcolor=graph[start.x][start.y];
	if(tempcolor!=graph[end.x][end.y])
	{
		return 0;
	}
	graph[start.x][start.y]=0;
	for(int ii=0;ii<3;ii++)
	{
		for(i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(temp[i][j]==ii)
				{
					int l=0;
					for(l=i-1;l>=0;l--)
					{
						if(graph[l][j]!=0 )
						{
							break;
						}
						if(temp[l][j]==-1)
						{
							temp[l][j]=ii+1;
						}
					}
					for(l=i+1;l<n;l++)
					{
						if(graph[l][j]!=0)
						{
							break;
						}
						if(temp[l][j]==-1)
						{
							temp[l][j]=ii+1;
						}	
					}
					for(l=j+1;l<m;l++)
					{
						if(graph[i][l]!=0)
						{
							break;
						}
						if(temp[i][l]==-1)
						{
							temp[i][l]=ii+1;
						}
					}
					
					for(l=j-1;l>=0;l--)
					{
						if(graph[i][l]!=0)
						{
							break;
						}
						if(temp[i][l]==-1)
						{
							temp[i][l]=ii+1;
						}
					}
					
					
				}
			}
		}
	}
	
	if(temp[start.x][start.y]!=-1)
	{
		find++;
		if(lasttime-mytime<=2)
		{
			score+=4;
		}
		else
		{
			score+=2;
		}
		remind1.x=-100;
		remind1.y=-100;
		remind2.x=-100;
		remind2.y=-100;
		graph[start.x][start.y]=0;
		graph[end.x][end.y]=0;
		choicenum=0;
		lasttime=mytime;
		return 1;
		
	}
	else
	{
		
		graph[start.x][start.y]=tempcolor;
		return 0;
	}
}
int remind()//提示算法
{
	int i=0;
	
	int temp[100][100];
	for(i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			temp[i][j]=-1;
		}
	}
	temp[remind2.x][remind2.y]=0;
	int tempcolor=graph[remind1.x][remind1.y];
	if(tempcolor!=graph[remind2.x][remind2.y])
	{
		return 0;
	}
	graph[remind1.x][remind1.y]=0;
	for(int ii=0;ii<3;ii++)
	{
		for(i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(temp[i][j]==ii)
				{
					int l=0;
					for(l=i-1;l>=0;l--)
					{
						if(graph[l][j]!=0 )
						{
							break;
						}
						if(temp[l][j]==-1)
						{
							temp[l][j]=ii+1;
						}
					}
					for(l=i+1;l<n;l++)
					{
						if(graph[l][j]!=0)
						{
							break;
						}
						if(temp[l][j]==-1)
						{
							temp[l][j]=ii+1;
						}	
					}
					for(l=j+1;l<m;l++)
					{
						if(graph[i][l]!=0)
						{
							break;
						}
						if(temp[i][l]==-1)
						{
							temp[i][l]=ii+1;
						}
					}
					
					for(l=j-1;l>=0;l--)
					{
						if(graph[i][l]!=0)
						{
							break;
						}
						if(temp[i][l]==-1)
						{
							temp[i][l]=ii+1;
						}
					}
					
					
				}
			}
		}
	}
	
	
	if(temp[remind1.x][remind1.y]!=-1)
	{
		graph[remind1.x][remind1.y]=tempcolor;	
		return 1;
		
	}
	else
	{
		graph[remind1.x][remind1.y]=tempcolor;
		return 0;
	}
}
void remindfun()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(graph[i][j]!=0)
			{
				remind1.x=i;
				remind1.y=j;
				for(int jj=j+1;jj<m;jj++)
				{
				}
				for(int ii=i+1;ii<n;ii++)
				{
					for(jj=0;jj<m;jj++)
					{
						if(graph[ii][jj]!=0)
						{
							remind2.x=ii;
							remind2.y=jj;
							if(remind()==1)
							{
								
								return;
							}
							
						}
						
					}
				}
				
			}
		}
	}
	remind1.x=-100;
	remind1.y=-100;
	remind2.x=-100;
	remind2.y=-100;
	
}


void startgame()
{
	
	
	
	int i=0;
	init();
	
	while(true)
	{
		mytime=mytime-0.002;
		choice();
		draw();
		if(choicenum>=2)
		{
			Sleep(100);
			int temp=judge();
			if(temp!=1)
			{
				choicenum=1;
				start=end;
			}
		}
		if(find>=70)
		{
			succeed=3;
		}
		if(mytime<=0)
		{
			succeed=2;
		}
		if(succeed!=0)
		{
			return;
		}
	
		
	}
	
	
}
void paihang()
{
	EndBatchDraw();
	cleardevice();//清空之前的绘制
	putimage(0,0,&mybk);
	setbkmode(TRANSPARENT);
	FILE *f=fopen("score.txt","r");
	record myrank[50];
	int ii=0;
	while(!feof(f))
	{
		fscanf(f,"%d%d",&myrank[ii].mark,&myrank[ii].time);
		fgetc(f);
		ii++;
	}
	ii--;
	//进行成绩排序
	for(int i=0;i<ii;i++)//对读取的结果进行排序
	{
		for(int j=i;j<ii;j++)
		{
			if(myrank[i].mark<myrank[j].mark)//分数高的排前面
			{
				record temp=myrank[i];
				myrank[i]=myrank[j];
				myrank[j]=temp;
			}
			else if(myrank[i].mark==myrank[j].mark)//如果分数相同 按照剩余时间多的排序
			{
				if(myrank[i].time<myrank[j].time)
				{
					record temp=myrank[i];
					myrank[i]=myrank[j];
					myrank[j]=temp;
				}
			}
		}
	}
	
	
	outtextxy(10,5,"按ESC退出");
	settextstyle(30,0,_T("楷体"));
	outtextxy(300,100,"排名       分数        时间");
	if(ii<8)//排行榜可以输出前八名  下列为分开输出函数，确保输出不超过8人
	{
		for(int j=0;j<ii;j++)
		{
			char mytemp[100];
			sprintf(mytemp,"%3d          %3d         %3d",j+1,myrank[j].mark,myrank[j].time);
			outtextxy(280,100+j*50+50,mytemp);
		}
		
	}
	else
	{
		for(int j=0;j<7;j++)
		{
			char mytemp[100];
			sprintf(mytemp,"%3d          %3d         %3d",j+1,myrank[j].mark,myrank[j].time);
			outtextxy(280,100+j*50+50,mytemp);
		}
	}
	while(true)
	{
		char c=getch();
		if(c==27)
		{
			return;
		}
	}
	
}
void shezhi()
{
	while(true)
	{
		mciSendString(TEXT("open bgm//bgm.mp3 alias song"),NULL,0,NULL);//加载音乐
		cleardevice();
		settextstyle(30,0,_T("楷体"));
		putimage(0,0,&mybk);
		setbkmode(TRANSPARENT);
		outtextxy(200,100,"按空格开关音乐，按ESC返回菜单");
		settextstyle(50,0,_T("楷体"));	
		setcolor(WHITE);
		if(music==1)
		{
			outtextxy(300,300,"音乐开启");
		}
		else 
		{
			outtextxy(300,300,"音乐关闭");
		}
		
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //清空键盘缓存
		char c=getch();
		if(c==32)
		{
			if(music==0)
			{
				music=1;
				mciSendString(TEXT("play song repeat"),NULL,0,NULL);//开音乐
				
			}
			else if(music==1)
			{
				music=0;
				mciSendString(TEXT("stop song"),NULL,0,NULL);//关音乐
			}
			
		}
		else if(c==27)
		{
			return;
		}
	}
}

void main()
{
	initgraph(1000,700);
	loadimage(&mybk,_T("bk.jpg"),1000,700,true);
	loadimage(&mybk1,_T("mybk1.JPG"),1000,700,true);
	while(true)
	{
		
		settextstyle(50,0,_T("楷体"));		
		cleardevice();
		BeginBatchDraw();
		putimage(0,0,&mybk);
		setbkmode(TRANSPARENT);
		outtextxy(350,140,"1.开始游戏");
		outtextxy(350,240,"2.游戏设置");
		outtextxy(350,340,"3.游戏排行");
		outtextxy(350,440,"4.退出游戏");
		EndBatchDraw();
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //清空键盘缓存
		char c=getch();
		if(c=='1')
		{
			init();
			startgame();
			EndBatchDraw();
			cleardevice();
			setcolor(WHITE);
			putimage(0,0,&mybk);
			setbkmode(TRANSPARENT);
			settextstyle(50,0,_T("楷体"));
			FILE *scorerank=fopen("score.txt","a+");
			int temptime=mytime;
			fprintf(scorerank,"%d %d\n",score,temptime);//保存记录
			fclose(scorerank);
			char s[100],ss[100];
			sprintf(s,"时间：%d",temptime);
			sprintf(ss,"得分：%d",score);
			outtextxy(250,100,s);//输出时间
			outtextxy(250,200,ss);//输出得分
			if(succeed==1 || succeed==2)//判定输赢
			{
				outtextxy(250,300,"很遗憾失败了");
			}
			else if(succeed==3)//判定输赢
			{
				outtextxy(250,300,"成功");
			}
			outtextxy(250,400,"按任意键返回菜单");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //清空键盘缓存
			getch();
			
		}
		else if(c=='2')
		{
			shezhi();
		}
		else if(c=='3')
		{
			paihang();
		}
		else if(c=='4')
		{
			break;
			
		}
		
		
		
		
		
		
	}
	
}
