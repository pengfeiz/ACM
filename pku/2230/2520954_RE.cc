#include <iostream>
#include <vector>
using namespace std;
#define MAX 20001

struct gao
{
	int x,y;
}d[MAX];
vector<int> a[MAX];
int n,m;
bool b[MAX]; 


void dfs(int x)
{
	vector<int>::iterator p;
	p=a[x].begin();
	while(p!=a[x].end())
	{
		if(!b[*p])
		{
			b[*p]=true;
			dfs(d[*p].x==x?d[*p].y:d[*p].x);
		}
		p++;
	}
	printf("%d\n",x);
}

int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
		a[i].clear();
	memset(b,0,sizeof(b));
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		d[2*i].x=d[2*i+1].y=x;
		d[2*i].y=d[2*i+1].x=y;
		a[x].push_back(2*i);
		a[y].push_back(2*i+1);
	}
	dfs(1);
	return 0;
}
