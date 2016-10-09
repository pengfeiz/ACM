#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxn 201

vector<int> a[maxn];
int n,in[maxn],maxx;


bool com(int a,int b)
{return a>b;}


int dfs(int x)
{
	int i,b[maxn],m=0,t,tt;
	vector<int>::iterator p;
	p=a[x].begin();
	while(p!=a[x].end())
	{
		b[m++]=dfs(*p);
		p++;
	}
	if(!m)
		return 1;
	sort(b,b+m,com);
	tt=t=0;
	for(i=0;i<m;i++)
	{
		if(t<b[i])
		{
			tt+=b[i]-t;
			t=b[i]-1;
		}
		else
			t--;
	}
	return tt;
}


int main()
{
	int tt,i,x,y,m,j;
	scanf("%d",&tt);
	while(tt--)
	{
		maxx=0;
		memset(in,0,sizeof(in));
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			a[i].clear();
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&y);
				in[y]++;
				a[x].push_back(y);
			}
		}
		for(i=1;i<=n;i++)
			if(!in[i])
			{
				printf("%d\n",dfs(i));
				break;
			}
	}
	return 0;
}
