#include <iostream>
using namespace std;
#define MAX 21

int n;
bool a[MAX][MAX][MAX];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,h,t;
	while(scanf("%d",&n),n)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			j=0;
			while(scanf("%d",&h),h)
			{
				for(k=0;k<h;k++)
					a[i][j][k]=true;
				j++;
			}
		}
		n=MAX;
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				t=0;
				for(j=0;j<n;j++)
				{
					if(a[i][j][k])
						t++;
					else
						break;
				}
				if(!t)
					break;
				else if(i)
					printf(" ");
				printf("%d",t);
			}
			if(i)
				printf("\n");
		}
		printf("\n");
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				t=0;
				for(i=0;i<n;i++)
				{
					if(a[i][j][k])
						t++;
					else
						break;
				}
				if(!t)
					break;
				else if(k)
					printf(" ");
				printf("%d",t);
			}
			if(k)
				printf("\n");
		}
		printf("\n\n");
	}
	return 0;
}

