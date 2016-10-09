#include <iostream>
using namespace std;
#define MAX 100002
int a[MAX],c,n,d[MAX];
int main()
{
    int i,x,s;
    while(scanf("%d%d",&c,&n),c)
    {
        memset(a,0,c*sizeof(int));
        memset(d,0xff,c*sizeof(int));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s=d[0]=0;
		for(i=1;i<=n;i++)
		{
			s+=a[i];
			s%=c;
			if(d[s]==-1)
				d[s]=i;
			else
			{
				x=d[s];
				break;
			}
		}
		printf("%d",x+1);
		for(x=x+2;x<=i;x++)
			printf(" %d",x);
        printf("\n");
    }
    return 0;
}
