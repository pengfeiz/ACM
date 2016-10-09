#include <iostream>
using namespace std;
#define maxn 40001
#define maxm 500001

struct gao
{
    int x,y;
}a[maxn];

int n,t;
char s[2];

int main()
{
    int i,j,tim,minn,p,x,l,cc=0;
    while(scanf("%d",&t),t)
    {
        cc++;
        printf("Case %d:\n",cc);
        n=tim=0;
        for(i=0;i<t;i++)
        {
            scanf("%s",s);
            if(s[0]=='B')
            {
                scanf("%d",&a[n].x);
                a[n++].y=(++tim);
            }
            else
            {
                scanf("%d",&p);
                minn=99999999;
                for(j=n-1;j>=0&&j>=n-2000;j--)
                {
                    l=a[j].x%p;
                    if(l<minn)
                    {
                        x=a[j].y;
                        minn=l;
                    }
                    if(!minn)
                        break;
                }
                for(j=0;j<=2000&&j<=n;j++)
                {
                    l=a[j].x%p;
                    if(l<=minn)
                    {
                        x=a[j].y;
                        minn=l;
                    }
                }
                printf("%d\n",x);
            }
        }
        printf("\n");
    }
    return 0;
}
    