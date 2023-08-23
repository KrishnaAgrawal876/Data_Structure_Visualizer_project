#include<graphics.h>
#include<conio.h>
#include<string>
#include<iostream>
#include<sstream>
#define size 10
using namespace std;

class _Main
{
	int height,width;
	char choice;
	public:
	bool initial;
	void init();	
	void footer();
	char* int_to_charP(int);
	void clearPixel(int,int,int,int);
	
	void firstFrame();
	char getChoice();
};


void _Main :: clearPixel(int left,int top, int right, int bottom)
{
	setcolor(getbkcolor());
	setfillstyle(SOLID_FILL,getbkcolor());
	bar(left,top,right,bottom);
}


char* _Main :: int_to_charP(int n)
{
	ostringstream str1;
	str1<<n;		//int to oString
	string sp = str1.str(); //oString to String
	char *co = const_cast<char*>(sp.c_str()); //string to char*
	if(strlen(co) ==  0)
		int_to_charP(n);
		
	return (co);
}


void _Main :: init()
{
	/*	Graphics Initialization*/
	height=GetSystemMetrics(SM_CYSCREEN);//Getting the maximum height of the window using in-built function
	width= GetSystemMetrics(SM_CXSCREEN);//Getting the maximum width of the window using in-built function 
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");//Initialization
	/*	initialize graphics window by maximum height and width */
	initwindow(width,height,"Data Structure VISUALIZER ~KRISHNA AGRAWAL		");
}
/*
int main() { 
	_Main obj;
	obj.firstFrame();
	obj.footer();
	getch();
return 0;
}*/
void _Main :: footer()
{	
	setcolor(15);
	settextstyle(10,0,3);
	rectangle(100,760,1350,800);
	setfillstyle(1,BLUE);//pattern,color
	floodfill(height/2,width/2,15); 
	outtextxy( (height/2)-300,width/2,"Designed by Krishna Agrawal, krishnaagrawal876@gmail.com, Indore (M.P.), India @ 2023");			
}

void _Main :: firstFrame()
{
	init();
	// Upper Circle 
	int xPos = 130;
	for(int x=1;x<=4;x++)
	{	
		if(initial) delay(500);
		if(x%2==0)//even
			setfillstyle(1,GREEN);//pattern:Solid,color:Green
		else
			setfillstyle(1,RED);
		circle(xPos,100,40);
		floodfill(xPos,100,15);//x,y,border_Color
		xPos = xPos + 450;
	}
	
	//Upper Line's 
	int x1=170,x2=540;
	for(int x=1;x<=3;x++)
	{	
		if(initial) delay(500);
		line(x1,100,x2,100);
		x1 += 450;
		x2 += 450;
	}
	
	//Lower Circle 
	 xPos = 130;
	for(int x=1;x<=4;x++)
	{
		if(initial) delay(500);
		if(x%2==0)//even
			setfillstyle(1,RED);//pattern:Solid,color:REd
		else
			setfillstyle(1,GREEN);
		circle(xPos,400,40);
		floodfill(xPos,400,15);//x,y,border_Color
		xPos = xPos + 450;
	}
	
	//Lower Line's
	x1=170,x2=540;
	for(int x=1;x<=3;x++)
	{	
		if(initial) delay(500);
		line(x1,400,x2,400);
		x1 += 450;
		x2 += 450;
	}

	//Heading 
	if(initial) delay(500);
	setcolor(14);//color:yellow
	settextstyle(4,0,10);//font_pattern,direction_(Horizontal:0 ? Vertical:1),font_siz
	outtextxy(50,200,"DS VISUALIZER");
	
	//Drawing Rectangle 
	setcolor(15);//WHITE
	if(initial) delay(500);		rectangle(150,500,550,600);//left,top,right,bottom
	if(initial) delay(500);		rectangle(150,650,550,750);
	if(initial) delay(500);		rectangle(1100,500,1500,600);
	if(initial) delay(500);		rectangle(1100,650,1500,750);
	if(initial) delay(500);     rectangle(600,625,1050,725);
	
	//Writing text inside Rectangle
	setcolor(CYAN);
	settextstyle(10,0,5);//font_pattern,direction_(Horizontal:0 ? Vertical:1),font_size
	delay(500);outtextxy(200,530,"1. Stack");
	delay(500);outtextxy(200,680,"2. Queue");
	delay(500);outtextxy(1110,530,"3.Insertion Sort");
	delay(500);outtextxy(1110,680,"4.Selection Sort");
	delay(500);outtextxy(620,655,"5. Bubble Sort");
	
}//End of frame function()

char _Main :: getChoice()
{	
	while(true)
	{
		setcolor(WHITE);
		settextstyle(10,0,5);//font_pattern,direction_(Horizontal:0 ? Vertical:1),font_size
		outtextxy(550,450,"Enter Your Choice				");
		fflush(stdin);/* To Clear the buffer */
		choice = getch();
		if(choice == 27)
		{
			exit(0);
		}
		if( (choice>=49 && choice<=53) )	//ASCII Value of 1 and 5
			break;
		else{
				setcolor(RED);
				settextstyle(1,0,5);		
				outtextxy(550,450,"Invalid Input Exception");
				delay(1000);//msec
				setcolor(getbkcolor());
				outtextxy(550,450,"Invalid Input Exception");
		}//End of else
	}//End of while loop
	return choice;						
}//End of function()



