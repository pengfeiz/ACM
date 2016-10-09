#include <iostream>
using namespace std;
#define MAX1 1000
#define MAX2 1000
int a[MAX1*MAX2+2],n,t;
char s[MAX1+2][MAX2+2];
void dosth(int i,int j)
{
	s[i][j]='.';
	a[t]++;
	if(s[i-1][j]=='*')
		dosth(i-1,j);
	if(s[i][j-1]=='*')
		dosth(i,j-1);
	if(s[i+1][j]=='*')
		dosth(i+1,j);
	if(s[i][j+1]=='*')
		dosth(i,j+1);
}
int main()
{
	int m,i,j;
	cin>>n>>m;
	memset(s,0,sizeof(s));
	for(i=1;i<=m;i++)
	{
		getchar();
		for(j=1;j<=n;j++)
			scanf("%c",&s[i][j]);
	}
	memset(a,0,sizeof(a));
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(s[i][j]=='*')
			{
				t++;
				dosth(i,j);
			}
	for(i=1,j=0;i<=t;i++)
		if(a[i]>j)
			j=a[i];
	printf("%d\n",j);
	return 0;
}

