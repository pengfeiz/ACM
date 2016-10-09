#include <iostream>
#include <math.h>
using namespace std;
void com(double x[3],double y[3],double mx[2],double my[2],double a[2])
{
	double a1,a2,b1,b2;
	if(x[0]==mx[0])
	{
		a[0]=x[0];
		a1=(y[1]-my[1])/(x[1]-mx[1]);
		b1=y[1]-a1*x[1];
		a[1]=a1*x[0]+b1;
		return;
	}
	if(x[1]==mx[1])
	{
		a[0]=x[1];
		a1=(y[0]-my[0])/(x[0]-mx[0]);
		b1=y[0]-a1*x[0];
		a[1]=a1*x[1]+b1;
		return;
	}
	a1=(y[0]-my[0])/(x[0]-mx[0]);
	b1=y[0]-a1*x[0];
	a2=(y[1]-my[1])/(x[1]-mx[1]);
	b2=y[1]-a2*x[1];
	a[0]=(b2-b1)/(a1-a2);
	a[1]=a[0]*a1+b1;
}
int main()
{
	double x[3],y[3],xx,yy,mx[2],my[2],xxx,yyy,a[2];
	int nn,i;
	cin>>nn;
	while(nn-->0)
	{
		for(i=0;i<3;i++)
			cin>>x[i]>>y[i];
		if(pow(x[0]-y[1]+y[0]-x[2],2)+pow(y[0]+x[1]-x[0]-y[2],2)<pow(x[0]+y[1]-y[0]-x[2],2)+pow(y[0]-x[1]+x[0]-y[2],2))
		{
			xx=x[0]+y[1]-y[0];
			yy=y[0]-x[1]+x[0];
		}
		else
		{
			xx=x[0]-y[1]+y[0];
			yy=y[0]+x[1]-x[0];
		}
		if(pow(x[0]-y[2]+y[0]-x[1],2)+pow(y[0]+x[2]-x[0]-y[1],2)<pow(x[0]+y[2]-y[0]-x[1],2)+pow(y[0]-x[2]+x[0]-y[1],2))
		{
			xxx=x[0]+y[2]-y[0];
			yyy=y[0]-x[2]+x[0];
		}
		else
		{
			xxx=x[0]-y[2]+y[0];
			yyy=y[0]+x[2]-x[0];
		}
		mx[0]=(xx+xxx)/2;
		my[0]=(yy+yyy)/2;
		if(pow(x[1]-y[0]+y[1]-x[2],2)+pow(y[1]+x[0]-x[1]-y[2],2)<pow(x[1]+y[0]-y[1]-x[2],2)+pow(y[1]-x[0]+x[1]-y[2],2))
		{
			xx=x[1]+y[0]-y[1];
			yy=y[1]-x[0]+x[1];
		}
		else
		{
			xx=x[1]-y[0]+y[1];
			yy=y[1]+x[0]-x[1];
		}
		if(pow(x[1]-y[2]+y[1]-x[0],2)+pow(y[1]+x[2]-x[1]-y[0],2)<pow(x[1]+y[2]-y[1]-x[0],2)+pow(y[1]-x[2]+x[1]-y[0],2))
		{
			xxx=x[1]+y[2]-y[1];
			yyy=y[1]-x[2]+x[1];
		}
		else
		{
			xxx=x[1]-y[2]+y[1];
			yyy=y[1]+x[2]-x[1];
		}
		mx[1]=(xx+xxx)/2;
		my[1]=(yy+yyy)/2;
		com(x,y,mx,my,a);
		printf("%.4f %.4f\n",a[0],a[1]);
	}
	return 0;
}


		
