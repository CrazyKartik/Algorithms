#include<iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b)?a:b;
}

int main()
{
	int n;
	cout<<"Enter length of rod : ";
	cin>>n;
	
	cout<<"Enter cost of the length of rods : ";
	int C[n];
	for(int i = 0; i < n; i++)
	cin>>C[i];
	
	int cost[n+1] = {0};
	
	for(int i = 1; i <= n; i++)
	{
		int price = 0;
		for(int j = 0; j < i; j++)
		{
			price = max(price, cost[j] + C[i-j-1]);
		}
		cost[i] = price;
	}
	cout<<cost[n];
}
