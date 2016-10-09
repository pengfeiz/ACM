#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 30001

struct gao
{
	int first;
	int n;
}a[MAX];

struct gao2
{
	char s[30];
	int num;
}c[MAX];

struct gao3
{
	char s[30];
}s[MAX];

int m;

bool com(gao2 a,gao2 b)
{
	int l1,l2;
	l1=strlen(a.s);
	l2=strlen(b.s);
	if(l1<l2)
		return true;
	else if(l1>l2)
		return false;
	return strcmp(a.s,b.s)<0;
}

bool com2(gao a,gao b)
{
	return a.n>b.n;
}

bool com3(gao3 a,gao3 b)
{
	int l1,l2;
	l1=strlen(a.s);
	l2=strlen(b.s);
	if(l1<l2)
		return true;
	else if(l1>l2)
		return false;
	return strcmp(a.s,b.s)<0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,t;
	t=1;
	memset(a,0,sizeof(a));
	while(scanf("%s",s[t].s)!=EOF)
		t++;
	strcpy(s[0].s," ");
	sort(s,s+t,com3);
	for(i=1;i<t;i++)
	{
		memcpy(c[i].s,s[i].s,sizeof(s[i].s));
		c[i].num=i;
		sort(c[i].s,c[i].s+strlen(c[i].s));
	}
	strcpy(c[0].s," ");
	c[0].num=0;
	sort(c,c+t,com);
	a[0].first=0;
	a[0].n=-999;
	for(i=1,m=0;i<t;i++)
	{
		if(strcmp(c[i].s,c[i-1].s)==0)
			a[m].n++;
		else
		{
			m++;
			a[m].first=i;
			a[m].n=1;
		}
	}
	sort(a+1,a+m,com2);
	if(m>5)
		m=5;
	for(i=1;i<=m;i++)
	{
		printf("Group of size %d: ",a[i].n);
		for(j=0;j<a[i].n;j++)
			printf("%s ",s[c[a[i].first+j].num].s);
		printf(".\n");
	}
	return 0;
}

	
