#include<iostream>
#include<cstring>
using namespace std;

bool not_in_line(int *S, int n, int r, int c, int v)
{
	for(int i=0; i<n; i++)
	{
		if(*(S+r*n+i)==v)
		return false;
		if(*(S+i*n+c)==v)
		return false;
	}
	return true;
}

bool not_in_box(int *S, int n, int v, int r, int c)
{
	for(int i=r; i<r+3; i++)
	{
		for(int j=c; j<c+3; j++)
		{
			if(*(S+i*n+j)==v)
			return false;
		}
	}
	return true;
}

void print_solution(int *S, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<*(S+i*n+j)<<" ";
		}
		cout<<endl;
	}
}

void Solve(int *S, int n, int col,int row)
{
	if(col==n)
	return;
	
	if(row==n)
	{
		cout<<endl<<endl;
		print_solution(S,n);
		return;
	}
	
	if(*(S+row*n+col)==0)
	{
		for(int k=1; k<=9; k++)
		{
			if(not_in_box(S,n,k,row-row%3,col-col%3) && not_in_line(S,n,row,col,k))
			{
				*(S+row*n+col)=k;
				Solve(S,n,col+1,row);
				if(col==n-1)
				Solve(S,n,0,row+1);
			}
			*(S+row*n+col)=0;
		}
	}
	else
	{
		Solve(S,n,col+1,row);
		if(col==n-1)
				Solve(S,n,0,row+1);
	}
}

int main()
{
	int S[9][9];
	cout<<"Enter a valid unfilled sudoku : \n";
	cout<<"Enter 0 where there is no number given : \n";
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cin>>S[i][j];
		}
	}
	
	Solve(*S,9,0,0);
}

/*
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0
*/
