#include <iostream>
#include <vector>
using namespace std;
#define MAX 110001
#define MAX2 11002

int d[MAX];
vector<int> a[MAX2];
int n,m;
bool b[MAX]; 

vector<int>::iterator p[MAX];
int h[MAX];
int l;

void dfs()
{
	p[l]=a[1].begin();
	while(p[0]!=a[h[0]].end())
	{
		if(!b[*p[l]])
		{
			b[*p[l]]=true;
			h[l+1]=d[*p[l]];
			l++;
			p[l]=a[h[l]].begin();
			continue;
		}
		p[l]++;
		if(p[l]==a[h[l]].end())
		{
			printf("%d\n",h[l]);
			l--;
		}
	}
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
		d[2*i]=y;
		d[2*i+1]=x;
		a[x].push_back(2*i);
		a[y].push_back(2*i+1);
	}
	l=0;
	h[0]=1;
	dfs();
	return 0;
}
