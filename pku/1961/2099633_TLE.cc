#include <iostream>
#define MAX 1000001
char s[MAX];
bool dosth(char s1[],char s2[],int k)
{
	int i;
	for(i=0;i<k;i++)
		if(s1[i]!=s2[i])
			return false;
	return true;
}
int main()
{
	int n,time=0,k,t;
	bool p;
	while(scanf("%d",&n),n>0)
	{
		time++;
		scanf("%s",s);
//		for(t=0;t<n;t++)
//			s[t]=rand()%3+'a';
		k=1;
		printf("Test case #%d\n",time);
		while(k<=n/2)
		{
			p=false;
			t=k;
			while(dosth(s,s+t,k))
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
