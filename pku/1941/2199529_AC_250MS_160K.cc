#include <iostream>
#include <math.h>
using namespace std;
int a[1025],b[1025],n;
void dosth(int x)
{
	int i;
	if(x==(int)pow(2,n*1.0))
		return;
	printf(" ");
	for(i=1;i<=x;i++)
	{
		if(a[i])
			printf("%c%c",47,92);
		else
			printf("  ");			
	}
	printf("\n");
	for(i=1;i<=x;i++)
	{
		if(a[i])
		{
			printf("%c__%c",47,92);
			i++;
		}
		else
			printf("  ");
	}
	printf("\n");
	memset(b,0,sizeof(b));
	for(i=1;i<=x+1;i++)
		b[i]=(a[i+1]+a[i-1])&1;
	memcpy(a,b,sizeof(b));
	dosth(x+1);
}
int main()
{
	int x;
	while(scanf("%d",&n),n)
	{
		memset(a,0,sizeof(a));
		x=(int)pow(2,(n-1)*1.0);
		a[x]=1;
		dosth(x);
		printf("\n");
	}
	return 0;
}