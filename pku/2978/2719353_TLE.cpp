#include <iostream>
#include <algorithm>
using namespace std;

struct gao
{
	int n,l;
}d[6],dd[6];
int a[5][101],n,m;
int c[5];
int b[101],minn;

bool com(gao a,gao b)
{return a.l<b.l;}

void bulid(int x)
{
	int i,j,t,p;
	if(x==m)
	{
		t=0;
		p=-1;
		memcpy(dd,d,sizeof(d));
		sort(dd,dd+m,com);
		for(i=0;i<m;i++)
		{
			for(j=p+1;j<dd[i].l;j++)
				if(b[j]!=dd[i].n)
					t++;
			p=dd[i].l;
		}
		if(j<n)
			t+=n-j-1;
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
	int i;
	while(scanf("%d%d",&n,&m),n||m)
	{
		minn=99999999;
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			b[i]-=1;
			a[b[i]][c[b[i]]]=i;
			c[b[i]]++;
		}
		bulid(0);
		printf("%d\n",minn);
	}
	return 0;
}


