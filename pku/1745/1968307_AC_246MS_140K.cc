#include <iostream> 
#include <math.h>
using namespace std;




int d[105], e[105], a, n, k; 
int main () 
{ 
    int i, p, q; 
    scanf ( "%d%d", &n, &k ); 
    memset ( d, 0, k*sizeof(int) ); 
    scanf ( "%d", &a ); 
    a = a%k; 
    if ( a < 0 )    a += k; 
    d[a] = 1; 
    while ( --n ) 
    { 
        scanf ( "%d", &a ); 
        p = a%k; 
        q = (-a)%k; 
        if ( p < 0 ) p += k; 
        if ( q < 0 ) q += k; 
        memset ( e, 0, k*sizeof(int) ); 
        for ( i = 0; i < k; i ++, p ++, q ++ ) 
        { 
            if ( d[i] == 1 ) 
            { 
                e[p%k] = e[q%k] = 1; 
            } 
        } 
        memcpy ( d, e, k*sizeof(int) ); 
    } 
    printf ( d[0] ? "Divisible\n" : "Not divisible\n" ); 
    return 0; 
} 