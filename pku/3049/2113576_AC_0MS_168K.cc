#include <iostream>
#include <algorithm>
using namespace std;

char a[15],b[15];
int n,m;

bool com(char a,char b)
{
	return a<b;
}

void dosth(int x,int y)
{
	int i,t1,t2;
	if(x==m)
	{
		t1=t2=0;
		for(i=0;i<m;i++)
		{
			if(b[i]=='a'||b[i]=='o'||b[i]=='e'||b[i]=='u'||b[i]=='i')
				t1++;
			else
				t2++;
		}
		if(t1<1||t2<2)
			return;
		for(i=0;i<m;i++)
			printf("%c",b[i]);
		printf("\n");
		return;
	}
	for(i=y;i<=n+x-m;i++)
	{
		b[x]=a[i];
		dosth(x+1,i+1);
	}
}

int main()
{
	int i;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,com);
	dosth(0,0);
	return 0;
}
	