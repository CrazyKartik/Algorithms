#include<iostream>
#include<cstring>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	string s;
	cin>>s;
	
	int l = s.length();
	int L[l+1][l+1];
	memset(L, 0, sizeof(L));
	
	for(int i = l-1; i >= 0; i--)
	{
		for(int j = l-1; j >= 0; j--)
		{
			if(s[i] == s[j] && i != j)
			L[i][j] = L[i+1][j+1] + 1;
			else
			L[i][j] = max(L[i+1][j], L[i][j+1]);
		}
	}
	cout<<"Length is : "<<L[0][0]<<endl;
	
	int i = 0, j = 0;
	while(true)
	{
		if(i == l || j == l)
		break;
		
		if(s[i] == s[j] && i != j)
		{
			cout<<s[i];
			i++;
			j++;
		}
		else
		{
			if(L[i][j] == L[i+1][j])
			i++;
			else
			j++;
		}
	}
}
