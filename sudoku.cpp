#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int i=0,j=0;
int k=0,x=0;
int l=0,p=0;
int m=0,t=0;

char v[9];
char sudoku[9][9];

void message()
{
	cout<<" \n Welcome,this program will verify a sudoku board for you \n";
	cout<<"Pls take care of few basic points before proceeding \n";
	cout<<" 1.Entries have to be made row wise\n";
	cout<<" 2.While user will provide entries,program will simultaneously validate the board entries \n";
	cout<<" 3.The following convention is used to denote sub-squares 3x3 \n";
    cout<<"1 1 1 2 2 2 3 3 3\n";
    cout<<"1 1 1 2 2 2 3 3 3\n";
    cout<<"1 1 1 2 2 2 3 3 3\n";
    cout<<"4 4 4 5 5 5 6 6 6\n";
    cout<<"4 4 4 5 5 5 6 6 6\n";
    cout<<"4 4 4 5 5 5 6 6 6\n";
    cout<<"7 7 7 8 8 8 9 9 9\n";
    cout<<"7 7 7 8 8 8 9 9 9\n";
    cout<<"7 7 7 8 8 8 9 9 9\n";
    cout<<"\n invalid entries at square 7 \n";
}	

void* condition_1(void*)
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(i==j)
				continue;
			if(v[i]==v[j])
			{
				cout<<"Invalid entries at row"<< l+1<<" and thus program exited \n";
				cout<<v[i]<<" "<<v[j]<<"\n";
				exit(0);
			}
		}
	}
	pthread_exit(0);
}

void* condition_2(void*)
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<=l;j++)
		{
			for(k=0;k<=l;k++)
			{
			 if(j==k)
				continue;
			 if(sudoku[k][i]==sudoku[j][i])
			  {
			 	 cout<<"Invalid entries at column"<<i+1<<" and thus program exited \n";
			 	 cout<<k<<" "<<j<<"\n";
				 exit(0);
			  }
			}    	
		}
	}
	pthread_exit(0);
}

void* condition_3(void*)
{
	t=p-2;
	m=p+1;
	for(i=t;i<m;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=t;k<m;k++)
			{
				for(x=0;x<3;x++)
                {
                	if(i==k && j==x)
				     continue;
			        if(sudoku[i][j]==sudoku[k][x])
			        {
			        	cout<<"Invalid entries at square"<<j/3+1<<" and thus program exited \n";
				        exit(0);
			        }	

		        }
		    }
		}        
	}
	for(i=t;i<m;i++)
	{
		for(j=3;j<6;j++)
		{
			for(k=t;k<m;k++)
			{
				for(x=3;x<6;x++)
                {
                	if(i==k && j==x)
				     continue;
			        if(sudoku[i][j]==sudoku[k][x])
			        {
			        	cout<<"Invalid entries at square"<<4+j/3<<" and thus program exited \n";
				        exit(0);
			        }	

		        }
		    }
		}        
	}
	for(i=t;i<m;i++)
	{
		for(j=6;j<9;j++)
		{
			for(k=t;k<m;k++)
			{
				for(x=6;x<9;x++)
                {
                	if(i==k && j==x)
				     continue;
			        if(sudoku[i][j]==sudoku[k][x])
			        {
			        	cout<<"Invalid entries at square"<<7+j/3<<" and thus program exited \n";
				        exit(0);
			        }	

		        }
		    }
		}        
	}
	pthread_exit(0);
}



int main()
{
	message();
	pthread_t t1,t2,t3;
	for(int h=0;h<9;h++)
	{
		cout<<"Enter row "<<h+1<<" Of sudoku board \n";
		scanf("%s",sudoku[h]);
		strcpy(v,sudoku[h]);
		l=h;
		p=h;
		pthread_create(&t1,NULL,&condition_1,NULL);
		if(h==0)
			continue;
		pthread_create(&t2,NULL,&condition_2,NULL);
		if((i+1)%3==0)
          pthread_create(&t3,NULL,&condition_3,NULL);
	}
    cout<<"The Sudoku board entries are valid! \n";
    return 0;
}