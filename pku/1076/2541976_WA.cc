#include <iostream>
using namespace std;

char s[101];
char c[1000];
int a[101];
int b[101];

int main()
{
//	freopen("in.txt","r",stdin);
	char cc;
	int x,y,i;
	while(scanf("%s",s)!=EOF)
	{
		memset(c,0,sizeof(c));
		memset(b,1,sizeof(b));
		printf("%-13s",s);
		for(i=0;i<9;i++)
		{
			scanf("%d",&x);
			y=0;
			if(x==-1)
				break;
			if(i)
			{
				if(b[i-1])
				{
					b[i-1]--;
					a[i-1]+=10-x;
				}
			}
			if(i>1)
			{
				if(b[i-2])
				{
					b[i-2]--;
					a[i-2]+=10-x;
				}
			}
			if(x==0)
			{
				a[i]=10;
				b[i]=2;
				strcpy(c+i*4,"X   ");
			}
			else
			{
				if(x==10)
					c[i*4]='-';
				else
					c[i*4]=10-x+'0';
				cc=10-x+'0';
				scanf("%d",&y);
				if(y==-1)
					break;
				if(y==0)
				{
					a[i]=10;
					b[i]=1;
					strcpy(c+i*4+1,"/  ");
				}
				else if(y==10)
				{
					a[i]=0;
					b[i]=0;
					strcpy(c+i*4+1,"-  ");
				}
				else
				{
					a[i]=10-y;
					b[i]=0;
					cc=x-y+'0';
					c[i*4+1]=cc;
					strcpy(c+i*4+2,"  ");
				}
				if(i)
				{
					if(b[i-1])
					{
						b[i-1]--;
						a[i-1]+=x-y;
					}
				}
				if(i>1)
				{
					if(b[i-2])
					{
						b[i-2]--;
						a[i-2]+=x-y;
					}
				}
			}
		}
		if(i==9)
		{
			for(i=0;i<4;i++)
			{
				scanf("%d",&x);
				if(x==-1)
					break;
				if(x==0)
				{
					c[36+i]='X';
					a[9]=10-x;
					if(!i)
						b[9]=2;
				}
				else if(x==10)
					c[36+i]='-';
				else
					c[36+i]=10-x+'0';
				if(b[9]&&i)
				{
					b[9]--;
					a[9]+=10-x;
				}
				if(b[8])
				{
					b[8]--;
					a[8]+=10-x;
				}
				if(b[7])
				{
					b[7]--;
					a[7]+=10-x;
				}
				if(x)
				{
					i++;
					scanf("%d",&y);
					if(y==-1)
						break;
					if(y==0)
					{
						c[36+i]='/';
						if(i==1)
						{
							a[9]=10-y;
							b[9]=1;
						}
					}
					else if(y==10)
						c[36+i]='-';
					else
						c[36+i]=x-y+'0';
					if(b[9]&&i>1)
					{
						a[9]+=x-y;
						b[9]--;
					}
					if(b[8])
					{
						b[8]--;
						a[8]+=x-y;
					}
					if(b[7])
					{
						b[7]--;
						a[7]+=x-y;
					}
				}
			}
		}
		printf("%s\n",c);
		for(i=0;i<12;i++)
			printf(" ");
		x=0;
		for(i=0;i<10;i++)
			if(!b[i])
			{
				x+=a[i];
				printf(" %3d",x);
			}
		printf("\n");
	}
	return 0;
}