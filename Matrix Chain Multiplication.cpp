#include<iostream>
#include<cstring>
using namespace std;

void print_parenthesis(int *bracket,char &nm,int i,int j,int sz)
{
	if(i==j)
	{
		cout<<nm++;
		return;
	}
	
	cout<<"(";
	print_parenthesis(bracket,nm,i,*(bracket+i*sz+j),sz);
	print_parenthesis(bracket,nm,*(bracket+i*sz+j)+1,j,sz);
	cout<<")";
}

int MCM(int M[],int *mem,int start,int end,int size,int *bracket)
{
	if(start>=end)
	return 0;
	
	if(*(mem+start*size+end)!=-1)
		return *(mem+start*size+end);
	
	int min=INT_MAX;
	
	for(int i=start; i<end; i++)
	{
		int cost=MCM(M,mem,start,i,size,bracket) + MCM(M,mem,i+1,end,size,bracket) + M[start-1]*M[i]*M[end];
		if(cost<min)
		{
			min=cost;
			*(bracket+start*size+end)=i;
		}
	}
	*(mem+start*size+end)=min;
	
	return min;
}

int main()
{
	int n;
	cin>>n;
	int M[n],mem[n+1][n+1],bracket[n+1][n+1];
	memset(mem,-1,sizeof(mem));
	memset(bracket,0,sizeof(bracket));
	for(int i=0; i<n; i++)
	cin>>M[i];
	
	cout<<MCM(M,*mem,1,n-1,n+1,*bracket)<<endl;
	char nm='A';
	print_parenthesis(*bracket,nm,1,n-1,n+1);
}
