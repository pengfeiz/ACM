#include <iostream>
#include <cmath>
using namespace std;
#define esp 1e-10

struct poi
{
	double x,y;
}pa,pb,pc,pd,p;

double ans,pi;


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


bool dosth(poi pa,poi pb,poi pc,poi pd)
{
	if(fabs(cha(pa.x-pb.x,pa.y-pb.y,pc.x-pd.x,pc.y-pd.y))<esp)
		return false;
	jiao(pa,pb,pc,pd,p);
	return true;
}



int main()
{
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&pa.x,&pa.y,&pb.x,&pb.y,&pc.x,&pc.y,&pd.x,&pd.y)!=EOF)
	{
		if(!dosth(pa,pb,pc,pd))
			printf("Ping xing or Chong he!\n");
		else
			printf("%lf %lf\n",p.x,p.y);
	}
	return 0;
}


