#include <iostream>
using namespace std;
#define MAX 1001

char s1[MAX];
char s2[MAX];

int a[MAX][MAX];

int minn(int a,int b)
{return a<b?a:b;}

int main()
{
	int l1,l2,i,j,q,t;
	while(scanf("%d",&l1)!=EOF)
	{
		scanf("%s",s1+1);
		scanf("%d",&l2);
		scanf("%s",s2+1);
		q=l2-l1;
		memset(a,127,sizeof(a));
		for(i=0;i<=q;i++)
			a[0][i]=i;
		t=0;
		for(i=0;i<=l1;i++)
		{
			if(s1[i]!=s2[i])
				t++;
			a[i][0]=t;
		}
		for(i=1;i<=l1;i++)
			for(j=i;j<=i+q;j++)
			{
				if(s1[i]==s2[j])
					a[i][j-i]=minn(a[i][j-i],a[i-1][j-i]);
				a[i][j-i]=minn(a[i][j-i],a[i-1][j-i]+1);
				a[i][j-i]=minn(a[i][j-i],a[i][j-i-1]+1);
			}
		printf("%d\n",a[l1][q]);
	}
	return 0;
}