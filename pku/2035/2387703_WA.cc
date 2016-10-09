#include <iostream>
using namespace std;

int a[15][53],n;
int b[15];
bool d[53];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j,q,tt,last,m,tim=0;
	bool f;
	scanf("%d",&t);
	while(t--)
	{
		f=true;
		scanf("%d",&n);
		for(i=0;i<52;i++)
			scanf("%d",&a[0][i]);
		for(i=0;f&&i<n;i++)
		{
			memset(d,0,sizeof(d));
			q=1;
			j=m=0;
			tt=0;
			while(f&&tt<52)
			{
				if(m>1000)
					break;
				if(d[j])
				{
					m++;
					continue;
				}
				if(a[i][j]==q)
				{
					d[j]=true;
					a[i+1][tt++]=q;
					last=q;
					j=(j+1)%52;
					q=q%13+1;
					m=0;
				}
				else
				{
					j=(j+1)%52;
					q=q%13+1;
					m++;
				}
			}
			if(tt<52)
				f=false;
			else
				b[i]=last;
		}
		tim++;
		printf("Case %d:",tim);
		if(!f)
			printf(" unwinnable\n");
		else
		{
			for(i=0;i<n;i++)
				printf(" %d",b[i]);
			printf("\n");
		}
	}
	return 0;
}

				