#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> a[1001];
int marked[1001],k;
int y[1001];

bool search(int v)
{
    vector<int>::iterator p;
    if(marked[v]==k)
        return false;
    marked[v]++;
    p=a[v].begin();
    while(p!=a[v].end())
    {
        if(y[*p]==-1||search(y[*p]))
        {
            y[*p]=v;
            return true;
        }
        p++;
    }
    return false;
}

int main()
{
    char s[25];
    int x,i,j,t;
    int r,l;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            while(getchar()!='\n')
            {
                scanf("%d",&x);
                a[x].push_back(i);
            }
        }
        r=1;
        l=n;
        while(r<l)
        {
            memset(y,0xff,sizeof(y));
            k=(r+l)/2;
            t=0;
            for(i=0;i<m;i++)
            {
                memset(marked,0,sizeof(marked));
                for(j=0;j<k;j++)
                {
                    if(search(i))
                        t++;
                    else
                        break;
                }
            }
            if(t==n)
                l=k;
            else
                r=k+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
