#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10001
#define maxm 1000001

int a[maxn];
struct gao
{
    int x,y;
}b[maxm];

int h,n,t,r;

bool com(gao a,gao b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
bool com2(gao a,gao b)
{
    if(a.x!=b.x||a.y!=b.y)
        return false;
    return true;
}

int main()
{
    int i,p;
    scanf("%d%d%d%d",&n,&t,&h,&r);
    memset(a,0,sizeof(a));
    for(i=0;i<r;i++)
    {  
        scanf("%d%d",&b[i].x,&b[i].y);
        if(b[i].x>b[i].y)
            swap(b[i].x,b[i].y);
    }
    sort(b,b+r,com);
    r=unique(b,b+r,com2)-b;
    for(i=0;i<r;i++)
    {
        a[b[i].x+1]--;
        a[b[i].y]++;
    }
    p=0;
    for(i=1;i<=n;i++)
    {
        p+=a[i];
        printf("%d\n",p+h);
    }
    return 0;
}
        