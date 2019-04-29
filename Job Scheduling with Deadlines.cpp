#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct
{
	int start,finish,profit;
}tasks;

bool compare(tasks t1,tasks t2)
{
	return t1.finish<t2.finish;
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

int profit(tasks t[],int n,int mem[])
{
	if(n<=1)
	return t[n-1].profit;
	
	if(mem[n]!=-1)
	return mem[n];
	
	int tmp=-1,p1=t[n].profit,p2;
	for(int i=n-1; i>=0; i--)
	{
		if(t[i].finish<=t[n-1].start)
		{
			tmp=i;
			break;
		}
	}
	if(tmp!=-1)
	p1+=profit(t,tmp+1,mem);
	p2=profit(t,n-1,mem);
	
	mem[n] = max(p1,p2);
	return mem[n];
}

int main()
{
	int n;
	cout<<"Enter number of processes : ";
	cin>>n;
	
	tasks t[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter start time of process : ";
		cin>>t[i].start;
		cout<<"Enter finish time of process : ";
		cin>>t[i].finish;
		cout<<"Enter profit : ";
		cin>>t[i].profit;
	}
	
	sort(t,t+n,compare);
	int mem[n+1];
	memset(mem,-1,sizeof(mem));
	cout<<profit(t,n,mem);
}
