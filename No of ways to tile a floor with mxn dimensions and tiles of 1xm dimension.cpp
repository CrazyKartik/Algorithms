#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	
	if(n < m)
	{
		cout<<1;
		return 0;
	}
	
	if(n == m)
	{
		cout<<2;
		return 0;
	}
	
	int ways[n+1];
	ways[0] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		if(i < m)
		{
			ways[i] = ways[i-1];
			continue;
		}
		ways[i] = ways[i-1] + ways[i-m];
	}
	cout<<ways[n];
}
