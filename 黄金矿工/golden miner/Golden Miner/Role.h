#pragma once
#include"Variable.h"
#include<vector>
class Hook;
class Mine;
class Role //角色信息
{
	friend class Hook;
	friend class Mine;
	friend void JudgeGrap(std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed, bool& f);
	friend void Prop0(Role& role, std::vector<Mine>& mine, Hook& hook, int&, bool& f);
	friend void Prop1(Role& role, std::vector<Mine>& mine, Hook& hook, int& speed);
	friend void drawback(Role& role, std::vector<Mine>& mine, Hook& hook, int MAX_MINE);
	friend void drawgame(Role& role, std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed);
	friend void outputStore(Role& role, Hook& hook);
	friend void drawresult(Role role, Hook hook);
public:
	Role();
	~Role();
	void drawrole();
private:
	int x;//贴图位置
	int y;
	int width;//图片宽高
	int height;
	int coin;//金币
};
void JudgeGrap(std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed, bool& f);
void Prop0(Role& role, std::vector<Mine>& mine, Hook& hook, int&, bool& f);
void Prop1(Role& role, std::vector<Mine>& mine, Hook& hook, int& speed);