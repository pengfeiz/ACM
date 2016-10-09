#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 10100
#define MAX2 110
 
struct gao
{
	int x,y;
}a[MAX];

bool u[MAX];
int b[MAX2][MAX2],n,m,d[MAX];
char s[MAX2];

int main()
{
	int i,j,x1,y1,x2,y2,xx,yy,ma;

	memset(b,0,sizeof(b));
	scanf("%d",&n);
	m=ma=0;

	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		for(j=0;j<n;j++)
		{
			if(s[j]=='J')
			{
				a[m].x=i;
				a[m].y=j;
				m++;
				b[i][j]=1;
			}
			else if(s[j]=='B')
				b[i][j]=2;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=m-1;j>=0;j--)
		{
			xx=a[j].x-a[i].x;
			yy=a[j].y-a[i].y;
			if(ma>=xx*xx+yy*yy)
				continue;
			x1=a[i].x+yy;
			if(x1<0||x1>=n)
				continue;
			y1=a[i].y-xx;
			if(y1<0||y1>=n)
				continue;
			x2=a[j].x+yy;
			if(x2<0||x2>=n)
				continue;
			y2=a[j].y-xx;
			if(y2<0||y2>=n)
				continue;
			if(b[x1][y1]==1||b[x2][y2]==1)
				if(b[x1][y1]!=2&&b[x2][y2]!=2)
					ma=xx*xx+yy*yy;
		}	
	}
	printf("%d\n",ma);
	return 0;
}