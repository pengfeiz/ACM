#include <iostream>
using namespace std;
#define MAX 2000
#define MAX2 11000002
char s[MAX];

__int64 a[MAX],m,n,x;
int d[MAX2];

__int64 gcd(__int64 n,__int64 m)
{
	__int64 t;
	while(n)
	{
		t=n;
		n=m%n;
		m=t;
	}
	return m;
}

int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,num,t,l,p,q,r;
	while(scanf("%I64d%I64d",&n,&x),n)
	{
		t=0;
		for(i=0;i<n;i++)
			d[i]=0;
		gets(s);
		p=q=-1;
		r=-9;
		l=strlen(s);
		do{
			t++;
			d[x]=t;
			if(p==-1)
				p=x;
			else if(q==-1)
				q=x;
			else if(r==-9)
				r=x;
			else if(p-q==q-r)
				break;
			m=0;
			i=1;
			while(i<l)
			{
				if(s[i]=='x')
					a[m++]=x;
				else if(s[i]=='N')
					a[m++]=n;
				else if(s[i]=='*')
				{
					a[m-2]=a[m-1]*a[m-2];
					if(a[m-2]>n)
						a[m-2]%=n;
					m--;
				}
				else if(s[i]=='+')
				{
					a[m-2]=a[m-1]+a[m-2];
					if(a[m-2]>n)
						a[m-2]%=n;
					m--;
				}
				else if(s[i]=='%')
				{
					a[m-2]=a[m-2]%a[m-1];
					m--;
				}
				else if(s[i]!=' ')
				{
					num=0;
					while(s[i]>='0'&&s[i]<='9')
						num=10*num+s[i++]-'0';
					if(num>n)
						num%=n;
					i--;
					a[m++]=num;
				}
				i+=2;
			}
			x=a[0];
		}while(!d[x]);
		if(p-q==q-r)
			printf("%d\n",n/gcd(q-p,n));
		else
			printf("%I64d\n",t-d[x]+1);
	}
	return 0;
}

