#include <iostream>
#include <cmath>
using namespace std;
#define esp 1e-3

double d[900];
int n,nn;
bool cc[900];

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
    for(i=0;i<nn+5;i++)
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
    if(i==nn+5)
        return true;
    return false;
}


int main()
{
    int i,l,j;
    double aa,bb,mid;
    while(scanf("%d",&n),n)
    {
        nn=0;
        memset(cc,0,sizeof(cc));
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            l=strlen(s);
  //          l=1000;
  //          for(j=0;j<1000;j++)
  //              s[j]='a';
  //          s[l]='\0';
            a[i].v=(s[0]-'a')*26+(s[1]-'a');
            a[i].u=(s[l-2]-'a')*26+(s[l-1]-'a');
            if(!cc[a[i].v])
            {
                cc[a[i].v]=true;
                nn++;
            }
            if(!cc[a[i].u])
            {
                cc[a[i].u]=true;
                nn++;
            }
            a[i].l=double(l);
        }
        aa=0.0;
        bb=1024.0;
        while(bb-aa>esp)
        {
            mid=(bb+aa)/2.0;
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
