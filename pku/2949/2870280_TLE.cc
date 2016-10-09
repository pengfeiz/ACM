#include <iostream>
#include <cmath>
using namespace std;
#define esp 1e-5

double d[900];
int n;

struct gao
{
    int v,u;
    double l;
}a[100010];

char s[1024];


bool dosth(double x)
{
    int i,j;
    bool key;
    memset(d,0,sizeof(d));
    for(i=0;i<n;i++)
    {
        key=true;
        for(j=0;j<n;j++)
            if(d[a[j].v]+a[j].l-x>d[a[j].u]+esp)
            {
                d[a[j].u]=d[a[j].v]+a[j].l-x;
                key=false;
            }
        if(key)
            break;
    }
    if(i==n)
        return true;
    return false;
}


int main()
{
    int i,l,j;
    double aa,bb,mid,ll;
    while(scanf("%d",&n),n)
    {
        ll=0.0;
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            l=strlen(s);
            a[i].v=(s[0]-'a')*26+(s[1]-'a');
            a[i].u=(s[l-2]-'a')*26+(s[l-1]-'a');
            a[i].l=double(l);
            if(l>ll)
                ll=l;
        }
        aa=0.0;
        bb=1025;
        while(bb-aa>esp)
        {
            mid=(bb+aa)/2;
            if(dosth(mid))
                aa=mid;
            else
                bb=mid;
        }
        if(aa<esp)
            printf("No solution.\n");
        else
            printf("%.2lf\n",aa);
    }
    return 0;
}
