#include <iostream>
using namespace std;

int main()
{
	int n,a,b,i,j;
	char s1[5];
	char s2[5];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",s1,s2);
		a=b=0;
		for(i=0;i<4;i++)
			if(s1[i]==s2[i])
				a++;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(i==j)
					continue;
				if(s1[i]==s2[j])
					b++;
			}
		}
		printf("%dA%dB\n",a,b);
	}
	return 0;
}