#include <iostream>
using namespace std;
#define MAX 240

struct gao
{
	int x[5];
}a[MAX],q[MAX];


int n,m,b[MAX][MAX],d[MAX];
char s[6];
int f[5];

void bulid(int x,int l)
{
	int i;
	f[x]=l;
	if(l==4)
	{
		for(i=0;i<5;i++)
			a[m].x[i]=f[i];
		m++;
		f[x]=-1;
		return;
	}

	for(i=0;i<5;i++)
		if(f[i]<0)
			bulid(i,l+1);
	f[x]=-1;
}

int judge(gao a,gao b)
{
	int i,j,k,l1,l2,s1,s2,t=0;
	for(i=0;i<4;i++)
		for(j=i+1;j<5;j++)
		{
			for(k=0;k<5;k++)
				if(a.x[k]==i)
				{
					l1=k;
					break;
				}
			for(k=0;k<5;k++)
				if(a.x[k]==j)
				{
					l2=k;
					break;
				}
			for(k=0;k<5;k++)
				if(b.x[k]==i)
				{
					s1=k;
					break;
				}
			for(k=0;k<5;k++)
				if(b.x[k]==j)
				{
					s2=k;
					break;
				}
			if(l1>l2&&s1<s2)
				t++;
			else if(l1<l2&&s1>s2)
				t++;
		}
	return t;
}

int main()
{
	int i,j,k,tt,t,he;
	m=0;
	for(i=0;i<5;i++)
		f[i]=-1;
	for(i=0;i<5;i++)
		bulid(i,0);
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			b[i][j]=judge(a[i],a[j]);
	while(scanf("%d",&n),n)
	{
		tt=0x7fffffff;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;j<5;j++)
				q[i].x[j]=s[j]-'A';
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				for(k=0;k<5;k++)
					if(q[i].x[k]!=a[j].x[k])
						break;
				if(k==5)
				{
					d[i]=j;
					break;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			t=0;
			for(j=0;j<n;j++)
				t+=b[i][d[j]];
			if(t<tt)
			{
				he=i;
				tt=t;
			}
		}
		for(i=0;i<5;i++)
			s[i]=a[he].x[i]+'A';
		s[5]='\0';
		printf("%s is the median ranking with value %d.\n",s,tt);
	}
	return 0;
}