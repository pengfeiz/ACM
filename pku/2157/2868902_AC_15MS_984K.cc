#include <iostream>
#include <vector>
using namespace std;

int a[170000],d[170000],c[170000],cc[170000],S,G,D[6];
vector<int> K[6];

struct gao
{
    int a[3];
};

int n;
int nn[3],m[3];
char s[170000];


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


void bfs(int p)
{
    int n1,n2,i,x,j,xx;
    gao h;
    memset(d,127,sizeof(d));
    d[p]=0;
    c[0]=p;
    n1=1;
    while(n1)
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
                    if(d[xx]>d[x]+1)
                    {
                        d[xx]=d[x]+1;
                        if(a[xx])
                            cc[n2++]=xx;
                    }
                }
                h.a[j]--;
                h.a[j]--;
                if(h.a[j]>=0&&h.a[j]<nn[j])
                {
                    change2(h,xx);
                    if(d[xx]>d[x]+1)
                    {
                        d[xx]=d[x]+1;
                        if(a[xx])
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
    int t=0,i;
    vector<int>::iterator p;
    for(i=0;i<5;i++)
    {
        bfs(S);
        p=K[i].begin();
        while(p!=K[i].end())
        {
            if(d[*p]>9999999)
                break;
            p++;
        }
        if(p==K[i].end()&&K[i].begin()!=K[i].end()&&d[D[i]]<9999999)
            a[D[i]]=1;
    }
    bfs(S);
    if(d[G]<9999999)
        printf("YES\n");
    else
        printf("NO\n");
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
            else if(s[i]=='G')
            {
                G=t+i;
                a[i+t]=1;
            }
            else if(s[i]=='S')
            {
                S=t+i;
                a[i+t]=1;
            }
            else if(s[i]>='a')
            {
                K[s[i]-'a'].push_back(t+i);
                a[i+t]=1;
            }
            else if(s[i]>='A')
            {
                D[s[i]-'A']=t+i;
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
    for(i=0;i<5;i++)
        K[i].clear();
    n=2;
    for(i=0;i<n;i++)
        scanf("%d",&nn[i]);
    if(!(nn[0]||nn[1]))
        exit(0);
    m[n-1]=1;
    for(i=n-2;i>=0;i--)
        m[i]=m[i+1]*nn[i+1];
    build(0,0);
}


int main()
{
   // freopen("in.txt","r",stdin);
    while(true)
    {
        init();
        solve();
    }
    return 0;
}

