#include <iostream>
using namespace std;
int c[7];
char x[729][729];
void dosth(int n,int a,int b)
{
	if(n==0)
	{
		x[a][b]='X';
		return;
	}
	dosth(n-1,a,b);
	dosth(n-1,a+2*c[n-1],b);
	dosth(n-1,a+c[n-1],b+c[n-1]);
	dosth(n-1,a,b+2*c[n-1]);
	dosth(n-1,a+2*c[n-1],b+2*c[n-1]);
}		
int main()
{
	int i,j,n;
	c[0]=1;
	for(i=1;i<7;i++)
		c[i]=c[i-1]*3;
	for(i=0;i<729;i++)
		for(j=0;j<729;j++)
			x[i][j]=' ';
	dosth(6,0,0);
	while(cin>>n&&n!=-1)
	{
		for(i=0;i<c[n-1];i++)
		{
			for(j=0;j<c[n-1];j++)
				printf("%c",x[i][j]);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}




