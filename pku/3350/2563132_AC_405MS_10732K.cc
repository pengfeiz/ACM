
#include <iostream>
using namespace std;
#define MAX 11001
#define MAX2 112
#define MAX3 513

int d[MAX];
int c[MAX][MAX2];
int n,k,w;
int a[MAX3][MAX];
int b[MAX3][MAX];

int main()
{	
	int tt;
	int i,j,jj,t,p,q,ff;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d",&n,&k,&w);
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
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
			for(j=0;j<=k;j++)
				a[j][i]=b[j][i]=0;
		for(i=0;i<n;i++)
			a[0][i]=-99999999;
		for(j=1;j<=k;j++)
			for(i=w;i<n;i++)
			{
				a[j][i]=b[j-1][i-w]+c[i-w][w];
ff=w>30?30:w;
				for(jj=0;jj<=ff;jj++)
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

