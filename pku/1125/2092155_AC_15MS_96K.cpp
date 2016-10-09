#include <iostream>
using namespace std;
#define MAX 100
int a[MAX][MAX];
int main()
{
	int n,i,j,k,m,p,q;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=99999999;
		for(i=0;i<n;i++)
			a[i][i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d%d",&p,&q);
				p--;
				if(a[i][p]>q)
					a[i][p]=q;
			}
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(a[i][k]+a[k][j]<a[i][j])
						a[i][j]=a[i][k]+a[k][j];
		m=q=p=0;
		for(i=0;i<n;i++)
			if(a[0][i]>q)
				q=a[0][i];
		for(i=1;i<n;i++)
		{
			k=0;
			for(j=0;j<n;j++)
				if(a[i][j]>k)
					k=a[i][j];
			if(k==0)
				m=1;
			if(k<q)
			{
				p=i;
				q=k;
			}
		}
		if(m)
			printf("disjoint\n");
		else
			printf("%d %d\n",p+1,q);
	}
	return 0;
}