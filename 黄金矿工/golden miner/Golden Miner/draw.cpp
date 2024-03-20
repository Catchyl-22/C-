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
	//���ر���
	srand((unsigned int)(time(0)));
	for (int i = 0; i < MAX_MINE; i++)
	{
		int temptemp = rand();
		int k = temptemp % 15, si;
		if (k % 2 == 0)si = 100 + temptemp % 50;
		else si = 100 - temptemp % 50;
		if (k == 0||k == 1)//��ʯ
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, si / 2, DIOMAND, (temptemp % 200 + 50) * (si / 50), "./images/m0.jpg", "./images/mm0.jpg", true);
			mine.push_back(temp);
		}
		else if (k == 2||k == 3 || k == 4 || k == 5)//����
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, si, GOLD, (temptemp % 150 + 25) * (si / 50), "./images/m1.jpg", "./images/mm1.jpg", true);
			mine.push_back(temp);
		}
		else if (k == 6||k == 7||k == 11)//ʯͷ
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, si, STONE, (temptemp % 50 + 1) * (si / 50), "./images/m3.jpg", "./images/mm3.jpg", true);
			mine.push_back(temp);
		}
		else if (k == 8|| k == 9|| k == 10)//��
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, 60, PIG, (temptemp % 50 + 50) * (si / 50), "./images/m4.jpg", "./images/mm4.jpg", true);
			mine.push_back(temp);
		}
		else//��ʯ��
		{
			Mine temp(temptemp % (WIN_WIDTH - si), temptemp % (WIN_HEIGHT - 150) + 150, 60, DIOMANDPIG, (temptemp % 100 + 100) * (si / 50), "./images/m5.jpg", "./images/mm5.jpg", true);
			mine.push_back(temp);
		}
	}
	//���������Ʒ
}
void drawgame(Role& role, vector<Mine>& mine, Hook& hook,int MAX_MINE,int&speed)
{
	IMAGE background;
	loadimage(&background, "./images/back.jpg", WIN_WIDTH, WIN_HEIGHT);
	//���ر���
	putimage(0, 0, &background);
	role.drawrole();
	char score[30] = "";
	sprintf(score, "������%d", hook.role.coin);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "����");
	outtextxy(20, 20, score);

	char prop1[30] = "";
	sprintf(prop1, "ըҩ[A]��%d", hook.prop[0]);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "����");
	outtextxy(900, 20, prop1);

	char prop2[30] = "";
	sprintf(prop2, "ҩˮ[S]��%d", hook.prop[1]);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "����");
	outtextxy(900, 50, prop2);
	//��ӡ������ҩˮ��ըҩ
	hook.GameControl(speed);
	//˦�����ж�
	for (int i = 0; i < MAX_MINE; i++)mine[i].Gamedraw();
	//��Ʒ����
	hook.DrawHook();
	hook.draw_hook();
	//������
}
void outputPage()//���ƿ�ʼ����
{
	initgraph(WIN_WIDTH, WIN_HEIGHT, SHOWCONSOLE);
	IMAGE backgroundmenu;
	loadimage(&backgroundmenu, _T("./images/background.jpg"), WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &backgroundmenu);
	//��ͼƬ������background��
	Button startbutton(200, 140, 240, 90, BLACK, _T("��ʼ��Ϸ"));
	Button closebutton(200, 280, 240, 90, BLACK, _T("������Ϸ"));
	Button musicbutton(200, 420, 240, 90, BLACK, _T("��Ϸ����"));
	//�����꣨0��0)������ͼƬ
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

		case WM_LBUTTONDOWN://����������
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
void drawtime(int tim, int limit)//����ʣ��ʱ��
{
	char time[30] = "";
	sprintf(time, "ʣ��ʱ�䣺%d", ((int)limit - tim));
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "����");
	outtextxy(700, 20, time);
}
void outputStore(Role& role, Hook& hook)//�����̵�
{
	int p = false;
	IMAGE backgroundstore;
	loadimage(&backgroundstore, _T("./images/background.jpg"), WIN_WIDTH, WIN_HEIGHT);
	//��ͼƬ������background��
	IMAGE zhadan_1, zhadan_2, yaoshui_1, yaoshui_2, next_1, next_2;
	loadimage(&yaoshui_1, _T("./images/���°׵�.png"), 149, 251);
	loadimage(&yaoshui_2, _T("./images/���ºڵ�.png"), 149, 251);
	loadimage(&zhadan_1, _T("./images/tnt�׵�.png"), 153, 150);
	loadimage(&zhadan_2, _T("./images/tnt�ڵ�.png"), 153, 150);
	loadimage(&next_1, _T("./images/��һ�ذ׵�.png"), 300, 100);
	loadimage(&next_2, _T("./images/��һ�غڵ�.png"), 300, 100);
	Button zhadan(150, 460, 149, 90, BLUE, "$50");
	Button yaoshui(450, 460, 149, 90, BLUE, "$100");
	//������Ʒ
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
		sprintf(prop1, "ըҩ��%d", hook.prop[0]);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "����");
		outtextxy(750, 20, prop1);

		char prop2[30] = "";
		sprintf(prop2, "ҩˮ��%d", hook.prop[1]);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "����");
		outtextxy(750, 80, prop2);

		char score[30] = "";
		sprintf(score, "��Ǯ��%d", hook.role.coin);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "����");
		outtextxy(750, 140, score);

		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
		{
			yaoshui.mouseInButton(m);
			zhadan.mouseInButton(m);
		}

		case WM_LBUTTONDOWN:                                            //����������
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
	//����Ʒ����
}
void drawresult(Role role, Hook hook)//���ƽ�������
{
	int i = 1;
	MOUSEMSG m;
	IMAGE backgroundmenu;
	char s[30] = "";
	loadimage(&backgroundmenu, _T("./images/background.jpg"), WIN_WIDTH, WIN_HEIGHT);      //��ͼƬ������background��
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

		sprintf(s, "��ķ���:%d", hook.role.coin);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(100, 0, "����");
		outtextxy(110, 200, s);
		sprintf(s, "������������е�������:%d", rank);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "����");
		outtextxy(110, 350, s);
		sprintf(s, "Ŀǰ��߷�Ϊ:%d", maxresult);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "����");
		outtextxy(110, 450, s);
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:                                            //����������
		{
			if (m.uMsg == WM_LBUTTONDOWN)
				i = 0;
		}
		}
		EndBatchDraw();
	}
}