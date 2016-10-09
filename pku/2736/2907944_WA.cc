#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 1010

__int64 n,m,t;
struct gao
{
    __int64 x1,x2,y1,y2;
}a[maxn];

__int64 count(__int64 xx,__int64 yy)
{
    __int64 x,y;
    x=xx;
    y=yy;
    if(x>y)
        swap(x,y);
    return x*(x+1)*(2*x+1)/6+(y-x)*(1+x)*x/2;
}

__int64 minn(__int64 a,__int64 b)
{return a<b?a:b;}
__int64 maxx(__int64 a,__int64 b)
{return a>b?a:b;}
void swapp(__int64 &a,__int64 &b)
{
    __int64 c;
    c=a;
    a=b;
    b=c;
}

int main()
{
//    freopen("in.txt","r",stdin);
 //   freopen("F2.out","w",stdout);
    __int64 i,j,cc=0;
    while(scanf("%I64d",&n),n)
    {
        t=0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d%I64d%I64d%I64d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
            if(a[i].x1>a[i].x2)
                swapp(a[i].x1,a[i].x2);
            if(a[i].y1>a[i].y2)
                swapp(a[i].y1,a[i].y2);
        }
        for(i=0;i<n;i++)
            t+=count(a[i].x2-a[i].x1,a[i].y2-a[i].y1);
        
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                if(a[i].x1==a[j].x2||a[i].x2==a[j].x1)
                {
                    if(a[i].y2<=a[j].y1+2||a[i].y1>=a[j].y2-2)
                        continue;
                    t+=count(minn(a[i].y2,a[j].y2)-maxx(a[i].y1,a[j].y1)-2,maxx(a[i].x2-a[j].x1,a[j].x2-a[i].x1));
                    t-=count(minn(a[i].y2,a[j].y2)-maxx(a[i].y1,a[j].y1)-2,a[i].x2-a[i].x1);
                    t-=count(minn(a[i].y2,a[j].y2)-maxx(a[i].y1,a[j].y1)-2,a[j].x2-a[j].x1);
                }
                if(a[i].y1==a[j].y2||a[i].y2==a[j].y1)
                {
                    if(a[i].x2<=a[j].x1+2||a[i].x1>=a[j].x2-2)
                        continue;
                    t+=count(minn(a[i].x2,a[j].x2)-maxx(a[i].x1,a[j].x1)-2,maxx(a[i].x2-a[j].y1,a[j].y2-a[i].y1));
                    t-=count(minn(a[i].x2,a[j].x2)-maxx(a[i].x1,a[j].x1)-2,a[i].y2-a[i].y1);
                    t-=count(minn(a[i].x2,a[j].x2)-maxx(a[i].x1,a[j].x1)-2,a[j].y2-a[j].y1);
                }
            }
        printf("Case%I64d: %I64d\n",++cc,t);
    }
    return 0;
}

