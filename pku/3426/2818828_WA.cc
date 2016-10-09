#include <iostream>
using namespace std;
#define maxn 1002

int a[maxn][maxn][5];
int b[maxn][maxn][2];
int n;

struct gao
{
    int x,y,z;
}c[maxn*maxn],cc[maxn*maxn],d[5]={0,0,0,0,1,0,1,0,0,0,-1,0,-1,0,0};
int n1,n2;

bool judge(int x,int y,int z,int k)
{
    int i;
    bool ff[5];
    for(i=1;i<=4;i++)
        ff[i]=true;
}

void bfs()
{
    int i,j,tim=1,x,y;
    n1=1;
    c[0].x=c[0].y=1;
    c[0].z=0;
    while(n1)
    {
        tim++;
        n2=0;
        for(i=0;i<n1;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(judge(c[i].x,c[i].y,c[i].z,j))
                    continue;
                x=c[i].x+d[j].x;
                y=c[i].y+d[j].y;
                if(x<=0||y<=0||x>n||y>n)
                    continue;
                if(a[x][y][j]<=tim)
                    continue;
                a[x][y][i]==tim;
                cc[n2].x=x;
                cc[n2].y=y;
                cc[n2].z=j;
                n2++;
            }
        }
        n1=n2;
        for(i=0;i<n1;i++)
        {
            c[i].x=cc[i].x;
            c[i].y=cc[i].y;
            c[i].z=cc[i].z;
        }
    }
}


int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d%d",&b[i][j][0],&b[i][j][1]);
    
    memset(a,127,sizeof(a));
    
    a[1][1][0]=1;
    bfs();
    
    return 0;
}
