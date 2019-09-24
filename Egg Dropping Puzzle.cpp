#include<iostream>
#include<cstring>
using namespace std;

int min(int a, int b)
{
	return (a > b) ? b : a;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int n,k;
	cout << "Enter n and k : ";
	cin >> n >> k;
	int drops[k+1][n+1];


	for(int i = 0; i <= k; i++)
	drops[i][1] = i;
	
	for(int i = 1; i <= n; i++)
	{
		drops[1][i] = 1;
		drops[0][i] = 0;
	}
	
	for(int i = 2; i <= n; i++)
	{
		for(int j = 2; j <= k; j++)
		{
			drops[j][i] = INT_MAX;
			for(int x = 1; x <= j; x++)
			{
				int tmp = 1 + max(drops[x-1][i-1], drops[j-x][i]);
				drops[j][i] = min(drops[j][i], tmp);
			}
		}
	}
	
	cout << drops[k][n] << endl;
}
