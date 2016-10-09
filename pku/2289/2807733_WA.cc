#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> a[1001];
bool marked[1001];
int y[1001];

bool search(int v)
{
    vector<int>::iterator p;
    if(marked[v])
        return false;
    marked[v]=true;
    p=a[v].begin();
    while(p!=a[v].end())
    {
        if(!y[*p]||search(y[*p]))
        {
            y[*p]=v;
            return true;
        }
        p++;
    }
}

int main()
{
    char s[25];
    int x,i,j,t;
    int r,l,k;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            while(getchar()!='\n')
            {
                scanf("%d",&x);
                a[x].push_back(x);
            }
        }
        r=1;
        l=n;
        while(r<l)
        {
            memset(y,0,sizeof(y));
            k=(r+l)/2;
            t=0;
            for(i=0;i<m;i++)
            {
                memset(marked,0,sizeof(marked));
                for(j=0;j<k;j++)
                {
                    if(search(i))
                        t++;
                }
            }
            if(t==n)
                r=k+1;
            else
                l=k;
        }
        printf("%d\n",r+1);
    }
    return 0;
}
