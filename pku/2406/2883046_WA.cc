#include <iostream>   //查找串b在串a中出现次数
using namespace std;

#define maxb 1000050
int lb;
char b[maxb];
int next[maxb];


int main()
{
	int i,j,t;
	while(scanf("%s",b+1),strcmp(b+1,"."))
	{
		t=0;
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
		printf("%d\n",lb/(lb+1-next[lb+1]));
	}
	return 0;
}
