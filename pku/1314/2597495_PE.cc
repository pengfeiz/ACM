#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

char c[51][51];

struct gao
{
	char s[5];
}s[MAX];
int n,m;

bool com(gao a,gao b)
{return strcmp(a.s,b.s)<0;}


int main()
{
	int i,j,x,y,k,l,tim=0;		
	char ss[2];
	while(scanf("%d",&n),n)
	{
		memset(c,0,sizeof(c));
		m=0;
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d",ss,&x,&y);
			c[x][y]=ss[0];
		}
		for(i=0;i<=50;i++)
			for(j=0;j<=50;j++)
			{
				if(c[i][j])
				{
					for(k=j+1;k<=50;k++)
						if(c[i][k])
						{
							for(l=i+1;l<=50;l++)
							{
								if(c[l][j]&&c[l][k])
								{
									s[m].s[3]=c[i][j];
									s[m].s[0]=c[i][k];
									s[m].s[1]=c[l][k];
									s[m].s[2]=c[l][j];
									s[m].s[4]='\0';
									m++;
								}
							}
						}
				}
			}
		sort(s,s+m,com);
		printf("Point set %d:",++tim);
		if(!m)
			printf("\nNo rectangles\n");
		else
		{
			for(i=0;i<m;i++)
			{
				if(i%10==0&&i!=m-1)
					printf("\n");
				printf(" %s",s[i].s);
			}
			printf("\n");
		}
	}
	return 0;
}