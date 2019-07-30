#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	
	int fib[n] = {0};
	fib[1] = 1;
	
	for(int i = 2; i < n; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	cout<<fib[n-1];
}
