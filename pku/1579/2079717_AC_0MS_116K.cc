#include<cstdio>
#include<algorithm>

int			a,b,c,ta,tb,tc;
int			f[21][21][21];

void	init()
{
	scanf("%d %d %d\n",&a,&b,&c);	
	ta=a;
	tb=b;
	tc=c;
	memset(f,128,sizeof(f));
	
	if ((a==-1)&&(b==-1)&&(c==-1))exit(0);
	if ((a<0)||(b<0)||(c<0))
	{
		a=0;
		b=0;
		c=0;
	}
	if ((a>20)||(b>20)||(c>20))
	{
		a=20;
		b=20;
		c=20;
	}
}

int		w(int	a,int	b,int	c)
{
	if (f[a][b][c]<0)
	{
		if (!a||!b||!c)
			f[a][b][c]=1;
		else	
			if ((a<b)&&(b<c))
				f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
			else
				f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
	return(f[a][b][c]);
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	while (true)
	{
		init();
		printf("w(%d, %d, %d) = %d\n",ta,tb,tc,w(a,b,c));
	}
	return(0);
}
