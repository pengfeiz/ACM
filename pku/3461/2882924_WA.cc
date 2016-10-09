#include <iostream>   //查找串b在串a中出现次数
using namespace std;
#define maxa 1005000
#define maxb 10050
int la,lb;
char a[maxa],b[maxb];
int next[maxb];

int main()
{
	int i,j,t,tt;
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		scanf("%s%s",b+1,a+1);
	//	scanf("%s",b+1);
		la=strlen(a+1);
		lb=strlen(b+1);
		next[0]=0;
		for(i=1;i<=lb;i++)
		{
			b[0]=b[i];
			j=next[i-1];
			while(b[j]!=b[i])
				j=next[j-1];
			next[i]=j+1;
		}
	//	for(i=1;i<=lb;i++)
	//		printf("%d ",next[i]);
	//	printf("\n");
		for(i=j=1;i<=la;i++)
		{
			if(a[i]!=b[j])
				j=next[j];
			else if(j==lb)
			{
				t++;
				j=next[j];
			}
			else
				j++;
		}
		printf("%d\n",t);
	}
	return 0;
}
