#include <iostream>
using namespace std;

int a[500][200];
int b[200],c[200];

bool strc1(int x)
{
	if(a[x][0]>b[0])
		return true;
	else if(a[x][0]<b[0])
		return false;
	return memcmp(a[x],b,sizeof(b))>=0;
}

bool strc2(int x)
{
	if(a[x][0]<c[0])
		return true;
	else if(a[x][0]>c[0])
		return false;
	return memcmp(a[x],c,sizeof(c))<=0;
}

void add(int x)
{
	int i;
	a[x][0]=a[x-1][0];
	for(i=1;i<=a[x][0];i++)
		a[x][i]=a[x-1][i]+a[x-2][i];
	for(i=1;i<a[x][0];i++)
	{
		a[x][i+1]+=a[x][i]/10;
		a[x][i]%=10;
	}
	while(a[x][a[x][0]]>9)
	{
		a[x][a[x][0]+1]=a[x][a[x][0]]/10;
		a[x][a[x][0]]%=10;
		a[x][0]++;
	}
}

int main()
{
	int i,t;
	char s1[200],s2[200];
	memset(a,0,sizeof(a));
	a[0][0]=a[1][0]=a[0][1]=a[1][1]=1;
	for(i=2;i<500;i++)
		add(i);
	while(scanf("%s%s",s1,s2)&&(strcmp(s1,"0")!=0||strcmp(s2,"0")!=0))
	{
		b[0]=strlen(s1);
		c[0]=strlen(s2);
		for(i=1;i<=b[0];i++)
			b[i]=s1[i-1]-'0';
		for(i=1;i<=c[0];i++)
			c[i]=s2[i-1]-'0';
		t=0;
		for(i=1;i<500;i++)
		{
			if(strc1(i))
			{
				for(;i<500;i++)
				{
					if(strc2(i))
						t++;
					else
						break;
				}
				break;
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
