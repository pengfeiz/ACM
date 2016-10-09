#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=771;

struct gao
{
	int x,y,n;
}a[maxn];

int n,m;
struct gao2
{
	int b[3];
}q[maxn*maxn];

bool com(gao a,gao b)
{return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool com2(gao2 a,gao2 b)
{
	if(a.b[0]!=b.b[0])
		return a.b[0]<b.b[0];
	if(a.b[1]!=b.b[1])
		return a.b[1]<b.b[1];
	return a.b[2]<b.b[2];
}

int main()
{
	int i,j,k;
	gao p;
	scanf("%d",&n);
	m=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].n=i+1;
	}
	sort(a,a+n,com);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			p.x=2*a[j].x-a[i].x;
			p.y=2*a[j].y-a[i].y;
			k=lower_bound(a,a+n,p,com)-a;
			if(k<n&&a[k].x==p.x&&a[k].y==p.y)
			{
				q[m].b[0]=a[i].n;
				q[m].b[1]=a[j].n;
				q[m].b[2]=a[k].n;
				sort(q[m].b,q[m].b+3);
				m++;
			}
		}
	if(m)
	{
		printf("%d\n",m);
		sort(q,q+m,com2);
		for(i=0;i<m;i++)
			printf("%d %d %d\n",q[i].b[0],q[i].b[1],q[i].b[2]);
	}
	return 0;
}


