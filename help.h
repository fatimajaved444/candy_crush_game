#include <windows.h>



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2,int color) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,6,RGB(color,color,color)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	
}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}
	
	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_ESCAPE);
	if (key == 1)
	{
		whichKey = 5;		// 1 if left key is pressed 
		return true;
	}
	
	return false;
}

bool isCursorKeyPressed2(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}
	
	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B,int a,int b,int c )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,4,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(a,b,c)); //Fill color can also be passed as parameter to the function!!!
	
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B,int a,int b,int c)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(a, b, c));  //Fill color is black
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
		

}
void myCursor(int x1, int y1, int x2, int y2, int R, int G, int B )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,4,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush =(HBRUSH) ::GetStockObject(NULL_BRUSH); //Fill color can also be passed as parameter to the function!!!
	
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}
void myDiamond(int x1, int y1, int x2, int y2, int R, int G, int B, int a, int b, int c)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	int mid1 = (x1 + x2) / 2;
	int mid2 = (y1 + y2) / 2;
	MoveToEx(device_context, mid1, y1, NULL);
	LineTo(device_context, x1, mid2);
	MoveToEx(device_context, x1, mid2, NULL);
	LineTo(device_context, mid1, y2);
	MoveToEx(device_context, mid1, y2, NULL);
	LineTo(device_context, x2, mid2);
	MoveToEx(device_context, x2, mid2, NULL);
	LineTo(device_context, mid1, y1);
	HBRUSH brush = ::CreateSolidBrush(RGB(a, b, c));  //Fill color 

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
}
void myTriangle(int x1, int y1, int x2, int y2,int R,int G,int B,int a,int b,int c) 
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	
	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 4, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	int mid=(x1+x2)/2;
	MoveToEx(device_context, mid, y1, NULL);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x1, y2);
	LineTo(device_context, mid+1, y1);
	ReleaseDC(console_handle, device_context);
	HBRUSH brush = ::CreateSolidBrush(RGB(a, b, c));  //Fill color is black
	FloodFill(device_context,mid,(y1+y2)/2,RGB(246,0,0));
	ReleaseDC(console_handle, device_context);
	SelectObject(device_context,brush);
	
		DeleteObject(pen);
	DeleteObject(brush);
}
void singleicon(int num,int i,int j)
{
	
}
void printboard(int a[][8])
{
	int x=450,y=100,matrix[8][8];
	for(int i=0;i<8;i++)
	{
		x=450;
		for(int j=0;j<8;j++)
		{
			if (a[i][j]==0)
			{
				myRectangle(x,y,x+60,y+60,137,12,130,255,0,0);		
			}
			else if(a[i][j]==1)
			{
				myTriangle(x,y,x+60,y+60,16,87,255,16,87,255);
			}
			else if(a[i][j]==2)
			{
				myEllipse(x,y,x+60,y+60,214,16,255,102,40,117);
			}
			else if(a[i][j]==3)
			{
				myEllipse(x,y,x+50,y+60,95,255,45,04,144,75);
			}
			else if(a[i][j]==4)
			{
				myDiamond(x,y,x+60,y+60,255,253,85,255,253,85);
			}
			else if(a[i][j]==6)
			{
				myRectangle(x-20,y-20,x+80,y+80,245,245,245,0,0,0);
			}
			else if(a[i][j]==7)
			{
				myRectangle(x,y,x+60,y+60,13,240,230,0,0,0);	
			    myDiamond(x,y,x+60,y+60,13,240,230,0,0,0);	
			}
			x=x+100;
		}
		y=y+100;
	}
}
void printGrid()
{
	int x1=430,x2=530,y2=180,y1=80;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			myCursor(x1,y1,x2,y2,245,245,245);
			x1=x1+100;
			x2=x2+100;
		}
		y1=y1+100;
		y2=y2+100;
		x1=430,x2=530;
	}
}
bool blasting( int matrix[8][8])
{
	int score=0;
	bool b=0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if(matrix[i][j]==matrix[i][j+1] && matrix[i][j]==matrix[i][j+2] && matrix[i][j]==matrix[i][j+3])
			{
				matrix[i][j+1]=6;
				matrix[i][j]=6;
				matrix[i][j+2]=6;
				matrix[i][j+3]=7;
				b=1;
				score=score+100;
			}
			else if(matrix[i][j]==matrix[i][j+1] && matrix[i][j]==matrix[i][j+2])
			{
				matrix[i][j+1]=6;
				matrix[i][j]=6;
				matrix[i][j+2]=6;	
				b=1;
				score=score+100;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(matrix[i][j]==matrix[i+1][j] && matrix[i][j]==matrix[i+2][j] && matrix[i+3][j]==matrix[i][j])
			{
			    matrix[i+1][j]=6;
				matrix[i][j]=6;
				matrix[i+2][j]=6;
				matrix[i+3][j]=7;
				b=1;
			}
			else if(matrix[i][j]==matrix[i+1][j] && matrix[i][j]==matrix[i+2][j])
			{
				matrix[i+1][j]=6;
				matrix[i][j]=6;
				matrix[i+2][j]=6;
				b=1;
			}
		}
	}
	return b;	    
}
void shapefitting(int matrix[][8])
{
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(matrix[i][j]==6)
			{
				matrix[i][j]=rand()%5;
			}
		}
	}
}
void ending()
{
	int num=1,q=900,p=230,q1=1000,p1=260,q2=1030,p2=290;

	myRectangle(0,0,1900,980,117, 22, 63, 117, 22, 63);//outer
	myRectangle(500,200,1120,450,0,16,194,117,22,63);//inner
	myLine(550,300,550,400,245);//E kamar
	myLine(550,300,610,300,245);//E upper
	myLine(550,400,610,400,245);//E lower
	myLine(550,350,610,350,245);//E middle
	myLine(680,300,680,400,245);//N start
	myLine(750,300,750,400,245);//N start	
	myLine(680,300,750,400,245);//N middle
	myLine(810,300,810,400,245);//D start
	myLine(810,300,870,300,245);//D upper
	myLine(810,400,870,400,245);//D lower
	myLine(870,300,870,400,245);//D end
	myEllipse(q,p,q+200,p+200,246,0,0,238,255,42);//emoji
	myEllipse(q1,p1,q1+70,p1+70,238,255,42,245,245,245);//eye
	myEllipse(q2,p2,q2+20,p2+20,0,0,0,0,0,0);//eye lid
	myLine(940,290,980,290,0);//blinker
	myLine(940,290,930,300,0);//left
	myLine(980,290,990,300,0);//right
	myLine(965,400,1040,400,0);//smile
	myLine(965,400,945,370,0);//left smile
	myLine(1040,400,1060,370,0);//right smile	
}
void starting()
{
	int st;
	int s=0;
	myRectangle(0, 0, 1900,980, 117, 22, 63, 117, 22, 63);
	
	//c
	myLine(50, 250, 50, 300, 255);
	myLine(50, 250, 80, 250, 255);
	myLine(50, 300, 80, 300, 255);
	//a
	
	myLine(100, 250, 100, 300, 255);

	myLine(100, 250, 130, 250,255);
	myLine(130, 250, 130, 300, 255);
	myLine(100, 280, 130, 280, 255);
	//n
	myLine(150, 250, 150, 300, 255);
	myLine(150, 250, 190, 300, 255);
	myLine(190, 250, 190,300, 255);
	//d
	myLine(210, 250, 210, 300, 255);
	myLine(250, 260, 250, 290, 255);
	myLine(210, 250, 250,260,255);
	myLine(210, 300, 250, 290, 255);
	//y
	myLine(290,270, 290,300 , 255);
	myLine(260,250, 290, 270, 255);
	myLine(320, 250, 290, 270, 255);

	
	//p
	myLine(430, 250, 430, 300, 255);
	myLine(430, 250,460,260,255);
	myLine(430,280, 460, 260, 255);
	
	//o
	myLine(470,250,470,300,255);
	myLine(500,250,500,300,255);
	myLine(470,300,500,300,255);
	myLine(470,250,500,250,255);
	//p
	myLine(520, 250, 520, 300, 255);
	myLine(520, 250, 550, 260, 255);
	myLine(520, 280, 550, 260, 255);
	//start box
	myRectangle(550, 420, 870, 550, 250, 54,223,217,42,131);
	//s
	myLine(580, 450, 620, 450, 255);
	myLine(580, 480, 620, 480, 255);
	myLine(580, 510, 620, 510, 255);
	myLine(580,450,580,480,255);
	myLine(620, 480,620,510,255);
	//t
	myLine(640, 450, 680, 450, 255);
	myLine(660, 450, 660, 510, 255);
	//a
	myLine(690,450,690,510,255);
	myLine(730, 450, 730, 510, 255);
	myLine(690, 450, 730, 450, 255);
	myLine(690, 480, 730, 480, 255);
	//r
	myLine(750, 450, 750, 510, 255);
	myLine(750, 450, 790, 450, 255);
	myLine(750, 480, 790, 480, 255);
	myLine(790, 450, 790, 480, 255);
	myLine(750, 480,790, 510, 255);
	//t
	myLine(820, 450, 820, 510, 255);
	myLine(800, 450, 840, 450, 255);
	while(s==0)
	{
		_getch();
		if(isCursorKeyPressed(st))
		{
			if(st==5)
			{
				system("cls");
				s=1;
			}
		}	
	}
}
void toffeeblast(int matrix[8][8])
{
	bool b=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(matrix[i][j]==7)
			{
				matrix[i][j]=6;
				matrix[i][j+1]=6;
				matrix[i][j+2]=6;
				matrix[i][j-1]=6;
				matrix[i][j-2]=6;
				matrix[i+1][j]=6;
				matrix[i+2][j]=6;
				matrix[i-1][j]=6;
				matrix[i-2][j]=6;
			}
		}
	}
}
void coloralpha(int a) //taken from google
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);
}
void toffeeblast2(int matrix[8][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(matrix[i][j]==7 && matrix[i][j+1]==7 || matrix[i][j]==7 && matrix[i+1][j]==7 )
			{
				matrix[i][j]=6;
				matrix[i][j+1]=6;
				matrix[i][j+2]=6;
				matrix[i][j+3]=6;
				matrix[i][j-3]=6;
				matrix[i][j-1]=6;
				matrix[i][j-2]=6;
				matrix[i+1][j]=6;
				matrix[i+2][j]=6;
				matrix[i+3][j]=6;
				matrix[i-3][j]=6;
				matrix[i-1][j]=6;
				matrix[i-2][j]=6;
			}
		}
	}
}

