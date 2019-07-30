#include<iostream>
using namespace std;

int main()
{
	long long int n,k;
	cout<<"Enter n and k : ";
	cin>>n>>k;
	
	long long int coef[k+1];
	coef[0] = 1;
	coef[1] = n;
	
	for(long long int i = 2; i <= k; i++)
	{
		coef[i] = coef[i-1] * (n + 1 - i);
		coef[i] /= i;
	}
	
	cout<<coef[k];
}
