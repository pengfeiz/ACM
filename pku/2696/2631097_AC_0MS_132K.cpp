#include<iostream>
using namespace std;
int mod(int a,int b)
{
	int c=a%b;
	if(c>=0)
		return c;
	else
		c+=b;
	return c;
}
int main()
{
	int a,b,c,d,e,f,g,h,t,n,i;
	int f0,f1,f2,F;
	//freopen("in.txt","r",stdin);
    scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&n);
		
		f0=a;
		f1=b;
		f2=c;
		if(n==0)
		{
			cout<<a<<endl;
			continue;
		}
		else if(n==1)
		{
			cout<<b<<endl;
			continue;
		}
		else
		{
		
		for(i=3;i<=n;i++)
		{
			if(i%2==1)

			
			

				F=mod(d*f2+e*f1-f*f0,g);
			
		  else
               	F=mod(f*f2-d*f1+e*f0,h);
            f0=f1;
			f1=f2;
			f2=F;
		}
	     cout<<F<<endl;
		}

	}
	return 0;
}