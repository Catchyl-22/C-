#include"Button.h"
Button::Button(int a, int b, int c, int d, const COLORREF& e, LPCTSTR f)//����������������꣬��������꣬���ο����θߣ���ť��ɫ���ı���
	:rectangle_x(a), rectangle_y(b), width(c), height(d), buttoncolor(e), buttoncolorREF(e), text(f)
{
	text_x = a + 20;
	text_y = b + 10;
	nwidth = 0;
	changecolor = RED;
	nheight = d - 40;
	textcolor = WHITE;
	textstyle = _T("����");
}
void Button::settext(int a, int b, int c, int d, COLORREF e, LPCTSTR f)//���������ʽ
{
	text_x = a; text_y = b;
	nwidth = d; nheight = c;
	textcolor = e;
	textstyle = f;
}
void Button::creatbutton()//������ť                           
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
void Button::setrectanglecolor(COLORREF color)         //�����þ�����ɫ
{
	buttoncolor = color;
}
void Button::setchangecolor(COLORREF m)                 //�����ñ任�����ɫ
{
	changecolor = m;
}
int Button::mouseInButton(MOUSEMSG m)                //����Ƿ��ڰ�ť�ڣ��ڵĻ��ͱ�ɫ�����������Ҫ�����ɫ
{

	if ((m.x >= rectangle_x && m.x <= rectangle_x + width) && (m.y >= rectangle_y && m.y <= rectangle_y + height))
	{
		setrectanglecolor(this->changecolor);
		return 1;
	}
	setrectanglecolor(buttoncolorREF);
	return 0;
}
int Button::clickButton(MOUSEMSG m)                            //�Ƿ������
{
	if (mouseInButton(m) && m.uMsg == WM_LBUTTONDOWN)
		return 1;
	return 0;
}