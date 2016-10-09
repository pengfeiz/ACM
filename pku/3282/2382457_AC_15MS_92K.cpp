#include <iostream>
using namespace std;
#define MAX 10000

int n,l,n1,n2;


int a[2][MAX];

int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j,tim,he,p;
	char c[10];
	scanf("%d",&t);
	while(t--)
	{
		n1=n2=0;
		scanf("%d%d",&l,&n);
		l*=100;
		for(i=0;i<n;i++)
		{
			scanf("%d%s",&he,c);
			if(c[0]=='l')
				a[0][n1++]=he;
			else
				a[1][n2++]=he;
		}
		a[0][n1]=a[1][n2]=99999999;
		tim=1;
		i=j=he=p=0;
		while(i!=n1||j!=n2)
		{
			if(he==0&&p+a[0][i]<=l)
			{
				p+=a[0][i];
				i++;
			}
			else if(he==1&&p+a[1][j]<=l)
			{
				p+=a[1][j];
				j++;
			}
			else
			{
				he=he^1;
				p=0;
				tim++;
			}
		}
		printf("%d\n",tim);
	}
	return 0;
}


