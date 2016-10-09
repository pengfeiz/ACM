#include<stdio.h>
#include<math.h>
#define E 1e-10
struct poi
{
	double x,y;
}pa,pb,pc,pd,p;
double ans,pi;

double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}

double dian(double x1,double y1,double x2,double y2)
{return x1*x2+y1*y2;}

void addd(struct poi pa,struct poi pb,struct poi pc,struct poi pd)
{
	double s1,s2;
	s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
	s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
	p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
	p.y=(s1*pb.y+s2*pa.y)/(s1+s2);
}

double di(double x1,double y1,double x2,double y2)
{return (fabs(x1-x2)>E?x1/x2:y1/y2);}

double ll(double i)
{return i*i;}

int work()
{	
	double l,r,rx,ry,k,l1,l2,x,y,la,sm,s;
	if(fabs(cha(pa.x-pb.x,pa.y-pb.y,pc.x-pd.x,pc.y-pd.y))<E)
	{
		l=0; 
		r=1;
	}
	else
	{
		addd(pa,pb,pc,pd);
		if(dian(pc.x-p.x,pc.y-p.y,pd.x-p.x,pd.y-p.y)<E)
		{
			if(cha(pc.x-pa.x,pc.y-pa.y,pb.x-pa.x,pb.y-pa.y)>-E) 
				l=0;
			else 
				l=di(p.x-pc.x,p.y-pc.y,pd.x-pc.x,pd.y-pc.y);
			if(cha(pd.x-pa.x,pd.y-pa.y,pb.x-pa.x,pb.y-pa.y)>-E) 
				r=1;
			else 
				r=di(p.x-pc.x,p.y-pc.y,pd.x-pc.x,pd.y-pc.y);
		}
		else 
		{
			if(cha(pc.x-pa.x,pc.y-pa.y,pb.x-pa.x,pb.y-pa.y)>-E) 
			{
				l=0; 
				r=1;
			}
			else 
				return 0;
		}
	}
	rx=pd.x-pc.x; 
	ry=pd.y-pc.y;
	la=ll(pa.x-pb.x)+ll(pa.y-pb.y);
	while(r-l>1e-7)
	{
		k=(l+r)/2;
		x=pc.x+rx*k;
		y=pc.y+ry*k;
		l1=ll(pa.x-x)+ll(pa.y-y);
		l2=ll(pb.x-x)+ll(pb.y-y);
		s=(l1+l2-la)/sqrt(l1*l2);
		k+=1e-10;
		x=pc.x+rx*k; y=pc.y+ry*k;
		l1=ll(pa.x-x)+ll(pa.y-y);
		l2=ll(pb.x-x)+ll(pb.y-y);
		sm=(l1+l2-la)/sqrt(l1*l2);
		if(sm>s)
			r=k;
		else 
			l=k;
	}
	ans=acos(s/2)*180/pi;
	return 1;
}

int main()
{
	pi=2*acos(0);
	while (scanf("(%lf,%lf)",&pa.x,&pa.y)!=EOF)
	{
		scanf(" (%lf,%lf)",&pb.x,&pb.y);
		scanf(" (%lf,%lf)",&pc.x,&pc.y);
		scanf(" (%lf,%lf)",&pd.x,&pd.y);
		scanf("\n");
		if(work()) 
			printf("%.3lf\n",ans);
		else 
			printf("0.000\n");
	}
	return 0;
}