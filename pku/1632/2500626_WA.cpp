#include <iostream>
using namespace std;

int maxx,n=36;
bool a[37][37];
__int64 b[37];
__int64 c[37];


void solve(int x,int l,__int64 y)
{
	if(x>n)
		return;
	__int64 w=y&b[x];
	int t=0,i,ll=l;
	bool f=true;
	ll++;
	for(i=1;i<=n;i++)
		if(w&c[i])
			t++;
	if(t<=maxx)
		f=false;
	if(ll==t)
	{
		maxx=t;
		f=false;
	}
	if(f)
		solve(x+1,l+1,y&b[x]);
	solve(x+1,l,y);
}

int main()
{
	int i,x,y,t,m,j;
	__int64 w;
	scanf("%d",&t);
	c[1]=1;
	for(i=2;i<=n;i++)
		c[i]=c[i-1]*2;
	w=c[36]*2-1;
	while(t--)
	{
		scanf("%d",&m);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			a[x][y]=true;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][j])
					b[i]+=c[j];
		maxx=0;
		solve(1,0,w);
		printf("%d\n",maxx);
	}
	return 0;
}

