#include <iostream>
using namespace std;
#define MAX 1001

char s1[MAX];
char s2[MAX];

int a[MAX][MAX];

int maxx(int a,int b)
{return a>b?a:b;}

int main()
{
	int l1,l2,i,j;
	scanf("%d",&l1);
	scanf("%s",s1+1);
	scanf("%d",&l2);
	scanf("%s",s2+1);
	memset(a,0,sizeof(a));
	for(i=1;i<=l1;i++)
		for(j=1;j<=l2;j++)
		{
			if(s1[i]==s2[j])
				a[i][j]=a[i-1][j-1]+1;
			a[i][j]=maxx(a[i][j],a[i][j-1]);
			a[i][j]=maxx(a[i-1][j],a[i][j]);
		}
	printf("%d\n",maxx(l1-a[l1][l2],l2-a[l1][l2]));
	return 0;
}