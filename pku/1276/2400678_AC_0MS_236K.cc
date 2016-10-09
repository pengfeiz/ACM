#include <iostream>
using namespace std;
#define MAX 100001

bool a[MAX];
struct gao
{
	int b,c;
}x[10];
int m,n;

int main()
{
	int i,j,k;
	while(scanf("%d",&m)!=EOF)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x[i].c,&x[i].b);
			x[i].c*=x[i].b;
		}
		memset(a,0,sizeof(a));
		a[0]=true;
		for(i=0;i<n;i++)
			for(j=m;j>=0;j--)
			{
				if(a[j])
					for(k=x[i].b;k<=x[i].c&&(j+k)<=m&&!a[j+k];k+=x[i].b)
						a[j+k]=true;
			}
		for(i=m;i>=0;i--)
			if(a[i])
				break;
		printf("%d\n",i);
	}
	return 0;
}


