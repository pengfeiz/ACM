#include <stdio.h>
#include <string.h>

int tbl[110000][52];
int hand[52];
char ranks[14]="A234567890JQK";
char suits[5]="CDHS";
int main()
{
	int n,i,node,h,next;
    while(scanf("%d",&n),n)
	{
        next=1;
        memset(tbl,0,sizeof(tbl));
        while(n--)
		{
            node=0;
            scanf("%d ",&h);
            for(i=0;i<h;i++)
			{
                char c;
                scanf("%c",&c);                
				if(c=='1')
					scanf("%c",&c);
                hand[i]=strchr(ranks,c)-ranks;
                scanf("%c ",&c);
                hand[i]+=13*(strchr(suits,c)-suits);
            }
            for(i=h-1;i>=0;i--)
			{
                if(tbl[node][hand[i]]==0)
                    tbl[node][hand[i]]=next++;
                node=tbl[node][hand[i]];
            }
        }
        printf("%d\n", next-1);
    }
	return 0;
}
