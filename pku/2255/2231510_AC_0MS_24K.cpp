#include <stdio.h>
#include <string.h>

char s1[27],s2[27];

void dosth(int x1,int y1,int x2,int y2)
{
	if(x1>=y1)
		return;
	int i;
	for(i=x2;i<y2;i++)
		if(s2[i]==s1[x1])
			break;
	i-=x2;
	dosth(x1+1,x1+i+1,x2,x2+i);
	dosth(x1+i+1,y1,x2+i+1,y2);
	printf("%c",s1[x1]);
}

int main()
{
	int l1,l2;
	while(scanf("%s",s1)!=EOF)
	{
		scanf("%s",s2);
		l1=strlen(s1);
		l2=strlen(s2);
		dosth(0,l1,0,l2);
		printf("\n");
	}
	return 0;
}