#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10005

__int64 n,minn,h,p;
__int64 t;

struct gao
{
	__int64 a,n;
}a[MAX];

bool c[MAX];

bool com(gao x,gao y)
{return x.a<y.a;}

	

int main()
{
	__int64 i,x,y;
	t=0;
	minn=0x7fffffff;
	scanf("%I64d",&n);
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i].a);
//		a[i].a=(i+1)%n*10;
		a[i].n=i;
		if(a[i].a<minn)
			minn=a[i].a;
	}
	sort(a,a+n,com);
	for(i=0;i<n;i++)
	{
		h=p=0;
		if(!c[i])
		{
			x=y=i;
			while(1){
				h++;
				c[x]=true;
				p+=a[x].a;
				if(a[x].n!=y)
					x=a[x].n;
				else
					break;
			}
			if((h-2)*a[i].a>(h+1)*a[0].a+a[i].a)
				t+=h*a[0].a+p+a[i].a+a[0].a;
			else
				t+=(h-2)*a[i].a+p;
		}
	}
	printf("%I64d\n",t);
	return 0;
}