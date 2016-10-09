#include <iostream>
using namespace std;
#define MAX 1000
#define MAX2 11000000
char s[MAX];

int a[MAX],m,n,x,l,t;
bool d[MAX2];

void compute()
{
	int i,num;
	do{
		d[x]=true;
		t++;
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
				a[m-2]=(__int64)a[m-1]*(__int64)a[m-2]%n;
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
}


int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d%d",&n,&x),n)
	{
		gets(s);
		l=strlen(s);
		t=0;
		for(i=0;i<n;i++)
			d[i]=false;
		compute();
		for(i=0;i<n;i++)
			d[i]=false;
		t=0;
		compute();
		printf("%d\n",t);
	}
	return 0;
}

