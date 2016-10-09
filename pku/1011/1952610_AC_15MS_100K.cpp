#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int a[64],n,t,c[64],len;
int search(int q, int rest, int pos)
{ 
	int flag=0; 
	if(rest==len) 
		flag = 1;
	int i; 
	if(q==t/len) 
		return 1; 
	for(i=pos;i<n;i++)  
		if(!c[i])  
		{   
			if(rest==a[i])   
			{    
				c[i]=1;    
				if(search(q+1,len,0))
					return 1;    
				c[i]=0;     
				return 0;  
            }   
			else if(a[i]<rest)   
			{    
				c[i]=1;    
				if(search(q,rest-a[i],i+1)) 
					return 1;    
				c[i]=0;    
				if(flag) return 0;    
				while(a[i]==a[i+1]) 
					i++;   
			}   
			else if(flag) 
				return 0;  
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
				len=t/i;
				memset(c,0,sizeof(c));
				if(search(1,t/i,0)==1)
					break;
			}
		cout<<t/i<<endl;
	}
	return 0;
}
		


				


