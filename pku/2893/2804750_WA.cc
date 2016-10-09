#include <iostream>
using namespace std;
const int maxn=1000000;


int n,m;
int a[maxn],t;

int b[4*maxn];

void push(int x,int k,int aa,int bb)
{
    if(aa==bb-1)
        b[k]++;
    else if(x>=(aa+bb)/2)
    {
        push(x,k*2+1,(aa+bb)/2,bb);
        b[k]++;
    }
    else if(x<(aa+bb)/2)
    {
        t+=b[2*k+1];
        push(x,k*2,aa,(aa+bb)/2);
        b[k]++;
    }
}

int main()
{
 //   freopen("c:\\in.txt","r",stdin);
    int i,j;
    while(scanf("%d%d",&n,&m),n||m)
    {
        n*=m;
        t=0;
        for(i=0;i<4*n;i++)
            b[i]=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)    
            push(a[i],i,0,n);
        if((t&1)==((n*m-1)&1))
            printf("YES\n");
        else
            printf("NO\n");
    };
    return 0;
}