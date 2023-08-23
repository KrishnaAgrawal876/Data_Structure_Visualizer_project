/*
*	This project is Contributed by Krishna Agrawal.
*	Basically, it is an Data Structure Visualizer, where user can easily visualize the static implementation of
*	Stack[LIFO], Circular Queue[FIFO] Data Structures. 
* 	Apart from above two data structure's, user can also visualize the sorting algorithms.
* 	This Project support following three types of Sorting.
*	(1) Bubble Sort (2) Insertion Sort (3) Selection Sort.
* 	Completed on July,2023 
*/
									
#include "_Main.cpp"
#include "GStack_Array.cpp"
#include "GQueue_Array.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
//#include "ArrayInput.cpp"

using namespace std;
int main()
{
	/*	Object Creation		*/
		_Main mainObject;
		BubbleSort bubble;
		InsertionSort insertion;
		SelectionSort selection;
	
		
	/*	GRAPHICS INITIALIZATION*/
	mainObject.initial = true;
	char another;
	do{
		GStack st;
		GQueue q;
		
		mainObject.init();
		mainObject.firstFrame();
		mainObject.footer();
	
		int input = (mainObject.getChoice()) - 48;/*ASCII Value of zero, for conversion char to int */
		cleardevice();closegraph();
		switch(input)
		{
			case 1: st.stackFrame(); st.stackInput(); break;
			case 2: q.queueFrame(); q.queueInput(); break;
			case 3: insertion.performInsertionSort(); break;
			case 4: selection.performSelectionSort(); break;
			case 5:	bubble.performBubbleSort(); break;
		}
		delay(1000); another = getch(); 	
			mainObject.initial = false;
	}while(another!=27);/*(ASCII of escape key), When user press escape key, loop terminate otherwise continue again*/ 
	
	getch();
	return 0;
}
