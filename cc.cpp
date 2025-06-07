#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include"help.h"

using namespace std;

int main()
{
	int num=1,key,x1=430,x2=530,y2=180,y1=80,z=0,matrix[8][8],score=0,move=10;
	int x=470,y=120;
	int x3=470,y3=120;
	srand(time(0));
	cout<<"Press 1 to start the game : ";
	cin>>num;
	//scorecard
	coloralpha(5);
	cout<<"Your score is : "<<score<<endl;
	//movescheck
	coloralpha(9);
	cout<<"moves left are : "<<move;
	//inserting random shapes in grid
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			matrix[i][j]=rand()%5;
		}
	}
	//checking same in coloumns
    for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (matrix[i][j+1] == matrix[i][j])
			{
	           if(matrix[i][j]==matrix[i][j+2])
			    {
			    	while (matrix[i][j] == matrix[i][j+2])
					{
						matrix[i][j] = (rand() % 5) ;
					}
				}
			}
		}
	}
	//checking same in rows
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (matrix[i+1][j] == matrix[i][j])
			{
			    if(matrix[i][j]==matrix[i+2][j])
			    {
			    	while (matrix[i][j] == matrix[i+2][j])
					{
						matrix[i][j] = (rand() % 5) ;
					}
				}
			}
		}
	}
	//grid
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			myRectangle(x1,y1,x2,y2,245,245,245,0,0,0);
			x1=x1+100;
			x2=x2+100;
		}
		y1=y1+100;
		y2=y2+100;
		x1=430,x2=530;
	}
	if(num==1)
	{
	//opening 	
	starting();
	printGrid();
	printboard(matrix);	
	 myCursor(530,180,430,80,246,0,0);	 
		int i=0,j=0;
		x1 = 430, y1 = 80;
		while(move>0 && score<=100000)
		{
			//blasting
			while(blasting(matrix))
			{
				score=score+100;
				printGrid();
				printboard(matrix);	
				myCursor(x1,y1,x1+100,y1+100,246,0,0);
				Sleep(200);
	//			system("cls");
				shapefitting(matrix);//shapefitting in empty spaces	
				printGrid();
				printboard(matrix);	
				myCursor(x1,y1,x1+100,y1+100,246,0,0);  
			}
			//cursor
			_getch();
			if(isCursorKeyPressed(key))
			{
			    if(key==4 && y1<=700)//move down
				{
					myCursor(x1,y1,x1+100,y1+100,245,245,245);
					y1=y1+100;
					y3=y3+100;
					i++;
					myCursor(x1,y1,x1+100,y1+100,246,0,0);    
				}												
				if(key==3 && x1<=1050)//move right
				{
					myCursor(x1,y1,x1+100,y1+100,245,245,245);
					x1=x1+100;
					x3=x3+100;
					j++;
					myCursor(x1,y1,x1+100,y1+100,246,0,0);
				}
				if(key==1 && x1>=470)//move left
				{
					myCursor(x1,y1,x1+100,y1+100,245,245,245);
					x1=x1-100;
					x3=x3-100;
					j--;
					myCursor(x1,y1,x1+100,y1+100,246,0,0);
				}
				if(key==2 && y1>=180)//move up
				{
					myCursor(x1,y1,x1+100,y1+100,245,245,245);
					y1=y1-100;
					y3=y3-100;
					i--;
					myCursor(x1,y1,x1+100,y1+100,246,0,0);
				}
				//swaping
				if (key==5)
				{
					_getch();
					
					if(isCursorKeyPressed(key))
			        {      
			            if(key==4 && y1 <= 700)//down swaping
				        {
				            swap(matrix[i][j],matrix[i+1][j]);
				            score=score+100;
				            if(matrix[i][j]==7 || matrix[i+1][j]==7)//toffe
				        	{
				        		toffeeblast(matrix);
				        	    printGrid();
							    printboard(matrix);	
							    myCursor(x1,y1,x1+100,y1+100,246,0,0);
							    Sleep(1000);
						//	system("cls");
							    shapefitting(matrix);//shapefitting in empty spaces	
							    printGrid();
							    printboard(matrix);	
							    myCursor(x1,y1,x1+100,y1+100,246,0,0);  
						    }
				            move--;
				            system("cls");
						    printGrid();
						    printboard(matrix);
						    Sleep(500);
						    myCursor(x1,y1,x1+100,y1+100,246,0,0);
						    if(!blasting(matrix))//reswaping if the blasting does not happens
						    {
							    swap(matrix[i][j],matrix[i+1][j]);
							    move++;
					            system("cls");
							    printGrid();
							    printboard(matrix);
							    myCursor(x1,y1,x1+100,y1+100,246,0,0);
							}
				        }													
			        	if(key==3 &&  x1<=1050 )//right swaping
			        	{
				        	swap(matrix[i][j],matrix[i][j+1]);
				        	score=score+100;
				        	if(matrix[i][j]==7 || matrix[i][j+1]==7)//toffee
				        	{
				        		toffeeblast(matrix);
				        			printGrid();
									printboard(matrix);	
									myCursor(x1,y1,x1+100,y1+100,246,0,0);
									Sleep(1000);
						//			system("cls");
									shapefitting(matrix);//shapefitting in empty spaces	
									printGrid();
									printboard(matrix);	
									myCursor(x1,y1,x1+100,y1+100,246,0,0);  
						    }
				        	move--;
				            system("cls");
						    printGrid();
						    printboard(matrix);
							Sleep(500);
							myCursor(x1,y1,x1+100,y1+100,246,0,0);	
						    if(!blasting(matrix))//reswaping if the blasting does not happens
						    {
						    	swap(matrix[i][j],matrix[i][j+1]);
						    	move++;
				            	system("cls");
						    	printGrid();
						    	printboard(matrix);
								myCursor(x1,y1,x1+100,y1+100,246,0,0);	
							}
						}
						if(key==1 && x1>=530)//left swaping
						{
							swap(matrix[i][j],matrix[i][j-1]);
							score=score+100;
							if(matrix[i][j]==7 || matrix[i][j-1]==7)//toffe
				        	{
				        		toffeeblast(matrix);
				        			printGrid();
									printboard(matrix);	
									myCursor(x1,y1,x1+100,y1+100,246,0,0);
									Sleep(1000);
						//			system("cls");
									shapefitting(matrix);//shapefitting in empty spaces	
									printGrid();
									printboard(matrix);	
									myCursor(x1,y1,x1+100,y1+100,246,0,0);  
						    }
							move--;
						    system("cls");
						    printGrid();
						    printboard(matrix);
							Sleep(500);	
							myCursor(x1,y1,x1+100,y1+100,246,0,0);
						    if(!blasting(matrix))//reswaping if the blasting does not happens
						    {
						    	swap(matrix[i][j],matrix[i][j-1]);
						    	move++;//returning move
						    	system("cls");
						    	printGrid();
						    	printboard(matrix);	
						    	myCursor(x1,y1,x1+100,y1+100,246,0,0);
							}
						}

						if(key==2 && y1>=180)//up swaping
						{
							swap(matrix[i][j],matrix[i-1][j]);
							score=score+100;//score increment
							if(matrix[i][j]==7 || matrix[i-1][j]==7)//toffee
				        	{
				        		toffeeblast(matrix);
				        			printGrid();
									printboard(matrix);	
									myCursor(x1,y1,x1+100,y1+100,246,0,0);
									Sleep(1000);
						//			system("cls");
									shapefitting(matrix);//shapefitting in empty spaces	
									printGrid();
									printboard(matrix);	
									myCursor(x1,y1,x1+100,y1+100,246,0,0);  
						    }
							move--;//move decrement
						    system("cls");
						    printGrid();
						    printboard(matrix);
							Sleep(500);	
							myCursor(x1,y1,x1+100,y1+100,246,0,0);
						    if(!blasting(matrix))//reswaping if the blasting does not happens
						    {
						    	swap(matrix[i][j],matrix[i-1][j]);//swapback
						    	move++;//returning move
						    	system("cls");
						    	printGrid();
						    	printboard(matrix);	
						    	myCursor(x1,y1,x1+100,y1+100,246,0,0);
							}
						}
				    }
				}
      			system("cls");
				coloralpha(5);
				cout<<"Your score is : "<<score<<endl;
				coloralpha(9);
	            cout<<"moves left are : "<<move;
	            printGrid();
				printboard(matrix);
				myCursor(x1,y1,x1+100,y1+100,246,0,0);
			}
		}
		//ending page
		ending();
		_getch();		
	}
	_getch();

}
