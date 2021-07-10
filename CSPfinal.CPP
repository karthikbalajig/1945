#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<stdlib.h>
#include<stdio.h>
const int space=32, esc=27, left=97, right=100;
struct enemy
{
    int x,y,n;
    enemy() {  x=0;y=20;n=0; }
};

struct player
{
    int x,y;
    player()
    {
	x=350;
	y=450;
    }
};

struct bullet
{
    int x,y,n;
    bullet()
    {
       n=0;
    }
};

struct high
{
    int max;
    char profile[20];
};

void play()
{
	fstream f("all.DAT",ios::in|ios::out|ios::binary|ios::app);
	int gdriver=DETECT,gmode,errorcode;
	int x,y;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

	enemy a1,a2,a3,a4,a5;
	bullet b[5];
	int score=0,d,a=-1;

	player p;         //initializing player
	int click,hit;    //kbhit initialization
	randomize();
	delay(500);
	hit=kbhit();
	for(int i=0;i<1000;i++)
	{

	    d=a;
	    a=random(9)+1;

	    do{
		a=random(9)+1;
	    }while(a==d);

	    setfillstyle(1,4);
	    hit=kbhit();                       //kbhit executuion
	    if(hit!=0)
	    {
		delay(100);
		click=getch();
		if(click==right)
		    p.x+=20;
		if(click==left)
		    p.x-=20;
		if(click==esc)
		    break;
		if(click==space)
		{
		    if(b[0].n==0)
		    {
			b[0].n=1;
			b[0].x=p.x;
			b[0].y=p.y-35;
		    }
		    else if(b[1].n==0)
		    {
			b[1].n=1;
			b[1].x=p.x;
			b[1].y=p.y-35;
		    }
		    else if(b[2].n==0)
		    {
			b[2].n=1;
			b[2].x=p.x;
			b[2].y=p.y-35;
		    }
		    else if(b[3].n==0)
		    {  	b[3].n=1;
			b[3].x=p.x;
			b[3].y=p.y-35;
		    }
		    else if(b[4].n==0)
		    {
			b[4].n=1;
			b[4].x=p.x;
			b[4].y=p.y-35;
		    }
		}
		hit=0;
		fillellipse(p.x,p.y,30,30);
	    }
	    setviewport(0,0,1000,1000,0);
	    fillellipse(p.x,p.y,30,30);
	    setfillstyle(3,3);
	    if(b[0].n==1)
		fillellipse(b[0].x,b[0].y-=40,5,5);
	    if(b[1].n==1)
		fillellipse(b[1].x,b[1].y-=40,5,5);
	    if(b[2].n==1)
		fillellipse(b[2].x,b[2].y-=40,5,5);
	    if(b[3].n==1)
		fillellipse(b[3].x,b[3].y-=40,5,5);
	    if(b[4].n==1)
		fillellipse(b[4].x,b[4].y-=40,5,5);

	    setfillstyle(5,5);
	    if(a1.n==1)
		fillellipse(a1.x, a1.y+=15,  20, 20);
	    if(a2.n==1)
		fillellipse(a2.x, a2.y+=15, 20, 20);
	    if(a3.n==1)
		fillellipse(a3.x,a3.y+=15,20,20);
	    if(a4.n==1)
		fillellipse(a4.x,a4.y+=15,20,20);
	    if(a5.n==1)
		fillellipse(a5.x,a5.y+=15,20,20);


	    hit=kbhit();                       //kbhit executuion
	    if(hit!=0)
	    {
		delay(100);
		click=getch();
		if(click==right)
		   p.x+=20;
		if(click==left)
		   p.x-=20;
		if(click==esc)
		   break;
		if(click==space)
		{
		   if(b[0].n==0)
		   {
		       b[0].n=1;
		       b[0].x=p.x;
		       b[0].y=p.y-35;
		   }
		   else if(b[1].n==0)
		   {
		       b[1].n=1;
		       b[1].x=p.x;
		       b[1].y=p.y-35;
		   }
		   else if(b[2].n==0)
		   {
		       b[2].n=1;
		       b[2].x=p.x;
		       b[2].y=p.y-35;
		   }
		   else if(b[3].n==0)
		   {
		       b[3].n=1;
		       b[3].x=p.x;
		       b[3].y=p.y-35;
		   }
		   else if(b[4].n==0)
		   {
		       b[4].n=1;
		       b[4].x=p.x;
		       b[4].y=p.y-35;
		   }
		}
		hit=0;
		setfillstyle(1,4);
		clearviewport();
		setviewport(0,0,1000,1000,0);
		fillellipse(p.x,p.y,30,30);
		setfillstyle(3,3);
		if(b[0].n==1)
		    fillellipse(b[0].x,b[0].y,5,5);
		if(b[1].n==1)
		    fillellipse(b[1].x,b[1].y,5,5);
		if(b[2].n==1)
		    fillellipse(b[2].x,b[2].y,5,5);
		if(b[3].n==1)
		    fillellipse(b[3].x,b[3].y,5,5);
		if(b[4].n==1)
		    fillellipse(b[4].x,b[4].y,5,5);

		setfillstyle(5,5);
		if(a1.n==1)
		    fillellipse(a1.x,a1.y,20,20);
		if(a2.n==1)
		    fillellipse(a2.x,a2.y,20,20);
		if(a3.n==1)
		    fillellipse(a3.x,a3.y,20,20);
		if(a4.n==1)
		    fillellipse(a4.x,a4.y,20,20);
		if(a5.n==1)
		    fillellipse(a5.x,a5.y,20,20);

	    }

	    if((i%5==0)&&((a1.n==0)||(a2.n==0)||(a3.n==0)||(a4.n==0)||(a5.n==0)))
	    {

		fillellipse(a*50,20,20,20);
		if(a1.n==0)
		    {    a1.n=1;    a1.x=a*50;      a1.y=20;      }
		else if(a1.n==1 && a2.n==0)
		    {   a2.n=1;    a2.x=a*50;       a2.y=20;      }
		else if(a1.n==1 && a2.n==1 && a3.n==0)
		    {   a3.n=1;    a3.x=a*50;       a3.y=20;      }
		else if(a1.n==1 && a2.n==1 && a3.n==1 && a4.n==0)
		    {   a4.n=1;    a4.x=a*50;       a4.y=20;     }
		else if(a1.n==1 && a2.n==1 && a3.n==1 && a4.n==1 && a5.n==0)
		    {   a5.n=1;    a5.x=a*50;       a5.y=20;     }

	    }

	    if(a1.n==1 && b[0].n==1 && b[0].y<=(a1.y+25) && (b[0].x<=(a1.x+25))  &&  (b[0].x>=(a1.x-25)))
	    {
		a1.n=0;
		b[0]=b[1];
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a2.n==1 && b[0].n==1 && b[0].y<=(a2.y+25) && (b[0].x<=(a2.x+25))  &&  (b[0].x>=(a2.x-25)))
	    {
		a2.n=0;
		b[0]=b[1];
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a3.n==1 && b[0].n==1 && b[0].y<=(a3.y+25) && (b[0].x<=(a3.x+25))  &&  (b[0].x>=(a3.x-25)))
	    {
		a3.n=0;
		b[0]=b[1];
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a4.n==1 && b[0].n==1 && b[0].y<=(a4.y+25) && (b[0].x<=(a4.x+25))  &&  (b[0].x>=(a4.x-25)))
	    {
		a4.n=0;
		b[0]=b[1];
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a5.n==1 && b[0].n==1 && b[0].y<=(a5.y+25) && (b[0].x<=(a5.x+25))  &&  (b[0].x>=(a5.x-25)))
	    {
		a5.n=0;
		b[0]=b[1];
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a1.n==1 && b[1].n==1 && b[1].y<=(a1.y+25) && (b[1].x<=(a1.x+25))  &&  (b[1].x>=(a1.x-25)))
	    {
		a1.n=0;
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a2.n==1 && b[1].n==1 && b[1].y<=(a2.y+25) && (b[1].x<=(a2.x+25))  &&  (b[1].x>=(a2.x-25)))
	    {
		a2.n=0;
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a3.n==1 && b[1].n==1 && b[1].y<=(a3.y+25) && (b[1].x<=(a3.x+25))  &&  (b[1].x>=(a3.x-25)))
	    {
		a3.n=0;
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a4.n==1 && b[1].n==1 && b[1].y<=(a4.y+25) && (b[1].x<=(a4.x+25))  &&  (b[1].x>=(a4.x-25)))
	    {
		a4.n=0;
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a5.n==1 && b[1].n==1 && b[1].y<=(a5.y+25) && (b[1].x<=(a5.x+25))  &&  (b[1].x>=(a5.x-25)))
	    {
		a5.n=0;
		b[1]=b[2];
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a1.n==1 && b[2].n==1 && b[2].y<=(a1.y+25) && (b[2].x<=(a1.x+25))  &&  (b[2].x>=(a1.x-25)))
	    {
		a1.n=0;
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a2.n==1 && b[2].n==1 && b[2].y<=(a2.y+25) && (b[2].x<=(a2.x+25))  &&  (b[2].x>=(a2.x-25)))
	    {
		a2.n=0;
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a3.n==1 && b[2].n==1 && b[2].y<=(a3.y+25) && (b[2].x<=(a3.x+25))  &&  (b[2].x>=(a3.x-25)))
	    {
		a3.n=0;
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a4.n==1 && b[2].n==1 && b[2].y<=(a4.y+25) && (b[2].x<=(a4.x+25))  &&  (b[2].x>=(a4.x-25)))
	    {
		a4.n=0;
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a5.n==1 && b[2].n==1 && b[2].y<=(a5.y+25) && (b[2].x<=(a5.x+25))  &&  (b[2].x>=(a5.x-25)))
	    {
		a5.n=0;
		b[2]=b[3];
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a1.n==1 && b[3].n==1 && b[3].y<=(a1.y+25) && (b[3].x<=(a1.x+25))  &&  (b[3].x>=(a1.x-25)))
	    {
		a1.n=0;
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a2.n==1 && b[3].n==1 && b[3].y<=(a2.y+25) && (b[3].x<=(a2.x+25))  &&  (b[3].x>=(a3.x-25)))
	    {
		a2.n=0;
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a3.n==1 && b[3].n==1 && b[3].y<=(a3.y+25) && (b[3].x<=(a3.x+25))  &&  (b[3].x>=(a3.x-25)))
	    {
		a3.n=0;
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a4.n==1 && b[3].n==1 && b[3].y<=(a4.y+25) && (b[3].x<=(a4.x+25))  &&  (b[3].x>=(a4.x-25)))
	    {
		a4.n=0;
		b[3]=b[4];
		b[4].n=0;
		score++;
	    }
	    if(a5.n==1 && b[3].n==1 && b[3].y<=(a5.y+25) && (b[3].x<=(a5.x+25))  &&  (b[3].x>=(a5.x-25)))
	    {
		b[3]=b[4];
		a5.n=0;
		b[4].n=0;
		score++;
	    }
	    if(a1.n==1 && b[4].n==1 && b[4].y<=(a1.y+25) && (b[4].x<=(a1.x+25))  &&  (b[4].x>=(a1.x-25)))
	    {
		a1.n=0;
		b[4].n=0;
		score++;
	    }
	    if(a2.n==1 && b[4].n==1 && b[4].y<=(a2.y+25) && (b[4].x<=(a2.x+25))  &&  (b[4].x>=(a3.x-25)))
	    {
		a2.n=0;
		b[4].n=0;
		score++;
	    }
	    if(a3.n==1 && b[4].n==1 && b[4].y<=(a3.y+25) && (b[4].x<=(a3.x+25))  &&  (b[4].x>=(a3.x-25)))
	    {
		a3.n=0;
		b[4].n=0;
		score++;
	    }
	    if(a4.n==1 && b[4].n==1 && b[4].y<=(a4.y+25) && (b[4].x<=(a4.x+25))  &&  (b[4].x>=(a4.x-25)))
	    {
		a4.n=0;
		b[4].n=0;
		score++;
	    }
	    if(a5.n==1 && b[4].n==1 && b[4].y<=(a5.y+25) && (b[4].x<=(a5.x+25))  &&  (b[4].x>=(a5.x-25)))
	    {
		a5.n=0;
		b[4].n=0;
		score++;
	    }

	    hit=kbhit();                       //kbhit executuion
	    if(hit!=0)
	    {
		delay(75);
		click=getch();
		if(click==right)
		    p.x+=20;
		if(click==left)
		    p.x-=20;
		if(click==esc)
		    break;
		if(click==space)
		{
		    if(b[0].n==0)
		    {
			b[0].n=1;
			b[0].x=p.x;
			b[0].y=p.y-35;
		    }
		    else if(b[1].n==0)
		    {
			b[1].n=1;
			b[1].x=p.x;
			b[1].y=p.y-35;
		    }
		    else if(b[2].n==0)
		    {
			b[2].n=1;
			b[2].x=p.x;
			b[2].y=p.y-35;
		    }
		    else if(b[3].n==0)
		    {
			b[3].n=1;
			b[3].x=p.x;
			b[3].y=p.y-35;
		    }
		    else if(b[4].n==0)
		    {
			b[4].n=1;
			b[4].x=p.x;
			b[4].y=p.y-35;
		     }
		}
		hit=0;
		setfillstyle(1,4);
		clearviewport();
		setviewport(0,0,1000,1000,0);
		fillellipse(p.x,p.y,30,30);
		setfillstyle(3,3);
		if(b[0].n==1)
		   fillellipse(b[0].x,b[0].y,5,5);
		if(b[1].n==1)
		   fillellipse(b[1].x,b[1].y,5,5);
		if(b[2].n==1)
		   fillellipse(b[2].x,b[2].y,5,5);
		if(b[3].n==1)
		   fillellipse(b[3].x,b[3].y,5,5);
		if(b[4].n==1)
		   fillellipse(b[4].x,b[4].y,5,5);
		setfillstyle(5,5);
		if(a1.n==1)
		   fillellipse(a1.x, a1.y,  20, 20);
		if(a2.n==1)
		   fillellipse(a2.x, a2.y, 20, 20);
		if(a3.n==1)
		   fillellipse(a3.x,a3.y,20,20);
		if(a4.n==1)
		   fillellipse(a4.x,a4.y,20,20);
		if(a5.n==1)
		   fillellipse(a5.x,a5.y,20,20);
		if(b[0].y<=0)
		   b[0].n=0;
		if(b[1].n<=0)
		   b[1].n=0;
		if(b[2].n<=0)
		   b[2].n=0;
		if(b[3].n<=0)
		   b[3].n=0;
		if(b[4].n<=0)
		   b[4].n=0;

	    }
	    if(a1.y>=440 || a2.y>=440 || a3.y>=440 ||  a4.y>=440 || a5.y>=440)
	    {
		 break;
	    }
	    delay(400);
	    clearviewport();
	}
	clearviewport();
	closegraph();
	cout<<"you were DESTROYED by LILLIAM PUMPERNICKEL";
	cout<<"\n YOUR SCORE IS "<<score;
	high t1,t2;
	cout<<endl<<"Enter your name ";
	gets(t1.profile);
	t1.max=score;
	f.write((char*)&t1,sizeof(t1));
	f.close();
}

