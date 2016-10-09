#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int build(int n1,int num[])
{
	int n=n1,t;
	do
	{
		for(int j=99;j>=0;j--)
		{
			if(num[j]>0)
			{
				t=j;
				break;
			}
			else
				t=j;
		}
		num[t]=0;
		n=n*(t+1);
		for(int i=t+1;i<100;i++)
		{
			if(n%(i+1)==0)
			{
				num[i]=1;
				n=n/(i+1);
				t=i;
			}
		}			
		if(n==n1)
			return 0;
	}while(n>1);
	return 1;
}

int rebuild(int n1,int num[])
{
	int n=1,t;
	do
	{
		for(int j=99;j>=0;j--)
		{
			if(num[j]>0)
			{
				t=j;
				break;
			}
			else
				t=j;
		}
		num[t]=0;
		n=n*(t+1);
		for(int i=t+1;i<100;i++)
		{
			if(n%(i+1)==0)
			{
				num[i]=1;
				n=n/(i+1);
				t=i;
			}
		}			
		if(n==n1)
			return 0;
	}while(n>1);
	return 1;
}

int compute(int n1,int n2)
{
	int num1[100],num2[100],i,t=0,t1,t2;
	t1=t2=1;
	for(i=0;i<100;i++)
	{
		num1[i]=0;
		num2[i]=0;
	}
	build(n1,num1);	
	do{
		for(i=0;i<100;i++)
			num2[i]=0;
		build(n2,num2);
		do{
			for(i=0;i<100;i++)
			{
				if(num1[i]==num2[i]&&num2[i]!=0)
				{
					t1=rebuild(n2,num2);
					t=1;
					break;
				}
				else
					t=0;
			}
		}while(t1!=0&&t==1);
		t2=rebuild(n1,num1);
	}while(t2!=0&&t==1);
	if(t==0)
		return 1;
	else 
		return 0;	
}
		
int judge(int n1,int n2)
{
	
	int i,n,t=0,num[100];
	if(n1<n2)
	{
		i=n1;
		n1=n2;
		n2=i;
	}
	n=n1;
	if(n2<1)
		return n1;
	for(i=0;i<100;i++)
		num[i]=0;
	if(build(n2,num)==0)
		return n1;
	for(i=0;i<100;i++)
		num[i]=0;		
	if(build(n1,num)==0)
		return n2;		
	else if(compute(n1,n2)==1)
		return n1;
	else
		return n2;
}

int main()
{
	int n1,n2;
//	ifstream in("input.txt");
//	ofstream out("output2.txt");
	while(cin>>n1>>n2)
	{
		cout<<judge(n1,n2)<<endl;		
	}
//	out.close();
//	in.close();
	return 0;
}




	