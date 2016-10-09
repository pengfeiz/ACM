#include <iostream>
using namespace std;
int main()
{
	int x,y;
	int i,j;
	char s[5];
	while(scanf("%s",s),strcmp(s,"00e0"))
	{
		x=(s[0]-'0')*10+s[1]-'0';
		i=s[3]-'0';
		while(i--)
			x*=10;
		y=x;
		j=0;
		while(y)
		{
			j++;
			y>>=1;
		}
		x=(x<<1)+1;
		x-=1<<j;
		printf("%d\n",x);
	}
	return 0;
}
