#include<iostream>
#include<cstring>
using namespace std;


int max(int a,int b)
{
	return (a>b)?a:b;
}

int knapsack(int W[],int V[],int n,int i,int cap,int *mem,int C)
{	
	if(i>=n)
		return 0;
	
	if(*((mem+C*cap)+i)!=-1)
		return *((mem+C*cap)+i);
	
	if(cap<W[i])
	{
		if(*((mem+cap*C)+i+1)==-1)
			*((mem+cap*C)+i+1)=knapsack(W,V,n,i+1,cap,mem,C);
		return *((mem+cap*C)+i+1);
	}
	
	if(*((mem+cap*C)+i+1)==-1)
		*((mem+cap*C)+i+1)=knapsack(W,V,n,i+1,cap,mem,C);
	
	if(*((mem+(cap-W[i])*C)+i+1)==-1)
		*((mem+(cap-W[i])*C)+i+1)=knapsack(W,V,n,i+1,cap-W[i],mem,C);
	
	return max(*((mem+cap*C)+i+1),V[i]+*((mem+(cap-W[i])*C)+i+1));
}

int main()
{
	int n,cap;
	
	cout<<"Enter n and capacity : ";
	cin>>n>>cap;
	
	int W[n],V[n];
	
	cout<<"Enter weight of each item : ";
	for(int i=0; i<n; i++)
	cin>>W[i];
	
	cout<<"Enter Value of each item : ";
	for(int i=0; i<n; i++)
	cin>>V[i];
	
	int mem[cap+1][n+1];
	memset(mem,-1,sizeof(mem));
	
	cout<<knapsack(W,V,n,0,cap,*mem,n+1);
}
