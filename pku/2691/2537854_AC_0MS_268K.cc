#include <iostream>
using namespace std;

int n,p;
char s1[81],s2[81];
double a,b;
int r,cc;

int main()
{
	int i,j,k;
	for(i=1;;i++)
	{
		scanf("%d%d",&n,&p);
		if(n==0&&p==0)
			break;
		
		getchar();
		cc=-1;
		for(j=0;j<n;j++)
			gets(s1);
		for(k=0;k<p;k++)
		{
			gets(s1);
			scanf("%lf%d",&a,&r);
			getchar();
			if(r>cc||(r==cc&&a<b))
			{
				cc=r;
				b=a;
				strcpy(s2,s1);
			}
			for(j=0;j<r;j++)
				gets(s1);	
		}
		if(i!=1)
			printf("\n");
		printf("RFP #%d\n%s\n",i,s2);
	}
	return 0;
}
