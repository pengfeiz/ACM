#include <iostream>   //查找串b在串a中出现次数
using namespace std;
#define maxa 1005000
#define maxb 10050
int la,lb;
char a[maxa],b[maxb];
int next[maxb];
int next2[maxb];

void getnext(char *b ,int nb,int *next)//求出有nb个元素的b数组的next
{
	int i=0,j=-1;
	next[0] = -1;
	while ( i < nb )
	{
		if ( b[i]==b[j] || j==-1 )
		{
			i++;
			j++;
			next[i] = j;//真正的next数组
		}
		else 
			j = next[j];
	}
}


int main()
{
	int i,j,t,tt;
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		scanf("%s%s",b+1,a+1);
//		scanf("%s",b+1);
		la=strlen(a+1);
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
/*		for(i=1;i<=lb+1;i++)
			printf("%d ",next[i]);
		printf("\n");*/
		for(i=j=1;i<=la;)
		{
			if(j==0||a[i]==b[j])
			{
				i++;
				j++;
				if(j==lb+1)
				{
					t++;
					j=next[j];
				}
			}
			else if(a[i]!=b[j])
				j=next[j];
		}
		printf("%d\n",t);
	}
	return 0;
}
