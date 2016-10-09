#include <iostream>
using namespace std;
#define MAX 302

struct gao
{
	int x,y;
}b[MAX];


int n,m;
int a[10*MAX][MAX];
bool c[10*MAX][MAX];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t,q,p;
	scanf("%d%d",&m,&n);
	memset(c,0,sizeof(c));
	memset(a,127,sizeof(a));
	for(i=1;i<=n;i++)
		scanf("%d%d",&b[i].x,&b[i].y);
	a[0][0]=0;
	t=c[0][0]=1;
	while(!c[t-1][n])
	{
		for(i=0;i<=n;i++)
		{
			if(!c[t-1][i])
				break;
			q=0;
			p=m-a[t-1][i];
			for(j=i+1;j<=n;j++)
			{
				if(p<b[j].x||q+b[j].y>m)
					break;
				p-=b[j].x;
				q+=b[j].y;
				if(q<a[t][j])
				{
					a[t][j]=q;
					c[t][j]=true;
				}
			}
			a[t][i]=0;
			c[t][i]=true;
		}
		t++;
	}
	printf("%d\n",t+1);
	return 0;
}