#ifndef BUTTON_H
#define BUTTON_H
#include<graphics.h>
class Button
{
public:
	Button(int a, int b, int c, int d, const COLORREF& e, LPCTSTR f);//����������������꣬��������꣬���ο����θߣ���ť��ɫ���ı���
	~Button() {}
	void settext(int a, int b, int c, int d, COLORREF e, LPCTSTR f);//���������ʽ

	void creatbutton();//������ť                           
	COLORREF getrectanglecolor();
	void setrectanglecolor(COLORREF color);//�����þ�����ɫ
	void setchangecolor(COLORREF m);//�����ñ任�����ɫ
	int mouseInButton(MOUSEMSG m);//����Ƿ��ڰ�ť�ڣ��ڵĻ��ͱ�ɫ�����������Ҫ�����ɫ
	int clickButton(MOUSEMSG m);//�Ƿ������

private:
	int rectangle_x;  
	int rectangle_y;
	int width;     
	int height;
	COLORREF buttoncolor;
	COLORREF buttoncolorREF;
	COLORREF changecolor;
	LPCTSTR text;
	int text_x; int text_y;
	int nwidth; int nheight;
	COLORREF textcolor;   
	LPCTSTR textstyle;    
};
#endif
