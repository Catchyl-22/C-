#include"Button.h"
Button::Button(int a, int b, int c, int d, const COLORREF& e, LPCTSTR f)//输入参数（起点横坐标，起点纵坐标，矩形宽，矩形高，按钮颜色，文本）
	:rectangle_x(a), rectangle_y(b), width(c), height(d), buttoncolor(e), buttoncolorREF(e), text(f)
{
	text_x = a + 20;
	text_y = b + 10;
	nwidth = 0;
	changecolor = RED;
	nheight = d - 40;
	textcolor = WHITE;
	textstyle = _T("宋体");
}
void Button::settext(int a, int b, int c, int d, COLORREF e, LPCTSTR f)//设置字体格式
{
	text_x = a; text_y = b;
	nwidth = d; nheight = c;
	textcolor = e;
	textstyle = f;
}
void Button::creatbutton()//创建按钮                           
{
	setlinecolor(BLACK);
	setfillcolor(buttoncolor);
	fillrectangle(rectangle_x, rectangle_y, rectangle_x + width, rectangle_y + height);
	setbkmode(TRANSPARENT);
	settextcolor(textcolor);
	settextstyle(nheight, nwidth, textstyle);

	outtextxy(text_x, text_y, text);
}
COLORREF Button::Button::getrectanglecolor()
{
	return this->buttoncolor;
}
void Button::setrectanglecolor(COLORREF color)         //重设置矩形颜色
{
	buttoncolor = color;
}
void Button::setchangecolor(COLORREF m)                 //重设置变换后的颜色
{
	changecolor = m;
}
int Button::mouseInButton(MOUSEMSG m)                //鼠标是否在按钮内，在的话就变色，输入参数含要变的颜色
{

	if ((m.x >= rectangle_x && m.x <= rectangle_x + width) && (m.y >= rectangle_y && m.y <= rectangle_y + height))
	{
		setrectanglecolor(this->changecolor);
		return 1;
	}
	setrectanglecolor(buttoncolorREF);
	return 0;
}
int Button::clickButton(MOUSEMSG m)                            //是否点击鼠标
{
	if (mouseInButton(m) && m.uMsg == WM_LBUTTONDOWN)
		return 1;
	return 0;
}