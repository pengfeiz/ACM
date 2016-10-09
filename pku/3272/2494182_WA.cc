#include <iostream>
#include <vector>
using namespace std;
#define MAX 5001

vector<int> b[MAX];
int n,m,t,maxx,p,q;
int in[MAX],d[MAX],a[MAX];

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
				in[*iter]--;
				if(!in[*iter])
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
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		in[y]++;
		b[x].push_back(y);
	}
	p=q=0;
	memset(d,0,sizeof(d));
	for(i=1;i<=n;i++)
	{
		if(!in[i])
		{
			a[q++]=i;
			d[i]=1;
		}
	}
	dfs();
	maxx=0;
	for(i=1;i<n;i++)
		if(maxx<d[i])
			maxx=d[i];
	printf("%d\n",maxx);
	return 0;
}
