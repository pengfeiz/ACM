#include <iostream>
#include <algorithm>
using namespace std;


const int maxn=200100;

int a[maxn],b[maxn],c[maxn],d[maxn];
struct gao
{
    int n,i;
}e[maxn];

bool f;
int n,m;


bool com(gao a,gao b)
{
    if(a.n!=b.n)
        return a.n<b.n;
    return a.i<b.i;
}

int main()
{
    int i,t;
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(c,127,sizeof(c));
        f=true;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            e[i].n=a[i];
            e[i].i=i;
        }
        sort(e,e+n,com);
        for(i=n-1;i>=0;i--)
        {
            t=lower_bound(c,c+m,e[i].i)-c;
            if(t>=m)
            {
                f=false;
                break;
            }
            a[e[i].i]=t;
            c[t]=e[i].i;
            d[i]=t;
        }
        if(f)
        {
            for(i=0;i<n;i++)
            {
                if(i)
                    printf(" ");
                printf("%d",a[i]+1);
            }
            printf("\n");
            for(i=0;i<n;i++)
            {
                if(i)
                    printf(" ");
                printf("%d",d[i]+1);
            }
            printf("\n");
        }
        else
            printf("Transportation failed\n");
    }
    return 0;
}

