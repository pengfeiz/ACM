#include <iostream>
#include <math.h>
#include <algorithm>
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

bool com(gao a,gao b)
{
	if(fabs(a.x-b.x)>esp)
		return a.x<b.x;
	return a.y<b.y;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,x,y;
	double ma=0,xx,yy;
	bool q1,q2;
	gao p1,p2;

	memset(b,0,sizeof(b));
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
	sort(a,a+m,com);
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			xx=(a[j].x-a[i].x)/2;
			yy=(a[j].y-a[i].y)/2;
			if(ma>=(xx*xx+yy*yy)*2)
				continue;
			p1.x=(a[i].x+a[j].x)/2-yy;
			p1.y=(a[i].y+a[j].y)/2+xx;
			p2.x=(a[i].x+a[j].x)/2+yy;
			p2.y=(a[i].y+a[j].y)/2-xx;
			q1=binary_search(a,a+m,p1,com);
			q2=binary_search(a,a+m,p2,com);
			if(q1&&q2)
			{
				if(ma<(xx*xx+yy*yy)*2)
					ma=(xx*xx+yy*yy)*2;
			}
			else if(q1)
			{
				x=(int)p2.x;
				y=(int)p2.y;
				if(b[x][y]!=2&&ma<(xx*xx+yy*yy)*2&&x>=0&&x<n&&y<n&&y>=0)
					ma=(xx*xx+yy*yy)*2;
			}
			else if(q2)
			{
				x=(int)p1.x;
				y=(int)p1.y;
				if(b[x][y]!=2&&ma<(xx*xx+yy*yy)*2&&x>=0&&y>=0&&x<n&&y<n)
					ma=(xx*xx+yy*yy)*2;
			}
		}
	}
	printf("%d\n",(int)ma);
	return 0;
}