#include <iostream>
using namespace std;
#define MAX 200
#define MAX2 12000000
char s[MAX];

__int64 a[MAX],m,n,x;
int d[MAX2];



int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,num,t,l;
	while(scanf("%I64d",&n),n)
	{
		t=0;
		scanf("%I64d",&x);
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
					a[m-2]%=n;
					m--;
				}
				else if(s[i]=='+')
				{
					a[m-2]=a[m-1]+a[m-2];
					a[m-2]%=n;
					m--;
				}
				else if(s[i]=='%')
				{
					a[m-2]=a[m-2]%a[m-1];
					a[m-2]%=n;
					m--;
				}
				else if(s[i]!=' ')
				{
					num=0;
					while(s[i]>='0'&&s[i]<='9')
						num=10*num+s[i++]-'0';
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

