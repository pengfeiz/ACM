#include <stdio.h>

int m,n,t;
int d[16][16],e;

int match(int e,int p)
{
    int i,j,k,best=999999;
    if(!e)
		return 0;
    for(i=p;!(e&(1<<i));i++);
    for(j=i+1;j<=n;j++)
		if(e&(1<<j))
		{
			k=match(e-(1<<i)-(1<<j),i+1);
			if(d[i][j]+k<best)
				best=d[i][j]+k;
		}
	return best;
}

int main()
{
	int i,j,k,p;
    while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				d[i][j]=999999;
			d[i][i]=0;
		}
		e=t=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&j,&k,&p);
			if(p<d[j][k])
				d[j][k]=d[k][j]=p;
			t+=p;
			e^=(1<<j);
			e^=(1<<k);
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					if(d[j][i]+d[i][k]<d[j][k])
						d[j][k]=d[j][i]+d[i][k];
		printf("%d\n",t+match(e,1));
	}
	return 0;
}