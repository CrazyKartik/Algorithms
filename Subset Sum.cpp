#include<iostream>
using namespace std;

int main()
{
	int n,s;
	cout<<"Enter n and sum : ";
	cin>>n>>s;
	
	int A[n];
	for(int i = 0; i < n; i++)
	cin>>A[i];
	
	bool sum[s+1][n+1];
	
	for(int i = 0; i <= s; i++)
	sum[i][0] = false;
	
	for(int i = 0; i <= n ; i++)
	sum[0][i] = true;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= s; j++)
		{
			sum[j][i] = sum[j][i-1];
			if((j - A[i-1]) >= 0)
			sum[j][i] = sum[j][i-1] || sum[j-A[i-1]][i-1];
		}
	}
	
	if(!sum[s][n])
	cout<<"No Such Subset\n";
	
	if(sum[s][n])
	{
		cout<<"One of the subset is : \n{";
		int row = s, col;
		for(int i = 0; i <= n; i++)
		{
			if(sum[s][i] == 1)
			{
				col = i;
				break;
			}
		}
		while (true)
		{
			if(row <= 0 || col <= 0)
			break;
			
			cout<<A[col-1];
			row = row - A[col-1];
			for(int i = col; i >= 0; i--)
			{
				if(sum[row][i] == 1)
				col = i;
			}
			if(row > 0 && col > 0)
			cout<<",";
		}
		cout<<"}";
	}
}
