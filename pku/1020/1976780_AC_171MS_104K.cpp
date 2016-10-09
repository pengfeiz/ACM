#include<iostream>
using namespace std;
#define MAX 40
int n,s;
int a[MAX][MAX],b[16],c[16];
int compare(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int dosth(int xx)
{
	int i,k1,k2,t=0,he=0,x,y;
	if(xx==s)
		return 1;
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
			if(a[x][y]==0)
			{
				t=1;
				break;
			}
		if(t==1)
			break;
	}
	for(i=0;i<s;i++)
	{
		if(he==b[i])
			continue;
		if(c[i]==0)
		{
			t=0;
			if(x+b[i]>n||y+b[i]>n)
				continue;
			for(k1=x;k1<b[i]+x;k1++)
			{
				for(k2=y;k2<b[i]+y;k2++)
					if(a[k1][k2]==1)
					{
						t=1;
						break;
					}
				if(t==1)
					break;
			}
			if(k1==b[i]+x&&k2==b[i]+y)
			{
				c[i]=1;
				for(k1=x;k1<b[i]+x;k1++)
					for(k2=y;k2<b[i]+y;k2++)
						a[k1][k2]=1;
				if(dosth(xx+1)==1)
					return 1;
				c[i]=0;				
				for(k1=x;k1<b[i]+x;k1++)
					for(k2=y;k2<b[i]+y;k2++)
						a[k1][k2]=0;
				he=b[i];
			}
		}
	}
	return 0;
} 
int main()
{
	int nn,i,t;
	cin>>nn;
	while(nn-->0)
	{
		cin>>n>>s;
		i=s;
		t=0;
		memset(a,0,MAX*MAX*sizeof(int));
		while(i-->0)
		{	
			c[i]=0;
			cin>>b[i];
			t+=b[i]*b[i];
		}
		if(t!=n*n)
		{	
			cout<<"HUTUTU!\n";
			continue;
		}
		qsort(b,s,sizeof(int),compare);
		if(dosth(0)==1)
			cout<<"KHOOOOB!\n";
		else
			cout<<"HUTUTU!\n";
	}
	return 0;
}
