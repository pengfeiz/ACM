#include <iostream>
using namespace std;

int a[1005000],d[1005000],c[1005000],cc[1005000],x,y,z;

struct gao
{
    int a[21];
};

int n;
int nn[21],m[21];
char s[1005000];


void change1(int x,gao &p)
{
    int i,t=x;
    for(i=0;i<n;i++)
    {
        p.a[i]=t/m[i];
        t%=m[i];
    }
}
void change2(gao p,int &x)
{
    int i,t=0;
    for(i=0;i<n;i++)
        t+=p.a[i]*m[i];
    x=t;
}


void bfs(int p,int q)
{
    int n1,n2,i,x,j,xx;
    gao h;
    memset(d,127,sizeof(d));
    d[p]=0;
    c[0]=p;
    n1=1;
    while(n1&&d[q]>9999999)
    {
        n2=0;
        for(i=0;i<n1;i++)
        {
            x=c[i];
            change1(x,h);
            for(j=0;j<n;j++)
            {
                h.a[j]++;
                if(h.a[j]>=0&&h.a[j]<nn[j])
                {
                    change2(h,xx);
                    if(d[xx]>d[x]+1&&a[xx])
                    {
                        d[xx]=d[x]+1;
                        cc[n2++]=xx;
                    }
                }
                h.a[j]--;
                h.a[j]--;
                if(h.a[j]>=0&&h.a[j]<nn[j])
                {
                    change2(h,xx);
                    if(d[xx]>d[x]+1&&a[xx])
                    {
                        d[xx]=d[x]+1;
                        cc[n2++]=xx;
                    }
                }
                h.a[j]++;
            }
        }
        n1=n2;
        for(i=0;i<n1;i++)
            c[i]=cc[i];
    }
}

void solve()
{
    int t=0;
    if(x<0||y<0||z<0)
    {    
        printf("No solution. Poor Theseus!\n");
        return ;
    }
    bfs(x,y);
    if(d[y]<9999999)
    {       
        t+=d[y];
        a[z]=1;
        bfs(y,z);
        if(d[z]<9999999)
        {
            t+=d[z];
            bfs(z,x);
            if(d[x]<9999999)
                printf("Theseus needs %d steps.\n",t+d[x]);
            else
                printf("No solution. Poor Theseus!\n");
        }
        else            
            printf("No solution. Poor Theseus!\n");
    }
    else
        printf("No solution. Poor Theseus!\n");
}



void build(int tt,int t)
{
    int i,l;
    if(tt==n-1)
    {
        scanf("%s",s);
        for(i=0;i<nn[n-1];i++)
        {
            if(s[i]=='#')
                a[i+t]=0;
            else if(s[i]=='.')
                a[i+t]=1;
            else if(s[i]=='T')
            {
                x=t+i;
                a[i+t]=1;
            }
            else if(s[i]=='S')
            {
                y=t+i;
                a[i+t]=1;
            }
            else if(s[i]=='M')
            {
                z=t+i;
                a[i+t]=0;
            }
        }
        return;
    }
    for(i=0;i<nn[tt];i++)
        build(tt+1,i*m[tt]+t);
}

void init()
{
    int i;
    x=y=z=-1;
    scanf("%d",&n);
    if(!n)
        exit(0);
    for(i=n-1;i>=0;i--)
        scanf("%d",&nn[i]);
    m[n-1]=1;
    for(i=n-2;i>=0;i--)
        m[i]=m[i+1]*nn[i+1];
    build(0,0);
}


int main()
{
    while(true)
    {
        init();
        solve();
    }
    return 0;
}
