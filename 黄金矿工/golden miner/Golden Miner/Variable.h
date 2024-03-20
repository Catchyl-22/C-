#ifndef VA_H
#define VA_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<graphics.h>
const int  WIN_WIDTH = 1080;//窗口宽读
const int  WIN_HEIGHT = 640;//窗口高度;
const int  MAX_IMAGE = 11;//最大图片数量
const int  MAX_ANGLE = 80;//最大角度
const int  NORMAL_SPEED = 8;//正常钩子速度
const int NORMAL_TIME = 30;//游戏时间
const int ANGLE_SPEED = 3;//钩子摆动速度
const int r = 10;//生成物品的数量
const double SLOW_RATE1 = 0.8;
const double SLOW_RATE2 = 0.5;
const double SLOW_RATE3 = 0.3;//变慢比率
const double  PI = 3.1415926535898;
const int PRICE_BOOM = 50;
const int PRICE_YAOSHUI = 100;
const int max_mine = 10;
enum MINE_TYPE //物品类型枚举
{
	GOLD,
	DIOMAND,
	STONE,
	PIG,
	DIOMANDPIG,
	//方向
	LEFT,
	RIGHT,
	//状态，正常，伸长，缩短
	M_NOMAL,
	M_LONG,
	M_SHORT,
	//道具
};

#endif