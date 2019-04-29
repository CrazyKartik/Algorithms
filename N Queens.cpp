#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

bool is_safe(int *A,int n,int r,int c)
{
	int r1=r,c1=c,c2=c;
	
	for(int i=0; i<r; i++)
	{
		if(*((A+i*n)+c)==1)
		return false;
	}
	
	while(r1>=0 && c2<n)
	{
		if(*((A+r1*n)+c2)==1)
		return false;
		r1--;
		c2++;
	}
	
	r1=r;
	while(r1>=0 && c1>=0)
	{
		if(*((A+r1*n)+c1)==1)
		return false;
		r1--;
		c1--;
	}
	
	return true;
}

int check(int *A,int n,int r)
{
	static int count=0;
	
	if(r>=n)
		return ++count;
	
	for(int i=0; i<n; i++)
	{	
		if(is_safe(A,n,r,i))
		{
			
			*((A+r*n)+i)=1;
			count=check(A,n,r+1);
			*((A+r*n)+i)=0;
		}
	}
	
	return count;
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	int A[n][n];
	memset(A,0,sizeof(A));
	
	int ways=check(*A,n,0);
	cout<<ways;
}
