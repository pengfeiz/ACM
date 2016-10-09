#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 11004
#define esp 1e-6


struct poi
{ 
	char s[1001];
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


bool init()
{
	int i,j,l,k,q;
	char s[1005],s1[501],s2[501];
	char c;
	i=q=0;
	while((c=getchar())!='\n')
	{
		if(c==EOF)
			return false;
		if(c==')')
		{
			i++;
			s[q]='\0';
			l=strlen(s);
			for(j=0;j<l;j++)
				if(s[j]==',')
					break;
			for(k=0;k<j;k++)
				s1[k]=s[k];
			s1[j]='\0';
			for(k=j+1;k<l;k++)
				s2[k-j-1]=s[k];
			s2[l-j-1]='\0';
			a[i].x=atof(s1);
			a[i].y=atof(s2);
			strcpy(a[i].s,s);
			q=0;
		}
		else if((c<='9'&&c>='0')||c=='.'||c==','||c=='-')
			s[q++]=c;
	}
	n=i;
	sort(a+1,a+1+n,com);
	return true;
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
	int i,t=0;
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
			printf("(%s)",a[d[i]].s);
		}
	}
	if(ff)
	{	
		printf(" ");
		printf("(%s)\n",a[d[t]].s);
	}
	else
		printf("(%s) (%s) (%s)\n",a[d[1]].s,a[d[p]].s,a[d[1]].s);
}



int main()
{
//	freopen("in.txt","r",stdin);
	while(init())
	{
		tubao();
		outt();
	}
	return 0;
}