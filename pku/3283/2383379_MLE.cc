#include <iostream>
#include <algorithm>
using namespace std;

int he[1100000][52];
int hand[52];
char *ranks="A234567890JQK";
char *suits="CDHS";
int main()
{
    int nextnode=1;
    int n,i;
    while(1)
	{
        memset(he,0,sizeof(he));
        scanf("%d ", &n);
        if(n<=0) break;
        while(n--)
		{
            int h;
            int node;
            scanf("%d ", &h);
            for(i = 0; i < h; i++) {
                char c;
                scanf("%c", &c);
                if(c == '1') scanf("%c", &c);
                hand[i] = strchr(ranks, c) - ranks;
                scanf("%c ", &c);
                hand[i] += 13*(strchr(suits, c) - suits);
            }
            sort(hand,hand+h);
            node = 0;
            for( i = h-1; i >= 0; i--) {
                if(he[node][hand[i]] == 0) {
                    he[node][hand[i]] = nextnode++;
                }
                node = he[node][hand[i]];
            }
        }
        printf("%d\n", nextnode-1);
    }
	return 0;
}
