#include <iostream>
#include <vector>
using namespace std;

struct gao
{
	char s[101];
	bool n;
};

vector<gao> a[101];
int n;

bool judge(char s1[101],char s2[101],int l)
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
//	freopen("in.txt","r",stdin);
	int i,l,ll;
	char s[101];
	vector<gao>::iterator q1,q2;
	gao p;
	scanf("%d",&n);

	scanf("%s",p.s);
	ll=strlen(p.s);
	p.n=true;
	a[ll].push_back(p);

	for(i=1;i<=n;i++)
	{
		scanf("%s",p.s);
		p.n=false;
		l=strlen(p.s);
		a[l].push_back(p);
	}

	for(i=ll;i<100;i++)
	{
		q1=a[i].begin();
		while(q1!=a[i].end())
		{
			if(q1->n)
			{
				strcpy(s,q1->s);
				q2=a[i+1].begin();
				while(q2!=a[i+1].end())
				{
					if(!q2->n&&judge(q1->s,q2->s,i))
						q2->n=true;
					q2++;
				}
			}
			q1++;
		}
	}
	printf("%s\n",s);
	return 0;
}