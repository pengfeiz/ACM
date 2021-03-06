#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20

int n,a[MAX][MAX],m,t,p[MAX*10];

struct gao
{
	int a,b,c;
}b[MAX*10];

bool com(gao x,gao y)
{
	if(x.b>=y.b)
		return true;
	if(x.b<y.b)
		return false;
	if(x.c>=y.c)
		return true;
	return false;
}

void floyd()
{ 
	int i,j,k;
    for(k=0;k<n;k++) 
		for(i=0;i<n;i++)
            for(j=0;j<n;j++)
				if(a[i][k]+a[k][j]<a[i][j]) 
					a[i][j]=a[i][k]+a[k][j];
} 

int main()
{
	int i,j,q,k;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]==-1)
					a[i][j]=999999;
			}
		floyd();
		for(i=0;i<m;i++)
			scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].c);
		sort(b,b+n,com);
		memset(p,0,sizeof(p));
		for(j=0;j<m;j++)
		{
			if(p[j]==0)
			{
				t++;
				q=b[j].b;
				for(k=j+1;k<m;k++)
				{
					if(p[k]==0)
					{
						if(q-a[b[j].a][b[k].a]-b[k].c>=b[k].b)
							p[k]=1;
					}
				}
			}
		}
		printf("%d\n",t);	
	}
	return 0;
}
		
		
