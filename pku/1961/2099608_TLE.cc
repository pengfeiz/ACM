#include <iostream>
#define MAX 1000000
char s[MAX];
int main()
{
	int n,time=0,k,t;
	bool p;
	while(scanf("%d",&n),n>0)
	{
		time++;
		scanf("%s",s);
		k=1;
		printf("Test case #%d\n",time);
		while(k<n)
		{
			p=false;
			t=k;
			while(strncmp(s,s+t,k*sizeof(char))==0)
			{
				p=true;
				t+=k;
				printf("%d %d\n",t,t/k);
			}
			if(p)
				k=t;
			else
				k++;
		}
		printf("\n");
	}
	return 0;
}
