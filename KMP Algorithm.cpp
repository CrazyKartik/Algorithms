#include<iostream>
using namespace std;

void calculateLPS (int lps[], string pat, int m)
{
	int i = 1, j = 0;
	lps[0] = 0;
	while (i < m)
	{
		if (pat[i] == pat[j])
		{
			lps[i] = j + 1;
			j++;
			i++;
		}
		else
		{
			if (j == 0)
			lps[i++] = j;
			else
			j = lps[j-1];
		}
	}
}

void findPattern (string s, string pat)
{
	int i = 0, j = 0, found = 0;
	int n = s.length();
	int m = pat.length();
	int lps[m];
	calculateLPS (lps, pat, m);
	
	while (i < n)
	{
		if (s[i] == pat[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j == 0)
				i++;
			else
				j = lps[j-1];
		}
		if(j == m)
		{
			cout << "Pattern Found at position : " << i - j << endl;
			j = lps[j-1];
			found = 1;
		}
	}
	
	if (!found)
	cout << "Pattern Not Found\n";
}

int main()
{
	string s,pat;
	cout << "Enter String : ";
	cin >> s;
	cout << "Enter Pattern : ";
	cin >> pat;
	
	findPattern(s, pat);
}
