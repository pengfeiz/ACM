#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define esp 1e-6
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
//	freopen("in.txt","r",stdin);
	int i,j,x1,y1,x2,y2,xx,yy,ma;

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
		for(j=0;j<m;j++)
		{
			xx=a[j].x-a[i].x;
			yy=a[j].y-a[i].y;
			if(ma>=xx*xx+yy*yy)
				continue;
			x1=a[i].x-yy;
			y1=a[i].y+xx;
			x2=a[j].x-yy;
			y2=a[j].y+xx;
			if(b[x1][y1]==1||b[x2][y2]==1)
				if(b[x1][y1]!=2&&b[x2][y2]!=2)
					ma=xx*xx+yy*yy;
		}	
	}
	printf("%d\n",(int)ma);
	return 0;
}