#include<iostream>
#include<cstdlib>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int calc_max(int P[],int n)
{
	int mx,val[n+1]={0},PC[n+1]={0};
	
	for(int i=1; i<=n; i++)
	{
		mx=0;
		for(int j=0; j<i; j++)
		{
			mx=max(mx,P[j]+val[i-j-1]);
			if(mx==P[j]+val[i-j-1])
				PC[i]=j+1;
		}
		val[i]=mx;
	}
	
	int i=n;
	while(i>0)
	{
		cout<<PC[i]<<" ";
		i-=PC[i];
	}
	cout<<endl;
	
	return val[n];
}

int main()
{
	int n;
	
	cout<<"Enter n : ";
	cin>>n;
	int P[n];
	
	if(n<0)
	exit(0);
	
	else
	{
		cout<<"Enter Prices : ";
		for(int i=0; i<n; i++)
		cin>>P[i];
		
		cout<<"Max cost is : "<<calc_max(P,n);
	}
}
