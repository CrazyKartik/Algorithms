#include<iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b)?a:b;
}

int main()
{
	int n,m;
	cout<<"Enter m and n : ";
	cin>>m>>n;
	
	int Mine[m][n], total[m][n];
	char path[m][n];
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>Mine[i][j];
			total[i][j] = Mine[i][j];
		}
	}
	
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = 0; j < m; j++)
		{
			int right = (i == n-1) ? 0 : total[j][i+1];
			int right_up = (j == 0 || i == n-1) ? 0 : total[j-1][i+1];
			int right_down = (j == m-1 || i == n-1) ? 0 : total[j+1][i+1];
			int mx = max(right, max(right_up, right_down));
			
			total[j][i] = total[j][i] + mx;
			
			if(mx == right)
			path[j][i] = '-';
			else if(mx == right_up)
			path[j][i] = '/';
			else if(mx == right_down)
			path[j][i] = '\\';
			else
			path[j][i] = '\0';
		}
	}
	
	int mx = 0, mx_row;
	for(int i = 0; i < m; i++)
	{
		mx = max(mx, total[i][0]);
		if(mx == total[i][0])
		mx_row = i;
	}
	cout<<mx<<endl;
	
	int row = mx_row, col = 0;
	cout<<"Path ---- \n";
	cout<<Mine[row][col]<<" ---> ";
	while(true)
	{
		if(col == m-1 || row == n-1 || path[row][col] == '\0')
		break;
		
		if(path[row][col] == '-')
		{
			cout<<Mine[row][col+1]<<" ---> ";
			col++;
		}
		else if(path[row][col] == '/')
		{
			cout<<Mine[row-1][col+1]<<" ---> ";
			row--;
			col++;
		}
		else if(path[row][col] == '\\')
		{
			cout<<Mine[row+1][col+1]<<" ---> ";
			row++;
			col++;
		}
	}
}
