#include <iostream>
using namespace std;
#define MAX 501
#define he 50

int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
int n;

int main()
{
	int i,j,k,ii,jj,kk,q;
	scanf("%d",&n);
	q=100*100*n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
	//		a[i][j]=0;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
	//		b[i][j]=0;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&c[i][j]);
			if(abs(c[i][j])>q)
			{
				printf("NO\n");
				return 0;
			}
	//		c[i][j]=0;
		}
	for(ii=0;ii<n;ii+=he)
		for(jj=0;jj<n;jj+=he)
			for(kk=0;kk<n;kk+=he)
				for(i=ii;i<ii+he;i++)
					for(j=jj;j<jj+he;j++)
						for(k=kk;k<kk+he;k+=10)
						{
							c[i][j]+=(a[i][k]*b[k][j]+a[i][k+1]*b[k+1][j]+a[i][k+2]*b[k+2][j]+a[i][k+3]*b[k+3][j]+a[i][k+4]*b[k+4][j]+a[i][k+5]*b[k+5][j]+a[i][k+6]*b[k+6][j]+a[i][k+7]*b[k+7][j]+a[i][k+8]*b[k+8][j]+a[i][k+9]*b[k+9][j]);
							if(c[i][j]>q||c[i][j]<-q)
							{
								printf("NO\n");
								return 0;
							}
						}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(c[i][j])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}
