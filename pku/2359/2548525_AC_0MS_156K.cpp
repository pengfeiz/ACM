#include<cstdio>
#include<string>


const	int		maxn=40000;

char		s[maxn];
int			n;

int		main()
{
	int		i,pos;
	
//	freopen("c:\\in.txt","r",stdin);

	n=-1;
	while (!feof(stdin))
	{
		s[++n]=getchar();
		if ((s[n]=='\n')||(s[n]==9)||(s[n]==337))
			n--;
	}
	pos=0;
	for (i=2;i<=n;i++)
		pos=(pos+1999)%i;
	switch(s[pos])
	{
	case'?':
		printf("Yes\n");
		break;
	case' ':
		printf("No\n");
		break;
	default:
		printf("No comments\n");
	}
	
	return(0);
}
