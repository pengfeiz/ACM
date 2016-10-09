#include <iostream>
using namespace std;
char a[101],b[101];
int l1,l2;
int main()
{
	int i,j,t,jud;
	while(1){
	scanf("%s%s",a,b);
	l1=strlen(a);
	l2=strlen(b);
	t=l1+l2;
	for(i=0;i<l1;i++)
	{
		jud=0;
		for(j=0;j<l2&&i+j<l1;j++)
			if(a[i+j]+b[j]-'0'>'3')
			{
				jud=1;
				break;
			}
		if(jud)
			continue;
		if(j==l2)
		{
			if(t>l1)
				t=l1;
		}
		if(i+j==l1)
		{
			if(t>l2+i)
				t=l2+i;
		}
	}
	for(i=0;i<l2;i++)
	{
		jud=0;
		for(j=0;j<l1&&i+j<l2;j++)
			if(b[i+j]+a[j]-'0'>'3')
			{
				jud=1;
				break;
			}
		if(jud)
			continue;
		if(j==l1)
		{
			if(t>l2)
				t=l2;
		}
		if(i+j==l2)
		{
			if(t>l1+i)
				t=l1+i;
		}
	}
	printf("%d\n",t);}
	return 0;
}