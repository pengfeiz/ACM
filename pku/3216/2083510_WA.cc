#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20

int n,a[MAX][MAX],m,t,xx[MAX*10],yy[MAX*10];
bool p[MAX*10][MAX*10],q[MAX*10];

struct gao
{
	int a,b,c;
}b[MAX*10];

void floyd()
{ 
	int i,j,k;
    for(k=0;k<n;k++) 
		for(i=0;i<n;i++)
            for(j=0;j<n;j++)
				if(a[i][k]+a[k][j]<a[i][j]) 
					a[i][j]=a[i][k]+a[k][j];
} 
	
bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=0;i<m;i++)
		if(p[x][i]&&(!yy[i]||find(yy[i])))
		{
			xx[x]=i;
			yy[i]=x;
			return true;
		}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		t=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]==-1)
					a[i][j]=99999999;
			}
		floyd();
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].c);
			b[i].a--;
		}
		memset(p,0,sizeof(p));
		memset(xx,0,sizeof(xx));
		memset(yy,0,sizeof(yy));
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				if(b[i].b-a[b[j].a][b[i].a]-b[j].c>=b[j].b)
					p[j][i]=true;
		for(i=0;i<m;i++)
		{
			memset(q,0,sizeof(q));
			if(find(i))
				t++;
		}
		printf("%d\n",m-t);
	}
	return 0;
}