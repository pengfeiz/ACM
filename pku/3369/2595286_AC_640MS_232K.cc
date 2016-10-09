#include <iostream>
using namespace std;
int main()
{
	int i,j,k,l,m=1000000,p,w,a,b,c,d;
	for(i=1;i<126;i++)
		for(j=i;j<593;j++)
		{
			w=i*j;
			for(k=j;k<885;k++)
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
						continue;
					if(i+k+j+l>2000)
						continue;
                                              a=i/100;
b=j/100;
c=k/100;
d=l/100;
					printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",a,i-a*100,b,j-b*100,c,k-c*100,d,l-d*100);
				}
			}
		}
	return 0;
}

