#include <iostream>
#include <stdlib.h>
using namespace std;

#define POOL 400
#define VALUE 21
#define JURY 21

int p[POOL],d[POOL];
int m,n;
int c=1;

int last[JURY][2*VALUE*JURY+1];
int sum[JURY][2*VALUE*JURY+1];

int compare(const void *a, const void *b)
{
  return *(int *)a-*(int *)b;
}

void solve()
{
	int i,j,k,l,l2;
	int sol[JURY];
	for(i=0;i<m;i++)
		for(j=0;j<2*VALUE*m+1;j++) 
			last[i][j]=sum[i][j]=-1;
	for(i=0;i<n;i++)
		if(p[i]+d[i]>sum[0][VALUE*m+p[i]-d[i]])
		{
			last[0][VALUE*m+p[i]-d[i]]=i;
			sum[0][VALUE*m+p[i]-d[i]]=p[i]+d[i];
		}
	for(j=0;j<m-1;j++)
		for(k=0;k<2*VALUE*m;k++)
			if(last[j][k]>=0)
				for(i=0;i<n;i++)
					if(sum[j+1][k+p[i]-d[i]]<sum[j][k]+p[i]+d[i])
					{
						for(l=j,l2=k;l>=0;l--)
						{
							if(last[l][l2] == i) 
								break;
							l2-=p[last[l][l2]]-d[last[l][l2]];
						}
						if(l<0)
						{
							last[j+1][k+p[i]-d[i]]=i;
							sum[j+1][k+p[i]-d[i]]=sum[j][k]+p[i]+d[i];
						}
					}
	for(i=0;i<=VALUE*m;i++)
		if(sum[m-1][VALUE*m+i]>=0||sum[m-1][VALUE*m-i]>=0)
		{
			if(sum[m-1][VALUE*m+i]>sum[m-1][VALUE*m-i])
				i=VALUE*m+i;
			else
				i=VALUE*m-i;
			break;
		}
	printf("Jury #%d\n",c++);
	printf("Best jury has value %d for prosecution and value %d for defence:\n",(sum[m-1][i]+(i-VALUE*m))/2,(sum[m-1][i]-(i-VALUE*m))/2);
	for(j=m-1;j>=0;j--)
    {
		sol[j]=last[j][i]+1;
		i-=p[last[j][i]]-d[last[j][i]];
    }
	qsort(sol,m,sizeof(int),compare);
	for(i=0;i<m;i++) 
		printf(" %d",sol[i]);
	printf("\n\n");
}

int read()
{
    int i;
    cin>>n>>m;
    if(n==0) 
		return 0;
    for(i=0;i<n;i++)
        cin>>p[i]>>d[i];
    return 1;
}

int main()
{
    while(read()) 
		solve();
    return 0;
}

