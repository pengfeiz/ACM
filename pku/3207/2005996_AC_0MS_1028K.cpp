#include <stdio.h>
#include <string.h>
#define MAX 1000
bool a[MAX][MAX];
int main()
{
	int n,m,i,j,t=1,p,q;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&p,&q);
		a[p][q]=true;
	}
	p=q=99999;
	for(i=0;i<n&&t;i++)
	{
		for(j=i;j<n&&t;j++)
			if(a[i][j])
			{
				if(j<p)
				{
					p=j;
					break;
				}
				else if(j<q)
				{
					q=j;
					break;
				}
				else if(j>q)
					t=0;
			}
		if(i>=p)
		{
			p=q;
			q=99999;
		}
	}
	if(t)
		printf("panda is telling the truth...\n");
	else
		printf("the evil panda is lying again\n");
	return 0;
}



		