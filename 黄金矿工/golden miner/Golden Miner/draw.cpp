#define _CRT_SECURE_NO_WARNINGS
#include"draw.h"
#include"game.h"
#include<windows.h>
#include<mmsystem.h>
#include<iostream>
#include<fstream>
#pragma comment(lib,"winmm.lib")
void drawback(Role& role, vector<Mine>& mine, Hook& hook,int MAX_MINE)
{
	IMAGE background;
	loadimage(&background, "./images/back.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &background);
	//加载背景
	srand((unsigned int)(time(0)));
	for (int i = 0; i < MAX_MINE; i++)
	{
		int temptemp = rand();
		int k = temptemp % 15, si;
		if (k % 2 == 0)si = 100 + temptemp % 50;
		else si = 100 - temptemp % 50;
		if (k == 0||k == 1)//钻石
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, si / 2, DIOMAND, (temptemp % 200 + 50) * (si / 50), "./images/m0.jpg", "./images/mm0.jpg", true);
			mine.push_back(temp);
		}
		else if (k == 2||k == 3 || k == 4 || k == 5)//金子
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, si, GOLD, (temptemp % 150 + 25) * (si / 50), "./images/m1.jpg", "./images/mm1.jpg", true);
			mine.push_back(temp);
		}
		else if (k == 6||k == 7||k == 11)//石头
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, si, STONE, (temptemp % 50 + 1) * (si / 50), "./images/m3.jpg", "./images/mm3.jpg", true);
			mine.push_back(temp);
		}
		else if (k == 8|| k == 9|| k == 10)//猪
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, 60, PIG, (temptemp % 50 + 50) * (si / 50), "./images/m4.jpg", "./images/mm4.jpg", true);
			mine.push_back(temp);
		}
		else//钻石猪
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, 60, DIOMANDPIG, (temptemp % 100 + 100) * (si / 50), "./images/m5.jpg", "./images/mm5.jpg", true);
			mine.push_back(temp);
		}
	}
	//随机生成物品
}
void drawgame(Role& role, vector<Mine>& mine, Hook& hook,int MAX_MINE,int&speed)
{
	IMAGE background;
	loadimage(&background, "./images/back.jpg", WIN_WIDTH, WIN_HEIGHT);
	//加载背景
	putimage(0, 0, &background);
	role.drawrole();
	char score[30] = "";
	sprintf(score, "分数：%d", hook.role.coin);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "楷体");
	outtextxy(20, 20, score);

	char prop1[30] = "";
	sprintf(prop1, "炸药[A]：%d", hook.prop[0]);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "楷体");
	outtextxy(900, 20, prop1);

	char prop2[30] = "";
	sprintf(prop2, "药水[S]：%d", hook.prop[1]);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "楷体");
	outtextxy(900, 50, prop2);
	//打印分数、药水，炸药
	hook.GameControl(speed);
	//甩钩子判断
	for (int i = 0; i < MAX_MINE; i++)mine[i].Gamedraw();
	//物品绘制
	hook.DrawHook();
	hook.draw_hook();
	//画钩子
}
void outputPage()//绘制开始界面
{
	initgraph(WIN_WIDTH, WIN_HEIGHT, SHOWCONSOLE);
	IMAGE backgroundmenu;
	loadimage(&backgroundmenu, _T("./images/background.jpg"), WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &backgroundmenu);
	//将图片加载入background中
	Button startbutton(200, 140, 240, 90, BLACK, _T("开始游戏"));
	Button closebutton(200, 280, 240, 90, BLACK, _T("结束游戏"));
	Button musicbutton(200, 420, 240, 90, BLACK, _T("游戏音乐"));
	//在坐标（0，0)处放置图片
	MOUSEMSG m;

	while (true)
	{
		BeginBatchDraw();
		startbutton.creatbutton();
		closebutton.creatbutton();
		musicbutton.creatbutton();
		m = GetMouseMsg();
		switch (m.uMsg)
		{

		case WM_MOUSEMOVE:
		{
			startbutton.mouseInButton(m);
			closebutton.mouseInButton(m);
			musicbutton.mouseInButton(m);
		}

		case WM_LBUTTONDOWN://鼠标左键按下
		{
			if (startbutton.clickButton(m))
			{
				if (playgame())
					putimage(0, 0, &backgroundmenu);
			}
			if (closebutton.clickButton(m))
			{
				closegraph();
				mciSendString(_T("close ./music/backgroundmusic.mp3"), 0, 0, 0);
				break;
			}
			if (musicbutton.clickButton(m))
			{
				mciSendString(_T("open ./music/backgroundmusic.mp3"), 0, 0, 0);
				mciSendString(_T("play ./music/backgroundmusic.mp3"), 0, 0, 0);
			}

		}
		}
		EndBatchDraw();
	}
}
void drawtime(int tim, int limit)//绘制剩余时间
{
	char time[30] = "";
	sprintf(time, "剩余时间：%d", ((int)limit - tim));
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "楷体");
	outtextxy(700, 20, time);
}
void outputStore(Role& role, Hook& hook)//绘制商店
{
	int p = false;
	IMAGE backgroundstore;
	loadimage(&backgroundstore, _T("./images/background.jpg"), WIN_WIDTH, WIN_HEIGHT);
	//将图片加载入background中
	IMAGE zhadan_1, zhadan_2, yaoshui_1, yaoshui_2, next_1, next_2;
	loadimage(&yaoshui_1, _T("./images/百事白底.png"), 149, 251);
	loadimage(&yaoshui_2, _T("./images/百事黑底.png"), 149, 251);
	loadimage(&zhadan_1, _T("./images/tnt白底.png"), 153, 150);
	loadimage(&zhadan_2, _T("./images/tnt黑底.png"), 153, 150);
	loadimage(&next_1, _T("./images/下一关白底.png"), 300, 100);
	loadimage(&next_2, _T("./images/下一关黑底.png"), 300, 100);
	Button zhadan(150, 460, 149, 90, BLUE, "$50");
	Button yaoshui(450, 460, 149, 90, BLUE, "$100");
	//绘制物品
	MOUSEMSG m;
	while (true)
	{
		BeginBatchDraw();
		putimage(0, 0, &backgroundstore);
		putimage(150, 270, &zhadan_1, SRCAND);
		putimage(150, 270, &zhadan_2, SRCPAINT);
		putimage(450, 210, &yaoshui_1, SRCAND);
		putimage(450, 210, &yaoshui_2, SRCPAINT);
		putimage(700, 270, &next_1, SRCAND);
		putimage(700, 270, &next_2, SRCPAINT);
		zhadan.creatbutton();
		yaoshui.creatbutton();

		char prop1[30] = "";
		sprintf(prop1, "炸药：%d", hook.prop[0]);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "楷体");
		outtextxy(750, 20, prop1);

		char prop2[30] = "";
		sprintf(prop2, "药水：%d", hook.prop[1]);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "楷体");
		outtextxy(750, 80, prop2);

		char score[30] = "";
		sprintf(score, "金钱：%d", hook.role.coin);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "楷体");
		outtextxy(750, 140, score);

		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
		{
			yaoshui.mouseInButton(m);
			zhadan.mouseInButton(m);
		}

		case WM_LBUTTONDOWN:                                            //鼠标左键按下
		{
			if (zhadan.clickButton(m) && hook.role.coin >= PRICE_BOOM)
			{
				hook.prop[0]++;
				hook.role.coin -= PRICE_BOOM;
				break;
			}
			if (yaoshui.clickButton(m) && hook.role.coin >= PRICE_YAOSHUI)
			{
				hook.prop[1]++;
				hook.role.coin -= PRICE_YAOSHUI;
				break;
			}
			if (m.x > 700 && m.x < 1000 && m.y>270 && m.y < 370 && (m.uMsg == WM_LBUTTONDOWN))
			{
				p = true;
				break;
			}
		}
		EndBatchDraw();
		}
		cleardevice();
		if (p)
			break;
	}
	//与物品互动
}
void drawresult(Role role, Hook hook)//绘制结束界面
{
	int i = 1;
	MOUSEMSG m;
	IMAGE backgroundmenu;
	char s[30] = "";
	loadimage(&backgroundmenu, _T("./images/background.jpg"), WIN_WIDTH, WIN_HEIGHT);      //将图片加载入background中
	int rank = 1;
	int maxresult = hook.role.coin;
	ifstream inallresults("allresults.txt", ios::in);
	if (inallresults)
	{
		int n;
		while (inallresults >> n)
		{
			if (n > hook.role.coin)
			{
				rank++;
				maxresult = max(maxresult, n);
			}
		}
	}
	inallresults.close();
	ofstream outallresults("allresults.txt", ios::app);
	outallresults << hook.role.coin << endl;
	outallresults.close();
	while (i)
	{
		BeginBatchDraw();
		m = GetMouseMsg();
		putimage(0, 0, &backgroundmenu);

		sprintf(s, "你的分数:%d", hook.role.coin);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(100, 0, "楷体");
		outtextxy(110, 200, s);
		sprintf(s, "你在所有玩家中的排名是:%d", rank);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "楷体");
		outtextxy(110, 350, s);
		sprintf(s, "目前最高分为:%d", maxresult);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "楷体");
		outtextxy(110, 450, s);
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:                                            //鼠标左键按下
		{
			if (m.uMsg == WM_LBUTTONDOWN)
				i = 0;
		}
		}
		EndBatchDraw();
	}
}