#include <iostream>
using namespace std;

#define MAX 1001

int d[MAX][MAX],n,m,h;

int main()
{
	int i,j,k,x,y,l,ma;
	scanf("%d%d%d",&n,&m,&h);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			d[i][j]=99999999;
	for(k=0;k<m;k++)
	{
		scanf("%d%d%d",&x,&y,&l);
		if(d[x][y]>l)
			d[x][y]=l;
	}
	ma=0;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
	for(i=1;i<=n;i++)
		if(d[i][h]!=99999999&&d[h][i]!=99999999&&ma<d[i][h]+d[h][i])
			ma=d[i][h]+d[h][i];
	printf("%d\n",ma);
	return 0;
}