#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

void solve_maze(int *m,int* sol,int n,int i,int j)
{
	static int solved=0;
	
	if(i<0 || i>n || j<0 || j>n)
	return;
	
	if(*((sol+i*n)+j)==2)
		return;
	
	if(i==n-1 && j==n-1)
	{
		solved=1;
		*((sol+i*n)+j)=1;
		return;
	}
	
	if(*((m+i*n)+j)==0)
		return;
	
	*((sol+i*n)+j)=2;
	
	if(!solved)
	{
		solve_maze(m,sol,n,i,j+1);
		if(!solved)
		*((sol+i*n)+j)=0;
	}
	if(!solved)
	{
		solve_maze(m,sol,n,i+1,j);
		if(!solved)
		*((sol+i*n)+j)=0;
	}
	if(!solved)
	{
		solve_maze(m,sol,n,i,j-1);
		if(!solved)
		*((sol+i*n)+j)=0;
	}
	if(!solved)
	{
		solve_maze(m,sol,n,i-1,j);
		if(!solved)
		*((sol+i*n)+j)=0;
	}
	
	if(solved)
		*((sol+i*n)+j)=1;
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	int maze[n][n];
	int sol[n][n];
	memset(sol,0,sizeof(sol));
	
	cout<<"Enter Maze : ";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>maze[i][j];
		}
	}
	
	cout<<endl;
	
	solve_maze(*maze,*sol,n,0,0);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}
