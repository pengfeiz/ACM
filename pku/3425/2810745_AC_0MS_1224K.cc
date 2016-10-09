#include <iostream>
using namespace std;
bool q[1000001];

int main()
{
    int i,n,x,y,z,t=0;
    memset(q,0,sizeof(q));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(y&&z)
        {
            t+=40;
            if(q[x])
                t+=10;
        }
        else if(y&&!z)
        {
            t+=20;
            if(q[x])
                t+=10;
        }
        else
            t+=10;
        q[x]=true;
    }
    printf("%d\n",t);
    return 0;
}