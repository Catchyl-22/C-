#include"Hook.h"
#include<iostream>
Hook::Hook(const Role& a)
	:role(a)
{
	x = role.x + 50;
	y = role.y + 90;
	len = 50;
	endx = x;
	endy = y + len;
	angle = 0;
	dir = RIGHT;
	vx = 0;
	vy = 0;
	state = M_NOMAL;
	index = -1;
	for (int i = 0; i < 5; i++)prop_f[i] = 1;
	prop[0] = 5;
	prop[1] = 5;
}

void Hook::HookRock()//钩子摆动
{
	if (state == M_NOMAL)
	{
		if (dir == RIGHT)
		{
			angle+=ANGLE_SPEED;
		}
		else
		{
			angle-= ANGLE_SPEED;
		}
		if (angle > MAX_ANGLE)
		{
			dir = LEFT;
		}
		else if (angle < -MAX_ANGLE)
		{
			dir = RIGHT;
		}
		//角度转弧度  360 2pai  180  PI  
		endx = x + (int)(sin(PI / 180 * angle) * len);
		endy = y + (int)(cos(PI / 180 * angle) * len);
	}
}
//钩子抓取
void Hook::GameControl(int &speed)
{
	if (GetAsyncKeyState(VK_SPACE) && state == M_NOMAL)
	{
		//按键，求出速度分量
		vx = (int)(sin(PI / 180 * angle) * speed);
		vy = (int)(cos(PI / 180 * angle) * speed);
		state = M_LONG;
	}
	//碰到边界返回
	if (endx<0 || endx>WIN_WIDTH || endy > WIN_HEIGHT)
	{
		state = M_SHORT;
	}
	if (state == M_LONG)
	{
		endx += vx;
		endy += vy;
	}
	else if (state == M_SHORT)
	{
		vx= (int)(sin(PI / 180 * angle) * speed);
		vy= (int)(cos(PI / 180 * angle) * speed);
		endx -= vx;
		endy -= vy;
		//缩短完成
		if (distance())
		{
			state = M_NOMAL;
		}
	}
}

int Hook::distance()//判断距离
{
	int dis = (int)(sqrt((double)((x - endx) * (x - endx) + (y - endy) * (y - endy))));
	return (dis <= len)||(endy<y+50);
}


void Hook::DrawHook()//画绳子
{
	setlinecolor(BROWN);
	setlinestyle(PS_SOLID, 5);
	line(x, y, endx, endy);
}
void Hook::draw_hook()//生成钩子图片
{
	IMAGE HOOK_1;
	IMAGE HOOK_2;
	loadimage(&HOOK_1, "./images/GZ.jpg", 40, 40);
	loadimage(&HOOK_2, "./images/GZD.jpg", 40, 40);
	putimage(endx - 20, endy - 10, &HOOK_1, SRCAND);
	putimage(endx - 20, endy - 10, &HOOK_2, SRCPAINT);

}
void Hook::clearhook()
{
	x = role.x + 50;
	y = role.y + 90;
	len = 50;
	endx = role.x;
	endy = role.y + len;
	angle = 0;
	dir = RIGHT;
	vx = 0;
	vy = 0;
	state = M_NOMAL;
	index = -1;
}
void JudgeGrap(std::vector<Mine>& mine, Hook& hook,int MAX_MINE,int& speed,bool& f)
{
	//判断抓到那个物品
	if (f)
	{
		for (int i = 0; i < MAX_MINE; i++)
		{
			if (mine[i].flag == true &&
				hook.endx > mine[i].x - 15 && hook.endx<mine[i].x + 15 + mine[i].size &&
				hook.endy>mine[i].y + 30 && hook.endy < mine[i].y + 30 + mine[i].size)
			{
				hook.index = i;
				break;
			}
		}
	}
		//如果抓到了
		if (hook.index != -1 && mine[hook.index].flag)
		{
			if (f) 
			{
				if (mine[hook.index].type == GOLD|| mine[hook.index].type == DIOMAND)
				{
					mciSendString(_T("close ./music/gold.wav"), 0, 0, 0);
					mciSendString(_T("open ./music/gold.wav"), 0, 0, 0);
					mciSendString(_T("play ./music/gold.wav"), 0, 0, 0);
				}
				else if (mine[hook.index].type == STONE)
				{
					mciSendString(_T("close ./music/stone.aiff"), 0, 0, 0);
					mciSendString(_T("open ./music/stone.aiff"), 0, 0, 0);
					mciSendString(_T("play ./music/stone.aiff"), 0, 0, 0);
				}
				else
				{
					mciSendString(_T("close ./music/pig.wav"), 0, 0, 0);
					mciSendString(_T("open ./music/pig.wav"), 0, 0, 0);
					mciSendString(_T("play ./music/pig.wav"), 0, 0, 0);
				}
				//mciSendString(_T("open ./music/1.mp3"), 0, 0, 0);
				//mciSendString(_T("play ./music/1.mp3"), 0, 0, 0);
				if (mine[hook.index].size < 75) speed *= SLOW_RATE1;
				else if (mine[hook.index].size < 125) speed *= SLOW_RATE2;
				else speed *= SLOW_RATE3;
			}
			hook.state = M_SHORT;
			mine[hook.index].x = hook.endx - mine[hook.index].size / 2;
			mine[hook.index].y = hook.endy - mine[hook.index].size / 4;
			f = false;
			//缩短完成
			if (hook.distance())
			{
				hook.role.coin += mine[hook.index].gold;
				mine[hook.index].flag = false;
				hook.index = -1;
				hook.state = M_NOMAL;
				speed = NORMAL_SPEED; 
				//mciSendString(_T("close ./music/1.mp3"), 0, 0, 0);
				f = true;
			}
		}
		for (int i = 0; i < 5; i++) hook.prop_f[i] = 1;
}
void Prop0(Role& role, std::vector<Mine>& mine, Hook& hook,int &speed,bool& f)
{
	//条件是按了按钮并且有炸药库存
	//&& hook.index != -1
	if ((GetAsyncKeyState('A')) && hook.prop[0] > 0 && hook.prop_f[0] == 1&&hook.index!=-1)
	{
		mciSendString(_T("close ./music/bomb.mp3"), 0, 0, 0);
		mciSendString(_T("open ./music/bomb.mp3"), 0, 0, 0);
		mciSendString(_T("play ./music/bomb.mp3"), 0, 0, 0);
		hook.prop_f[0] = 0;
		hook.prop[0]--;
		for (int i = 0; i < mine.size(); i++)
		{
			if
				(mine[i].flag == true && ((mine[i].x > hook.endx - 100 && mine[i].y > hook.endy - 100)) && (mine[i].x < hook.endx + 100 && mine[i].y < hook.endy + 100))
			{
				mine[i].flag = false;
				mine[i].gold = 0;
			}
		}
		speed = NORMAL_SPEED;
		f = true;
	}
}
void Prop1(Role& role, std::vector<Mine>& mine, Hook& hook,int&speed)//条件是按了按钮并且有库存且抓到物体
{
	if ((GetAsyncKeyState('S')) && hook.prop[1] > 0 && hook.prop_f[1] == 1&& hook.index != -1&&mine[hook.index].flag)
	{
		mciSendString(_T("close ./music/yaoshui.wav"), 0, 0, 0);
		mciSendString(_T("open ./music/yaoshui.wav"), 0, 0, 0);
		mciSendString(_T("play ./music/yaoshui.wav"), 0, 0, 0);
		hook.prop_f[1] = 0;
		hook.prop[1]--;
		speed*=3;
	}
}