#include <iostream>
using namespace std;

char s[21][101];
char c[21][101];
int n,m;

int main()
{
	int i,j,l;
	char ss[101];
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%s%s",s[i],c[i]);
	for(i=0;i<n;i++)
	{
		scanf("%s",ss);
		for(j=0;j<m;j++)
			if(strcmp(ss,s[j])==0)
				break;
		if(j<m)
			printf("%s\n",c[i]);
		else
		{
			l=strlen(ss);
			if(ss[l-1]=='y'&&ss[l-2]!='a'&&ss[l-2]!='e'&&ss[l-2]!='o'&&ss[l-2]!='u'&&ss[l-2]!='i')
			{
				ss[l-1]='\0';
				printf("%sies\n",ss);
			}
			else if(ss[l-1]=='o'||ss[l-1]=='x'||ss[l-1]=='s'||(ss[l-1]=='h'&&(ss[l-2]=='c'||ss[l-2]=='s')))
				printf("%ses\n",ss);
			else
				printf("%ss\n",ss);
		}
	}
	return 0;
}