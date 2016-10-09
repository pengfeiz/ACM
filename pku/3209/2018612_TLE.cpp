#include<cstdio>
#include<algorithm>

const	int	maxlen=100;


unsigned	__int64	n;


void	convertarr(unsigned __int64	a,int	t[])
{
	int	i;
	
	for (i=0;i<maxlen;i++)
		t[i]=0;
	
	while (a)
	{
		t[0]++;
		t[t[0]]=a%10;
		a/=10;
	}
}

void	convertnum(int	a[],unsigned __int64 &t)
{
	int	i;
	t=0;
	
	for (i=a[0];i>=1;i--)
		t=t*10+a[i];		
}

void	subtract(int a[],int b[],int c[])
{
	int	i;
	int	t[maxlen];
	
	memset(t,0,sizeof(t));
	
	t[0]=a[0];
	if (b[0]>t[0])t[0]=b[0];
	
	t[1]=0;
	
	for (i=1;i<=t[0];i++)
	{
		t[i]+=a[i]-b[i];
		if (t[i]<0)
		{			
			t[i+1]=-1;
			t[i]+=10;
		}
		else
			t[i+1]=0;
	}
	
	while ((t[t[0]]==0)&&(t[0]>1))t[0]--;
	
	memmove(c,t,sizeof(t));
}

void	multiply(int a[],int b[],int c[])
{
	int	i,j;
	int	t[maxlen];
	
	memset(t,0,sizeof(t));
	
	
	t[0]=a[0]+b[0];
	for (i=1;i<=t[0];i++)
		t[i]=0;
	
	for (i=1;i<=a[0];i++)
		for (j=1;j<=b[0];j++)
		{
			t[i+j]+=(t[i+j-1]+a[i]*b[j])/10;
			t[i+j-1]=(t[i+j-1]+a[i]*b[j])%10;
		}
		
	while ((t[t[0]]==0)&&(t[0]>1))t[0]--;
	
	memmove(c,t,sizeof(t));
}

bool	greater(int	a[],int b[])
{
	int	i;	
	
	if (a[0]>b[0])return(true);
	if (a[0]<b[0])return(false);
	
	for (i=a[0];i>=1;i--)
	{
		if (a[i]>b[i])return(true);
		if (a[i]<b[i])return(false);
	}
	
	return(true);
}

void	move(int a[],int t)
{
	int	i;	
	
	if ((a[0]==1)&&(a[1]==0))
	{
		a[1]=t;
		return;
	}
	
	for (i=a[0];i>=1;i--)
		a[i+1]=a[i];
		
	a[0]++;
	a[1]=t;
}

void	divide(int a[],int b[],int c[],int d[])
{
	int	i;
	int cc[maxlen],dd[maxlen];
	
	memset(cc,0,sizeof(cc));
	memset(dd,0,sizeof(dd));		
	dd[0]=1;	
	
	for (i=a[0];i>=1;i--)
	{
		move(dd,a[i]);
		while (greater(dd,b))
		{
			subtract(dd,b,dd);
			cc[i]++;
			if (!cc[0])cc[0]=i;
		}
	}
	
	memmove(c,cc,sizeof(cc));
	memmove(d,dd,sizeof(dd));
}

unsigned __int64	mulmod(unsigned	__int64 a,unsigned	__int64 b,unsigned __int64 n)
{
	int	aa[maxlen],bb[maxlen],nn[maxlen];
	unsigned	__int64	t;
	
	if ((a<=0xFFFFFFFF)&&(b<=0xFFFFFFFF))
		return((a*b)%n);
	
	convertarr(a,aa);
	convertarr(b,bb);
	convertarr(n,nn);
	
	multiply(aa,bb,aa);
	
	divide(aa,nn,aa,aa);
	
	return(convertnum(aa,t),t);
}

unsigned	__int64	gcd(unsigned __int64	a,unsigned __int64	b)
{
	unsigned __int64	t;

	while (b)
	{
		t=a;
		a=b;
		b=t%b;		
	}
	return(a);
}


bool	miller_rabbin(unsigned __int64	n)
{
	int	i;
	unsigned __int64 a,b,d,t;
	
	if (n==2)return(true);
	if (n%2==0)return(false);

	
	for (i=1;i<=100;i++)
	{
		a=rand()%(n-2)+2;
		b=n-1;
		d=1;
				
		while (b>0)
		{
			if (b&1) d=mulmod(d,a,n);
			
			t=mulmod(a,a,n);			
			if((a!=1)&&(a!=n-1)&&(t==1))return(false);
			a=t;
			b=b>>1;			
		}
		if (d!=1)return(false);
	}
	
	return(true);
}

unsigned __int64	rho1(unsigned __int64	n)
{
	unsigned __int64		i,x,y,k,d,c;
	


	while(true)
	{
		do
		{
			c=rand()%n;
		}while((c==0)||(c==2));
		x=rand()%n;
		y=x;		
		i=1;	
		k=2;
		do
		{			
			i++;	
			if (x>y)
				d=x-y;
			else
				d=y-x;
			d=gcd(d,n);
			if ((d>1)&&(d<n))return(d);
			if (i==k)
			{
				y=x;
				k=k<<1;
			}
			x=mulmod(x,x,n);
			if (x>c)
				x=(x-c)%n;
			else
				x=(c-x)%n;			
		}while ((x!=y)&&(i<0xFFFF));		
	}
}

unsigned __int64	rho2(unsigned __int64	n)
{
	unsigned __int64		i,x,y,k,d;

	x=rand()%n;
	y=x;		
	i=1;	
	k=2;
	while (true)
	{			
		i++;	
		
		if (x>y)
			d=x-y;
		else
			d=y-x;
		d=gcd(d,n);
		if ((d>1)&&(d<n))return(d);
		if (i==k)
		{
			y=x;
			k=k<<1;
		}
		x=mulmod(x,x,n);
		if (!x)
			x=n-1;
		else
			x=x-1;
			
	}
}

void	init()
{
	char		c;
	
	n=0;
	
	while(scanf("%c",&c)!=EOF)
	{	
		if (c=='-')
		{
			n=0;
			break;
		}
		if (c=='\n')break;
		n=n*10+c-'0';		
	}
	scanf("\n");
}

void	starmain()
{
	unsigned	__int64	t;
	int					sum;
	
	if (!n)
	{
		printf("NO\n");
		return;
	}
	
	while (n>1)
	{
		t=n;
		while (!miller_rabbin(t))
//			t=rho1(t);
			t=rho2(t);
				
		sum=0;		
		while (n%t==0)
		{
			n=n/t;
			sum++;
		}
		if ((t%4==3)&&(sum&1))
		{
			printf("NO\n");
			return;
		}
	}
	
	printf("YES\n");
}

int	main()
{
	int	i,t;
	
//	freopen("c:\\in.txt","r",stdin);
	
	scanf("%d\n",&t);
	for (i=1;i<=t;i++)
	{	
		init();
		starmain();
	}
	return(0);
}
