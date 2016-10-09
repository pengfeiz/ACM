#include<cstdio>
#include<algorithm>

const   int     maxn=501;
const   int     maxm=100001;

int     coin1[maxn];
int     ctail1;

int     coin2[maxn];
int     ctail2;

int     goal;

bool com(int a,int b)
{return a>b;}
void    init()
{
    double  t;
    int     i,c;
    
    
    ctail1=0;
    ctail2=0;
    
    scanf("%lf\n",&t);
    if (t<0)
        exit(0);
    goal=(int)(t*100+0.1);
 
    
    while(true)
    {
        scanf("%lf",&t);
        if (t<0)
            break;
        scanf("%dx\n",&c);
        for (i=1;i<=c;i++)
        {
            ctail1++;
            coin1[ctail1]=t*100+0.1;
        }
    }
    scanf("\n");
    while(true)
    {
        scanf("%lf",&t);
        if (t<0)
            break;
        scanf("%dx\n",&c);
        for (i=1;i<=c;i++)
        {
            ctail2++;
            coin2[ctail2]=t*100+0.1;
        }
    }
    scanf("\n");
}


int     f1[maxm];
int     f2[maxm];

int     q[maxm];
int     qtail;
int     max;

void    cal(int coin[],int  ctail,int   f[])
{
    int i,j,qq;
    
    memset(f,127,sizeof(*f)*max);
    f[0]=0;
    qtail=1;
    q[qtail]=0;
    
    for (i=1;i<=ctail;i++)
        for (j=qtail;j>0;j--)
        {
            qq=q[j]+coin[i];
            if (!(f[qq]^0x7f7f7f7f))
            {
                qtail++;
                q[qtail]=q[j]+coin[i];
                f[qq]=f[q[j]]+1;
            }
            else    if (f[q[j]]+1<f[qq])
                f[qq]=f[q[j]]+1; 
}   
}

void    starmain()
{
    int     i,ans,q;
    max=0;

    for(i=1;i<=ctail1;i++)
        max+=coin1[i];
    
    std::sort(coin1,coin1+ctail1,com);
    std::sort(coin2,coin2+ctail2,com);
    cal(coin1,ctail1,f1);
    cal(coin2,ctail2,f2);
    
    ans=0x7f7f7f7f;
    for (i=goal;i<=max;i++)
    {
        q=ans-f2[i-goal];
        if(f1[i]<q)
            ans=f1[i]+f2[i-goal];
    }
    if(ans!=0x7f7f7f7f)
        printf("%d tenders must be exchanged.\n",ans);
    else
        printf("The payment is impossible.\n");
}
int     main()
{
    //freopen("/export/team41/f/f.out","w",stdout);
    
    while(true)
    {
        init();
        starmain();
    }
    
    return(0);
}

