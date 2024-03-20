#include"Role.h"
Role::Role()
{
	this->width = 140;
	this->height = 120;
	this->x = WIN_WIDTH / 2 - this->width / 2;//xÖá¾ÓÖÐ
	this->y = 0;
	this->coin = 0;
	drawrole();
	return;
}
void Role:: drawrole()
{
	IMAGE RolE;
	loadimage(&RolE, "./images/KG.jpg", width, height);
	putimage(this->x, this->y, &RolE,SRCPAINT);
}
Role::~Role()
{
	return;
}
