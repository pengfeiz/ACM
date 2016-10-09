#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 10003
#define esp 1e-8


struct poi
{
	char s1[10],s2[10];
	double x,y;
}a[MAX];


int n,d[MAX],p;
bool u[MAX];


bool com(poi a,poi b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}


void init()
{
	int i,j,l,k;
	char s[100];
	i=0;
	while(scanf("%s",s)!=EOF)
	{
		i++;
		l=strlen(s);
		for(j=0;j<l;j++)
			if(s[j]==',')
				break;
		for(k=1;k<j;k++)
			a[i].s1[k-1]=s[k];
		a[i].s1[j]='\0';
		for(k=j+1;k<l-1;k++)
			a[i].s2[k-j-1]=s[k];
		a[i].s2[l-j-2]='\0';
		a[i].x=atof(a[i].s1);
		a[i].y=atof(a[i].s2);
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

void outt()
{
	int i;
	for(i=1;i<=p;i++)
	{
		if(i>1)
			printf(" ");
		printf("(%s,%s)",a[d[i]].s1,a[d[i]].s2);
	}
	printf("\n");
}


int main()
{
	//freopen("in.txt","r",stdin);
	init();
	tubao();
	outt();
	return 0;
}