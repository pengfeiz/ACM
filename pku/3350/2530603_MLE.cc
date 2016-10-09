#include <iostream>
using namespace std;
#define MAX 12001
#define MAX2 503
#define MAX3 503

int d[MAX];
int c[MAX][MAX2];
int n,k,w;
int a[MAX][MAX3];
int b[MAX][MAX3];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("s5.5.in","r",stdin);
	int tt;
	int i,j,t,jj;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d",&n,&k,&w);
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		n+=w;
		for(i=w;i<n;i++)
			scanf("%d",&d[i]);
		n+=w;
		for(i=0;i<n;i++)
		{
			t=0;
			c[i][0]=0;
			for(j=1;j<=w;j++)
			{
				t+=d[i+j];
				c[i][j]=t;
			}
		}
		for(i=0;i<n-w;i++)
			a[1][i+w]=c[i][w];
		t=0;
		for(i=1;i<n;i++)
		{
			b[1][i]=b[1][i-1]>a[1][i]?b[1][i-1]:a[1][i];
			if(b[1][i]>t)
				t=b[1][i];
		}
		for(j=2;j<=k;j++)
			for(i=w;i<n;i++)
			{
				a[j][i]=b[j-1][i-w]+c[i-w][w];
				for(jj=1;jj<w;jj++)
					if(a[j][i]<a[j-1][i-w+jj]+c[i-w][w]-c[i-w][jj])
						a[j][i]=a[j-1][i-w+jj]+c[i-w][w]-c[i-w][jj];
				if(a[j][i]>b[j][i])
					b[j][i]=a[j][i];
				if(b[j][i]<b[j][i-1])
					b[j][i]=b[j][i-1];
				if(b[j][i]>t)
					t=b[j][i];
			}
		printf("%d\n",t);
	}
	return 0;
}