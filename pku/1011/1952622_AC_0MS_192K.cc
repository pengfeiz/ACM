#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int a[64],n,t,c[64],l;
int sea(int q, int rest,int p)
{ 
	int f=0; 
	if(rest==l) 
		f=1;
	int i; 
	if(rest==0)
		return sea(q+1,l,0);
	if(q==t/l) 
		return 1; 
	for(i=p;i<n;i++)  
		if(!c[i]&&a[i]<=rest) 
		{    
			c[i]=1;    
			if(sea(q,rest-a[i],i+1)) 
				return 1;    
			c[i]=0;    
			if(f) 
				return 0;    
			while(a[i]==a[i+1]) 
				i++;
		} 
	return 0;
}
int com(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int i;
	while(cin>>n&&n)
	{
		for(i=t=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			t+=a[i];
		}
		qsort(a,n,sizeof(a[0]),com);
		for(i=n;i>0;i--)
			if(t%i==0)
			{
				if(a[0]>t/i)
					continue;
				l=t/i;
				memset(c,0,sizeof(c));
				if(sea(1,t/i,0)==1)
					break;
			}
		cout<<t/i<<endl;
	}
	return 0;
}
		


				


