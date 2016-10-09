#include <iostream>
using namespace std;
const int maxn=1000000;


int n,m;
int a[maxn],t;

int b[3*maxn];

void push(int x,int k,int aa,int bb)
{
    if(aa==bb-1)
        b[k]++;
    else if(x>=(aa+bb)/2)
    {
        push(x,k*2+1,(aa+bb)/2,bb);
        b[k]++;
    }
    else
    {
        t+=b[2*k+1];
        push(x,k*2,aa,(aa+bb)/2);
        b[k]++;
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m),n||m)
    {
        n*=m;
        t=0;
        for(i=0;i<3*n;i++)
            b[i]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0)
                t=(n/m-(i+m-1)/m)+m-1-(i-1)%m;
        }
        for(i=1;i<=n;i++)    
            push(a[i],1,0,n);
        if((t&1)==(n&1))
            printf("NO\n");
        else
            printf("YES\n");
    };
    return 0;
}
