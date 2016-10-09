#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 120000

struct gao
{
    int l,r;
    int s,sum;
}a[maxn];


struct gao2
{
    int x,y,y2,h;
    friend bool operator<(gao2 a,gao2 b)
    {
        if(a.x!=b.x)
            return a.x<b.x;
        return a.y<b.y;
    }
}b[maxn];


int n,w,h,lx,ly;
int x[maxn];
int y[maxn];
int maxx(int a,int b)
{return a>b?a:b;}


void bulid(int x,int l,int r)
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


void dosth(int x,int l,int r,int h)
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
    int i,t,j;
    while(scanf("%d%d%d",&n,&w,&h)!=EOF)
    {
        lx=ly=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&b[2*i].x,&b[2*i].y,&b[2*i].h);
            x[lx++]=b[2*i].x;
            x[lx++]=b[2*i+1].x=b[2*i].x+w;
            y[ly++]=b[2*i].y;
            b[2*i+1].y=b[2*i].y;
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
        printf("%d\n",t);
    }
    return 0;
}
