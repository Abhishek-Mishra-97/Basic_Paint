/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
				    |
Developer - Abhishek Mishra         |
				    |
				    |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>

union REGS in,out;
int i,j,k,l,a,b,c,d,e,f,g,h;

void show_mouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
}
void background()
{
	setcolor(15);
	line(0,34,640,34);

	setfillstyle(1,0);
	bar(32*0,2,32*1,32);
	setfillstyle(1,1);
	bar(32*1,2,32*2,32);
	setfillstyle(1,3);
	bar(32*2,2,32*3,32);
	setfillstyle(1,4);
	bar(32*3,2,32*4,32);
	setfillstyle(1,5);
	bar(32*4,2,32*5,32);
	setfillstyle(1,6);
	bar(32*5,2,32*6,32);
	setfillstyle(1,7);
	bar(32*6,2,32*7,32);
	setfillstyle(1,8);
	bar(32*7,2,32*8,32);
	setfillstyle(1,9);
	bar(32*8,2,32*9,32);
	setfillstyle(1,10);
	bar(32*9,2,32*10,32);
	setfillstyle(1,11);
	bar(32*10,2,32*11,32);
	setfillstyle(1,12);
	bar(32*11,2,32*12,32);
	setfillstyle(1,13);
	bar(32*12,2,32*13,32);
	setfillstyle(1,14);
	bar(32*13,2,32*14,32);
	setfillstyle(1,15);
	bar(32*14,2,32*15,32);
	setfillstyle(1,15);
	bar((32*15)+2,2,(32*16)+4,32);
	bar((32*16)+6,2,(32*17)+8,32);
	bar((32*17)+10,2,(32*18)+12,32);
	bar((32*18)+14,2,(32*19)+16,32);
	setfillstyle(1,4);
	bar((32*19)+14,2,640,32);
	setcolor(1);
	ellipse(499,17,0,360,2,2);
	setfillstyle(1,0);
	fillellipse(499,17,2,2);
	ellipse(601,17,0,360,8,8);
	fillellipse(601,17,8,8);

	line(524,8,546,26);
	rectangle(558,8,582,26);
	line(626,9,638,21);
	line(626,21,638,9);
}
void start()
{
	setbkcolor(0);
	settextstyle(4,0,6);
	setcolor(4);
	outtextxy(220,10,"Welcome");
	settextstyle(1,0,3);
	setcolor(9);
	outtextxy(135,70,"Some Important Instructions");
	settextstyle(1,0,1.5);
	setcolor(5);
	outtextxy(20,130,"1> Use Right Click Of Mouse For Eraser");
	outtextxy(20,160,"2> Use X or Esc to close the program");
	getch();
	clrscr();
	setfillstyle(1,0);
	bar(0,0,640,480);
}

void mouse_pos(int &xpos,int &ypos,int &click)
{
	in.x.ax=3;
	int86(51,&in,&out);
	click=out.x.bx;
	xpos=out.x.cx;
	ypos=out.x.dx;
}

void selection(int x,int y,int &cl1,int &tl)
{

	if(x<32*1)f=0;

	if(x>32*1&&x<32*2)f=1;

	if(x>32*2&&x<32*3)f=3;

	if(x>32*3&&x<32*4)f=4;

	if(x>32*4&&x<32*5)f=5;

	if(x>32*5&&x<32*6)f=6;

	if(x>32*6&&x<32*7)f=7;

	if(x>32*7&&x<32*8)f=8;

	if(x>32*8&&x<32*9)f=9;

	if(x>32*9&&x<32*10)f=10;

	if(x>32*10&&x<32*11)f=11;

	if(x>32*11&&x<32*12)f=12;

	if(x>32*12&&x<32*13)f=13;

	if(x>32*13&&x<32*14)f=14;

	if(x>32*14&&x<32*15)f=15;

	if(x>(32*15)+2&&x<(32*16)+4)tl=1;
	if(x>(32*16)+6&&x<(32*17)+8)tl=2;
	if(x>(32*17)+10&&x<(32*18)+12)tl=3;
	if(x>(32*18)+14&&x<(32*19)+16)tl=4;

	if(x>(32*19)+14&&x<640)exit(0);


}

void main()
{clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	show_mouse();
	start();

	background();
	int cl=0,tl=1,x,y;
start:
	e=0;g=0;h=0;
	a=0;b=0;c=0;d=0;

	while(!kbhit())
	{
		mouse_pos(x,y,cl);

		if(cl==1&&y<34){selection(x,y,f,tl);}

		if(e>0&&cl==1)
		{
			c=x;d=y;continue;}

		if(cl!=1&&e>0&&tl==2){if(d<34)goto chance;else {setcolor(f);line(a,b,c,d);} }
		if(cl!=1&&e>0&&tl==3){if(d<34)goto chance;else {setfillstyle(1,f);bar(a,b,c,d);} }
		if(cl!=1&&e>0&&tl==4){if((b-(d-b))<32)goto chance;else {setfillstyle(1,f);setcolor(f);ellipse(a,b,0,360,c-a,d-b);fillellipse(a,b,c-a,d-b); }}

		if(cl==1&&tl==1){if(y<34)goto chance; else putpixel(x-1,y,f);}


		if(cl==1&&e==0&&tl!=1){ if(y<34)continue;else {a=x;b=y;e+=1;putpixel(x,y,f);putpixel(x+1,y+1,f);putpixel(x-1,y-1,f);putpixel(x,y+1,f);putpixel(x+1,y,f);putpixel(x-1,y+1,f);continue;}}
		if(cl==2){ setfillstyle(1,0);bar(x-2,y-2,x+2,y+2);continue; }

chance:
		e=0;a=0;b=0;c=0;d=0;

	}

	if(getch()==27)exit(0);
	else goto start;





	getch();
}

