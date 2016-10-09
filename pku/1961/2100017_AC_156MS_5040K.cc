#include <iostream>
using namespace std;
#define MAX 1000002

char s[MAX];
int b[MAX];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,a1,a2,time=0;
	while(scanf("%d",&n),n)
	{
		time++;
		printf("Test case #%d\n",time);
		scanf("%s",s+1);
		b[0]=0;
		for(i=1;i<=n;i++)
		{
			s[0]=s[i];
			j=b[i-1];
			while(s[j]!=s[i])
				j=b[j-1];
			b[i]=j+1;
			a1=i;
			a2=b[i]-1;
			if(a2&&a1%(a1-a2)==0)
				printf("%d %d\n",a1,a1/(a1-a2));
		}
		printf("\n");
	}
	return 0;
}

