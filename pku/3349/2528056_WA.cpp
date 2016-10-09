
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010


int n;
struct gao
{
	int b[6];
}a[MAX];

bool b[17][17][17][17][17][17];


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
	int i,j,k,x[6],yy;
	bool f;
	gao p,q,w;
	while(scanf("%d",&n)!=EOF)
	{
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
		for(yy=0;yy<10;yy++)
		{
			memset(b,0,sizeof(b));
			for(k=0;k<6;k++)
				x[k]=10+rand()%7;
			for(i=0;i<n;i++)
			{
				if(!b[a[i].b[0]%x[0]][a[i].b[1]%x[1]][a[i].b[2]%x[2]][a[i].b[3]%x[3]][a[i].b[4]%x[4]][a[i].b[5]%x[5]])
					b[a[i].b[0]%x[0]][a[i].b[1]%x[1]][a[i].b[2]%x[2]][a[i].b[3]%x[3]][a[i].b[4]%x[4]][a[i].b[5]%x[5]]=true;
				else
					break;
			}
			if(i==n)
				break;
		}
		if(yy==20)
			printf("Twin snowflakes found.\n");
		else
			printf("No two snowflakes are alike.\n");
	}
	return 0;
}