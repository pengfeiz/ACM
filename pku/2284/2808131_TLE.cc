#include <iostream>
#include <cmath>
using namespace std;
#define MAX 301
#define E 1e-5

struct poi
{
	double x,y;
}pa,pb,pc,pd,p,a[MAX],b[MAX*MAX];


double pi,r;
int m,n;


double ll(double x)
{return x*x;}
double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double dian(double x1,double y1,double x2,double y2)
{return x1*x2+y1*y2;}
bool jiao(poi pa,poi pb,poi pc,poi pd,poi &p)
{
	double s1,s2;
	if(fabs(cha(pa.x-pb.x,pa.y-pb.y,pc.x-pd.x,pc.y-pd.y))<E)
		return false;
	s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
	s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
	p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
	p.y=(s1*pb.y+s2*pa.y)/(s1+s2);
	return true;
}


int main()
{
	int i,j,k,tim=0;
	while(scanf("%d",&n),n)
	{
		tim++;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		n--;
		m=0;
		for(i=0;i<n;i++)
			for(j=2;j<n-1;j++)
			{
				if(jiao(a[i],a[(i+1)%n],a[(i+j)%n],a[(i+j+1)%n],p))
				{
					if(dian(p.x-a[i].x,p.y-a[i].y,a[(i+1)%n].x-p.x,a[(i+1)%n].y-p.y)<E)
						continue;
					for(k=0;k<m;k++)
					{
						if(fabs(b[k].x-p.x)<E&&fabs(b[k].y-p.y)<E)
							break;
					}
					if(k==m)
					{
						b[m].x=p.x;
						b[m++].y=p.y;
					}
				}
			}
		printf("Case %d: There are %d pieces.\n",tim,m+2);
	}
	return 0;				
}
