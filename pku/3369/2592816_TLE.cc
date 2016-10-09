#include <iostream>
#include <math.h>
using namespace std;
#define he 20
#define esp 1e-6

int main()
{
//    freopen("out.txt","w",stdout);
    double i,j,k,l,s,x;
    int y;
    for(i=0.01;i<=5;i+=0.01)
        for(j=i;j<=7;j+=0.01)
            for(k=j;k<=10;k+=0.01)
            {
                l=i+j+k;
                s=i*j*k;
                x=l/(s-1);
                if(x<k||x+l>he+esp)
                    continue;
                y=(int(x*100+esp));
                s=double(y);
                l=x*100;
                if(fabs(s-l)<esp)
                    printf("%.2lf %.2lf %.2lf %.2lf\n",i,j,k,x);
            }
    return 0;
}
