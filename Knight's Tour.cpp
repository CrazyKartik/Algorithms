#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int moves=0;

void moveKnight(int *B,int n,int i,int j)
{	
	if(i<0 || i>=n || j<0 || j>=n)
	return;
	
	if(*((B+i*n)+j)!=-1)
		return;
	
	if(*((B+i*n)+j)==-1)
		*((B+i*n)+j)=moves++;
	
	moveKnight(B,n,i+2,j+1);
	moveKnight(B,n,i+2,j-1);
	moveKnight(B,n,i-2,j+1);
	moveKnight(B,n,i-2,j-1);
	moveKnight(B,n,i+1,j+2);
	moveKnight(B,n,i+1,j-2);
	moveKnight(B,n,i-1,j+2);
	moveKnight(B,n,i-1,j-2);
	
	return;
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	
	int B[n][n];
	memset(B,-1,sizeof(B));
	
	moveKnight(*B,n,0,0);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<B[i][j]<<"  ";
		}
		cout<<endl;
	}
}
