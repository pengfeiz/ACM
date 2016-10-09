#include <iostream>
#include <algorithm>
using namespace std;


struct gao
{
	int l,r;
	int h;
        bool f;
}a[300006];

int n,m,t;

struct gao2
{
	int x,y,h;
}b;
bool cc[32];


//build线段树
void build(int x,int l,int r)
{
	a[x].h=1;
	a[x].l=l;
	a[x].r=r;
        a[x].f=true;
	if(l==r-1)
		return;
	build(2*x,l,(l+r)/2);
	build(2*x+1,(l+r)/2,r);
}


//中间过程
void dosth(int x,int l,int r,int h)
{
        if(l==r)
            return;
	if(a[x].l==l&&a[x].r==r)
	{
                a[x].f=true;
		a[x].h=h;
		return;
	}
        if(a[x].f&&a[x].h==h)
            return;
        //分情况讨论
	if(l>=(a[x].l+a[x].r)/2)
        {
            if(a[x].f)
            {
                dosth(2*x,a[x].l,(a[x].l+a[x].r)/2,a[x].h);
                dosth(2*x+1,(a[x].l+a[x].r)/2,l,a[x].h);
            }
            a[x].f=false;
            dosth(2*x+1,l,r,h);
        }
	else if(r<=(a[x].l+a[x].r)/2)
        {
            if(a[x].f)
            {
                dosth(2*x+1,(a[x].l+a[x].r)/2,a[x].r,a[x].h);
                dosth(2*x,a[x].l,l,a[x].h);	
            }
            a[x].f=false;
            dosth(2*x,l,r,h);
        }
	else
	{
            if(a[x].f)
            { 
                dosth(2*x,a[x].l,l,a[x].h);
                dosth(2*x+1,r,a[x].r,a[x].h);
            }
            a[x].f=false;
            dosth(2*x,l,(a[x].l+a[x].r)/2,h);
            dosth(2*x+1,(a[x].l+a[x].r)/2,r,h);
	}
        //这里进行合并
        if(a[2*x].f&&a[2*x+1].f&&a[2*x].h==a[2*x+1].h)
        {
            a[x].f=true;
            a[x].h=h;
        }
}


//查找过程
void find(int x,int l,int r)
{
        if(l==r)
            return;
	if(a[x].l==l&&a[x].r==r&&a[x].f)
        {
            if(!cc[a[x].h])
            {
                t++;
                cc[a[x].h]=true;
            }
//          return a[x].h;
            return;
        }
	if(l>=(a[x].l+a[x].r)/2)
            find(2*x+1,l,r);
	else if(r<=(a[x].l+a[x].r)/2)
            find(2*x,l,r);
        else
        {
            find(2*x,l,(a[x].l+a[x].r)/2);
            find(2*x+1,(a[x].l+a[x].r)/2,r);
        }            
}


//主函数
int main()
{
	int i;
	int tt;
        char s[3];scanf("%d%d%d",&n,&i,&tt);
//        while(scanf("%d%d%d",&n,&i,&tt)!=EOF)
        {
            build(1,1,n+1);
            for(i=0;i<tt;i++)
            {
                    scanf("%s",s);
                    if(s[0]=='C')
                    {
                        scanf("%d%d%d",&b.x,&b.y,&b.h);
                        if(b.x>b.y)
                            swap(b.x,b.y);
                        b.y++;
                        dosth(1,b.x,b.y,b.h);
                    }
                    else
                    {
                        scanf("%d%d",&b.x,&b.y);
                        if(b.x>b.y)
                            swap(b.x,b.y);
                        b.y++;
                        memset(cc,0,sizeof(cc));
                        t=0;
                        find(1,b.x,b.y);
                        printf("%d\n",t);
                    }
            }
        }
	return 0;
}
