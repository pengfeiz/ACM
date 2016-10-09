#include <iostream>
using namespace std;

int a[101][53],n;
int b[101];
bool d[53];
int jn[53];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j,q,tt,last,tim=0;
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
			memset(jn,0xff,sizeof(jn));
			memset(d,0,sizeof(d));
			q=1;
			j=0;
			tt=0;
			while(f&&tt<52)
			{
				if(q==jn[j])
					break;
				if(d[j])
				{
					jn[j]=q;
					j=(j+1)%52;
					continue;
				}
				if(a[i][j]==q)
				{
					memset(jn,0xff,sizeof(jn));
					d[j]=true;
					a[i+1][tt++]=q;
					last=q;
					j=(j+1)%52;
					q=q%13+1;
				}
				else
				{
					jn[j]=q;
					j=(j+1)%52;
					q=q%13+1;
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

				