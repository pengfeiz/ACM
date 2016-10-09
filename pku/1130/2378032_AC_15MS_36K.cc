#include <iostream>
using namespace std;
#define MAX 10

bool d[MAX][MAX],b[MAX];
int a[MAX],c[MAX];
int n,m;

int dfs(int x)
{
	int i,t=0;
	b[x]=true;
	if(x==m)
	{
		a[m]++;
		return 1;
	}
	for(i=0;i<n;i++)
		if(d[x][i]&&(!b[i]||i==m))
			t+=dfs(i);
	a[x]+=t;
	return t;
}

void dfs2(int x,int depth)
{
	int i;
	if(c[x]<=depth)
		return;
	c[x]=depth;
	for(i=0;i<n;i++)
		if(d[i][x])
			dfs2(i,depth+1);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int p,q,i;
	scanf("%d%d",&n,&m);
	memset(d,0,sizeof(d));
	while(scanf("%d%d",&p,&q)!=EOF)
		d[p][q]=true;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,127,sizeof(c));
	q=dfs(0);
	dfs2(m,0);
	q=-1;
	p=-1;
	for(i=0;i<n;i++)
	{
		if(i==m)
			continue;
		if(a[i]>q)
		{
			q=a[i];
			p=i;
		}
		else if(a[i]==q&&c[p]>c[i])
		{
			q=a[i];
			p=i;
		}
	}
	printf("Put guards in room %d.\n",p);
	return 0;
}