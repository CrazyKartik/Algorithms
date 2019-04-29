#include<iostream>
#include<cstdlib>
using namespace std;

int min(int a,int b)
{
	return (a<b)?a:b;
}

int main()
{
	int n,max=1,mul_2=2,mul_3=3,mul_5=5,i2=0,i3=0,i5=0,ugly=1;
	int *A=(int*)malloc(sizeof(int));
	*(A)=1;
	
	while(true)
	{
		cout<<"Enter n : ";
		cin>>n;
		
		if(n<=0)
		exit(0);
		
		else
		{
			if(n>max)
			{
				A=(int*)realloc(A,n*sizeof(int));
				for(int i=max; i<n; i++)
				*(A+i)=-1;
			}
			
			if(*(A+n-1)!=-1)
				cout<<*(A+n-1)<<endl;
			
			else
			{
				for(int i=max; i<n; i++)
				{
					ugly=min(mul_2,min(mul_3,mul_5));
					
					*(A+i)=ugly;
					
					if(ugly==mul_2)
					{
						i2+=1;
						mul_2=(*(A+i2))*2;
					}
					if(ugly==mul_3)
					{
						i3+=1;
						mul_3=(*(A+i3))*3;
					}
					if(ugly==mul_5)
					{
						i5+=1;
						mul_5=(*(A+i5))*5;
					}
				}
				max=n;
				cout<<*(A+n-1)<<endl;
			}
		}
	}
}
