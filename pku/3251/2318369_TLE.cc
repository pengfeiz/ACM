#include <iostream>
#include <math.h>
using namespace std;
#define esp 1e-6
#define MAX 10100
#define MAX2 110
 
struct gao
{
	double x,y;
}a[MAX];


int b[MAX2][MAX2],n,m;
char s[MAX2];


bool dian(double x1,double y1,double x2,double y2)
{
	if(fabs(x1*x2+y2*y1)<esp&&fabs(x1*x1+y1*y1-x2*x2-y2*y2)<esp)
		return true;
	return false;
}


int main()
{
	int i,j,k;
	memset(b,0,sizeof(b));
	int x,y;
	double ma;
	scanf("%d",&n);
	m=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		for(j=0;j<n;j++)
		{
			if(s[j]=='J')
			{
				a[m].x=double(i);
				a[m].y=double(j);
				m++;
				b[i][j]=1;
			}
			else if(s[j]=='B')
				b[i][j]=2;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(j==i)
				continue;
			for(k=0;k<m;k++)
			{
				if(k==i||k==j)
					continue;
				if(dian(a[j].x-a[i].x,a[j].y-a[i].y,a[k].x-a[j].x,a[k].y-a[j].y))
				{
					x=(int)(a[i].x+a[k].x-a[j].x);
					y=(int)(a[i].y+a[k].y-a[j].y);
					if(b[x][y]!=2)
						if((a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y)>ma)
							ma=(a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y);
				}
			}
		}
	}
	printf("%d\n",(int)ma);
	return 0;
}