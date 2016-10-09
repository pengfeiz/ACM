#include <iostream>
using namespace std;

int d[101][53];

int dd[53],a[53];

char s1[4][10]={"Clubs","Diamonds","Hearts","Spades"};

char s2[13][10]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
int i,j,k,n,m;
int main()
{
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		for(j=1;j<=52;j++)
			scanf("%d",&d[i][j]);
	for(i=1;i<=52;i++)
		dd[i]=i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=52;i++)
			a[i]=dd[d[n][i]];
		for(i=1;i<=52;i++)
			dd[i]=a[i];
		for(i=1;i<=52;i++)
			printf("%s of %s\n",s2[(dd[i]-1)%13],s1[(dd[i]-1)/13]);
		printf("\n");
	}
	return 0;
}

