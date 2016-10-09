#include <iostream>
#include <vector>
using namespace std;
#define MAX 1002
#define esp 1e-6

struct gao
{__int64 x,y;}a[MAX];

int n,s,e;
int b[MAX];
int c[MAX],cc[MAX];
__int64 l;


__int64 ll(__int64 x)
{return x*x;}
__int64 dis(gao a,gao b)
{return ll(a.x-b.x)+ll(a.y-b.y);}
void bfs()
{
	int n1,n2,i,t=0,j;
        for(i=0;i<n;i++)
            b[i]=99999999;
        c[0]=s;
        n1=1;
        b[s]=t;
        while(n1)
        {
            t++;
            n2=0;
            for(i=0;i<n1;i++)
            {
                for(j=0;j<n;j++)
                    if(dis(a[c[i]],a[j])<=l&&b[j]==99999999)
                    {
                        cc[n2++]=j;
                        b[j]=t;
                        if(j==e)
                            return;
                    }
            }
            n1=n2;
            for(i=0;i<n1;i++)
                c[i]=cc[i];
        }
}
void solve()
{
	int i,j;
        bfs();
        if(b[e]==99999999)
            printf("Impossible\n");
        else
            printf("%d\n",b[e]);
}


void init()
{
        double l1,l2;
	int i;
        scanf("%d%d%d%lf%lf",&n,&s,&e,&l1,&l2);
        s--;e--;
        l=(__int64)((l1+l2)*(l1+l2));
        for(i=0;i<n;i++)
             scanf("%I64d%I64d",&a[i].x,&a[i].y);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
	solve();
    }
    return 0;
}

