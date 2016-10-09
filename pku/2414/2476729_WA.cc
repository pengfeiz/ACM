#include <iostream>
using namespace std;

int b[513][1001][26];
char s[1001];
int n,l,q,t;

void dosth(int x,int d)
{
	int i,j,p1,p2,q1,q2;
	if(q==d)
	{
		scanf("%s",s);
		j=x>>1;
		for(i=0;i<l;i++)
			b[j][i][s[i]-'A']++;
		return;
	}
	dosth(2*x,d+1);
	dosth(2*x+1,d+1);
	if(d==q-1)
	{
		for(i=0;i<l;i++)
		{
			for(j=0;j<26;j++)
				if(b[x][i][j]==1)
				{
					t++;
					break;
				}
		}
		return;
	}
	q1=2*x;
	q2=2*x+1;
	for(i=0;i<l;i++)
	{
		p1=p2=0;
		for(j=0;j<26;j++)
		{
			if(b[q1][i][j]>b[q1][i][p1])
				p1=j;
			if(b[q2][i][j]>b[q2][i][p2])
				p2=j;
			b[x][i][j]=b[q1][i][j]+b[q2][i][j];
		}
		if(p1!=p2)
			t++;
	}
}
		
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,p,k;
	while(scanf("%d%d",&n,&l),n||l)
	{
		t=0;
		p=n>>1;
		for(i=0;i<p;i++)
			for(j=0;j<l;j++)
				for(k=0;k<26;k++)
					b[i][j][k]=0;
		q=0;
		j=n;
		while(j)
		{
			q++;
			j>>=1;
		}
		p=1;
		k=0;
		dosth(k,p);
		for(i=0;i<l;i++)
		{
			p=0;
			for(j=0;j<26;j++)
				if(b[0][i][j]>b[0][i][p])
					p=j;
			printf("%c",p+'A');
		}
		printf(" %d\n",t);
	}
	return 0;
}
