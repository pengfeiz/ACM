#include <stdio.h>
#include <string.h>

int tbl[110000][52];
int hand[52];
char* ranks = "A234567890JQK";
char* suits = "CDHS";
main() {
    while(1) {
        int nextnode = 1;
        int N, i;
        memset(tbl, 0, sizeof(tbl));
        scanf("%d ", &N);
        if(N<=0) break;
        while(N--) {
            int h;
            int node;
            scanf("%d ", &h);
            for(i = 0; i < h; i++) {
                char c;
                int node;
                scanf("%c", &c);
                if(c == '1') scanf("%c", &c);
                hand[i] = strchr(ranks, c) - ranks;
                scanf("%c ", &c);
                hand[i] += 13*(strchr(suits, c) - suits);
            }
            node = 0;
            for( i = h-1; i >= 0; i--) {
                if(tbl[node][hand[i]] == 0) {
                    tbl[node][hand[i]] = nextnode++;
                }
                node = tbl[node][hand[i]];
            }
        }
        printf("%d\n", nextnode-1);
    }
}
