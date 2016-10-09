#include <iostream>
#include <math.h>
using namespace std;
long a,k,b[105],c[105],n;
int main()
{
	long i,j,p;
	while(cin>>n>>k&&(n||k))
	{
		memset(b,0,k);
		scanf("%ld",&a);
		a=(a%k+k)%k;
		b[a]=1;
		for(j=1;j<n;j++)
		{
			scanf("%ld",&a);
			p=a%k;
			memset(c,0,n);
			for(i=0;i<k;i++)
				if(b[i]==1)
					c[((a+i)%k+k)%k]=c[((i-a)%k+k)%k]=1;
			memcpy(b,c,k);
		}
		if(b[0])	
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
	return 0;
}


		