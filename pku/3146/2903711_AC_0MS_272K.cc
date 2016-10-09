#include <iostream>
using namespace std;
int main()
{
    int n,p,t,cc=0;
    while(scanf("%d%d",&p,&n),n||p)
    {
        t=1;
        while(n)
        {
            t*=n%p+1;
            t%=10000;
            n/=p;
        }
        printf("Case %d: %04d\n",++cc,t);
    }
    return 0;
}