#include <iostream>
using namespace std;

int a[21][21];
struct gao
{
    int x,y;
}b[4]={0,-1,-1,-1,-1,0,-1,1};

int main()
{
    int t,i,k,tt,q,j;
    int t1,t2,p,x,y;
    int f;
    scanf("%d",&t);
    while(t--)
    {
        f=0;
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
        
        if(t1==t2)
            p=2;
        else
            p=1;
        for(i=1;i<=19;i++)
            for(j=1;j<=19;j++)
            {
                if(a[j][i]==p)
                {
                    for(k=0;k<3;k++)
                    {
                        tt=1;
                        q=1;
                        while(a[j+b[k].x*q][i+b[k].y*q]==p)
                        {
                            tt++;
                            q++;
                        }
                        q=1;
                        while(a[j-b[k].x*q][i-b[k].y*q]==p)
                        {
                            tt++;
                            q++;
                        }
                        if(tt==5)
                        {
                            if(f==0)
                            {
                                x=j;
                                y=i;
                            }
                            f=1;
                        }
                        if(tt>5)
                            f=2;
                    }
                }
            }
        if(f==1)
        {
            printf("%d\n",p);
            printf("%d %d\n",x,y);
        }
        else
            printf("0\n");
        
    }
    return 0;
}
