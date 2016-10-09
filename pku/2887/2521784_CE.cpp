#include<stdio.h>
using namespace std;

#define M 1000011
#define N 2001

char s[M],op[N][4],ch[N][4],ans;
int loc[N], i, j, n, len;

int main()
{
	gets(s);
	len = strlen(s);
	scanf("%d",&n);
	for(i = 0; i < n; i ++)
	{
		scanf("%1s",op[i]);
		if(op[i][0]=='Q')
		{
			scanf("%d",&loc[i]);
			ans='\0';
			for(j = i - 1; j >= 0; j -- )
			{
				if(op[j][0]=='I')
				{
					if(loc[j] < loc[i])loc[i]--;
					else if(loc[j] ==loc[i]){
						ans=ch[j][0];
						break;
					}
				}
			}
			if(ans=='\0')ans=s[loc[i]-1];
			putchar(ans);putchar('\n');
		}
		else if(op[i][0]=='I')
		{
			scanf("%1s%d",ch[i],&loc[i]);
			if(loc[i] > len)loc[i] = len + 1;
			len ++;
		}
	}
	return 0;
}
