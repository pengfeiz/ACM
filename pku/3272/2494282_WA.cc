#include <iostream>
#include <vector>
using namespace std;
#define MAX 5002

vector<int> b[MAX];
int n,m,t,maxx,p,q;
int in[MAX],out[MAX],d[MAX],a[MAX];

void dfs()
{
	vector<int>::iterator iter;
	int i;
	while(p<q)
	{
		for(i=p;i<q;i++)
		{
			iter=b[a[i]].begin();
			while(iter!=b[a[i]].end())
			{
				d[*iter]+=d[a[i]];
				out[*iter]--;
				if(!out[*iter])
					a[q++]=*iter;
				iter++;
			}
		}
		p=q;
	}
}

int main()
{
	int i,x,y;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		in[y]++;
		out[x]++;
		b[y].push_back(x);
	}
	p=q=0;
	memset(d,0,sizeof(d));
	for(i=1;i<=n;i++)
	{
		if(!out[i])
		{
			a[q++]=i;
			d[i]=1;
		}
	}
	dfs();
	maxx=0;
	for(i=1;i<n;i++)
		if(!in[i])
			maxx+=d[i];
	printf("%d\n",maxx);
	return 0;
}
