#include <iostream>
using namespace std;

int r[25],t[25],s[25];
int n;

bool bellman(int sum)
{
	int i,j,k;
	bool f;
	for(j=0;j<25;j++)
	{
		f=false;
		for(i=23;i>=0;i--)
			if(s[i+1]<s[i])
				s[i]=s[i+1],f=true;		
		for(i=1;i<=24;i++)
			if(s[i-1]<s[i]-t[i])
				s[i]=s[i-1]+t[i],f=true;
		if(s[24]>sum+s[0])
			s[24]=sum+s[0],f=true;
		for(i=1;i<=24;i++)
		{
			k=(i+7)%24+1;
			if(k>i)
			{
				if(s[k]-s[i]<r[k])
					s[i]=s[k]-r[k],f=true;
			}
			else if(k<i)
			{
				if(s[k]-s[i]<r[k]-sum)
					s[i]=s[k]-r[k]+sum,f=true;
			}
		}
		if(!f)
			break;
	}
	if(j==25||s[0])
		return false;
	if(s[24]==sum)
		return true;
	return false;
}

int main()
{
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
/*		a=0;
		b=n;
		while(b>a)
		{
			memset(s,0,sizeof(s));
			mid=(a+b)/2;
			if(bellman(mid))
				b=mid;
			else
				a=mid+1;
		}*/
		for(b=0;b<=n;b++)
		{
			memset(s,127,sizeof(s));
			s[0]=0;
			if(bellman(b))
			{
				printf("%d\n",b);
				break;
			}
		}
		if(b>n)
			printf("No Solution\n");/*
		if(!bellman(b))
			printf("No Solution\n");
		else
			printf("%d\n",b);*/
	}
	return 0;
}
