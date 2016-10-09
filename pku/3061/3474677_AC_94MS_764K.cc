#include <iostream>
using namespace std;
int main()
{
	int num[100000],n,m,i,j,nn,tt,min;
	scanf("%d",&nn);
	while(nn-->0)
	{
                scanf("%d%d",&n,&m);
		min=n+1;
		tt=0;
		for(i=0;i<n;i++)
		    scanf("%d",&num[i]);
		for(i=j=0;i<n;i++)
		{
			while(tt<m&&j<n)
			{
				tt+=num[j];
				j++;
			}
			if(j-i<min&&tt>=m)
				min=j-i;
			tt-=num[i];
		}
		if(min==n+1)
			printf("0\n");
		else
			printf("%d\n",min);
	}
	return 0;
}

