#include <iostream>
#include <vector>
using namespace std;
#define MAX 302

vector<int> a[MAX];
int n,m;
int y[MAX],tt;
bool q[MAX];

bool find(int x)
{
	if(q[x])
		return false;
	q[x]=true;
	vector<int>::iterator p;
	p=a[x].begin();
	while(p!=a[x].end())
	{
		if(!y[*p]||find(y[*p]))
		{
			if(!y[*p])
				tt++;
			y[*p]=x;
			return true;
		}
		p++;
	}
	return false;
}

int main()
{
	int i,t,x,nn;
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		memset(a,0,sizeof(a));
		memset(y,0,sizeof(y));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&nn);
			while(nn--)
			{
				scanf("%d",&x);
				a[i].push_back(x);
			}
		}
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			find(i);
		}
		if(tt==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}