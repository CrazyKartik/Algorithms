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

bool is_valid(int V[],int *A,int l,int color[],int col,int i)
{
	for(int j=0; j<l; j++)
	{
		if(*(A+j+i*l)==1)
		{
			if(color[j]==col)
			return false;
		}
	}
	return true;
}

void color_graph(int V[],int *A,int l,int color[],int *col,int i)
{
	if(color[i]!=0 || i>=l)
	return;


	for(int c=1; c<=*col; c++)
	{
		if(is_valid(V,A,l,color,c,i))
		{
			color[i]=c;
			break;
		}
	}
	if(!color[i])
	color[i]=++*col;

	color_graph(V,A,l,color,col,i+1);
}


int main()
{
	int *V=(int*)malloc(sizeof(int));
	int c,i=0,v1,v2;
	
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
		int i1=find_index(v1,V,i);
		int i2=find_index(v2,V,i);
		if(i1==-1 || i2==-1)
			cout<<"Enter valid vertices!!!!\n\n";
		else
		{
			A[i1][i2]=1;
			A[i2][i1]=1;
		}
		cout<<"Enter 0 to exit : ";
		cin>>c;
	}
	while(c);
	cout<<endl;
	
	int color[i],col=1;
	memset(color,0,sizeof(color));
	color_graph(V,*A,i,color,&col,0);
	
	cout<<endl<<col<<" different colors needed to color the graph\n";
}
