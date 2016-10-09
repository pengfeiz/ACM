#include <iostream>
#include <cmath>
using namespace std;
#define MAX 301
#define E 1e-7

struct poi
{
	double x,y;
}pa,pb,pc,pd,p,a[MAX],b[MAX],bb[MAX],aa[MAX];

double pi,r;
int m,n;

double ll(double x)
{return x*x;}
double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double dian(double x1,double y1,double x2,double y2)
{return x1*x2+y1*y2;}
void jiao(poi pa,poi pb,poi pc,poi pd,poi &p)
{
	double s1,s2;
	s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
	s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
	p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
	p.y=(s1*pb.y+s2*pa.y)/(s1+s2);
}
double dis(poi a,poi b)
{return sqrt(ll(a.x-b.x)+ll(a.y-b.y));}

void solve(int ii)
{
	int i=0,mm=0,hi=0,tt=0;
	int f=0;
	poi he;
	he.x=a[(ii+1)%n].x-a[ii].x;
	he.y=a[(ii+1)%n].y-a[ii].y;
	while(tt<m&&hi<=2*m)
	{
		if(cha(he.x,he.y,b[i].x-a[ii].x,b[i].y-a[ii].y)>E)
		{
			if(f==1)
			{
				jiao(b[(i-1+m)%m],b[i],a[ii],a[(ii+1)%n],p);
				bb[mm].x=p.x;
				bb[mm].y=p.y;
				mm++;
				f=2;
			}
			if(f)
				tt++;
		}
		else
		{
			if(!f)
			{
				tt--;
				f=1;
			}
			else if(f==2)
			{
				jiao(b[(i-1+m)%m],b[i],a[ii],a[(ii+1)%n],p);
				bb[mm].x=p.x;
				bb[mm].y=p.y;
				mm++;
                                f++;
			}
			tt++;
			if(tt)
			{
				bb[mm].x=b[i].x;
				bb[mm].y=b[i].y;
				mm++;
			}
		}
		i=(i+1)%m;
		hi++;
	}
	m=mm;
	for(i=0;i<m;i++)
	{
		b[i].x=bb[i].x;
		b[i].y=bb[i].y;
	}
}


void dostar()
{
	bool f;
        double xx,yy,l,x1,y1,x2,y2;
	int i,j;
	f=false;
	scanf("%d%lf",&n,&r);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&aa[i].x,&aa[i].y);
        for(i=0;i<n;i++)
        {
            yy=aa[i].x-aa[(i+1)%n].x;
            xx=aa[(i+1)%n].y-aa[i].y;
            a[2*i].x=aa[i].x+xx/sqrt(ll(xx)+ll(yy))*r;
            a[2*i].y=aa[i].y+yy/sqrt(ll(xx)+ll(yy))*r;
            a[2*i+1].x=aa[(i+1)%n].x+xx/sqrt(ll(xx)+ll(yy))*r;
            a[2*i+1].y=aa[(i+1)%n].y+yy/sqrt(ll(xx)+ll(yy))*r;
        }
        n*=2;
	m=4;
	b[0].x=-999999999.0;
	b[0].y=-999999999.0;
	b[1].x=-999999999.0;
	b[1].y=999999999.0;
	b[2].x=999999999.0;
	b[2].y=999999999.0;
	b[3].x=999999999.0;
	b[3].y=-999999999.0;
	for(i=0;i<n;i+=2)
		solve(i);
        l=0;
        for(i=0;i<m;i++)
            for(j=0;j<m;j++)
                if(dis(b[i],b[j])>l)
                {
                    l=dis(b[i],b[j]);
                    x1=b[i].x;
                    y1=b[i].y;
                    x2=b[j].x;
                    y2=b[j].y;
                }
        printf("%.4lf %.4lf %.4lf %.4lf\n",x1,y1,x2,y2);
}


int main()
{
        dostar();
        return 0;
}

