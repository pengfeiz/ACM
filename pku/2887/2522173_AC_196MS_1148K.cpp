#include <iostream>
using namespace std;
#define MAX 1000002
#define MAX2 2001

char s[MAX];

struct gao
{
	int n;
	char c;
}a[MAX2];

int main()

{
	char c[2];
	int m=1,n,i,p,j,k;
	a[0].n=99999999;
	a[0].c='?';
	scanf("%s",s);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		if(c[0]=='I')
		{
			scanf("%s",c);
			scanf("%d",&p);
			for(j=0;j<m;j++)
				if(a[j].n>=p)
					break;
			for(k=m;k>j;k--)
			{
				a[k].n=a[k-1].n+1;
				a[k].c=a[k-1].c;
			}
			m++;
			a[j].n=p;
			a[j].c=c[0];
		}
		else
		{
			scanf("%d",&p);
			for(j=0;j<m;j++)
				if(a[j].n>=p)
					break;
			if(a[j].n==p)
				printf("%c\n",a[j].c);
			else
			{
				if(j)
					printf("%c\n",s[p-j-1]);
				else
					printf("%c\n",s[p-1]);
			}
		}
	}
	return 0;
}