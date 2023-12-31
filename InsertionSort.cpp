//INSERTION SORT
/*
* This code is generated by KRISHNA AGRAWAL
*/

//#include "ArrayInput.cpp"
static int track=0;

class InsertionSort
{
	public:	
    int data[7];
    int *arr;
	void fillGreenColor();
    void fillRedColor(int,int,int);
	void performInsertionSort();	
	void printArray(int[],int,bool,bool);
};

void InsertionSort :: performInsertionSort()
{
	ArrayInput ai;
	ai.inputFrame(3); //3 means -> ArrayInput is called by Insertion Sort
	arr=ai.getdata(3); 
	for(int i=0;i<7;i++) //indicates that, This call from insertion sort
	{
		data[i]= arr[i];
	}
	_Main obj;
	obj.init();
	obj.footer();
	
	int i,j,k,key;
	bool interchange=false;
	settextstyle(10,0,7);
	setcolor(YELLOW);	outtextxy(120,20,"INSERTION SORT");
		
	settextstyle(10,0,3);	setcolor(WHITE);
	bool redColorRequired=false;
	printArray(data,7,interchange,redColorRequired);   getch();
	int xAxis=150,yAxis=225;
	int execute;
	for(i=1;i<7;i++)
	{
		
		execute=0;
		printArray(data,7,interchange,redColorRequired);    getch();                                      
		interchange = false;
		key = data[i];
		j = i -1;
		
		while(j>=0 && data[j]>key)
		{
			data[j+1] = data[j];
			j = j -1;
			interchange=true;
			execute++;
		}
		
		data[j+1] = key;
		
		if(interchange==true)
		{
			 fillRedColor(xAxis,yAxis,execute);//xaxis,yaxis,counter
			 execute=0;		
		}
		xAxis +=100;
		yAxis +=100;
	} getch(); 
}

void InsertionSort :: fillGreenColor()
{
	{ track++;} 
	static int x=100,y=125;
	setfillstyle(1,GREEN);
	floodfill(x,y,15);
	x += 200; y += 100;
}

void InsertionSort :: fillRedColor(int xAxis,int yAxis,int counter)
{
	setfillstyle(1,RED);//pattern,color
	while(counter!=0)
	{
		floodfill(xAxis,yAxis,15);
		counter--;
		xAxis -=100;
	}
}

void InsertionSort :: printArray(int arr[],int n,bool interchange,bool redColorRequired)
{
	static int y1=100,y2=150,dataX=100,dataY=125;;
	static int counter=-1;
	counter++;
	char element[20];
	//4 Boundary lines
	line(50,y1,50,y2);	line(50,y2,1400,y2);	line(1400,y2,1400,y1);	line(1400,y1,50,y1);
	//	inner lines 
 	line(200,y1,200,y2);	line(400,y1,400,y2);	line(600,y1,600,y2);	line(800,y1,800,y2);	line(1000,y1,1000,y2);	line(1200,y1,1200,y2);
	y1 += 100; y2 += 100;
	//dislay()
		
	for(int t=0;t<7;t++)  
	{
		sprintf(element,"%d",arr[t]);
		outtextxy(dataX,dataY,element);
		dataX = dataX+200;	//dataX,dataY ko for loop k bahar declare karna hai
	}
	dataY = dataY+100;
	dataX =100;	
		fillGreenColor();
		
	static int yAxis=125; 	
	yAxis+=100;	
		
}

