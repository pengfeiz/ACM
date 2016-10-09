#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.1415926535

int n,m;

int main()
{
    double t,c;
    int tim=0,tt;
    double s[5];
    scanf("%d",&tt);
    while(tt--)
    {
        tim++;
        scanf("%d%d%lf%lf",&n,&m,&t,&c);
        m++;
        n++;
        c/=2.0;
        s[2]=((n-1)*(m-2)+(m-1)*(n-2))*(t-2*c)*2*c+2*c*c*(2*m+2*n-8);
        s[4]=(n-2)*(m-2)*pi*c*c;
        s[3]=(n-2)*(m-2)*4*c*c-s[4];
        s[1]=(n-1)*t*(m-1)*t-s[2]-s[3]-s[4];
        s[0]=s[1]+s[2]+s[3]+s[4];
        printf("Case %d:\nProbability of covering 1 tile  = %.4lf%%\nProbability of covering 2 tiles = %.4lf%%\nProbability of covering 3 tiles = %.4lf%%\nProbability of covering 4 tiles = %.4lf%%\n\n",tim,s[1]/s[0]*100,s[2]/s[0]*100,s[3]/s[0]*100,s[4]/s[0]*100);
    }
    return 0;
}

