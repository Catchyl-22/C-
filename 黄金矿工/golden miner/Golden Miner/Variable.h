#ifndef VA_H
#define VA_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<graphics.h>
const int  WIN_WIDTH = 1080;//���ڿ��
const int  WIN_HEIGHT = 640;//���ڸ߶�;
const int  MAX_IMAGE = 11;//���ͼƬ����
const int  MAX_ANGLE = 80;//���Ƕ�
const int  NORMAL_SPEED = 8;//���������ٶ�
const int NORMAL_TIME = 30;//��Ϸʱ��
const int ANGLE_SPEED = 3;//���Ӱڶ��ٶ�
const int r = 10;//������Ʒ������
const double SLOW_RATE1 = 0.8;
const double SLOW_RATE2 = 0.5;
const double SLOW_RATE3 = 0.3;//��������
const double  PI = 3.1415926535898;
const int PRICE_BOOM = 50;
const int PRICE_YAOSHUI = 100;
const int max_mine = 10;
enum MINE_TYPE //��Ʒ����ö��
{
	GOLD,
	DIOMAND,
	STONE,
	PIG,
	DIOMANDPIG,
	//����
	LEFT,
	RIGHT,
	//״̬���������쳤������
	M_NOMAL,
	M_LONG,
	M_SHORT,
	//����
};

#endif