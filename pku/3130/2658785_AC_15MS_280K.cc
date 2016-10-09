//必须顺时针输入

#include <iostream>
using namespace std;
#define MAX 501
#define E 1e-7

struct poi
{
	double x,y;
}pa,pb,pc,pd,p,a[MAX],b[MAX],bb[MAX];

double ans,pi;
int m,n;


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


bool dostar()
{
	bool f;
	int i;
	f=false;
	if(scanf("%d",&n),n==0)
		return false;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&b[i].x,&b[i].y);
	for(i=0;i<n;i++)
	{
		a[i].x=b[n-i-1].x;
		a[i].y=b[n-i-1].y;
	}
	m=4;
	b[0].x=-9999999999999.0;
	b[0].y=-9999999999999.0;
	b[1].x=-9999999999999.0;
	b[1].y=9999999999999.0;
	b[2].x=9999999999999.0;

	b[2].y=9999999999999.0;
	b[3].x=9999999999999.0;
	b[3].y=-9999999999999.0;
	for(i=n-1;i>=0;i--)
		solve(i);
	//b数组存维护以后的凸多边形
	if(m)
		printf("1\n");
	else
		printf("0\n");
	return true;
}


int main()
{
	//freopen("in.txt","r",stdin);
	while(dostar());
	return 0;
}
