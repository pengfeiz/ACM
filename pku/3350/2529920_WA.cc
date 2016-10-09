#include <iostream>
using namespace std;
#define MAX 121
#define MAX2 12
#define MAX3 52

int d[MAX];
int c[MAX][MAX2];
int n,k,w;
int a[MAX][MAX3];
int b[MAX][MAX3];

int main()
{
	freopen("in.txt","r",stdin);
	int tt;
	int i,j,t,jj;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d",&n,&k,&w);
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		n+=w;
		for(i=w;i<n;i++)
			scanf("%d",&d[i]);
		n+=w;
		for(i=w;i<n;i++)
		{
			t=0;
			for(j=0;j<w;j++)
			{
				t+=d[i-j];
				c[i][j]=t;
			}
		}
		for(j=1;j<=k;j++)
			for(i=w;i<n;i++)
			{
				for(jj=0;jj<w;jj++)
					if(a[j][i]<a[j-1][i-w+jj]+c[i][w-jj-1])
						a[j][i]=a[j-1][i-w+jj]+c[i][w-jj-1];
				if(a[j][i]<b[j-1][i-w]+c[i][w-1])
					a[j][i]=b[j-1][i-w]+c[i][w-1];
				if(a[j][i]>b[j][i])
					b[j][i]=a[j][i];
				if(b[j][i]<b[j][i-1])
					b[j][i]=b[j][i-1];
			}
		t=-99999999;
		for(i=w;i<n;i++)
			if(a[k][i]>t)
				t=a[k][i];
		printf("%d\n",t);
	}
	return 0;
}