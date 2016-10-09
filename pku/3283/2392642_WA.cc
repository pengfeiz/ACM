#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100001

char s[14]="A234567890JQK",l[5]="CDHS";
int a[MAX][52],b[52],n,m;

int main()
{
	int i,t,p;
	char c;
	while(scanf("%d",&n),n)
	{
		memset(a[1],0,sizeof(a[0]));
		t=1;
		while(n--)
		{
			scanf("%d ",&m);
			for(i=0;i<m;i++)
			{
				scanf("%c",&c);
				if(c=='1')
					scanf("%c",&c);
				b[i]=strchr(s,c)-s;
				scanf("%c ",&c);
				b[i]+=13*(strchr(l,c)-l);
			}
			p=0;
			for(i=m-1;i>=0;i--)
			{
				if(!a[p][b[i]])
				{
					a[p][b[i]]=t++;
					memset(a[t],0,sizeof(a[0]));
				}
				p=a[p][b[i]];
			}
		}
		printf("%d\n",t-1);
	}
	return 0;
}
