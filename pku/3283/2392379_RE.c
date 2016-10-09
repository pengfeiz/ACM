#include <stdio.h>
#include <string.h>

int tbl[110000][52];
int hand[52];
char ranks[14]="A234567890JQK";
char suits[5]="CDHS";
int main()
{
	int n,i;
    while(scanf("%d",&n),n)
	{
        int nextnode=1;
        memset(tbl, 0, sizeof(tbl));
        while(n--)
		{
            int h;
            int node;
            scanf("%d ", &h);
            for(i=0;i<h;i++)
			{
                char c;
                scanf("%c", &c);          
                hand[i]=strchr(ranks,c)-ranks;
                scanf("%c",&c);
                hand[i]+=13*(strchr(suits,c)-suits);
            }
            node=0;
            for(i=h-1;i>=0;i--)
			{
                if(tbl[node][hand[i]]==0)
                    tbl[node][hand[i]]=nextnode++;
                node=tbl[node][hand[i]];
            }
        }
        printf("%d\n", nextnode-1);
    }
	return 0;
}
