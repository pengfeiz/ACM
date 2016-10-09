#include <iostream>
using namespace std;

char a[100],b[100];

int x[100][100];

int main()
{
	int i,j,la,lb;
	scanf("%s%s",a+1,b+1);
	la=strlen(a+1);
	lb=strlen(b+1);
	memset(x,0,sizeof(x));
	x[0][0]=0;
	for(i=1;i<=la;i++)
		for(j=1;j<=lb;j++)
		{
			if(a[i]==b[j])
			{
				if(x[i][j]<x[i-1][j-1]+1)
					x[i][j]=x[i-1][j-1]+1;
			}
			if(x[i][j]<x[i-1][j])
				x[i][j]=x[i-1][j];
			if(x[i][j]<x[i][j-1])
				x[i][j]=x[i][j-1];
		}
	printf("%d\n",x[la][lb]);
system("pause");
	return 0;
}

