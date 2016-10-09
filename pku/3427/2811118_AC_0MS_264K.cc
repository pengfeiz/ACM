#include <iostream>
#include <algorithm>
using namespace std;

int n,l;
int a[30002];

int main()
{
    int i,t,y,maxx,tim,ii;
    scanf("%d%d",&n,&l);
    t=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]%=l;
        t+=a[i];
    }
    maxx=t;
    y=tim=0;
    sort(a+1,a+n+1);
    a[0]=-1;
    ii=n+1;
    for(i=n;i>0;i--)
    {
        if(a[i]==a[i-1])
            continue;
        tim+=(l-(a[i]+tim)%l)%l;
        t=t+(n-(ii-i))*((l-(a[i]+tim)%l)%l)-(ii-i)*a[i];
        if(t<maxx)
        {
            maxx=t;
            y=tim;
        }
        ii=i;
    }
    printf("%d\n",y);
    return 0;
}
