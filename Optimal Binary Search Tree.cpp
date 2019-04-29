#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int find_cost(int F[],int K[],int start,int end,int *S,int sz,int *mem,int size)
{
	if(end<start)
	return 0;
	
	if(end==start)
		return F[start];
	
	if(*(mem+start*size+end)!=-1)
		return *(mem+start*size+end);
	
	int min=INT_MAX;
	for(int i=start; i<=end; i++)
	{
		if(*(mem+size*start+i-1)==-1)
			*(mem+size*start+i-1)=find_cost(F,K,start,i-1,S,sz,mem,size);
		int c1=*(mem+size*start+i-1);
		
		if(*(mem+size*(i+1)+end)==-1)
			*(mem+size*(i+1)+end)=find_cost(F,K,i+1,end,S,sz,mem,size);
		int c2=*(mem+size*(i+1)+end);
		
		int c=c1+c2;
		if(c<min)
			min=c;
	}
	
	return min+*(S+start*sz+end);
}

int main()
{
	int n;
	cout<<"Enter number of keys : ";
	cin>>n;
	
	int K[n],F[n],S[n][n],mem[n+1][n+1],T[n];
	
	cout<<"Enter Keys : ";
	for(int i=0; i<n; i++)
	cin>>K[i];
	cout<<"Enter Frequency : ";
	for(int i=0; i<n; i++)
	cin>>F[i];
	
	memset(S,0,sizeof(S));
	memset(mem,-1,sizeof(mem));
	
	for(int i=0; i<n; i++)
	S[i][i]=F[i];
	
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			S[i][j]=S[i][j-1]+F[j];
		}
	}
	
	
	cout<<find_cost(F,K,0,n-1,*S,n,*mem,n+1);
}