void highscore()
{
	high t1,t2,t;
	fstream f("all.DAT",ios::in|ios::out|ios::binary|ios::app);
	f.seekg(0);
	f.read((char*)&t1, sizeof(t1));
	t=t1;
	while(!f.eof())
	{
	    f.read((char*)&t2, sizeof(t2));
	    if(t2.max>t1.max)
		t=t2;
	}
	cout<<"Name:"<<t.profile<<endl;
	cout<<"High score:"<<t.max;
}

void rules()
{
    char ch;
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    setcolor(RED);
    settextstyle(4,0,5);
    outtextxy(180,100,"1945:Version 2.0");
    setcolor(GREEN);
    settextstyle(2,0,4);
    outtextxy(0,150,"Welcome to the greatest game in the history of C++ The aim of the game is to destroy as many enemy planes as ");
    outtextxy(0,170,"possible, by firing bullets at them ");
    setcolor(BLUE);
    settextstyle(1,0,3);
    outtextxy(0,190,"INSTRUCTIONS:");
    settextstyle(2,0,4);
    outtextxy(0,220,"Use A to move to the left, and D to move to the right. Use Space to fire bullets and destroy the enemy");
    setcolor(YELLOW);
    settextstyle(2,0,4);
    outtextxy(0,240,"To start playing, press P Else to view highscore, press H");
    ch=getch();
    closegraph();
    if(ch=='P'||ch=='p')
    {
	play();
    }

    else if(ch=='H'||ch=='h')
    {
	 highscore();
    }
}


void main()
{
    clrscr();
    rules();
}
