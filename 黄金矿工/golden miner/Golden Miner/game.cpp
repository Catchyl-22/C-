#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

int playgame()
{
	int gametimes = 2;
	Role role;
	Hook hook(role);
	while (1)
	{
		vector<Mine>mine;
		drawback(role, mine, hook, max_mine);
		DWORD t1, t2;
		t1 = t2 = time(0);
		int speed = NORMAL_SPEED;
		bool f = true;
		int tt1 = time(0);
		while (1)
		{
			if (f)	hook.HookRock();
			Prop1(role, mine, hook,speed);
			drawgame(role, mine, hook, max_mine,speed);

			if (time(0) - tt1 >= NORMAL_TIME || time(0) - tt1 < 0)
			{
				hook.clearhook();
				speed = NORMAL_SPEED;
				break;
			}
			drawtime(time(0) - tt1);
			FlushBatchDraw();
			hook.GameControl(speed);
			JudgeGrap(mine, hook, max_mine, speed, f);
			//·ÀÖ¹ÉÁÍË
			Prop0(role, mine, hook, speed, f);
		}
		if (gametimes)
		{
			outputStore(role, hook);
		}
		else
		{
			drawresult(role,hook);
			return 1;
		}
		gametimes--;
		cleardevice();

	}
	return 1;
}