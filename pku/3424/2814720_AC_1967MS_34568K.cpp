#include<cstdio>
#include<algorithm>
#include<set>

const   int     maxn=1001;
const   int     maxm=201;
const   int     maxx=300;
const   int     maxy=300;

int     map[maxn][maxn];
struct  pnode
{
    int x,y;
};

pnode   point[maxm];
int     ptail;
int     mmx,mmy;

void    color(int   x,int   y,int   c)
{
    int i,j;
    
    for (i=x;i<x+100;i++)
        for (j=y;j<y+100;j++)
            map[i][j]=c;
}

void    init()
{
    int i,mx,my;
    
    scanf("%d",&ptail);
    mx=0x7fffffff;
    my=0x7fffffff;

    
    for (i=1;i<=ptail;i++)
    {
        scanf("%d%d",&point[i].y,&point[i].x);
        
        if (point[i].x<mx)
            mx=point[i].x;
        if (point[i].y<my)
            my=point[i].y;
    }
    
 
    
    mmx=0;
    mmy=0;
    for (i=1;i<=ptail;i++)
    {
        point[i].x-=mx;    
        point[i].y-=my;

        if ((point[i].x>maxx)||(point[i].y>maxy))
        {
            printf("NONE\n");
            exit(0);
        }
        if (point[i].x>mmx)
            mmx=point[i].x;
        if (point[i].y>mmy)
            mmy=point[i].y;      
    }
  
}

struct  anode
{
    int     q[maxm];
    int     qtail;
    
    friend  bool    operator==(anode a,anode b)
    {
        int i;
        
        for (i=1;i<=a.qtail;i++)
            if (a.q[i]!=b.q[i])
                return(false);
        return(true);
    }
    
    friend  bool    operator<(anode a,anode b)
    {
        int i;
        
        for (i=1;i<=a.qtail;i++)
            if (a.q[i]!=b.q[i])
                return(a.q[i]<b.q[i]);
        return(false);
    }
};

anode   ans,t;

std::set<anode>   fuck;


bool   check(int   x,int   y)
{
    int     i,tx,ty;
    
    t.qtail=0;
    
    for (i=1;i<=ptail;i++)
    {
        tx=x+point[i].x;
        ty=y+point[i].y;
        
        if ((tx<1)||(tx>maxx)||(ty<1)||(ty>maxy))
            return false;
        t.qtail++;
        t.q[t.qtail]=map[tx][ty];
    }
 
    if (t==ans)
        return false;
/*   for (i=1;i<=ptail;i++)
        printf("%d",t.q[i]);
    printf("\n");*/
    
    return true;
}

void    gogogo(int  x,int   y)
{
    int i,j;
    bool ff;
    for (i=1;i<=x;i++)
    {
        ff=false;
        for (j=y;j>0;j--)
        {
            if(check(i,j))
            {   
                if(fuck.find(t)!=fuck.end()&&!ff)
                    break;
                ff=true;
                ans=t;
                fuck.insert(t);
            }
        }
    }    
            
}

void    starmain()
{
    int i,j;
    
    fuck.clear();
    
    ans.q[1]=-1;
    
    gogogo(300,300);

    
    std::set<anode>::iterator   iter;
    
    if(fuck.empty())
        printf("NONE\n");
    else
        for (iter=fuck.begin();iter!=fuck.end();iter++)
        {
            for (i=1;i<=ptail;i++)
                printf("%d",(*iter).q[i]);
            printf("\n");
        }
            
 }
int     main()
{
    
    color(1,1,7);
    color(1,101,8);
    color(1,201,9);
    
    color(101,1,4);
    color(101,101,5);
    color(101,201,6);
    
    color(201,1,1);
    color(201,101,2);
    color(201,201,3);
    
    
    init();
    starmain();
    
    
    return(0);
}
