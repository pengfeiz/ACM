#include <iostream>
#include <math.h>
using namespace std;

#define esp 1e-6
double X[3],Y[3],R[3];

struct gao
{
    double px, py;
    double vx, vy;
    double ra;
    bool isLine;
};

double ll(double x){return x*x;}

void com1(int idx1,int idx2,gao *il)
{
    double ux,uy,dist,rd,t1,t2;
	il->isLine=(R[idx1]==R[idx2]);
    if(il->isLine) 
	{
		il->px=(X[idx1]+X[idx2])/2.0;
		il->py=(Y[idx1]+Y[idx2])/2.0;
		il->vx=Y[idx1]-Y[idx2];
		il->vy=X[idx2]-X[idx1];
    }
	else
	{
		ux=X[idx2]-X[idx1];
		uy=Y[idx2]-Y[idx1];
		dist=hypot(ux,uy);
		ux/=dist;
		uy/=dist;
		rd=R[idx1]*dist;
		t1=rd/(R[idx1]-R[idx2]);
		t2=rd/(R[idx1]+R[idx2]);
		il->ra=fabs(t1-t2)/2.0;
		t1=(t1+t2)/2.0;
		il->px=X[idx1]+t1*ux;
		il->py=Y[idx1]+t1*uy;
    }
}

void com2(gao *il1,gao *il2)
{
    double det,dx,dy,tt,xx,yy;
	det=il1->vx*il2->vy-il1->vy*il2->vx;
    dx=il1->px-il2->px;
    dy=il1->py-il2->py;
	tt=(dx*il2->vy-dy*il2->vx)/det;
	xx=il1->px-tt*il1->vx;
	yy=il1->py-tt*il1->vy;
    printf("%.2f %.2f\n",xx,yy);
}

void com3(gao *il1,gao *il2)
{
    double dx,dy,dist,aa,bb,xx,yy,hx1,hx2,hy1,hy2;
	dx=il2->px-il1->px;
	dy=il2->py-il1->py;
    dist=hypot(dx,dy);
    aa=(dist*dist+il1->ra*il1->ra-il2->ra*il2->ra)/(2.0*dist);
    bb=il1->ra*il1->ra-aa*aa;
    if(bb<-esp)
	{printf("No solution\n");
return;
    }
    bb=sqrt(bb)/dist;
    aa/=dist;
	xx=il1->px+aa*dx;
    yy=il1->py+aa*dy;
	hx1=xx+bb*dy;
	hy1=yy-bb*dx;
	hx2=xx-bb*dy;
	hy2=yy+bb*dx;
	if((ll(hx1-X[0])+ll(hy1-Y[0]))>(ll(hx2-X[0])+ll(hy2-Y[0])))
		printf("%.2lf %.2lf\n",hx2,hy2);
	else
		printf("%.2lf %.2lf\n",hx1,hy1);
}
void dosth()
{
    gao il1,il2;
	com1(0,1,&il1);
	com1(0,2,&il2);if(il1.isLine)
	{if(il2.isLine)
			com2(&il1,&il2); 
		else {
			com1(1,2,&il1);
			com3(&il1,&il2);}}else
{
		if(il2.isLine)
			com1(1,2,&il2);
		com3(&il1,&il2);}
}
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&X[0],&Y[0],&R[0],&X[1],&Y[1],&R[1],&X[2],&Y[2],&R[2])!=EOF)
    {
		if(fabs(X[0])<esp&&fabs(X[1])<esp&&fabs(X[2])<esp&&fabs(Y[0])<esp&&fabs(Y[1])<esp&&fabs(Y[2])<esp&&fabs(R[0])<esp&&fabs(R[1])<esp&&fabs(R[2])<esp)
			break;
		dosth();
    }
	return 0;
}