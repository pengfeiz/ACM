#include <iostream>
using namespace std;

int a[21][21];
struct gao
{
    int x,y;
}b[4]={0,1,1,1,1,0,-1,1};

int main()
{
//    freopen("in.txt","r",stdin);
    int t,i,k,tt,q,j;
    int t1,t2,x,y;
    int f[3];
    scanf("%d",&t);
    while(t--)
    {
        memset(f,0,sizeof(f));
        t1=t2=0;
        memset(a,0,sizeof(a));
        
        for(i=1;i<=19;i++)
            for(j=1;j<=19;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==1)
                    t1++;
                else if(a[i][j]==2)
                    t2++;
            }
        for(i=1;i<=19;i++)
            for(j=1;j<=19;j++)
            {
                if(a[j][i])
                {
                    for(k=0;k<4;k++)
                    {
                        tt=1;
                        q=1;
                        while(a[j+b[k].x*q][i+b[k].y*q]==a[j][i])
                        {
                            tt++;
                            q++;
                        }
                        if(tt==5)
                        {
                            if(f[a[j][i]]==0)
                            {
                                x=j;
                                y=i;
                                f[a[j][i]]=1;
                            }
                        }
                        if(tt>5)
                            f[a[j][i]]=2;
                    }
                }
            }
        if(f[1]==1)
        {
            printf("%d\n",1);
            printf("%d %d\n",x,y);
        }
        else if(f[2]==1)
        {
            printf("%d\n",2);
            printf("%d %d\n",x,y);
        }            
        else
            printf("0\n");
        
    }
    return 0;
}
