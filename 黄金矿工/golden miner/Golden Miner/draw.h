#pragma once
#include"Button.h"
#include"Hook.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void drawback(Role& role, vector<Mine>& mine, Hook& hook,int MAX_MINE);//绘制游戏背景，初始化物品
void drawgame(Role& role, vector<Mine>& mine, Hook& hook, int MAX_MINE,int&speed);//游戏中进行绘制
void outputPage();
void drawtime(int, int = NORMAL_TIME);
void outputStore(Role& role,Hook& hook);
void drawresult(Role role, Hook hook);