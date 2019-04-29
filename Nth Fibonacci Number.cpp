#include<iostream>
#include<cstdlib>
using namespace std;

long long int fib(long long int n,long long int *F)
{
	if(*(F+n)>=0)
	return *(F+n);
	if(n==0)
	return 0;
	if(n==1)
	return 1;
	
	*(F+n)=fib(n-1,F)+fib(n-2,F);
	return *(F+n);
}

int main()
{
	long long int n,n1=0;
	long long int *F=(long long int*)malloc(sizeof(long long int));
	*F=-1;
	
	while(true)
	{
		cout<<"Enter n : ";
		cin>>n;
		if(n>n1)
		{
			F=(long long int*)realloc(F,sizeof(long long int)*(n1+(n-n1)+1));
			for(long long int i=n1+1; i<=n; i++)
			*(F+i)=-1;
		}
		cout<<fib(n,F)<<endl;
	}
}
