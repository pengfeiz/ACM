#include <stdio.h>
#define MAX 100
char s[MAX];
long f[MAX];
int main()
{
    int n,i,j,time=0,lw,lf;
    while(scanf("%d", &n),n)
	{
        time++;
        scanf("%s",s+1);
        printf("Test case #%d\n",time);
        f[1]=0;
        for(i=2;i<=n+1;i++) 
		{
            s[0]=s[i-1];
            for(j=f[i-1];s[j]!=s[i-1];j=f[j])
				;
            f[i]=j+1;
            lw=i-1; 
			lf=f[i]-1;
            if(lf&&i>2&&lw%(lw-lf)==0) 
                printf("%d %d\n",lw,lw/(lw-lf));
        }
        printf("\n");
    }
	return 0;
}       