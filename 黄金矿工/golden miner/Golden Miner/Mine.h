#ifndef MINE_H
#define MINE_H
#include<string>
#include<vector>
#include"Hook.h"
#include"Role.h"
#include"Variable.h"
class Hook;
class Role;
class Mine
{
	friend class Hook;
	friend class Role;
	friend void JudgeGrap(std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed, bool& f);
	friend void Prop0(Role& role, std::vector<Mine>& mine, Hook& hook, int&, bool& f);
	friend void Prop1(Role& role, std::vector<Mine>& mine, Hook& hook, int& speed);
	friend void drawback(Role& role, std::vector<Mine>& mine, Hook& hook, int MAX_MINE);
	friend void drawgame(Role& role, std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed);
	friend void drawresult(Role role, Hook hook);
	friend void outputStore(Role& role, Hook& hook);
public:
	Mine(int, int, int, int, int, const char[],const char[],bool, const char[]="./images/qm4.jpg", const char[]="./images/qmm4.jpg",const char[]="./images/qm5.jpg", const char[] = "./images/qmm5.jpg");
	void Gamedraw();
	~Mine() {}
private:
	int x, y;
	int size;
	bool flag;
	int type;
	int gold;
	bool temp;
	IMAGE img;
	IMAGE imge;
	IMAGE img_pig;
	IMAGE imge_pig;
	IMAGE img_diopig;
	IMAGE imge_diopig;
};
void JudgeGrap(std::vector<Mine>& mine, Hook& hook, int MAX_MINE, int& speed, bool& f);
#endif // !MINE_H