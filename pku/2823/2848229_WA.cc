#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=100001;

struct gao1
{int x,n;};
struct gao2
{int x,n;};

priority_queue<gao1>dq;
priority_queue<gao2>dl;

bool operator <(const gao1 &a,const gao1 &b)
{return a.x<b.x;}
bool operator <(const gao2 &a,const gao2 &b)
{return a.x>b.x;}
bool com(int a,int b)
{return a<b;}


int a[maxn],b[maxn],c[maxn];

int main()
{
    int n,k,i,m;
    gao1 h1,hh1;
    gao2 h2,hh2;
    scanf("%d%d",&n,&k);
    m=0;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<k-1;i++)
    {
        hh1.n=i;
        hh1.x=a[i];
        dq.push(hh1);
    }
    for(i=k-1;i<n;i++)
    {
        hh1.n=i;
        hh1.x=a[i];
        dq.push(hh1);
        do
        {
            h1=dq.top();
            if(h1.n<=i-k)
            {
                dq.pop();
                continue;
            }
            break;
        }while(1);
        b[m++]=h1.x;        
    }
    for(i=0;i<k-1;i++)
    {
        hh2.n=i;
        hh2.x=a[i];
        dl.push(hh2);
    }
    m=0;
    for(i=k-1;i<n;i++)
    {
        hh2.n=i;
        hh2.x=a[i];
        dl.push(hh2);
        do
        {
            h2=dl.top();
            if(h2.n<=i-k)
            {
                dl.pop();
                continue;
            }
            break;
        }while(1);
        c[m++]=h2.x;        
    }
    sort(b,b+m,com);
    sort(c,c+m,com);
    for(i=0;i<m;i++)
    {
        if(i)
            printf(" ");
        printf("%d",c[i]);
    }
    printf("\n");
    for(i=0;i<m;i++)
    {
        if(i)
            printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
    return 0;
}
