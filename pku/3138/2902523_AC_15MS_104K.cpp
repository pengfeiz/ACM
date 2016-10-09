#include <iostream>
#include <algorithm>
using namespace std;


int n,s,m;
bool b[101];
int a[101];
struct gao
{
    int n,x,y,i;
}c[101];


bool com(gao a,gao b)
{return a.n<b.n;}

int main()
{
   // freopen("xc","r",stdin);
    int i,x,cc=0;
    int p,q,t;
    gao f;
    while(scanf("%d%d%d",&n,&s,&m),n||s||m)
    {
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
            scanf("%d%d%d",&c[i].n,&c[i].x,&c[i].y);
        sort(c,c+n,com);
        for(i=0;i<n;i++)
            c[i].i=i;
        for(i=0;i<n;i++)
            a[i]+=c[i].x+c[i].y;
        for(i=0;i<s;i++)
        {
            scanf("%d%d",&p,&q);
            f.n=p;
            x=lower_bound(c,c+n,f,com)-c;
            if(b[x])
                continue;
            if(q<m)
                continue;
            a[c[x].i]++;
            b[c[x].i]=true;
        }
        t=0;
        for(i=0;i<n;i++)
            t+=a[i];
        printf("Case %d: %d\n",++cc,t);
    }
    return 0;
}
