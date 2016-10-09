#include<iostream>

const   int     maxn=100;

struct  qnode
{
    int     v;
    qnode   *next;
};

qnode   mem[maxn];
int     mtail;

qnode   *head[maxn];

int     main()
{
    memset(head,0,sizeof(head));
    mtail=0;
    
    mtail++;
    mem[mtail];
    
    mem[mtail].next=head[0];
    head[0]=&mem[mtail];
    
    
    return(0);
}
