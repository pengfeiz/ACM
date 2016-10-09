#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 30000
#define MAX2 100000


struct gao
{
	int a[5],t;
}c[MAX];


int n,x,b[5][5],d[MAX2],he;


bool prime(int x)
{
	int i,f;
	f=(int)sqrt(x*1.0);
	for(i=2;i<=f;i++)
		if(x%i==0)
			return false;
	return true;
}


bool com(gao a,gao b)
{
	int i;
	if(a.t!=b.t)
		return a.t<b.t;
	for(i=0;i<=he;i++)
		if(a.a[i]!=b.a[i])
			return a.a[i]<b.a[i];
	return false;
}


bool jud(gao a,gao b,int xx)
{
	int i,t=0;
	for(i=0;i<=xx;i++)
	{
		if(a.a[i]!=b.a[i])
			return true;
		t+=a.a[i];
		if(t>x)
			return true;
	}
	return false;
}

void solve(int xx)
{
	int i,j,i1,i2,k,k1,k2,jj,kk;
	if(xx==5)
	{
		k=0;
		for(i=0;i<5;i++)
			k=k*10+b[i][i];
		if(d[k]!=x)
			return;
		k=0;
		for(i=0;i<5;i++)
			k=k*10+b[4-i][i];
		if(d[k]!=x)
			return;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%d",b[i][j]);
			printf("\n");
		}
		printf("\n");
		return;
	}
	gao p;	
	for(i=0;i<=xx;i++)
		p.a[i]=b[xx][i];
	if(xx==0)
		he=0;
	else
		he=xx-1;
	p.t=x;
	i1=lower_bound(c,c+n,p,com)-c;
	i2=upper_bound(c,c+n,p,com)-c;
	for(i=i1;i<i2;i++)
	{
		for(j=xx;j<5;j++)
			b[xx][j]=c[i].a[j];
		for(j=xx;j<5;j++)
		{
			for(k=0;k<=xx;k++)
				p.a[k]=b[k][j];
			he=xx;
			p.t=x;
			k=lower_bound(c,c+n,p,com)-c;
			if(jud(c[k],p,xx))
				break;
		}
		if(j==5)
		{
			for(k=0;k<=xx;k++)
				p.a[k]=b[k][xx];
			he=xx;
			p.t=x;
			k1=lower_bound(c,c+n,p,com)-c;
			k2=upper_bound(c,c+n,p,com)-c;
			for(k=k1;k<k2;k++)
			{
				for(jj=xx;jj<5;jj++)
					b[jj][xx]=c[k].a[jj];
				for(jj=xx;jj<5;jj++)
				{
					for(kk=0;kk<=xx;kk++)
						p.a[kk]=b[jj][kk];
					p.t=x;
					he=xx;
					kk=lower_bound(c,c+n,p,com)-c;
					if(jud(c[kk],p,xx))
						break;
				}
				if(jj==5)
					solve(xx+1);
			}
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	memset(d,0,sizeof(d));
	n=0;
	for(i=10000;i<=99999;i++)
		if(prime(i))
		{
			x=i;
			c[n].t=0;
			for(j=4;j>=0;j--)
			{
				c[n].t+=x%10;
				c[n].a[j]=x%10;
				x/=10;
			}
			d[i]=c[n].t;
			n++;
		}
	he=4;
	sort(c,c+n,com);
	scanf("%d%d",&x,&b[0][0]);
	solve(0);
	return 0;
}