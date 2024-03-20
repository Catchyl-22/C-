#ifndef HOOK_H
#define HOOK_H
#include"Role.h"
#include"Mine.h"
class Hook
{
	friend void JudgeGrap(std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed, bool& f);
	friend void Prop0(Role& role, std::vector<Mine>& mine, Hook& hook, int&, bool& f);
	friend void Prop1(Role& role, std::vector<Mine>& mine, Hook& hook, int& speed);
	friend void drawback(Role& role, std::vector<Mine>& mine, Hook& hook, int MAX_MINE);
	friend void drawgame(Role& role, std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed);
	friend void outputStore(Role& role, Hook& hook);
	friend void drawresult(Role role, Hook hook);
public:
	Hook(const Role& a);
	void clearhook();
	~Hook() {}
	void HookRock();
	void draw_hook();
	int distance();
	void GameControl(int&);
	void DrawHook();
private:
	int x;
	int y;
	int endx;
	int endy;
	int len;//����
	int angle;//�Ƕ�
	int dir;//�ڶ�����
	int vx;//�ٶȷ���
	int vy;
	int state;
	int index;//��¼ץ������Ʒ�±�
	Role role;
	int prop[5] = { 0 };//����
	bool prop_f[5];//�Ƿ�ʹ��
};
void JudgeGrap(std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed, bool& f);
void Prop0(Role& role, std::vector<Mine>& mine, Hook& hook, int&, bool& f);
void Prop1(Role& role, std::vector<Mine>& mine, Hook& hook, int& speed);
#endif