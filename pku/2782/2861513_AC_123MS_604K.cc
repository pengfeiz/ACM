#include <iostream>
#include <algorithm>
using namespace std;


int a[100005],n,m;

int main()
{
    int i,j,t;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    t=0;
    for(i=0,j=n-1;i<=j;)
    {
        if(a[i]+a[j]<=m)
        {
            i++;
            t++;
            j--;
        }
        else
        {
            j--;
            t++;
        }
    }
    printf("%d\n",t);
    return 0;
}
