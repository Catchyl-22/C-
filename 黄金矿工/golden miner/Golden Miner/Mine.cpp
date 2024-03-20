#include"Mine.h"
#undef UNICODE
#undef _UNICODE
Mine::Mine(int minex, int miney,int minesize, int minetype, int minegold,const char image[], const char imagee[],bool mineflag, const char qmage[], const char qmagee[], const char qqmage[], const char qqmagee[])
{
	x = minex;
	y = miney;
	size = minesize;
	type = minetype;
	gold = minegold;
	flag = mineflag;
	if(x > 500)temp = 0;
	else temp = 1;
	loadimage(&img, image, minesize, minesize);
	loadimage(&imge, imagee, minesize, minesize);
	loadimage(&img_pig, qmage, minesize, minesize);
	loadimage(&imge_pig, qmagee, minesize, minesize);
	loadimage(&img_diopig, qqmage, minesize, minesize);
	loadimage(&imge_diopig, qqmagee, minesize, minesize);
	Gamedraw();
}
void Mine::Gamedraw()
{
	if (flag != 0&&(type==PIG||type==DIOMANDPIG))
	{
			if (temp)
			{
				x += 10;
				if (x > 1000)temp = !temp;
			}
			else
			{
				x -= 10;
				if (x < 50)temp = !temp;
			}
	}
	if (flag == true)
	{
		if (type == PIG)
		{
			if(!temp)
			{
				putimage(x, y, &img, SRCAND);
				putimage(x, y, &imge, SRCPAINT);
			}
			else
			{
				putimage(x, y, &img_pig, SRCAND);
				putimage(x, y, &imge_pig, SRCPAINT);
			}
		}
		else if(type==DIOMANDPIG)
		{
			if (!temp)
			{
				putimage(x, y, &img, SRCAND);
				putimage(x, y, &imge, SRCPAINT);
			}
			else
			{
				putimage(x, y, &img_diopig, SRCAND);
				putimage(x, y, &imge_diopig, SRCPAINT);
			}
		}
		else
		{
			putimage(x, y, &img, SRCAND);
			putimage(x, y, &imge, SRCPAINT);
		}	
		
	}
}
