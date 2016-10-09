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
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&k);
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
				strcpy(s,"0");
				break;
			}
			a[k]=true;
		}
		printf("%s\n",s);
	}
	return 0;
}
