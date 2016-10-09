#include <iostream>   //查找串b在串a中出现次数
using namespace std;

#define maxb 1000500
int lb;
char b[maxb];
int next[maxb];


int main()
{
	int i,j;
	while(gets(b+1),strcmp(b+1,"."))
	{
		lb=strlen(b+1);
		i=1,j=0;
		next[1]=0;
		while(i<=lb+1)
		{
			if(j==0||b[i]==b[j])
			{
				++i;
				++j;
				if(b[i]!=b[j])
					next[i]=j;
				else
					next[i]=next[j];
			}
			else
				j=next[j];
		}
		if(lb%(lb+1-next[lb+1])==0)
			printf("%d\n",lb/(lb+1-next[lb+1]));
		else
			printf("1\n");
	}
	return 0;
}
