#include <iostream>
#include <vector>
using namespace std;

#define MAX 10002
#define MAX2 50001

struct gao
{
	int x,y;
}edge[MAX2];

vector<int> a[MAX],b[MAX];

int d[MAX],e[MAX],in[MAX];
int n,m,t;
bool c[MAX];


void dfs1(int x)
{
	vector<int>::iterator p;
	c[x]=true;
	p=a[x].begin();
	while(p!=a[x].end())
	{
		if(!c[*p])
			dfs1(*p);
		p++;
	}
	d[t++]=x;
}
void dfs2(int x)
{
	vector<int>::iterator p;
	c[x]=true;
	e[x]=t;
	p=b[x].begin();
	while(p!=b[x].end())
	{
		if(!c[*p])
			dfs2(*p);
		p++;
	}
}


int main()
{
	int i,p,q;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&edge[i].x,&edge[i].y);
		a[edge[i].x].push_back(edge[i].y);
		a[edge[i].y].push_back(edge[i].x);
	}
	memset(c,0,sizeof(c));
	t=1;
	for(i=1;i<=n;i++)
		if(!c[i])
			dfs1(i);
	t=1;
	memset(c,0,sizeof(c));
	for(i=n;i>0;i--)
		if(!c[d[i]])
		{
			dfs2(d[i]);
			t++;
		}
	memset(in,0,sizeof(in));
	for(i=0;i<m;i++)
		if(e[edge[i].x]!=e[edge[i].y])
			in[edge[i].x]++;
	q=0;
	for(i=1;i<=t;i++)
		if(!in[i])
		{
			p=i;
			q++;
		}
	if(q!=1)
		printf("0\n");
	else
	{
		t=0;
		for(i=1;i<=n;i++)
			if(e[i]==p)
				t++;
		printf("%d\n",t);
	}
	return 0;
}
