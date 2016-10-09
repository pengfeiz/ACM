#include <iostream>
using namespace std;
#define MAX 2000
#define MAX2 11000002
char s[MAX];

__int64 a[MAX],m,n,x;
int d[MAX2];



int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,num,t,l;
	while(scanf("%I64d%I64d",&n,&x),n)
	{
		t=0;
		for(i=0;i<n;i++)
			d[i]=0;
		gets(s);
		l=strlen(s);
		do{
			t++;
			d[x]=t;
			i=m=0;
			while(i<l)
			{
				if(s[i]==' ')
				{
					i++;
					continue;
				}
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
					a[m++]=num;
				}
				i++;
			}
			x=a[0];
		}while(!d[x]);
		printf("%I64d\n",t-d[x]+1);
	}
	return 0;
}

