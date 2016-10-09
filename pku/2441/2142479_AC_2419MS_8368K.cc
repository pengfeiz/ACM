#include <iostream>
using namespace std;
#define MAX 1048577
#define MAX2 21
int a[2][MAX];
int b[MAX2][MAX2],n,m;

int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i][0]);
		for(j=1;j<=b[i][0];j++)
			scanf("%d",&b[i][j]);
	}
	a[0][0]=1;
	m=1<<m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=b[i][0];j++)
			for(k=0;k<m;k++)
				if(a[0][k]&&(k%(1<<b[i][j])<(1<<(b[i][j]-1))))
					a[1][k+(1<<(b[i][j]-1))]+=a[0][k];
		memcpy(a[0],a[1],m*sizeof(int));
		memset(a[1],0,m*sizeof(int));
	}
	j=0;
	for(i=1;i<m;i++)
		j+=a[0][i];
	printf("%d\n",j);
	return 0;
}


	


			

