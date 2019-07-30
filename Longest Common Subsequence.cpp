#include<iostream>
#include<cstring>
using namespace std;

int max(int a, int b)
{
	return (a > b)?a:b;
}

int main()
{
	int l1,l2;
	
	cin>>l1>>l2;
	int seqA[l1], seqB[l2];
	
	for(int i = 0; i < l1; i++)
	cin>>seqA[i];
	
	for(int i = 0; i < l2; i++)
	cin>>seqB[i];
	
	if(l1 == 0 || l2 == 0)
	{
		return 0;
	}
	
	int tab[l2+1][l1+1];
	memset(tab, 0, sizeof(tab));
	
	for(int i = 1; i <= l2; i++)
	{
		for(int j = 1; j <= l1; j++)
		{
			if(seqA[j-1] == seqB[i-1])
			tab[i][j] = tab[i-1][j-1] + 1;
			
			else
				tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
		}
	}
	
	int i = l2, j = l1;
	int output[tab[l2][l1]];
	memset(output, 0, sizeof(output));
	int k = 0;
	while (true)
	{
		if (i==0 || j==0)
			break;
		if (tab[i][j] == tab[i][j-1])
			j--;
		else if (tab[i][j] == tab[i-1][j])
			i--;
		else
		{
			output[k] = seqB[i-1];
			k++;
			i--;
			j--;
		}
	}
	for (int i=0; i<tab[l2][l1]; i++)
		cout << output[tab[l2][l1]-i-1] << " ";
}
