#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxm 10241

struct gao
{
    int t,n;
};

vector<gao> h4[maxm+1];
__int64 h8[1<<16];

int b[16],q[8];
int m=1<<16,tim;
int cc[16];
int sum[24],len;
__int64 ans;


void getsum(int i1,int i2,int i3,int i4)
{
	sum[len++]=i1*4+i2*3+i3*2+i4 ;
	sum[len++]=i1*4+i2*3+i4*2+i3 ;
	sum[len++]=i1*4+i3*3+i2*2+i4 ;
	sum[len++]=i1*4+i3*3+i4*2+i2 ;
	sum[len++]=i1*4+i4*3+i2*2+i3 ;
	sum[len++]=i1*4+i4*3+i3*2+i2 ;
}

void pushpush(int x)
{
    int i;
    gao h;
    len=0;
    getsum(q[0],q[1],q[2],q[3]);
    getsum(q[1],q[0],q[2],q[3]);
    getsum(q[2],q[1],q[0],q[3]);
    getsum(q[3],q[1],q[2],q[0]);
    h.t=1;
    h.n=x;
    sort(sum,sum+len);
    for(i=0;i<len-1;i++)
    {
        if(sum[i]==sum[i+1])
            h.t++;
        else
        {
            h4[sum[i]].push_back(h);
            h.t=1;
        }
    }
    h4[sum[i]].push_back(h);
}


void dosth(vector<gao> f)
{
    vector<gao>::iterator p,q;
    for(p=f.begin();p<f.end();p++)
        for(q=f.begin();q<f.end();q++)
            if(! ((p->n) & (q->n)) )
                h8[p->n+q->n]+=p->t*q->t;
}

void dosth2()
{
    int i,mm=m/2;
    ans=0;
    for(i=0;i<mm;i++)
        ans+=h8[i]*h8[i^(m-1)];
    printf("Case %d: %I64d\n",++tim,ans/4);
}

int main()
{
    freopen("in.txt","r",stdin);
    

    int i,t,j,i1,i2,i3,i4;
    for(i=0;i<16;i++)
        cc[i]=1<<i;
    
    while(scanf("%d",&b[0]),b[0])
    {
        memset(h8,0,sizeof(h8));
        for(i=1;i<16;i++)
            scanf("%d",&b[i]);
        sort(b,b+16);
        for(i=0;i<maxm;i++)
            h4[i].clear();	
        for(i1=0;i1<16;i1++)
		for(i2=0;i2<i1;i2++)
			for(i3=0;i3<i2;i3++)
				for(i4=0;i4<i3;i4++)
				{
                                    q[0]=b[i1];
                                    q[1]=b[i2];
                                    q[2]=b[i3];
                                    q[3]=b[i4];
                                    pushpush(cc[i1]+cc[i2]+cc[i3]+cc[i4]);
                                }
        for(i=0;i<maxm;i++)
            dosth(h4[i]);
        dosth2();
    }
    return 0;
}

