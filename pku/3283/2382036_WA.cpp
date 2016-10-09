#include <iostream>
using namespace std;

int a[4][13],b[4][13];

char s[300000];
int main()
{
	int n,i,m,l,p,q,j;
	while(scanf("%d",&n),n)
	{
		memset(a,0,sizeof(a));
		while(n--)
		{
			memset(b,0,sizeof(b));
			scanf("%d",&m);
			gets(s);
			i=0;
			if(s[i]==' ')
				i++;
			l=strlen(s);
			for(;i<l;i+=3)
			{
				if(s[i]=='A')
					p=0;
				else if(s[i]=='J')
					p=10;
				else if(s[i]=='Q')
					p=11;
				else if(s[i]=='K')
					p=12;
				else
					p=s[i]-'1';
				if(s[i+1]=='C')
					q=0;
				else if(s[i+1]=='D')
					q=1;
				else if(s[i+1]=='H')
					q=2;
				else
					q=3;
				b[q][p]++;
			}
			for(i=0;i<4;i++)
				for(j=0;j<13;j++)
					if(b[i][j]>a[i][j])
						a[i][j]=b[i][j];
		}
		p=0;
		for(i=0;i<4;i++)
			for(j=0;j<13;j++)
				p+=a[i][j];
		printf("%d\n",p);
	}
	return 0;
}
