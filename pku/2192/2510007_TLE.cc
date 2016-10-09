#include <iostream>
using namespace std;
#define MAX 1001
char s1[MAX],s2[MAX],s3[MAX];
int c1[MAX],c2[MAX];

int main()
{
	int t,i1,i2,i3,top,l,tim;
	scanf("%d",&t);
	for(tim=1;tim<=t;tim++)
	{
		top=0;
		scanf("%s%s%s",s1,s2,s3);
		l=strlen(s3);
		i1=i2=i3=0;
		while(i3<l)
		{
			if(s1[i1]==s3[i3]&&s2[i2]!=s3[i3])
			{
				i1++;
				i3++;
			}
			else if(s1[i1]!=s3[i3]&&s2[i2]==s3[i3])
			{
				i2++;
				i3++;
			}
			else if(s1[i1]==s3[i3]&&s2[i2]==s3[i3])
			{
				c1[top]=i1;
				c2[top]=i2;
				i1++;
				i3++;
				top++;
			}
			else
			{
				if(top--)
				{
					i1=c1[top];
					i2=c2[top]+1;
					i3=i1+i2;
				}
				else
					break;
			}
		}
		if(i3<l)
			printf("Data set %d: no\n",tim);
		else
			printf("Data set %d: yes\n",tim);
	}
	return 0;
}