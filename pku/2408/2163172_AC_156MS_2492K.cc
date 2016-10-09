#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 30002
#define MAX2 50

struct gao
{
	int first;
	int n;
}a[MAX];

struct gao2
{
	char s[MAX2];
	int num;
}c[MAX];

struct gao3
{
	char s[MAX2];
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
	l1=strcmp(a.s,b.s);
	if(l1<0)
		return true;
	else if(l1>0)
		return false;
	return strcmp(s[a.num].s,s[b.num].s)<0;
}

bool com2(gao a,gao b)
{
	int q;
	q=a.n-b.n;
	if(q!=0)
		return q>0;
	return strcmp(s[c[a.first].num].s,s[c[b.first].num].s)<0;
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
//	freopen("in2.txt","r",stdin);
	int i,j,t;
	t=1;
	memset(a,0,sizeof(a));
	while(scanf("%s",s[t].s)!=EOF)
		t++;
	strcpy(s[t].s,"#!@#@2");
	sort(s+1,s+t,com3);
	for(i=1;i<t;i++)
	{
		memcpy(c[i].s,s[i].s,sizeof(s[i].s));
		c[i].num=i;
		sort(c[i].s,c[i].s+strlen(c[i].s));
	}
	strcpy(c[0].s,"#!@#");
	sort(c+1,c+t,com);
	a[0].first=0;
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
	sort(a+1,a+m+1,com2);
	if(m>5)
		m=5;
	for(i=1;i<=m;i++)
	{
		printf("Group of size %d: ",a[i].n);
		t=a[i].first;
		for(j=0;j<a[i].n;j++,t++)
			if(strcmp(s[c[t].num].s,s[c[t+1].num].s))
				printf("%s ",s[c[t].num].s);
		printf(".\n");
	}
	return 0;
}

	
