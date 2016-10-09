#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 30000

struct gao
{
	int n;
	int x,y;
}a[MAX],b[MAX];

bool com1(gao a,gao b) 
{
    if(a.x<b.x) 
		return true;
	if(a.x==b.x&&a.y<b.y)
		return true;
    return false;
}

bool com2(gao a,gao b) 
{
    if(a.y<b.y) 
		return true;
	if(a.y==b.y&&a.x<b.x)
		return true;
    return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int l,n,i,c[MAX],t,t1,t2,tt,aa[MAX],bb[MAX],q;
	scanf("%d",&l);
	while(l-->0)
	{
		tt=0;
		memset(c,0,sizeof(c));
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].n=i;
		}
		if(n%2==1)
		{
			printf("-1\n");
			continue;
		}
		a[0].x=a[0].y=-99999999;
		a[0].n=0;
		a[n+1].x=a[n+1].y=99999999;
		a[n+1].n=n+1;
		memcpy(b,a,sizeof(a));
		sort(a,a+n+2,com1);
		sort(b,b+n+2,com2);
		for(i=1;i<=n;i++)
		{
			aa[a[i].n]=i;
			bb[b[i].n]=i;
		}
		t=q=1;
		for(i=0;i<n;i++)
		{
			if(t)
			{
				t=0;
				t1=t2=1;
				q=bb[a[q].n];
				while(b[q-t1].y==b[q].y)
					t1++;
				while(b[q+t2].y==b[q].y)
					t2++;
				if(t1%2&&t2%2)
					break;
				if(!(t1%2)&&!(t2%2))
					break;
				if(t1%2&&!(t2%2))
				{
					if(c[b[q+1].n])
						break;
					else
						c[b[q+1].n]=1;
					tt+=b[q+1].x-b[q].x;
					q++;
				}
				else
				{
					if(c[b[q-1].n])
						break;
					else
						c[b[q-1].n]=1;
					tt+=b[q].x-b[q-1].x;
					q--;
				}
			}
			else
			{
				t=t1=t2=1;
				q=aa[b[q].n];
				while(a[q-t1].x==a[q].x)
					t1++;
				while(a[q+t2].x==a[q].x)
					t2++;
				if(t1%2&&t2%2)
					break;
				if(!(t1%2)&&!(t2%2))
					break;
				if(t1%2&&!(t2%2))
				{
					if(c[a[q+1].n])
						break;
					else
						c[a[q+1].n]=1;
					tt+=a[q+1].y-a[q].y;
					q++;
				}
				else
				{
					if(c[a[q-1].n])
						break;
					else
						c[a[q-1].n]=1;
					tt+=a[q].y-a[q-1].y;
					q--;
				}
			}
		}
		if(i<n)
			printf("-1\n");
		else
			printf("%d\n",tt);
	}
	return 0;
}
