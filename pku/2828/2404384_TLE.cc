#include<iostream.h>

int B[600002],E[600002],C[600002];
int person[200000][2];
int result[200001];

void Init(int begin,int end,int v)
{
	if(begin==end)
	{
		B[v]=begin;
		E[v]=end;
		C[v]=1;
	}
	else                         
	{
		B[v]=begin;
		E[v]=end;
		C[v]=end-begin+1;
		Init(begin,(begin+end)/2,2*v);
		Init((begin+end)/2+1,end,2*v+1);
	}
}

void change(int count,int value,int v)
{
	C[v]--;
	if(B[v]==E[v])                     
	{
		result[B[v]]=value;
		return;
	}
	if(C[2*v]>count)
	{
		change(count,value,2*v);
	}
	else
	{
		change(count-C[2*v],value,2*v+1);
	}
}
int main()
{
	int n,i;
	while(cin>>n)
	{
		Init(1,n,1);
		for(i=0;i<n;i++)
		{
			cin>>person[i][0]>>person[i][1];
		}
		for(i=n-1;i>=0;i--)
		{
			change(person[i][0],person[i][1],1);
		}
		for(i=1;i<n;i++)
		{
			cout<<result[i]<<' ';
		}
		cout<<result[i]<<endl;
	}
	return 0;
}