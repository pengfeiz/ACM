#include<stdio.h>
#include<string.h>
char dic[81][1000][81];
int s[81];
char start[81],temp[81];
int maxlen;
char max[81];

bool test(char *st,char *en,int len)
{
	int i;
	for(i=0;i<len;i++)
		if(st[i]!=en[i])break;
	for(;i<len;i++)
		if(st[i]!=en[i+1])return 0;
	return 1;
}

void getmax(char *st,int len)
{
	int i;
	for(i=0;i<s[len];i++)
	{
		if( test(st,dic[len][i],len-1) )
		{
			if(len>maxlen)
			{
				strcpy(max,dic[len][i]);
				maxlen=len;
			}
			getmax(dic[len][i],len+1);
		}
	}
}

int main()
{
	int d,l;
	while(scanf("%d%s",&d,start)!=EOF)
	{
		memset(s,0,sizeof(s));
		l=strlen(start);
		if(l!=3)while(1);
		while(d--)
		{
			scanf("%s",temp);
			l=strlen(temp);
			strcpy(dic[l][s[l]++],temp);
		}
		maxlen=3;
		strcpy(max,start);
		getmax(start,4);
		printf("%s\n",max);
	}
	return 0;
}
