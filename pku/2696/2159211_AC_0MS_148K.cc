#include <iostream>
using namespace std;

int x[1000];

int mod(int a,int b)
{
	int c=a%b;
	if(c>=0)
		return c;
	c+=b;
	return c;
}

int main()
{
	int a,b,c,d,e,f,g,h,i,n,j;
	scanf("%d",&n);
	while(n--)
	{
		memset(x,0,sizeof(x));
		scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
		x[0]=a;
		x[1]=b;
		x[2]=c;
		for(j=3;j<=i;j++)
		{
			if(j%2==1)
				x[j]=mod((d*x[j-1]+e*x[j-2]-f*x[j-3]),g);
			else
				x[j]=mod((f*x[j-1]-d*x[j-2]+e*x[j-3]),h);
		}
		printf("%d\n",x[i]);
	}
	return 0;
}
