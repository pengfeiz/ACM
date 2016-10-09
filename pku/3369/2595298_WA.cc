#include <iostream>
using namespace std;
int main()
{
	int i,j,k,l,m=1000000,p,w;
	for(i=8;i<126;i++)
		for(j=i>50?i:50;j<593;j++)
		{
			w=i*j;
			for(k=j>100?j:100;k<885;k++)
			{
				p=w*k;
				if(i+j+k>2000)
					break;
				if(p==m)
					continue;
				if((i+j+k)*m%(p-m)==0)
				{
					l=(i+j+k)*m/(p-m);
					if(l<=0||l<k)
						break;
					if(i+k+j+l>2000)
						continue;
					printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",i/100,i%100,j/100,j%100,k/100,k%100,l/100,l%100);
				}
			}
		}
	return 0;
}
