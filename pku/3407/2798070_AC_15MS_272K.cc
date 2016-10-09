#include <iostream>
#include <math.h>
using namespace std;

const double pi=3.1415926535;

int main()
{
    double t,phi,tm,pm;
    double t1,phi1,t2,phi2;
    char s1[10],s2[10];
    while(scanf("%lf%lf%s%lf%lf%s",&t,&tm,s1,&phi,&pm,s2)!=EOF)
    {
        t+=tm/60;
        phi+=pm/60;
        if(strcmp(s1,"N")==0)
            t1=90-t;
        else
            t1=90+t;
        if(strcmp(s2,"E")==0)
            phi1=phi;
        else
            phi1=360-phi;
        scanf("%lf%lf%s%lf%lf%s",&t,&tm,s1,&phi,&pm,s2);
        t+=tm/60;
        phi+=pm/60;
        if(strcmp(s1,"N")==0)
            t2=90-t;
        else
            t2=90+t;
        if(strcmp(s2,"E")==0)
            phi2=phi;
        else
            phi2=360-phi;
        t1=t1*pi/180;
        t2=t2*pi/180;
        phi1=phi1*pi/180;
        phi2=phi2*pi/180;
        double p=6370.0;
        double x1,y1,z1,x2,y2,z2;
        x1=p*sin(t1)*cos(phi1);
        y1=p*sin(t1)*sin(phi1);
        z1=p*cos(t1);
        x2=p*sin(t2)*cos(phi2);
        y2=p*sin(t2)*sin(phi2);
        z2=p*cos(t2);
        
        double alpha=acos((x1*x2+y1*y2+z1*z2)/((sqrt(x1*x1+y1*y1+z1*z1))*(sqrt(x2*x2+y2*y2+z2*z2))));
        printf("%.3lf\n",alpha*p);
    }
    return 0;
}