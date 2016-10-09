#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20

int n,a[MAX][MAX],m;
bool p[MAX*10][MAX*10],q[MAX*10];

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

int dosth(int x)
{
	int i,t=0,w;
	for(i=x+1;i<m;i++)
	{
		if(q[i]&&p[x][i])
		{
			if(i==x+1)
			{
				q[i]=true;
				w=dosth(i);
				q[i]=false;
				if(w>t)
					t=w;
			}
			else
			{
				q[x+1]=true;
				q[i]=true;
				w=dosth(i)+dosth(x+1);
				if(w>t)
					t=w;
				q[i]=false;
				q[x+1]=false;
			}
		}
	}
	if(i==m)
	{
		if(q[m-1])
			return 1;
		return 2;
	}
	return t;
}
		
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
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
		sort(b,b+m,com);
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		for(i=0;i<m-1;i++)
			for(j=i+1;j<m;j++)
				if(b[i].b-a[b[i].a][b[j].a]-b[j].c>=b[j].b)
					p[i][j]=true;
		q[0]=true;
		printf("%d\n",dosth(0));	
	}
	return 0;
}
		
		
