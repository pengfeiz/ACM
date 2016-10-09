#include <iostream>
using namespace std;
#define MAX 122

int y[MAX],n,m,t;
bool a[MAX][MAX];
bool q[MAX];


bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=n;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
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
	int tt,i,xx,yy;
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		memset(a,0,sizeof(a));
		memset(y,0,sizeof(y));
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&xx,&yy);
			a[xx][yy]=true;
		}
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			find(i);
		}
		printf("%d\n",n-t);
	}
	return 0;
}