#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010


int n;
struct gao
{
	int b[6];
}a[MAX];

bool b[6][100000];


bool com(gao a,gao b)
{
	int i;
	for(i=0;i<6;i++)
		if(a.b[i]!=b.b[i])
			return a.b[i]<b.b[i];
	return true;
}

int main()
{
	int i,j,k,x[6],yy,u;
	bool f,ff;
	gao p,q,w;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
			scanf("%d",&a[i].b[j]);
//			a[i].b[j]=rand()%1000;
		for(j=0;j<6;j++)
			q.b[j]=p.b[5-j]=a[i].b[j];
		for(k=0;k<6;k++)
			w.b[k]=999999999;
		for(k=0;k<6;k++)
		{
			f=true;
			for(j=0;j<6;j++)
			{
				if(w.b[j]>p.b[(j+k)%6])
					break;
				else if(w.b[j]<p.b[(j+k)%6])
				{
					f=false;
					break;
				}
			}
			if(f&&j<6)
			{
				for(j=0;j<6;j++)
					w.b[j]=p.b[(j+k)%6];
			}
		}
		for(k=0;k<6;k++)
			a[i].b[k]=w.b[k];
		for(k=0;k<6;k++)
			w.b[k]=999999999;
		for(k=0;k<6;k++)
		{
			f=true;
			for(j=0;j<6;j++)
			{
				if(w.b[j]>q.b[(j+k)%6])
					break;
				else if(w.b[j]<q.b[(j+k)%6])
				{
					f=false;
					break;
				}
			}
			if(f&&j<6)
			{
				for(j=0;j<6;j++)
					w.b[j]=q.b[(j+k)%6];
			}
		}
		f=true;
		for(k=0;k<6;k++)
		{
			if(a[i].b[k]>w.b[k])
				break;
			else if(a[i].b[k]<w.b[k])
			{
				f=false;
				break;
			}
		}
		if(f&&k<6)
		{
			for(k=0;k<6;k++)
				a[i].b[k]=w.b[k];
		}
	}
	f=true;
	for(yy=0;f&&yy<1;yy++)
	{
		memset(b,0,sizeof(b));
		for(k=0;k<6;k++)
			x[k]=rand()%50000+rand()%31234+1234;
		for(i=0;f&&i<n;i++)
		{
			ff=false;
			for(k=0;k<6;k++)
			{
				u=a[i].b[k]%x[k];
				if(!b[k][u])
				{
					ff=true;
					b[k][u]=true;
				}
			}
			if(!ff)
				break;
		}
		if(i==n)
		{
			f=false;
			break;
		}
	}
	if(f)
		printf("Twin snowflakes found.\n");
	else
		printf("No two snowflakes are alike.\n");
	return 0;
}