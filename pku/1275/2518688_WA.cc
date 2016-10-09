#include <iostream>
using namespace std;

int r[25],t[25],s[25];
int n;

bool bellman(int sum)
{
	int i,j,k;
	bool f;
	for(j=0;j<50;j++)
	{
		f=false;
		for(i=1;i<=24;i++)
		{
			k=(i+7)%24+1;
			if(k>i)
			{
				if(s[k]-s[i]<r[i])
					s[k]=s[i]+r[i],f=true;
			}
			else if(k<i)
			{
				if(s[k]-s[i]<r[i]-sum)
					s[i]=s[k]-r[i]+sum,f=true;
			}
		}
		for(i=0;i<24;i++)
			if(s[i+1]<s[i])
				s[i+1]=s[i],f=true;		
		for(i=1;i<=24;i++)
			if(s[i]>s[i-1]+t[i])
				s[i]=s[i-1]+t[i],f=true;
		if(s[24]-s[0]<sum)
			s[24]=sum,f=true;
		if(!f)
			break;
	}
	if(s[24]==sum)
		return true;
	return false;
}



int main()
{
//	freopen("in.txt","r",stdin);
	int tt,i,y,a,b,mid;
	scanf("%d",&tt);
	while(tt--)
	{
		memset(r,0,sizeof(r));
		memset(t,0,sizeof(t));
		for(i=1;i<=24;i++)
			scanf("%d",&r[i]);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&y);
			t[y+1]++;
		}
		a=0;
		b=99999;
		while(b>a)
		{
			memset(s,0,sizeof(s));
			mid=(a+b)/2;
			if(bellman(mid))
				b=mid;
			else
				a=mid+1;
		}
		printf("%d\n",b+1);
	}
	return 0;
}