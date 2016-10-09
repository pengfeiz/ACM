#include<iostream>
using namespace std;
#define MAX 700000

struct gao
{
	int a,b,c;
}x[MAX];

int result[200001];
int p[200001][2];

void Init(int begin,int end,int v)
{
	if(begin==end)
	{
		x[v].a=begin;
		x[v].b=end;
		x[v].c=1;
	}
	else                         
	{
		x[v].a=begin;
		x[v].b=end;
		x[v].c=end-begin+1;
		Init(begin,(begin+end)/2,2*v);
		Init((begin+end)/2+1,end,2*v+1);
	}
}

void change(int count,int value,int v)
{
	x[v].c--;
	if(x[v].a==x[v].b)                     
	{
		result[x[v].a]=value;
		return;
	}
	if(x[2*v].c>count)
		change(count,value,2*v);
	else
		change(count-x[2*v].c,value,2*v+1);
}
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		Init(1,n,1);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i][0],&p[i][1]);
		for(i=n-1;i>=0;i--)
			change(p[i][0],p[i][1],1);
		for(i=1;i<n;i++)
			printf("%d ",result[i]);
		printf("%d",result[n]);
	}
	return 0;
}