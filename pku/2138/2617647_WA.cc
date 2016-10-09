#include <iostream>
#include <vector>
using namespace std;

struct gao
{
	char s[81];
	int n;
};

vector<gao> a[81];
int n;

bool judge(char s1[81],char s2[81],int l)
{
	int i,j;
	i=j=0;
	for(;i<l;i++,j++)
	{
		if(s1[i]!=s2[j])
		{
			if(i==j)
				j++;
			else
				return false;
		}
	}
	return true;
}
		
int main()
{
	int i,l,maxx=0;
	char s[81];
	vector<gao>::iterator q1,q2;
	gao p;
	scanf("%d",&n);

	scanf("%s",s);
	strcpy(p.s,s);
	p.n=1;
	a[3].push_back(p);

	for(i=1;i<=n;i++)
	{
		scanf("%s",p.s);
		p.n=0;
		l=strlen(p.s);
		if(l>=3)
			a[l].push_back(p);
	}

/*	q2=a[3].begin();
	while(q2!=a[3].end())
	{
		if(strcmp(q2->s,s)==0)
			q2->n=1;
		q2++;
	}*/
	for(i=3;i<=79;i++)
	{
		q1=a[i].begin();
		while(q1!=a[i].end()&&q1->n)
		{
			q2=a[i+1].begin();
			while(q2!=a[i+1].end())
			{
				if(q2->n<q1->n+1&&judge(q1->s,q2->s,i))
				{
					q2->n=q1->n+1;
					if(maxx<q2->n)
					{
						maxx=q2->n;
						strcpy(s,q2->s);
					}
				}
				q2++;
			}
			q1++;
		}
	}
	printf("%s\n",s);
	return 0;
}