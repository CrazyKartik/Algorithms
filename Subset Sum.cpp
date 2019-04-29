#include<iostream>
#include<cstring>
using namespace std;


string sum(int A[],int start,int end,int k,int sm,string *sub,int size)
{
	if(sm==k)
	return "1";
	
	if(start>=end || sm>k)
	return "0";
	
	if(*(sub+start*size+sm)!="")
	return *(sub+start*size+sm);
	
	string s="",s1="1",s2="0";
	
	s1+=sum(A,start+1,end,k,sm+A[start],sub,size);
	s2+=sum(A,start+1,end,k,sm,sub,size);
	if(s1[s1.length()-1]=='1')
	s+=s1;
	else
	s+=s2;
	
	*(sub+(start+1)*size+sm)=s;
	
	return s;
}

int main()
{
	int n,k;
	
	cout<<"Enter n : ";
	cin>>n;
	
	cout<<"Enter k : ";
	cin>>k;
	
	int A[n];
	cout<<"Enter Elements : ";
	for(int i=0; i<n; i++)
	cin>>A[i];
	
	string sub[n+1][k+1];
	
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=k; j++)
		{
			sub[i][j]="";
		}
	}
	string s=sum(A,0,n,k,0,*sub,k+1);
	
	int cnt=0;
	for(int i=0; i<s.length()-1; i++)
	{
		if(s[i]=='1')
		cout<<A[cnt]<<" ";
		cnt++;
	}
}
