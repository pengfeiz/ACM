#include<cstdio>
#include<algorithm>

int			a,b,c;
__int64		f[21][21][21];

void	init()
{
	scanf("%d %d %d\n",&a,&b,&c);	
	memset(f,128,sizeof(f));
	
	if ((a==-1)&&(b==-1)&&(c==-1))exit(0);
	if ((a>20)||(b>20)||(c>20))
	{
		a=20;
		b=20;
		c=20;
	}
	if (a<0)a=0;
	if (b<0)b=0;
	if (c<0)c=0;
}

__int64		w(int	a,int	b,int	c)
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
		printf("w(%d, %d, %d) = %I64d\n",a,b,c,w(a,b,c));
	}
	return(0);
}
