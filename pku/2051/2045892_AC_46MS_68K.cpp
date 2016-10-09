#include <iostream>
#include <algorithm>
using namespace std;
struct gao
{
	int a,b;
}a[10000];
bool com(gao x,gao y)
{
	if(x.a<y.a)
		return true;
	else if(x.a==y.a&&x.b<y.b)
		return true;
	return false;
}
int main()
{
	char s[100];
	int n=0,i,m,t,k;
	while(scanf("%s",s)&&strcmp(s,"#")!=0)
	{
		scanf("%d%d",&a[n].a,&a[n].b);
		n++;
	}
	scanf("%d",&k);
	t=m=0;
	sort(a,a+n,com);
	while(t<k)
	{
		m++;
		for(i=0;i<n;i++)
		{
			if(m%a[i].b==0)
			{
				printf("%d\n",a[i].a);
				t++;
			}
		}
	}
	return 0;
}

		