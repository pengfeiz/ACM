#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 11004
#define esp 1e-6


struct poi
{
	char s1[2001],s2[2001];
	double x,y;
}a[MAX];


int n,d[MAX],p;
bool u[MAX];


bool com(poi a,poi b)
{
	if(fabs(a.x-b.x)>esp)
		return a.x<b.x;
	return a.y<b.y;
}


void init()
{
	int i,j,l,k,q;
	char s[4005];
	char c;
	i=q=0;
	while(scanf("%c",&c)!=EOF)
	{
		if(c==' '||c=='(')
			continue;
		if(c==')')
		{
			i++;
			s[q]='\0';
			l=strlen(s);
			for(j=0;j<l;j++)
				if(s[j]==',')
					break;
			for(k=0;k<j;k++)
				a[i].s1[k]=s[k];
			a[i].s1[j]='\0';
			for(k=j+1;k<l;k++)
				a[i].s2[k-j-1]=s[k];
			a[i].s2[l-j-1]='\0';
			a[i].x=atof(a[i].s1);
			a[i].y=atof(a[i].s2);
			q=0;
		}
		else
			s[q++]=c;
	}
	n=i;
	sort(a+1,a+1+n,com);
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
	p--;
}



bool chaa(double x1,double y1,double x2,double y2)
{
	if(fabs(x1*y2-x2*y1)<esp)
		return true;
	return false;
}
bool linee(poi a,poi b,poi c)
{return chaa(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);}



void outt()
{
	int i,t;
	bool ff=false;
	memset(u,0,sizeof(u));
	d[p+1]=d[1];
	d[0]=d[p];
	for(i=1;i<=p;i++)
		if(linee(a[d[i-1]],a[d[i]],a[d[i+1]]))
			u[i]=true;
	for(i=p;i>0;i--)
	{
		if(ff)
			printf(" ");
		if(!u[i])
		{
			if(!ff)
				t=i;
			ff=true;
			printf("(%s,%s)",a[d[i]].s1,a[d[i]].s2);
		}
	}
	if(ff)
	{	
		printf(" ");
		printf("(%s,%s)\n",a[d[t]].s1,a[d[t]].s2);
	}
	else
		printf("(%s,%s) (%s,%s) (%s,%s)\n",a[d[1]].s1,a[d[1]].s2,a[d[p]].s1,a[d[p]].s2,a[d[1]].s1,a[d[1]].s2);
}



int main()
{
//	freopen("in.txt","r",stdin);
	init();
//	tubao();
//	outt();
	return 0;
}