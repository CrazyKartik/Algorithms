#include<iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	
	int A[n], S[n], mx;
	for(int i = 0; i < n; i++)
		cin>>A[i];
	S[0] = A[0];
	mx = S[0];
	
	for(int i = 1; i < n; i++)
	{
		S[i] = max(S[i-1] + A[i], A[i]);
		mx = max(mx, S[i]);
	}
	cout<<mx;
}
