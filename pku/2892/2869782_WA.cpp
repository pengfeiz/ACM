//离散化+中间过程

#include <iostream>
#include <algorithm>
using namespace std;


struct gao
{
	int l,r;
	int h;
	bool f;
}a[60001];

int n,m;

struct gao2
{
	int x,y,h;
}b[50002],bb;
bool cc[50002];



int maxx(int a,int b)
{return a>b?a:b;}


void build(int x,int l,int r)
{
	a[x].h=0;
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
                    dosth(2*x+1,r,a[x].r,a[x].h);
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
			dosth(2*x,r,(a[x].l+a[x].r)/2,a[x].h);
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
int find(int x,int l,int r,int t)
{
        int xx;
	if(l==r)
		return 0;
	if(a[x].l<=l&&a[x].r>=r&&a[x].f)
        {
            if(t==a[x].h)
                return a[x].r-l;
            else
                return 0;
        }
	if(l>=(a[x].l+a[x].r)/2)
            return find(2*x+1,l,r,t);
	else if(r<=(a[x].l+a[x].r)/2)
            return find(2*x,l,r,t);
        else
        {
            xx=find(2*x,l,(a[x].l+a[x].r)/2,t);
            xx+=find(2*x+1,(a[x].l+a[x].r)/2,r,t);
            return xx;
        }
        return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	int maxx,t;
        char c[3];
        while(scanf("%d%d",&m,&n)!=EOF)
        {
            memset(cc,0,sizeof(cc));
            maxx=0;
            build(1,1,m+1);
            t=0;
            for(i=0;i<n;i++)
            {
                scanf("%s",cc);
                if(cc[0]=='D')
                {
                    t++;
                    scanf("%d",&b[t].x);
                    b[t].y=b[t].x+1;
                    b[t].h=1;
                    dosth(1,b[t].x,b[t].y,b[t].h);
                }
                else if(cc[0]=='R')
                {
                    b[t].h=0;
                    dosth(1,b[t].x,b[t].y,b[t].h);
                    t--;
                }
                else
                {
                    scanf("%d",&bb.x);
                    bb.y=m;
                    bb.h=0;
                    printf("%d\n",find(1,bb.x,bb.y,bb.h));
                }
            }
        }
	return 0;
}
