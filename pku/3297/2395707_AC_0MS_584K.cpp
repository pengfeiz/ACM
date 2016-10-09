#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10002
#define MAX2 102

struct gao
{
	char s[MAX2];
	int n;
}a[MAX],b[MAX2];

char c[MAX2];
int n,m;

bool com(gao a,gao b)
{
	int q=strcmp(a.s,b.s);
	if(q>0)
		return false;
	else if(q<0)
		return true;
	return a.n<b.n;
}

bool com2(gao a,gao b)
{
	if(a.n!=b.n)
		return a.n>b.n;
	return strcmp(a.s,b.s)<0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,p;
	bool f;
	n=m=0;
	while(1)
	{
		gets(c);
		if(strcmp(c,"1")==0)
		{
			sort(a,a+n,com);
			a[n].s[0]='@';
			a[n].s[1]='\0';
			for(i=0;i<n;i++)
			{
				p=i;
				f=false;
				while(strcmp(a[i].s,a[i+1].s)==0)
				{
					if(a[i].n!=a[i+1].n)
						f=true;
					i++;
				}
				if(f)
					continue;
				for(;p<=i;p++)
				{
					b[a[p].n].n++;
					while(a[p].n==a[p+1].n&&p<=i)
						p++;
				}
			}
			sort(b,b+m,com2);
			for(i=0;i<m;i++)
				printf("%s %d\n",b[i].s,b[i].n);
			n=m=0;
			continue;
		}
		else if(strcmp(c,"0")==0)
			return 0;
		else if(c[0]>='A'&&c[0]<='Z')
		{
			strcpy(b[m].s,c);
			b[m++].n=0;
		}
		else
		{
			strcpy(a[n].s,c);
			a[n++].n=m-1;
		}
	}
	return 0;
}
