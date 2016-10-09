#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define cc '*'
char s[MAX*10][MAX];
int n,l[MAX*10];
void dosthl()
{
	int i,ll;
	printf("%s",s[0]);
	ll=l[0];
	for(i=1;i<n;i++)
	{
		if(ll+l[i]<75)
		{
			printf("%s",s[i]);
			ll++;
			ll+=l[i];
		}
		else
		{
			ll=l[i];
			printf("%s",s[i]);
		}
	}
	printf("\n");
}

void dosthr()
{
	int i,ll,a[MAX],m,j;
	m=0;
	memset(a,0,sizeof(a));
	ll=l[0];
	a[m++]=0;
	for(i=1;i<n;i++)
	{
		if(ll+l[i]<75)
		{
			a[m++]=i;
			ll++;
			ll+=l[i];
		}
		else
		{
			for(j=75;j>ll;j--)
				printf("%c",cc);
			printf("%s",s[a[0]]);
			for(j=1;j<m;j++)
				printf("%c%s",cc,s[a[j]]);
			memset(a,0,sizeof(a));
			m=1;
			a[0]=i;
			printf("\n");
			ll=l[i];
		}
	}
	for(j=75;j>ll;j--)
		printf("%c",cc);
	printf("%s",s[a[0]]);
	for(j=1;j<m;j++)
		printf("%c%s",cc,s[a[j]]);
	memset(a,0,sizeof(a));
	m=1;
	a[0]=i;
	printf("\n");
}

void dosthc()
{
	int i,ll,a[50],m,j,k;
	m=0;
	memset(a,0,sizeof(a));
	ll=l[0];
	a[m++]=0;
	for(i=1;i<n;i++)
	{
		if(ll+l[i]<75)
		{
			a[m++]=i;
			ll++;
			ll+=l[i];
		}
		else
		{
			j=(75-ll)/2;
			for(k=0;k<j;k++)
				printf("%c",cc);
			printf("%s",s[a[0]]);
			for(k=1;k<m;k++)
				printf("%c%s",cc,s[a[k]]);
			memset(a,0,sizeof(a));
			j=75-ll-j;
			for(k=0;k<j;k++)
				printf("%c",cc);
			m=1;
			a[0]=i;
			printf("\n");
			ll=l[i];
		}
	}
	j=(75-ll)/2;
	for(k=0;k<j;k++)
		printf("%c",cc);
	printf("%s",s[a[0]]);
	for(i=1;i<m;i++)
		printf("%c%s",cc,s[a[i]]);
	j=75-ll-j;
	for(k=0;k<j;k++)
		printf("%c",cc);
	m=1;
	a[0]=i;
	printf("\n");
}

void dosthj()
{
	int i,ll,a[MAX],m,j,q,p,k,w;
	m=0;
	memset(a,0,sizeof(a));
	ll=l[0];
	a[m++]=0;
	for(i=1;i<n;i++)
	{
		if(ll+l[i]<75)
		{
			a[m++]=i;
			ll++;
			ll+=l[i];
		}
		else
		{
			k=0;
			if(m==1)
			{
				printf("%s",s[a[0]]);
				for(i=0;i<75-ll;i++)
					printf("%c",cc);
				printf("\n");
				continue;
			}
			q=(75-ll)/(m-1);
			p=75-ll-q*(m-1);
			q++;
			printf("%s",s[a[0]]);
			for(j=1;j<m;j++)
			{
				if(k<p)
				{
					printf("%c",cc);
					k++;
				}
				for(w=0;w<q;w++)
					printf("%c",cc);
				printf("%s",s[a[j]]);
			}
			memset(a,0,sizeof(a));
			m=1;
			a[0]=i;
			printf("\n");
			ll=l[i];
		}
	}
	if(m==1)
	{
		printf("%s",s[a[0]]);
		for(i=0;i<75-ll;i++)
			printf("%c",cc);
		printf("\n");
		return;
	}
	k=0;
	q=(75-ll)/(m-1);
	p=75-ll-q*(m-1);
	q++;
	printf("%s",s[a[0]]);
	for(j=1;j<m;j++)
	{
		if(k<p)
		{
			printf("%c",cc);
			k++;
		}
		for(w=0;w<q;w++)
			printf("%c",cc);
		printf("%s",s[a[j]]);
	}
	printf("\n");
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	char c;
	n=0;
	scanf("%c",&c);
	while(scanf("%s",s[n])!=EOF)
		n++;
	for(i=0;i<n;i++)
		l[i]=strlen(s[i]);
	if(c=='L')
		dosthl();
	else if(c=='R')
		dosthr();
	else if(c=='C')
		dosthc();
	else dosthj();
	return 0;
}



