#include <iostream>
using namespace std;
#define MAX 302

bool a[MAX][MAX];
int n,m;
int y[MAX],tt;
bool q[MAX];

bool find(int x)
{
	if(q[x])
		return false;
	q[x]=true;
	int i;
	for(i=1;i<=m;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			if(y[i]==0)
				tt++;
			y[i]=x;
			return true;
		}
	return false;
}

int main()
{
	int i,t,y,nn;
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&nn);
			while(nn--)
			{
				scanf("%d",&y);
				a[i][y]=true;
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

