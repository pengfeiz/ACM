#include<iostream>
using namespace std;
#define MAX 40
int n,s;
int a[MAX][MAX],b[16];
int compare(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int dosth(int x)
{
	int i,j,k1,k2,t;
	if(x==s)
		return 1;
	if(b[x]==0)
		return dosth(x+1);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==0&&n-i>=b[x]&&n-j>=b[x])
			{
				t=0;
				for(k1=i;k1<b[x]+i;k1++)
				{
					for(k2=j;k2<j+b[x];k2++)
						if(a[k1][k2]==1)
						{
							t=1;
							break;
						}
					if(t==1)
						break;
				}
				if(k1==i+b[x]&&k2==j+b[x])
				{
					for(k1=i;k1<b[x]+i;k1++)
						for(k2=j;k2<j+b[x];k2++)
							a[k1][k2]=1;
					if(dosth(x+1)==1)
						return 1;
					for(k1=i;k1<b[x]+i;k1++)
						for(k2=j;k2<j+b[x];k2++)
							a[k1][k2]=0;
					break;
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
