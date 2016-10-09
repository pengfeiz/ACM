#include <iostream>
using namespace std;

const int maxn=501;

int a[maxn][maxn];
int y[maxn];
int n,k;
bool q[maxn];


void init()
{
	int x,y;
	scanf("%d%d",&n,&k);
	memset(a,0,sizeof(a));
	while(k--)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
}


bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=n;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			y[i]=i;
			return true;
		}
	return false;
}

void solve()
{
	int i,t=0;
	memset(y,0,sizeof(y));
	for(i=1;i<=n;i++)
	{
		memset(q,0,sizeof(q));
		if(find(i))
			t++;
	}
	printf("%d\n",t);
}


int main()
{
	init();
	solve();
	return 0;
}
