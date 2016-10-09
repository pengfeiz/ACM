#include <iostream>
#include <vector>
using namespace std;


int n,k,m;

int a[101];
bool c[101][1001];
vector<int> b[1001]; 
bool d[1001];


void dosth(int x,int y)
{
    if(c[y][x])
        return;
    int i;
    vector<int>::iterator p;
    c[y][x]=true;
    p=b[x].begin();
    while(p!=b[x].end())
    {
        dosth(*p,y);
        p++;
    }
    
}


int main()
{
 //   freopen("c:\\in.txt","r",stdin);
    int i,j;
    int x,y;
    memset(c,0,sizeof(c));
    for(i=0;i<1001;i++)
        d[i]=true;
    scanf("%d%d%d",&k,&n,&m);
    for(i=0;i<k;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        b[x].push_back(y);
    }
    for(i=0;i<k;i++)
    {
        dosth(a[i],i);
        for(j=1;j<=n;j++)
            if(!c[i][j])
                d[j]=false;
    }
    i=0;
    for(j=1;j<=n;j++)
        if(d[j])
            i++;
    printf("%d\n",i);
    return 0;
}
