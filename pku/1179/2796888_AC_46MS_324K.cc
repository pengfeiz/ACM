#include <iostream>
using namespace std;


int a[100],b[100],n;
char o[100],p[100];

void init()
{
    int i;
    char s[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
        scanf("%s%d",s,&b[i]);
        o[i]=s[0];
    }
}

int maxx(int a,int b)
{return a>b?a:b;}
int minn(int a,int b)
{return a<b?a:b;}


int move()
{
    int i,j,k,f[100][100][2];
    for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			f[i][j][0]=0x7fffffff;
			f[i][j][1]=-0x7fffffff;
		}
    for(i=0;i<n;i++) f[i][i][0]=f[i][i][1]=a[i];
    for(i=n-2;i>=0;i--) 
		for(j=i+1;j<n;j++)
		{
			for(k=i;k<j;k++)
				if(p[k]=='t')
				{
					f[i][j][0]=minn(f[i][j][0],f[i][k][0]+f[k+1][j][0]);
					f[i][j][1]=maxx(f[i][j][1],f[i][k][1]+f[k+1][j][1]);
				}
				else
				{
					f[i][j][0]=minn(f[i][j][0],f[i][k][0]*f[k+1][j][0]);
					f[i][j][0]=minn(f[i][j][0],f[i][k][0]*f[k+1][j][1]);
					f[i][j][0]=minn(f[i][j][0],f[i][k][1]*f[k+1][j][0]);
					f[i][j][1]=maxx(f[i][j][1],f[i][k][0]*f[k+1][j][0]);
					f[i][j][1]=maxx(f[i][j][1],f[i][k][1]*f[k+1][j][1]);
				}
		}
    return f[0][n-1][1];
}


int main()
{
    int i,j,max=-0x7fffffff,ans[100];
    init();
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
		{
            a[j]=b[(i+j)%n];
            if(j<n-1)
				p[j]=o[(i+j+1)%n];
        }
        ans[i]=move();
        max=maxx(max,ans[i]);
    }
    printf("%d\n",max);
    for(i=0;i<n;i++)
		if(ans[i]==max)
			printf("%d ",i+1);
	printf("\n");
    return 0;
}