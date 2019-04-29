#include<iostream>
using namespace std;

string longer(string s1,string s2)
{
	return (s1.length()>s2.length())?s1:s2;
}

string LCS(string s1,string s2,int ss1,int es1,int ss2,int es2,string *mem,int col)
{
	if(ss1>=es1 || ss2>=es2)
	return "";
	
	if(*((mem+ss1*col)+ss2)!="")
		return *((mem+ss1*col)+ss2);
	
	int k=es2;
	for(int i=ss2; i<es2; i++)
	{
		if(s2[i]==s1[ss1])
		{
			k=i;
			break;
		}
	}
	
	if(k>=es2)
	{
		if(*((mem+(ss1+1)*col)+ss2)=="")
			*((mem+(ss1+1)*col)+ss2)=LCS(s1,s2,ss1+1,es1,ss2,es2,mem,col);
		return *((mem+(ss1+1)*col)+ss2);
	}
	
	if(*((mem+(ss1+1)*col)+k+1)=="")
			*((mem+(ss1+1)*col)+k+1)=LCS(s1,s2,ss1+1,es1,k+1,es2,mem,col);
	string r1=s1[ss1]+*((mem+(ss1+1)*col)+k+1);
	
	if(*((mem+(ss1+1)*col)+ss2)=="")
			*((mem+(ss1+1)*col)+ss2)=LCS(s1,s2,ss1+1,es1,ss2,es2,mem,col);
	string r2=*((mem+(ss1+1)*col)+ss2);
	
	return longer(r1,r2);
}

int main()
{
	string s1,s2;
	cout<<"Enter First String : ";
	cin>>s1;
	cout<<"Enter Second String : ";
	cin>>s2;
	
	int l1=s1.length();
	int l2=s2.length();
	
	string mem[l1+1][l2+1];
	for(int i=0; i<l1+1; i++)
	{
		for(int j=0; j<l2+1; j++)
		{
			mem[i][j]="";
		}
	}
	
	cout<<LCS(s1,s2,0,l1,0,l2,*mem,l2+1);
}
