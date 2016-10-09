#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 5001

struct gao
{
	int x1,y1,x2,y2;
}a[MAX];

int n,l,m,c[2*MAX],d[2*MAX];

void build()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		c[2*i]=a[i].x1;
		c[2*i+1]=a[i].x2;
		d[2*i]=a[i].y1;
		d[2*i+1]=a[i].y2;
	}
	c[2*n]=d[2*n]=999999;
}

bool com(gao a,gao b)
{
	return a.y1<b.y1;
}

void change()
{
	int i;
	sort(c,c+2*n);
	sort(d,d+2*n);
	sort(a,a+n,com);
	i=l=0;
	while(c[i]!=999999)
	{
		if(c[i]!=c[i+1])
			c[l++]=c[i];
		i++;
	}
	i=m=0;
	while(d[i]!=999999)
	{
		if(d[i]!=d[i+1])
			d[m++]=d[i];
		i++;
	}
	c[l]=d[m]=999999;
}

bool b[2][MAX];

void dosth()
{
	int i,j,ans=0,p=0,q,y;
	memset(b,0,sizeof(b));
	for(i=0;i<l;i++)
	{
		y=0;
		q=(p+1)&1;
		for(j=0;j<n;j++)
		{
			if(a[j].x1<=c[i]&&a[j].x2>c[i])
			{
				if(a[j].y2<=d[y])
					continue;
				if(a[j].y1<d[y]&&a[j].y2>d[y])
				{
					while(d[y]<a[j].y2)
						b[q][y++]=true;
				}
				if(a[j].y1>=d[y])
				{
					while(d[y]<a[j].y1)
						b[q][y++]=false;
					while(d[y]<a[j].y2)
						b[q][y++]=true;
				}
			}
		}
		for(;y<m;y++)
			b[q][y]=false;
		if(b[q][0]==true)
			ans+=c[i+1]-c[i];
		if(b[q][m-1]==true)
			ans+=c[i+1]-c[i];
		for(j=0;j<m-1;j++)
			if(b[q][j]^b[q][j+1])
				ans+=c[i+1]-c[i];
		for(j=0;j<m-1;j++)
			if(b[q][j]^b[p][j])
				ans+=d[j+1]-d[j];
		p=(p+1)&1;
	}
	printf("%d\n",ans);
}

int main()
{
//	freopen("in.txt","r",stdin);
	build();
	change();
	dosth();
	return 0;
}