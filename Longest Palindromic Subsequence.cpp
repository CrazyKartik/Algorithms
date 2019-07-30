#include<iostream>
#include<cstring>
using namespace std;

int max(int a, int b)
{
	return (a > b)?a:b;
}

int main()
{
	string s;
	getline(cin,s);
	int l = s.length();
	
	int L[l][l];
	memset(L,0,sizeof(L));
	for(int i = 0; i < l; i++)
	L[i][i] = 1;
	
	if(l == 1)
	{
		cout<<1;
		return 0;
	}
	if(l == 2)
	{
		if(s[0] == s[1])
		{
			cout<<2;
			return 0;
		}
		else
		{
			cout<<1;
			return 0;
		}
	}
	
	for(int i = 1; i < l; i++)
	{
		for(int j = 0; j < l - i; j++)
		{
			if(s[j] == s[j + i])
			L[j][j+i] = L[j+1][j+i-1] + 2;
			else
			L[j][j+i] = max(L[j][j+i-1], L[j+1][j+i]);
		}
	}
	
	cout<<L[0][l-1];
	return 0;
}
