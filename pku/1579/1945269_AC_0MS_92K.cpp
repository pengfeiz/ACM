#include <stdio.h>
void main(void)
{
	int w[21][21][21];
	int a,b,c;
	int i,j,k;
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;
	for(i=1;i<21;i++)
		for(j=1;j<21;j++)
			for(k=1;k<21;k++)
			{
				if((i<j)&&(j<k))
					w[i][j][k] = w[i][j][j-1] + w[i][j-1][k-1] - w[i][j-1][k];
				else
					w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
			}
	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		i =a;j=b;k=c;
		if(a==-1 && b==-1 && c==-1)
			break;
        else if(a<=0 || b<=0 || c<=0)
			i=j=k=0;
        else if(a>20 || b>20 || c>20)
			i=j=k=20;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w[i][j][k]);
	}

}
