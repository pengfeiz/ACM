#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define pi 3.1415926535897931
#define N 101
#define esp 1e-8

struct poi
{
	int x,y;
};

struct pnt
{
	int x,y,dis;
	double ang;
};

struct tbel
{
	int area;
	poi v;
};

int cha(poi va,poi vb)
{return va.x*vb.y-va.y*vb.x;}

poi mkv(pnt &pa,pnt &pb)
{
	poi v;
	v.x=pa.x-pb.x;
	v.y=pa.y-pb.y;
	return v;
}

double cmpta(pnt pa,pnt bsp)
{
	poi v;
	double ang;
	v=mkv(pa,bsp);
	ang=atan2(v.y,v.x);
	if(ang<0)
		ang+=2*pi;
	if(v.y==0&&v.x<0)
		ang=pi;
	return ang;
} 

bool comp(pnt pa,pnt pb)
{
	if(fabs(pa.ang-pb.ang)<esp)
		return pa.dis<pb.dis;
	return pa.ang<pb.ang;
}


void arange(pnt *p,int np,pnt bsp)
{
	int i;
	poi v;
	for(i=0;i<np;i++)
	{
		p[i].ang=cmpta(p[i],bsp);
		v=mkv(p[i],bsp);
		p[i].dis=v.x*v.x+v.y*v.y;
	}
	sort(p,p+np,comp);
}

int main()
{
	pnt wp[N],p[N],bsp;
	int np,nc;
	int i,j,k,l;
	int ta,tta,ma,mma;
	tbel tb[N][N];
	poi vnow;
	//	freopen("input.in","r",stdin);
	for(scanf("%d",&nc);nc;nc--)
	{
		scanf("%d",&np);
		for(i=0;i<np;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		mma=0;
		memcpy(wp,p,sizeof(pnt)*np);
		for(i=0;i<np;i++)
		{
			bsp=p[i];
			arange(wp,np,bsp);
			memset(tb,0,sizeof(tb));
			ma=0;
			for(j=2;j<np&&wp[j].ang<=pi;j++)
			{
				tta=0;
				for(k=j-1;k;k--)
				{
					ta=0;
					vnow=mkv(wp[j],wp[k]);
					tb[j][k].v=vnow;
					if(tb[j][k].area<0)
						continue;
					if(wp[j].ang-wp[k].ang<esp)
						continue;
					for(l = k - 1; l >= 0; l--)
					{
						if(wp[k].ang-wp[l].ang<esp)
							break;
						if(cha(vnow,tb[k][l].v)>0)
						{
							tb[j][l].area=-1;
							continue;
						}
						if(tb[k][l].area>ta)
							ta=tb[k][l].area;
					}
					ta+=cha(mkv(wp[k],bsp),mkv(wp[j],bsp));
					if(ta>tta)
						tta=ta;
					tb[j][k].area=ta;
				}
				if(tta>ma)
					ma=tta;
			}
			if(ma>mma)
				mma=ma;
		}
		printf("%.1lf\n",double(mma)/2);				
	}
	return 0;
}
