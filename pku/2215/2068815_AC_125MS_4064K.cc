#include <iostream>
int a[1000][1000];
int main()
{
	int n,m,k,p,i,j,t,x1,x2,y1,y2;
	scanf("%d",&k);
	while(k-->0)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		scanf("%d",&p);
		while(p-->0)
		{
			t=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(i=x1-1;i<x2;i++)
				for(j=y1-1;j<y2;j++)
					t+=a[i][j];
			printf("Absolutni hodnota pohodlnosti je %d bodu.\n",t);
		}
		printf("\n");
	}
	return 0;
}
