#include<cstdio>
#include<algorithm>

const   int     maxn=2000001;
const   int     max=1000000;

int     q[5];

bool    f[maxn];

int	gcd(int a,int   b)
{
	int t;
		
	while (b)
	{
		t=a;
		a=b;
		b=t%b;
	}
	
	return(a);
}

void    starmain()
{
    int i,j,total,t,d,ans;
    
    total=0;
    memset(f,0,sizeof(f));
    f[0]=true;
    ans=0;
    for (i=1;i<maxn;i++)
    {
        for (j=1;j<=4;j++)
            if (i-q[j]>=0)
                f[i]|=f[i-q[j]];
        if (!f[i])
        {
            if (i<=max)   
                total++;         
                ans=i;
        }
    }
    printf("%d\n",total);
    if (ans>=max)
        printf("--1\n");
    else
        printf("%d\n",ans);
    
    /*
    
    
    d=gcd(gcd(q[1],q[2]),q[3]);
    
    t=(2*q[1]*q[2]*q[3])/(d*d)+q[4]*d-q[1]-q[2]-q[3]-q[4];
    
    if (t>=maxn)
        printf("--1\n");
    else
        printf("%d\n",t);
     */
}

int     main()
{
    int     t;
    
  //  freopen("c:\\in.txt","r",stdin);
    
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d %d %d %d\n",&q[1],&q[2],&q[3],&q[4]);
        starmain();
    }
    
    return(0);
}
