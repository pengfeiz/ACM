#include <iostream>
using namespace std;
int main()
{
	int n,i,j,min;
	while(scanf("%d",&n)&&n)
	{
		min=0;
		for(i=0;i*i*i<=n;i++)
			for(j=0;;j++)
			{
				if(i*i*i+j*(j+1)*(j+2)/6<=n&&i*i*i+j*(j+1)*(j+2)/6>min)
					min=i*i*i+j*(j+1)*(j+2)/6;
				if(i*i*i+j*(j+1)*(j+2)/6>n)
					break;
			}
		printf("%d\n",min);
	}
	return 0;
}


