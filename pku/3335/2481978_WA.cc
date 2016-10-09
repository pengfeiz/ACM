#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 101
#define EP 1e-8

struct POINT
{
	double x,y;
}Polygon[MAX];
struct LINESEG
{
	POINT s; 
	POINT e; 
	LINESEG(POINT a, POINT b)
	{
		s=a;
		e=b;
	}
	LINESEG()
	{}
};

int vcount;

double maxx(double x,double y)
{return x>y?x:y;}
double minn(double x,double y)
{return x<y?x:y;}


double multiply(POINT sp,POINT ep,POINT op)
{return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));}
bool online(LINESEG l,POINT p)
{return(fabs(multiply(l.e,p,l.s))<EP&&(((p.x-l.s.x)*(p.x-l.e.x)<EP)&&((p.y-l.s.y)*(p.y-l.e.y)<EP)));}
bool intersect(LINESEG u,LINESEG v){return((maxx(u.s.x,u.e.x)>minn(v.s.x,v.e.x)-EP)&&(maxx(v.s.x,v.e.x)>minn(u.s.x,u.e.x)-EP)&&(maxx(u.s.y,u.e.y)>minn(v.s.y,v.e.y)-EP)&&(maxx(v.s.y,v.e.y)>minn(u.s.y,u.e.y)-EP)&&(multiply(v.s,u.e,u.s)*multiply(u.e,v.e,u.s)>-EP)&&(multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>-EP));} 
bool intersect_A(LINESEG u,LINESEG v){return((intersect(u,v))&&(!online(u,v.s))&&(!online(u,v.e))&&(!online(v,u.e))&&(!online(v,u.s)));} 

int insidepolygon(int vcount,POINT Polygon[],POINT q) 
{ 
	int c=0,i,n;
	LINESEG l1,l2;
	bool bintersect_a,bonline1,bonline2,bonline3;
	double r1,r2;
	l1.s=q;
	l1.e=q;
	l1.e.x=9999999999.0;
	n=vcount;
	for(i=0;i<n;i++)
	{ 
		l2.s=Polygon[i]; 
		l2.e=Polygon[(i+1)%n];
		if(online(l2,q))
			return 1;
		if((bintersect_a=intersect_A(l1,l2))||( (bonline1=online(l1,Polygon[(i+1)%n]))&&( (!(bonline2=online(l1,Polygon[(i+2)%n])))&&((r1=multiply(Polygon[i],Polygon[(i+1)%n],l1.s)*multiply(Polygon[(i+1)%n],Polygon[(i+2)%n],l1.s))>0)||(bonline3=online(l1,Polygon[(i+2)%n]))&&((r2=multiply(Polygon[i],Polygon[(i+2)%n],l1.s)*multiply(Polygon[(i+2)%n],Polygon[(i+3)%n],l1.s))>0))))
			c++; 
	}      
	if(c%2==1)         
		return 0;      
	else      
		return 2; 
} 

bool judge(int p)
{
	int i;
	double j;
	double xx,yy;
	POINT x;
	for(i=0;i<vcount;i++)
	{
		xx=Polygon[i].x-Polygon[p].x;
		yy=Polygon[i].y-Polygon[p].y;
		for(j=0.31;j<1;j+=0.031)
		{
			x.x=Polygon[p].x+j*xx;
			x.y=Polygon[p].y+j*yy;
			if(insidepolygon(vcount,Polygon,x)==2)
				return false;
		}
	}
	return true;
}
int main() 
{
	//freopen("in.txt","r",stdin);
	int t,i;
	bool f;
	scanf("%d",&t);
	while(t--)
	{
		f=false;
		scanf("%d",&vcount);
		for(i=0;i<vcount;i++)
			scanf("%lf%lf",&Polygon[i].x,&Polygon[i].y);
		for(i=0;!f&&i<vcount;i++)
			if(judge(i))
				f=true;
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
	