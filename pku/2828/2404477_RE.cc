#include<iostream>
using namespace std;
#define MAX 700000

struct gao
{
	int a,b,c;
}x[MAX];

int ans[200001];
int p[200001][2];

void build(int begin,int end,int v)
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
		x[v].c=begin-end+1;
		build(begin,(begin+end)/2,2*v);
		build((begin+end)/2+1,end,2*v+1);
	}
}

void change(int num,int q,int v)
{
	x[v].c--;
	if(x[v].a==x[v].b)
		ans[x[v].a]=q;
	if(num<x[2*v].c)
		change(num,q,2*v);
	else
		change(num-x[2*v].c,q,2*v+1);
}
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		build(1,n,1);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i][0],&p[i][1]);
		for(i=n-1;i>=0;i--)
			change(p[i][0],p[i][1],1);
		for(i=1;i<n;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}