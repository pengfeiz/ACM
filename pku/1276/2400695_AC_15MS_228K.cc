#include <iostream>
int main()
{
	int i,j,k,c,b,m,n;
	while(scanf("%d",&m)!=EOF)
	{
		bool a[100001]={0};
		a[0]=true;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&c,&b);
			c*=b;
			for(j=m;j>=0;j--)
				if(a[j])
					for(k=b;k<=c&&(j+k)<=m&&!a[j+k];k+=b)
						a[j+k]=true;
		}
		for(i=m;i>=0&&!a[i];i--);
		printf("%d\n",i);
	}
	return 0;
}