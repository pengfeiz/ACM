
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
char b[MAX][7];
int num[MAX];
int com(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    char a[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};	
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		num[i]=0;
        for(j=0;j<7;j++)
    	{
            scanf("%c",&b[i][j]);
            if('A'<=b[i][j]&&b[i][j]<='Z')
    		{
                b[i][j]=a[b[i][j]-'A'];
                num[i]=b[i][j]-'0'+num[i]*10;
    		}
            else if((b[i][j]>'9'||b[i][j]<'0')&&(b[i][j]>'Z'||b[i][j]<'A'))
            	j=j-1;
            else num[i]=b[i][j]-'0'+num[i]*10;
    	}
    }
    qsort(num,n,sizeof(int),com);
    num[n]=0;
    for(i=0;i<n;i++)
    {
        if(num[i]==num[i+1])
        {
            j=1;
            while(num[i]==num[i+1]&&i<n-1)
            {
                i++;
                j++;
            }
            printf("%03d-%04d %d\n",num[i]/10000,num[i]%10000,j);
        }
    }    
    return 0;
}
