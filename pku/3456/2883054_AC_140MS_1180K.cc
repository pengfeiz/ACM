#include<cstdio>
#include<algorithm>

const   int     maxn=1010001;
const   int     max=1000001;

int     q[5];

bool    f[maxn];

void    starmain()
{
    int i,j,total,ans;
    
    total=0;
    memset(f,0,sizeof(f));
    f[0]=true;
    ans=0;
    for (i=1;i<maxn;i++)
    {
        for (j=1;j<=4;j++)
            if ((i-q[j]>=0)&&(f[i-q[j]]))
            {
                f[i]|=true;
                break;
            }
        if (!f[i])
        {
            if (i<max)
                total++;
            ans=i;
        }
    }
    printf("%d\n",total);
    
    if ((ans<max)&&(total))
        printf("%d\n",ans);
    else
        printf("-1\n");

}

int     main()
{
    int     t;
    
    //freopen("c:\\in.txt","r",stdin);
    
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d %d %d %d\n",&q[1],&q[2],&q[3],&q[4]);
        starmain();
    }
    
    return(0);
}
