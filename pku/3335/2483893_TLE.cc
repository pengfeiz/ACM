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
	int i=0,mm=0,tt=0;
	int f=0;
	poi he;
	he.x=a[(ii+1)%n].x-a[ii].x;
	he.y=a[(ii+1)%n].y-a[ii].y;
	while(tt<m&&i<3*m)
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
	}
	m=mm;
	for(i=0;i<m;i++)
	{
		b[i].x=bb[i].x;
		b[i].y=bb[i].y;
	}
}


int main()
{
//	freopen("in.txt","r",stdin);
	int t,i;
	bool f;
	scanf("%d",&t);
	while(t--)
	{
		f=false;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		m=4;
		b[0].x=-999999999.0;
		b[0].y=-999999999.0;
		b[1].x=-999999999.0;
		b[1].y=999999999.0;
		b[2].x=999999999.0;
		b[2].y=999999999.0;
		b[3].x=999999999.0;
		b[3].y=-999999999.0;
		for(i=0;i<n;i++)
			solve(i);
		if(m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
