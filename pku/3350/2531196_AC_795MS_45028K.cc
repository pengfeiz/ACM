#include <iostream>
using namespace std;
#define MAX 10301
#define MAX2 102
#define MAX3 503
int d[MAX],c[MAX][MAX2],n,k,w,a[MAX3][MAX],b[MAX3][MAX];

int main()
{	
	int tt;
	int i,j,jj,t,p,q;
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
		p=1;q=0;
		n+=w;
		for(i=0;i<n;i++)
			a[0][i]=-99999999;
		for(j=1;j<=k;j++)
			for(i=w;i<n;i++)
			{
				a[j][i]=b[j-1][i-w]+c[i-w][w];
				for(jj=0;jj<=w;jj++)
					if(a[j][i]<a[j-1][i-w+jj]+c[i-w][w]-c[i-w][jj])
						a[j][i]=a[j-1][i-w+jj]+c[i-w][w]-c[i-w][jj];
				if(a[j][i]>b[j][i])
					b[j][i]=a[j][i];
				if(b[j][i]<b[j-1][i])
					b[j][i]=b[j-1][i];
				if(b[j][i]<b[j][i-1])
					b[j][i]=b[j][i-1];
			}
		printf("%d\n",b[k][n-1]);
	}
	return 0;
}
