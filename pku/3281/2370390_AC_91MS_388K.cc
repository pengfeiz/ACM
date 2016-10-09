#include <iostream>
using namespace std;

#define MAX 512

bool a[MAX][MAX];
int t,n,f,d,ans;
int ll[MAX],b[MAX];


bool solve()
{
	int p,q,x,i;
	memset(b,0xff,sizeof(b));
	ll[0]=b[0]=p=0;
	q=1;
	while(p<q)
	{
		x=ll[p++];
		for(i=0;i<=t;i++)
			if(a[x][i]&&b[i]==-1)
			{
				b[i]=x;
				if(i==t)
				{
					x=t;
					while(x)
					{
						a[b[x]][x]=false;
						a[x][b[x]]=true;
						x=b[x];
					}
					return true;
				}
				ll[q++]=i;
			}
	}
	return false;
}


int main()
{
	int i,x,y,p;
	scanf("%d%d%d",&n,&f,&d);
	memset(a,0,sizeof(a));
	t=n*2+f+d+1;
	for(i=1;i<=n;i++)
		a[i+f][i+n+f]=true;
	for(i=1;i<=f;i++)
		a[0][i]=true;
	for(i=2*n+1+f;i<t;i++)
		a[i][t]=true;
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		while(x--)
		{
			scanf("%d",&p);
			a[p][i+f]=true;
		}
		while(y--)
		{
			scanf("%d",&p);
			a[i+f+n][2*n+f+p]=true;
		}
	}
	while(solve())
		ans++;
	printf("%d\n",ans);
	return 0;
}