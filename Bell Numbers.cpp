#include<iostream>
#include<cstring>
using namespace std;

//Using Bell's Triangle
int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	
	int S[n+1][n+1];
	memset(S, 0, sizeof(S));
	S[0][0] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		S[i][0] = S[i-1][i-1];
		for(int j = 1; j <= i; j++)
		{
			S[i][j] = S[i-1][j-1] + S[i][j-1];
		}
	}
	cout<<S[n][0];
}
