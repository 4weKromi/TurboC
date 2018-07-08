
#include "GLOBAL.H"

union REGS i,o;

/* initiate mouse */
int initMouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return (o.x.ax);
}

/*display mouse pointer */
void showMousePtr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

/* Hide mouse */
void mouseHide()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}

/*get mouse position */
void getMousePos(int *btn,int *x, int *y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*btn=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}

/* set mouse position*/
void setMousePos(int x,int y)
{
	i.x.ax=4;
	i.x.cx=x;
	i.x.dx=y;
	int86(0x33,&i,&o);
}

/* dialog mouse */
int dialogMouse()
{
	int btn,x,y;
	int clickOpt=0;
	initMouse();
	setMousePos(200,100);
	showMousePtr();
	while(1)
	{
		getMousePos(&btn,&x,&y);
		showMousePtr();
		if(btn==1)
		{
			initMouse();
			if((x>220&&y>208)&&(x<280&&y<228))
			{
				clickOpt=5;
				break;
			}
			if((x>320&&y>208)&&(x<380&&y<228))
			{
				clickOpt=1;
				break;
			}
		}
	}
	return clickOpt;
}

/* play mouse */
int playMouse()
{
	int btn,x,y,clickOpt=0;
	initMouse();
	setMousePos(200,100);
	showMousePtr();
	while(!kbhit())
	{
		getMousePos(&btn,&x,&y);
		showMousePtr();
		if(btn==1)
		{
			initMouse();
			if((x>20&&y>35)&&(x<110&&y<70))
			{
				clickOpt=1;
				break;
			}
			if((x>130&&y>35)&&(x<220&&y<70))
			{
				clickOpt=2;
				break;
			}
			if((x>240&&y>35)&&(x<330&&y<70))
			{
				clickOpt=3;
				break;
			}
			if((x>520&&y>35)&&(x<600&&y<70))
			{
				quitTab();
				break;
			}
			delay(100);
		}
	}
	return clickOpt;
}

/* About Mouse */
int aboutMouse()
{
	int btn,x,y,clickOpt;
	initMouse();
	setMousePos(200,100);
	showMousePtr();
	while(1)
	{
		getMousePos(&btn,&x,&y);
		showMousePtr();
		if(btn==1)
		{
			initMouse();
			if((x>20&&y>35)&&(x<110&&y<70))
			{
				clickOpt=1;
				break;
			}
			if((x>130&&y>35)&&(x<220&&y<70))
			{
				clickOpt=2;
				break;
			}
			if((x>240&&y>35)&&(x<330&&y<70))
			{
				clickOpt=3;
				break;
			}
			if((x>520&&y>35)&&(x<600&&y<70))
			{
				quitTab();
				break;
			}
		}
	}
	return clickOpt;
}

/* determine mouse click */
void funcMouse(int mClick)
{
	if(mClick==1)
		startPiano();
	else if(mClick==2)
		openTab();
	else if(mClick==3)
		aboutTab();
	else if(mClick==4)
		quitTab();
	else if(mClick==5)
		exit(0);
}
/* Open Mouse */
void openMouse()
{
	int btn,x,y;
	initMouse();
	setMousePos(200,100);
	showMousePtr();
	while(1)
	{
		getMousePos(&btn,&x,&y);
		showMousePtr();
		if(btn==1)
		{
			initMouse();
			if((x>20&&y>35)&&(x<110&&y<70))
			{
				delay(150);
				startPiano();
				break;
			}
			if((x>130&&y>35)&&(x<220&&y<70))
			{
				delay(150);
				openTab();
				break;
			}
			if((x>240&&y>35)&&(x<330&&y<70))
			{
				delay(150);
				aboutTab();
				break;
			}
			if((x>520&&y>35)&&(x<600&&y<70))
			{
				delay(150);
				quitTab();
			}
			if((x>400&&y>150)&&(x<480&&y<180))
			{
				startA();
				pReload();
			}
			if((x>400&&y>200)&&(x<480&&y<230))
			{
				startB();
				pReload();
			}
			if((x>400&&y>250)&&(x<480&&y<280))
			{
				startC();
				pReload();
			}
			if((x>530&&y>250)&&(x<590&&y<280))
			{
				deleteC();
				pReload();
			}
			if((x>400&&y>300)&&(x<480&&y<330))
			{
				startD();
				pReload();
			}
			if((x>530&&y>300)&&(x<590&&y<330))
			{
				deleteD();
				pReload();
			}
			if((x>400&&y>350)&&(x<480&&y<380))
			{
				startE();
				pReload();
			}
			if((x>530&&y>350)&&(x<590&&y<380))
			{
				deleteE();
				pReload();
			}
			delay(100);
		}
	}
}
