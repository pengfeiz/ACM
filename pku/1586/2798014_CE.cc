#include <iostream>
#include <math.h>
using namespace std;

const double pi=3.14159265358979323846264338327950288;

double ll(double x)
{return x*x;}
double dist(double x1,double y1,double x2,double y2)
{return sqrt(ll(x1-x2)+ll(y1-y2));}
bool judge(double a,double b)
{return abs(a-b)<1e-2;}
double maxx(double a,double b)
{return a>b?a:b;}
double minn(double a,double b)
{return a<b?a:b;}


int main()
{
    double x1,y1,x2,y2,x3,y3,am;
	double l1,l2,l3,ll1,ll2,ll3;
    double a1,a2,a3;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        l1=hypot(x2-x3,y2-y3);
        l2=hypot(x1-x3,y1-y3);
        l3=hypot(x1-x2,y1-y2);
        ll1=maxx(maxx(l1,l2),l3);
        ll3=minn(minn(l1,l2),l3);
        ll2=l1+l2+l3-ll1-ll3;
        l1=ll1;
        l2=ll2;
        l3=ll3;
        if(judge(l1,l2+l3))
        {
            printf("Not a Triangle\n");
            continue;
        }
        if(judge(l1,l3))
            printf("Equilateral ");
        else if(judge(l1,l2)||judge(l2,l3))
            printf("Isosceles ");
        else
            printf("Scalene ");

        a1=acos((ll(l2)+ll(l3)-ll(l1))/(2*l2*l3));
        a2=acos((ll(l3)+ll(l1)-ll(l2))/(2*l3*l1));
        a3=acos((ll(l1)+ll(l2)-ll(l3))/(2*l1*l2));
        am=maxx(maxx(a1,a2),a3)*180/pi;
        if(am>88&&am<92)
            printf("Right\n");
        else if(am>90)
            printf("Obtuse\n");
        else
            printf("Acute\n");
    }
    printf("End of Output\n");
    return 0;
}