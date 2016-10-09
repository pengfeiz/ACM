#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


#define MAX 17
#define esp 1e-8


struct poi
{
	double x,y,v,l;
	int n;
}a[MAX],q[MAX];


int nn,n,m,d[MAX],p;
int b[MAX],xx[MAX];
bool u[MAX];

void copy(poi &a,poi &b)
{
	a.x=b.x;
	a.y=b.y;
	a.n=b.n;
	a.v=b.v;
	a.l=b.l;
}

bool com(poi a,poi b)
{
	if(fabs(a.y-b.y)>esp)
		return a.y<b.y;
	return a.x<b.x;
}

bool cha(double x1,double y1,double x2,double y2)
{
	double x;
	x=x1*y2-x2*y1;
	if(x>esp)
		return true;
	return false;
}

void tubao()
{
	int i;
/*	if(n==1)
	{
		p=2;
		d[1]=1;
		return;
	}
	if(n==2)
	{
		p=3;
		d[1]=1;
		d[2]=2;
		return;
	}*/
	memset(u,0,sizeof(u));
	d[1]=1;
	d[2]=p=2;
	u[2]=true;
	for(i=3;i<=n;i++)
	{
		while( p>1 && cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y))
			u[d[p--]]=false;
		d[++p]=i;
		u[i]=true;
	}
	for(i=n;i>0;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y))
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
}

double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{return sqrt(ll(a.x-b.x)+ll(a.y-b.y));}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,mn,tim=0;
	double v,l,mv,ll,ml;
	for(i=1;i<=16;i++)
		xx[i]=1<<(i-1);
	while(scanf("%d",&nn),nn)
	{
		mn=0;
		mv=99999999999.0;
		for(i=1;i<=nn;i++)
		{
			scanf("%lf%lf%lf%lf",&q[i].x,&q[i].y,&q[i].v,&q[i].l);
			q[i].n=i;
		}
		sort(q+1,q+nn+1,com);
		m=1<<nn;
		for(i=1;i<m;i++)
		{
			n=0;
			v=ll=0.0;
			for(j=1;j<=nn;j++)
			{
				if(!(xx[j]&i))
				{
					n++;
					copy(a[n],q[j]);
				}
				else
				{
					v+=q[j].v;
					ll+=q[j].l;
				}
			}
			if(v>mv+esp)
				continue;
			else
			{
				tubao();
				d[p]=d[1];
				l=0;
				for(j=1;j<p;j++)
					l+=dis(a[d[j]],a[d[j+1]]);
				if(l>ll+esp)
					continue;
				if(fabs(v-mv)<esp&&p>mn)
					continue;
				memset(u,0,sizeof(u));
				mv=v;
				ml=ll-l;
				for(j=1;j<=n;j++)
					u[a[j].n]=true;
				mn=0;
				for(j=1;j<=nn;j++)
					if(!u[j])
						b[++mn]=j;
			}
		}
		printf("Forest %d\n",++tim);
		printf("Cut these trees:");
		for(i=1;i<=mn;i++)
			printf(" %d",b[i]);
		printf("\nExtra wood: %.2lf\n\n",ml);
	}
	return 0;
}
