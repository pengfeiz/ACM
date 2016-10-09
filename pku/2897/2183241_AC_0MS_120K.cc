#include <iostream>
using namespace std;
bool a[100];
char s[100];
int n,k;
int main()
{
	int m,nn,t;
	scanf("%d",&nn);
	while(nn--)
	{
		m=0;
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&k);
		if(n>k)
		{
			printf("0\n");
			continue;
		}
		t=k;
		while(1)
		{
			s[m]=k/n+'0';
			m++;
			k=k%n*10+k/n;
			if(t==k)
				break;
			else if(a[k]==true)
			{
				s[0]='0';
				s[1]='\0';
				break;
			}
			a[k]=true;
		}
		printf("%s\n",s);
	}
	return 0;
}
