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
    int i,j,tim,minn,p,x;
    while(scanf("%d",&t),t)
    {
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
                for(j=n-1;j>=0;j--)
                {
                    if((a[j].x%p)<minn)
                    {
                        x=a[j].y;
                        minn=a[j].x%p;
                    }
                }
                printf("%d\n",x);
            }
        }
    }
    return 0;
}
    