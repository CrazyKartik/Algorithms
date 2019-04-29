#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int find_index(int v,int V[],int l)
{
	for(int i=0; i<l; i++)
	{
		if(V[i]==v)
		return i;
	}
	return -1;
}

int min(int a,int b)
{
	return (a<b)?a:b;
}

void TSP(int *G,int vis[],int n,int &ans,int cur,int cost,int count)
{
	if(count==n && *(G+cur*n))
	{
		cost=cost+*(G+cur*n);
		ans=min(ans,cost);
		return;
	}
	
	for(int i=0; i<n; i++)
	{
		if(!vis[i] && *(G+cur*n+i))
		{
			vis[i]=1;
			TSP(G,vis,n,ans,i,cost+*(G+cur*n+i),count+1);
			vis[i]=0;
		}
	}
}


int main()
{
	int *V=(int*)malloc(sizeof(int));
	int c,i=0,v1,v2,w;
	
	do
	{
		V=(int*)realloc(V,(i+1)*sizeof(int));
		cout<<"Enter vertex : ";
		cin>>*(V+i);
		i++;
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	cout<<endl;
	for(int j=0; j<i; j++)
	cout<<*(V+j)<<" ";
	cout<<endl<<endl;
	
	int A[i][i];
	memset(A,0, sizeof(A));
	
	do
	{
		cout<<"Enter vertex v1 of edge : ";
		cin>>v1;
		cout<<"Enter vertex v2 of edge : ";
		cin>>v2;
		cout<<"Enter Weight of the edge : ";
		cin>>w;
		int i1=find_index(v1,V,i);
		int i2=find_index(v2,V,i);
		if(i1==-1 || i2==-1)
			cout<<"Enter valid vertices!!!!\n\n";
		else
		{
			A[i1][i2]=w;
			A[i2][i1]=w;
		}
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	cout<<endl;
	
	int ans=INT_MAX;
	int vis[i];
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	TSP(*A,vis,i,ans,0,0,1);
	
	cout<<endl<<ans;
}
