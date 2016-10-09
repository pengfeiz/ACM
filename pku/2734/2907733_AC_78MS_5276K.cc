#include <iostream>
using namespace std;

#define maxn 110

int n,m;
int nq,nk,np;
struct gao
{
    int x,y;
}q[maxn],p[maxn],k[maxn],e[8]={1,2,2,1,1,-2,-2,1,-1,-2,-2,-1,-1,2,2,-1},ff[8]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};

int a[1010][1010];
bool b[1010][1010];

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,t,x,y,cc=0;
    while(scanf("%d%d",&n,&m),n||m)
    {
        t=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&nq);
        for(i=0;i<nq;i++)
        {
            scanf("%d%d",&q[i].x,&q[i].y);
            b[q[i].x][q[i].y]=a[q[i].x][q[i].y]=true;
        }
        scanf("%d",&nk);
        for(i=0;i<nk;i++)
        {
            scanf("%d%d",&k[i].x,&k[i].y);
            b[k[i].x][k[i].y]=a[k[i].x][k[i].y]=true;
        }
        scanf("%d",&np);
        for(i=0;i<np;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            b[p[i].x][p[i].y]=a[p[i].x][p[i].y]=true;
        }
        for(i=0;i<nk;i++)
        {
            for(j=0;j<8;j++)
            {
                x=k[i].x+e[j].x;
                y=k[i].y+e[j].y;
                if(x>n||x<=0||y>m||y<=0)
                    continue;
                a[x][y]=true;
            }
        }
        for(i=0;i<nq;i++)
        {
            for(j=0;j<8;j++)
            {
                x=q[i].x;
                y=q[i].y;
                while(1)
                {
                    x+=ff[j].x;
                    y+=ff[j].y;
                    if(x>n||x<=0||y>m||y<=0)
                        break;
                    if(b[x][y])
                        break;
                    a[x][y]=true;
                }
            }
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(!a[i][j])
                    t++;
       
        printf("Board %d has %d safe squares.\n",++cc,t);
                
    }
        
    return 0;
}
