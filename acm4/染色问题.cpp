//离散化+中间过程

#include <iostream>
#include <algorithm>
using namespace std;


struct gao
{
	int l,r;
	int h;
	bool f;
}a[100001];

int n,m,t;

struct gao2
{
	int x,y,h;
}b[10002];
bool cc[10002];

int p[20100];


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
void find(int x,int l,int r)
{
		if(l==r)
			return;
		if(a[x].l<=l&&a[x].r>=r&&a[x].f)
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

int main()
{
	//	freopen("in.txt","r",stdin);
		int i;
		int tt,maxx,m;
		scanf("%d",&tt);
        while(tt--)
        {
            memset(cc,0,sizeof(cc));
            maxx=0;
            scanf("%d%d",&n,&m);
            for(i=0;i<m;i++)
            {
                    scanf("%d%d",&b[i].x,&b[i].y);
                    if(b[i].x>b[i].y)
                        swap(b[i].x,b[i].y);
                    b[i].h=i+1;
                    p[i*2]=b[i].x;
                    b[i].y++;
                    p[i*2+1]=b[i].y;
            }
            m=0;

            sort(p,p+2*n);
            p[2*n]=-1;
            for(i=0;i<2*n;i++)
                    if(p[i]!=p[i+1])
                            p[m++]=p[i];

            for(i=0;i<n;i++)
            {
                    b[i].x=lower_bound(p,p+m,b[i].x)-p;
                    b[i].y=lower_bound(p,p+m,b[i].y)-p;
            }

            build(1,0,m-1);
            for(i=0;i<n;i++)
                 dosth(1,b[i].x,b[i].y,b[i].h);
            
			t=0;
            cc[0]=true;
            find(1,0,m-1);
			printf("%d\n",t);
            
        }
		return 0;
}
