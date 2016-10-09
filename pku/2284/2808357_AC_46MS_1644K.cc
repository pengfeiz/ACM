#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 301
#define E 1e-6

struct poi
{
	double x,y;
}p,a[MAX],b[MAX][MAX];


int m[MAX],n;


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

double com(poi a,poi b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}

int main()
{
	int i,j,k,tim=0,t;
	while(scanf("%d",&n),n)
	{
		tim++;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		n--;
		t=0;
		memset(m,0,sizeof(m));
		for(i=1;i<n;i++)
		{
			for(j=0;j<i-1;j++)
			{
				if(i==n-1&&j==0)
					continue;
				if(jiao(a[i],a[(i+1)%n],a[j%n],a[(j+1)%n],p))
				{
					if(dian(p.x-a[i].x,p.y-a[i].y,a[(i+1)%n].x-p.x,a[(i+1)%n].y-p.y)<-E||dian(p.x-a[j].x,p.y-a[j].y,a[(j+1)%n].x-p.x,a[(j+1)%n].y-p.y)<-E)
						continue;
					for(k=0;k<m[i-1];k++)
						if(fabs(b[i-1][k].x-p.x)<E&&fabs(b[i-1][k].y-p.y)<E)
							break;
					if(k<m[i-1])
						continue;
					for(k=0;k<m[i];k++)
						if(fabs(b[i][k].x-p.x)<E&&fabs(b[i][k].y-p.y)<E)
							break;
					if(k==m[i])
					{
						t++;
						b[i][m[i]].x=p.x;
						b[i][m[i]++].y=p.y;
					}
				}

			}
		}
		printf("Case %d: There are %d pieces.\n",tim,t+2);
	}
	return 0;				
}

