#include<iostream>
#include<cstdlib>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int solve(int A[], int l)
{
	if(l<=0)
	return 0;
	
	int cost = 0;
	
	for(int j=0; j<l; j++)
	{
		cost = max(cost,A[l-j-1] + solve(A,j));
	}
	
	return cost;
}

int main()
{
	int l;
	cin>>l;
	int A[l];
	for(int i = 0; i < l; i++)
	cin>>A[i];
	
	int ans = solve(A,l);
	cout<<ans;
}
