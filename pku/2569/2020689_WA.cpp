#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 6000

char s[MAX];
int t;

struct gao
{
	char a,b;
	int n;
}a[MAX];

int find(char c1,char c2)
{
	int i;
	for(i=0;i<t;i++)
		if(a[i].a==c1&&a[i].b==c2)
			return i;
	return t;
}

bool com(gao a,gao b)
{
	if(a.n<b.n)
		return false;
	else if(a.n==b.n)
	{
		if(a.a>b.a)
			return false;
		else if(a.a==b.a&&a.b>b.b)
			return false;
	}
	return true;
}

int main()
{
	int n,i,l,j,ls;
	char c[80];
	while(cin>>n&&n)
	{
		getchar();
		ls=0;
		t=1;
		for(i=0;i<n;i++)
		{
			gets(c);
			l=strlen(c);
			for(j=0;j<l;j++)
				s[ls+j]=c[j];
			ls+=l;
		}
		s[ls]='\0';
		for(i=0;i<ls-1;i++)
		{
			l=find(s[i],s[i+1]);
			a[l].n++;
			if(l==t)
			{
				a[t-1].a=s[i];
				a[t-1].b=s[i+1];
				a[t-1].n=1;
				t++;
			}
		}
		sort(a,a+t,com);
		for(i=0;i<5;i++)
			printf("%c%c %d %.6lf\n",a[i].a,a[i].b,a[i].n,(a[i].n*1.0)/(ls-1.0));
		printf("\n");
	}
	return 0;
}



				

