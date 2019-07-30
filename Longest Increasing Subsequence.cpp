#include<iostream>
#include<cstdlib>
using namespace std;

int max(int a, int b)
{
	return (a > b)?a:b;
}

int main()
{
	int n;
	cout<<"Enter the length of array : ";
	cin>>n;
	
	int A[n];
	for(int i = 0; i < n; i++)
	cin>>A[i];
	
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	
	int tab[n];
	tab[0] = 1;
	
	int ans = 1;
	
	for(int i = 1; i < n; i++)
	{
		int l = 1;
		for(int j = 0; j < i; j++)
		{
			if(A[i] > A[j])
				l = max(l,tab[j]+1);
		}
		tab[i] = l;
		ans = max(ans, tab[i]);
	}
	cout<<ans;
}
