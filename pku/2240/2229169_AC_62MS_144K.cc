#include <iostream>
using namespace std;
#define MAX 100
#define MAX2 30

char s[MAX2][MAX];
double a[MAX2][MAX2];
int n,m;

int main()
{
	int i,p,q,tim=0;
	double x;
	char c1[MAX],c2[MAX];
	while(scanf("%d",&n),n)
	{
		tim++;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s%lf%s",c1,&x,c2);
			for(p=0;p<n;p++)
				if(strcmp(c1,s[p])==0)
					break;
			for(q=0;q<n;q++)
				if(strcmp(c2,s[q])==0)
					break;
			if(a[p][q]<x)
				a[p][q]=x;
		}
		for(i=0;i<n;i++)
			if(a[i][i]<1.0)
				a[i][i]=1.0;
		for(i=0;i<n;i++)
			for(p=0;p<n;p++)
				for(q=0;q<n;q++)
					if(a[p][q]<a[p][i]*a[i][q])
						a[p][q]=a[p][i]*a[i][q];
		for(i=0;i<n;i++)
			if(a[i][i]>1.0)
				break;
		if(i<n)
			printf("Case %d: Yes\n",tim);
		else
			printf("Case %d: No\n",tim);
	}
	return 0;
}