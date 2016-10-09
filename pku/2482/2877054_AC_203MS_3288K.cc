#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 20100

struct gao
{
    __int64 l,r;
    __int64 s,sum;
}a[4*maxn];


struct gao2
{
    __int64 x,y,y2,h;
    friend bool operator<(gao2 a,gao2 b)
    {return a.x<b.x;}
}b[maxn];


__int64 n,w,h,lx,ly;
__int64 x[maxn];
__int64 y[maxn];

__int64 maxx(__int64 a,__int64 b)
{return a>b?a:b;}
void bulid(__int64 x,__int64 l,__int64 r)
{
    a[x].l=l;
    a[x].r=r;
    a[x].s=a[x].sum=0;
    if(l<r-1)
    {
        bulid(2*x,l,(r+l)/2);
        bulid(2*x+1,(r+l)/2,r);
    }
}
void dosth(__int64 x,__int64 l,__int64 r,__int64 h)
{
    if(a[x].l==l&&a[x].r==r)
    {
        a[x].s+=h;
        a[x].sum+=h;
        return;
    }
    if(r<=(a[x].l+a[x].r)/2)
        dosth(2*x,l,r,h);
    else
        dosth(2*x+1,l,r,h);
    a[x].s=a[2*x].s+a[2*x+1].s;
    a[x].sum=maxx(a[2*x].sum,a[2*x].s+a[2*x+1].sum);
}


int main()
{
 //   freopen("in.txt","r",stdin);
    __int64 i,t,j;
//    n=100;
    while(scanf("%d%d%d",&n,&w,&h)!=EOF)
    {
//        w=h=100;
        lx=ly=0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d%I64d%I64d",&b[2*i].x,&b[2*i].y,&b[2*i].h);
//            b[2*i].x=rand();
//            b[2*i].y=rand();
//            b[2*i].h=rand()%100;
            x[lx++]=b[2*i].x;
            x[lx++]=b[2*i+1].x=b[2*i].x+w;
            y[ly++]=b[2*i+1].y=b[2*i].y;
            y[ly++]=b[2*i].y2=b[2*i+1].y2=b[2*i].y+h;
            b[2*i+1].h=-b[2*i].h;
        }
        sort(x,x+lx);
        sort(y,y+ly);
        lx=unique(x,x+lx)-x;
        ly=unique(y,y+ly)-y;
        for(i=0;i<2*n;i++)
        {
            b[i].x=lower_bound(x,x+lx,b[i].x)-x;
            b[i].y=lower_bound(y,y+ly,b[i].y)-y;
            b[i].y2=lower_bound(y,y+ly,b[i].y2)-y;
        }
        sort(b,b+2*n);
        bulid(1,0,ly);
        t=0;
        b[2*n].x=-1;
        for(i=0;i<2*n;i++)
        {
            for(j=i;j<2*n;j++)
            {
                dosth(1,b[j].y,b[j].y+1,b[j].h);
                dosth(1,b[j].y2,b[j].y2+1,-b[j].h);
                if(b[j].x!=b[j+1].x)
                    break;
            }
            i=j;
            if(t<a[1].sum)
                t=a[1].sum;
        }
        printf("%I64d\n",t);
    }
    return 0;
}
