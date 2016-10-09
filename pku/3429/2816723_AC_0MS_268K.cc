#include <iostream>
#include <cmath>
using namespace std;

struct fac
{
	__int64 u, d;
};

__int64 Gcd(__int64 a,__int64 b)
{return b==0?a:Gcd(b,a%b);}

fac operator +(fac f1,fac f2)
{
	fac r;
	r.u=f1.u*f2.d+f1.d * f2.u;
	r.d=f1.d*f2.d;
	__int64 g=Gcd(r.u,r.d);
	r.u/=g,r.d/=g;
	return r;
}
fac operator -(fac f1,fac f2)
{
	fac r;
	r.u=f1.u*f2.d-f1.d*f2.u;
	r.d=f1.d*f2.d;
	__int64 g=Gcd(r.u,r.d);
	r.u/=g,r.d/=g;
	return r;
}
fac operator *(fac f1,fac f2)
{
	fac r;
	r.u=f1.u*f2.u;
	r.d=f1.d*f2.d;
	__int64 g=Gcd(r.u,r.d);
	r.u/=g,r.d/=g;
	return r;
}
fac operator /(fac f1,fac f2)
{
	fac r;
	r.u=f1.u*f2.d;
	r.d=f1.d*f2.u;
	__int64 g=Gcd(r.u,r.d);
	r.u/=g,r.d/=g;
	return r;
}
bool zero(fac ff)
{return ff.u==0;}



struct point
{
	fac x,y;
};

point p[1000];

void Get_line(point inpA,point inpB,fac &a1,fac &b1,fac &c1)
{
	a1=inpB.y-inpA.y;
	b1=inpA.x-inpB.x;
	c1=inpA.y*(inpB.x-inpA.x)-inpA.x*(inpB.y-inpA.y);
}
bool Get_point(point a,point b,point c,point d,point &ret)
{
	fac a1,b1,c1,a2,b2,c2;
	Get_line(a,b,a1,b1,c1);
	Get_line(c,d,a2,b2,c2);
	if(zero(b1*a2-a1* b2))
		return false;
	ret.y=(a1*c2-c1*a2)/(b1*a2-a1*b2);
	if(zero(a2))
	{
		ret.x=(b1*ret.y+c1)/a1;
		ret.x.u*=-1;
	}
	else
	{
		ret.x=(b2*ret.y+c2)/a2;
		ret.x.u*=-1;
	}
	return true;
}

int main(void)
{
	int i,N,M;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=1;i<=N;i++)
		{
			scanf("%I64d%I64d",&p[i].x.u,&p[i].y.u);
			p[i].x.d=p[i].y.d=1;
		}
		scanf("%d",&M);
		int ans=0;
		int k=0;
		bool flag=false;
		for(i=1;i<=M;i++)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(!flag)
			{
				point add;
				bool ok=Get_point(p[a],p[b],p[c],p[d],add);
				if(ok)
				{
					if(zero(add.x)&&zero(add.y))
					{
						ans=i;
						flag=true;
					}
					p[N+i]=add;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
