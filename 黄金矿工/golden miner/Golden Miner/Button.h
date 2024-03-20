#ifndef BUTTON_H
#define BUTTON_H
#include<graphics.h>
class Button
{
public:
	Button(int a, int b, int c, int d, const COLORREF& e, LPCTSTR f);//输入参数（起点横坐标，起点纵坐标，矩形宽，矩形高，按钮颜色，文本）
	~Button() {}
	void settext(int a, int b, int c, int d, COLORREF e, LPCTSTR f);//设置字体格式

	void creatbutton();//创建按钮                           
	COLORREF getrectanglecolor();
	void setrectanglecolor(COLORREF color);//重设置矩形颜色
	void setchangecolor(COLORREF m);//重设置变换后的颜色
	int mouseInButton(MOUSEMSG m);//鼠标是否在按钮内，在的话就变色，输入参数含要变的颜色
	int clickButton(MOUSEMSG m);//是否点击鼠标

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
