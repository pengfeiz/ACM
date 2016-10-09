#include <iostream>
using namespace std;
#define MAX 11001
#define MAX2 102
#define MAX3 502

int d[MAX];
int b[MAX][2];
int n,k,w;
int a[MAX][MAX3];

int main()
{
//	freopen("in.txt","r",stdin);
	int tt;
	int i,j,t;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d",&n,&k,&w);
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(b,0,sizeof(b));
		n+=w;
		for(i=w;i<n;i++)
			scanf("%d",&d[i]);
		for(i=w;i<n;i++)
		{
			t=0;
			for(j=0;j<w;j++)
			{
				t+=d[i-j];
				if(t>b[i][0])
				{
					b[i][0]=t;
					b[i][1]=j;
				}
			}
		}
		for(j=1;j<=k;j++)
			for(i=1;i<=n;i++)
			{
				if(a[i][j]<a[i-b[i][1]-1][j-1]+b[i][0])
					a[i][j]=a[i-b[i][1]-1][j-1]+b[i][0];
				if(a[i][j]<a[i-1][j])
					a[i][j]=a[i-1][j];
			}
		t=-99999999;
		for(i=w;i<=n;i++)
			if(a[i][k]>t)
				t=a[i][k];
		printf("%d\n",t);
	}
	return 0;
}