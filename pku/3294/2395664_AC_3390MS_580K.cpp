#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1024
char s[MAX*MAX],*p[MAX*MAX],q[MAX],*findd;

bool com(char *s1,char *s2)
{
	return strcmp(s1,s2)<0;
}

int same(char *a, char *b)
{
    int i=0;
    while(a[i]&&a[i]==b[i])
		i++;
    return i;
}

int main()
{
	int i,j,k,n,c,x,best,time=0;
    while(scanf("%d",&n)&&n)
	{
        if(time++) 
			printf("\n");
        for(i=k=0;i<n;i++) 
		{
            scanf("%s",s+i*MAX);
            for(j=0;s[i*MAX+j];j++)
                p[k++]=s+i*MAX+j;
		}
        sort(p,p+k,com);
        memset(q,0,sizeof(q));
        best=0;
		for(i=j=c=0;i<k;) 
		{
			while(c<=n/2&&i<k)
				if(!(q[(p[i++]-s)/MAX]++)) 
					c++;
			while(c>n/2)
				if(!(--q[(p[j++]-s)/MAX])) 
					c--;
			if(j&&same(p[j-1],p[i-1])>best)
				best=same(p[j-1],p[i-1]);
		}
		if(!best) 
		{
			printf("?\n");
			continue;
		}
        findd="";
        memset(q,0,sizeof(q));
        for(i=j=c=0;i<k;) 
		{
			while(c<=n/2&&i<k) 
				if(!(q[(p[i++]-s)/MAX]++)) 
					c++;
			while(c>n/2)
				if(!(--q[(p[j++]-s)/MAX])) 
					c--;
			if(j&&same(p[j-1],p[i-1])==best) 
			{
				if(strncmp(findd,p[j-1],best)) 
				{
					findd=p[j-1];
					for(x=0;x<best;x++) 
						printf("%c",p[j-1][x]);
					printf("\n");
				}
			}
		}
	}
	return 0;
}

