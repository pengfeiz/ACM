#include <iostream>
#include <math.h>

using namespace std;
#define MAXN 5010
#define esp 1e-9


struct poi
{
	__int64 x,y;
}a[MAXN];


__int64 n;
double l;


__int64 ll(__int64 x)
{return x*x;}
double dis(poi a,poi b)
{return sqrt((ll(a.x-b.x)+ll(a.y-b.y))*1.0);}
__int64 comp(poi a,poi b,poi c)
{return (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);}



__int64 compute(__int64 i1,__int64 i2)
{
	__int64 i,s=0;
	if(i2-i1>1)
	{
		for(i=i1+1;i<i2;i++)
			s+=comp(a[i1],a[i],a[i+1]);
		if(s<0)
			s*=-1;
	}
	return s;
}

int main()
{
	__int64 i,j,q,ma;
	double y,s,angle;
	scanf("%I64d%lf",&n,&l);
	for(i=0;i<n;i++)
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
	ma=0;
	for(i=0;i<n;i++)
	{
		y=1.0;
		q=i;
		for(j=i+1;j<n;j++)
		{
			s=dis(a[i],a[j]);
			angle=(a[j].y-a[i].y)/s;
			if(angle<y+esp)
			{
				y=angle;
				if(s<l+esp)
					q=j;
				if(y<-esp&&s>l+esp)
					break;
			}
		}
		q=compute(i,q);
		if(q>ma)
			ma=q;
	}
	if(ma%2==1)
		printf("%I64d.5\n",ma/2);
	else
		printf("%I64d\n",ma/2);
	return 0;
}