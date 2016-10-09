#include <iostream>
#include <algorithm>
using namespace std;

struct gao
{
	int n,l;
}d[6],dd[6];
int a[5][102],n,m;
int c[5];
int b[101],minn;

int p[5][101][101];

bool com(gao a,gao b)
{return a.l<b.l;}

void bulid(int x)
{
	int i,t,pp;
	if(x==m)
	{
		t=0;
		pp=0;
		memcpy(dd,d,sizeof(d));
		sort(dd,dd+m,com);
		for(i=0;i<m;i++)
		{
			t+=p[dd[i].n][pp][dd[i].l];
			if(t>=minn)
				return;
			pp=dd[i].l;
		}
		if(pp<n)
			t+=n-pp;
		if(t<minn)
			minn=t;
		return;
	}
	for(i=0;i<c[x];i++)
	{
		d[x].n=x;
		d[x].l=a[x][i];
		bulid(x+1);
	}
}



int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,t,l;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(p,0,sizeof(p));
		minn=99999999;
		for(i=0;i<m;i++)
		{
			c[i]=1;
			a[i][0]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
//			b[i]=rand()%m+1;
			b[i]-=1;
			a[b[i]][c[b[i]]]=i;
			c[b[i]]++;
		}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				for(k=j+1;k<=n;k++)
				{
					t=0;
					for(l=j+1;l<=k;l++)
						if(b[l]!=i)
							t++;
					p[i][j][k]=t;
				}
		bulid(0);
		printf("%d\n",minn);
	}
	return 0;
}


