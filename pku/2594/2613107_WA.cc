//e存它的连通枝编号，d存它的第一次逆遍历时候的标号,edge是边


#include <iostream>
#include <vector>
using namespace std;

#define MAX 502
#define MAX2 5001

struct gao
{
	int x,y;
}edge[MAX2];

vector<int> a[MAX],b[MAX];

int d[MAX],e[MAX],y[MAX],q[MAX];
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


bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=n;i++)
		if(e[x]==e[i]&&(i!=x)&&(!y[i]||find(y[i])))
		{
			if(!y[i])
				t++;
			y[i]=x;
			return true;
		}
	return false;
}


int main()
{
	int i;
	while(scanf("%d%d",&n,&m),n||m)
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&edge[i].x,&edge[i].y);
			b[edge[i].x].push_back(edge[i].y);
			a[edge[i].y].push_back(edge[i].x);
		}
		memset(c,0,sizeof(c));
		t=1;
		for(i=1;i<=n;i++)
			if(!c[i])
				dfs1(i);
		t=0;
		memset(c,0,sizeof(c));
		for(i=n;i>0;i--)
			if(!c[d[i]])
			{
				dfs2(d[i]);
				t++;
			}
		t=0;
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			find(i);
		}
		printf("%d\n",n-t);
	}
	return 0;
}