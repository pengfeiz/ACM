#include <iostream>
#include <cmath>
using namespace std;

#define esp 1e-7

struct poi
{
    double x,y;
}p;

struct gra
{
    char c;
    int n;
    poi a[25];
}q[30];

int n;
char c[2];


double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double dian(double x1,double y1,double x2,double y2)
{return x1*x2+y1*y2;}
bool com(gra a,gra b)
{return a.c<b.c;}
void jiao(poi pa,poi pb,poi pc,poi pd,poi &p)
{
    double s1,s2;
    s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
    s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
    p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
    p.y=(s1*pb.y+s2*pa.y)/(s1+s2);
}
bool jjudge(poi pa,poi pb,poi pc,poi pd)
{
    if(fabs(cha(pa.x-pb.x,pa.y-pb.y,pc.x-pd.y,pc.y-pd.y))<esp)
        return false;
    jiao(pa,pb,pc,pd,p);
    if(dian(pa.x-p.x,pa.y-p.y,p.x-pb.x,p.y-pb.y)>-esp&&dian(pc.x-p.x,pc.y-p.y,p.x-pd.x,p.y-pd.y)>-esp)
        return true;
    return false;
}

void dosth(char s[20],int n)
{
    q[n].c=c[0];
    scanf("%s",s);
    double x1,y1,x2,y2,xx,yy;
    int i;
    
        if(strcmp(s,"square")==0)
        {
            q[n].n=4;
            scanf(" (%lf,%lf)",&x1,&y1);
            scanf(" (%lf,%lf)",&x2,&y2);
            q[n].a[0].x=x1;
            q[n].a[0].y=y1;
            q[n].a[2].x=x2;
            q[n].a[2].y=y2;
            xx=(x1+x2)/2.0;
            yy=(y1+y2)/2.0;
            x2-=x1;
            y2-=y1;
            x2/=2;
            y2/=2;
            q[n].a[1].x=xx+y2;
            q[n].a[1].y=yy-x2;
            q[n].a[3].x=xx-y2;
            q[n].a[3].y=yy+x2;
        }
        else if(strcmp(s,"line")==0)
        {
            q[n].n=2;            
            scanf(" (%lf,%lf)",&x1,&y1);
            scanf(" (%lf,%lf)",&x2,&y2);
            q[n].a[0].x=x1;
            q[n].a[1].x=x2;
            q[n].a[0].y=y1;
            q[n].a[1].y=y2;
        }
        else if(strcmp(s,"triangle")==0)
        {
            q[n].n=0;            
            scanf(" (%lf,%lf)",&x1,&y1);
            q[n].a[q[n].n].x=x1;
            q[n].a[q[n].n].y=y1;
            q[n].n++; 
            scanf(" (%lf,%lf)",&x1,&y1);
            q[n].a[q[n].n].x=x1;
            q[n].a[q[n].n].y=y1;
            q[n].n++;
            scanf(" (%lf,%lf)",&x1,&y1);
            q[n].a[q[n].n].x=x1;
            q[n].a[q[n].n].y=y1;
            q[n].n++;            
        }
        else if(strcmp(s,"rectangle")==0)
        {
            q[n].n=0;          
            scanf(" (%lf,%lf)",&x1,&y1);
            q[n].a[q[n].n].x=x1;
            q[n].a[q[n].n].y=y1;
            q[n].n++; 
            scanf(" (%lf,%lf)",&x1,&y1);
            q[n].a[q[n].n].x=x1;
            q[n].a[q[n].n].y=y1;
            q[n].n++;
            scanf(" (%lf,%lf)",&x1,&y1);
            q[n].a[q[n].n].x=x1;
            q[n].a[q[n].n].y=y1;
            q[n].n++;
            q[n].a[q[n].n].x=q[n].a[2].x+q[n].a[0].x-q[n].a[1].x;
            q[n].a[q[n].n].y=q[n].a[2].y+q[n].a[0].y-q[n].a[1].y;
            q[n].n++;
        }
        else
        {
            scanf("%d",&q[n].n);
            for(i=0;i<q[n].n;i++)
            {
                scanf(" (%lf,%lf)",&x1,&y1);
                q[n].a[i].x=x1;
                q[n].a[i].y=y1;
            }
        }
}

bool judge(gra a,gra b)
{
    int i,j;
    for(i=0;i<a.n;i++)
        for(j=0;j<b.n;j++)
            if(jjudge(a.a[i],a.a[(i+1)%a.n],b.a[j],b.a[(j+1)%b.n]))
                return true;
    return false;
}


int main()
{
    int i,j,t,l;
    char s[20];
    bool f[30];
    int cc[30];
    
    while(scanf("%s",&c),strcmp(c,"."))
    {
        memset(f,0,sizeof(f));
        n=1;
        dosth(s,0);
        while(scanf("%s",&c),strcmp(c,"-"))
            dosth(s,n++);
        sort(q,q+n,com);
        for(j=0;j<n;j++)
        {
            t=0;
            for(i=0;i<n;i++)
            {
                if(i==j)
                    continue;
                if(judge(q[j],q[i]))
                    cc[t++]=i;
            }
            if(!t)
                printf("%c has no intersections\n",q[j].c);
            else
            {
                printf("%c intersects with ",q[j].c);
                if(t==1)
                    printf("%c\n",q[cc[0]].c);
                else if(t==2)
                    printf("%c and %c\n",q[cc[0]].c,q[cc[1]].c);
                else
                {
                    for(i=0;i<t-1;i++)
                        printf("%c, ",q[cc[i]].c);
                    printf("and %c\n",q[cc[t-1]].c);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

