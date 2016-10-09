#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<math.h>
#include<assert.h>
using namespace std;
#define NEG 1e-7

struct intersect
{
    int other; 
    char sign;
    double x, y, x0, y0;
}p[20][40];
struct circle{
    int x,y,r;
}cir[20];
int n,nsec[20];
bool v[20][40];


bool operator<(const intersect& x, const intersect& y)
{
    return atan2(x.y-x.y0,x.x-x.x0)<atan2(y.y-y.y0,y.x-y.x0)-NEG;
}
int Partition(intersect b[],int l,int r,int a)
{
    intersect x=b[l],t;
    int i=l-1,j=r+1;
    while(1)
    {
        do
		{
            --j;
        }while(x<b[j]);
        do
		{
            ++i;
        }while(b[i]<x);
        if(i<j)
		{
            p[b[i].other/100][b[i].other%100].other=a*100+j;
            p[b[j].other/100][b[j].other%100].other=a*100+i;
            t=b[i];b[i]=b[j];b[j]=t;
        }
        else return j;
    }
    return l;
}
void quicksort(intersect b[],int l,int r,int a)
{
    int n;
    if(l<r)
    {
        n=Partition(b,l,r,a);
        quicksort(b,l,n,a);
        quicksort(b,n+1,r,a);
    }
    return;
}


void GetPoint(int a,int b,intersect& p1,intersect& p2)
{
    int A,B,C,D,E,F;
    double A1,B1,C1;
    A=-2*cir[a].x;B=-2*cir[a].y;
    C=cir[a].x*cir[a].x+cir[a].y*cir[a].y-cir[a].r*cir[a].r;
    D=-2*cir[b].x;E=-2*cir[b].y;
    F=cir[b].x*cir[b].x+cir[b].y*cir[b].y-cir[b].r*cir[b].r;
    if(A==D)
    {
        p1.y=p2.y=(F-C)/(double)(B-E);
        p1.x=(-A+sqrt((double)A*A-4*(p1.y*p1.y+B*p1.y+C)))/2.0;
        p2.x=(-A-sqrt((double)A*A-4*(p2.y*p2.y+B*p2.y+C)))/2.0;
    }
    else if(B==E)
    {
        p1.x=p2.x=(F-C)/(double)(A-D);
        p1.y=(-B+sqrt((double)B*B-4*(p1.x*p1.x+A*p1.x+C)))/2.0;
        p2.y=(-B-sqrt((double)B*B-4*(p2.x*p2.x+A*p2.x+C)))/2.0;
    }
    else
    {
        A1=(double)(E-B)*(E-B)+(double)(A-D)*(A-D);
        B1=2.0*(E-B)*(F-C)+((double)D)*(A-D)*(E-B)+(A-D)*(A-D)*(double)E;
        C1=(double)(F-C)*(F-C)+((double)D)*(A-D)*(F-C)+((double)F)*(A-D)*(A-D);
        p1.y=(-B1+sqrt(B1*B1-4*A1*C1))/(2*A1);
        p2.y=(-B1-sqrt(B1*B1-4*A1*C1))/(2*A1);
        p1.x=(p1.y*(E-B)+(F-C))/(A-D);
        p2.x=(p2.y*(E-B)+(F-C))/(A-D);
    }
    return;
}

bool Cover(int k,intersect& p0)
{
    if((p0.x-cir[k].x)*(p0.x-cir[k].x)+(p0.y-cir[k].y)*(p0.y-cir[k].y)>cir[k].r*cir[k].r+NEG)
        return false;
    return true;
}

int Visit(int i,int j)
{
    double lx,ly,s;
    s=0;lx=p[i][j].x;ly=p[i][j].y;
    while(!v[i][j])
    {
        v[i][j]=true;
        i=p[i][j].other;
        j=i%100;
		i/=100; 
        v[i][j]=true;
        if(j<nsec[i]-1)
			j++;
        else 
			j=0;
        s+=(lx*p[i][j].y-ly*p[i][j].x)/2;
        lx=p[i][j].x;ly=p[i][j].y;
    }                             
    if(s>-NEG)
		return 0;       
    return 1;        
}

int main()
{
    int t,index,i,j,k;
    intersect p1,p2;
    cin>>t;
    for(index=1;index<=t;index++)
    { 
        cin>>n;
        for(i=0;i<n;i++)
            cin>>cir[i].x>>cir[i].y>>cir[i].r;
        fill(nsec,nsec+n,0);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                if((cir[i].x-cir[j].x)*(cir[i].x-cir[j].x)+(cir[i].y-cir[j].y)*(cir[i].y-cir[j].y)<(cir[i].r+cir[j].r)*(cir[i].r+cir[j].r))
                {
                    GetPoint(i,j,p1,p2);
                    for(k=0;k<n;k++)
                        if(k!=i&&k!=j&&Cover(k,p1))break;
                    if(k==n)
                    {
                        p[i][nsec[i]].x=p1.x;p[i][nsec[i]].y=p1.y;
                        p[j][nsec[j]].x=p1.x;p[j][nsec[j]].y=p1.y;
                        p[i][nsec[i]].x0=cir[i].x;p[i][nsec[i]].y0=cir[i].y;
                        p[j][nsec[j]].x0=cir[j].x;p[j][nsec[j]].y0=cir[j].y;
                        p[i][nsec[i]].other=j*100+nsec[j];
                        p[j][nsec[j]].other=i*100+nsec[i];
                        if((p1.x-cir[i].x)*(p2.y-cir[i].y)-(p1.y-cir[i].y)*(p2.x-cir[i].x)<-NEG)  
                        {
                            p[i][nsec[i]].sign='+';p[j][nsec[j]].sign='-';
                        }
                        else
                        {
                            p[i][nsec[i]].sign='-';p[j][nsec[j]].sign='+';
                        }
                        nsec[i]++;nsec[j]++;
                    }
                    for(k=0;k<n;k++)
                        if(k!=i&&k!=j&&Cover(k,p2))
							break;
                    if(k==n)
                    {
                        p[i][nsec[i]].x=p2.x;p[i][nsec[i]].y=p2.y;
                        p[j][nsec[j]].x=p2.x;p[j][nsec[j]].y=p2.y;
                        p[i][nsec[i]].x0=cir[i].x;p[i][nsec[i]].y0=cir[i].y;
                        p[j][nsec[j]].x0=cir[j].x;p[j][nsec[j]].y0=cir[j].y;
                        p[i][nsec[i]].other=j*100+nsec[j];
                        p[j][nsec[j]].other=i*100+nsec[i];
                        if((p1.x-cir[i].x)*(p2.y-cir[i].y)-(p1.y-cir[i].y)*(p2.x-cir[i].x)<-NEG)
                        {
                            p[i][nsec[i]].sign='-';p[j][nsec[j]].sign='+';
                        }
                        else
                        {
                            p[i][nsec[i]].sign='+';p[j][nsec[j]].sign='-';
                        }
                        nsec[i]++;nsec[j]++;
                    }
                }
            quicksort(p[i],0,nsec[i]-1,i);
        }
        fill(&v[0][0],&v[n][0],false);
        int s=0;
        for(i=0;i<n;i++)
            for(j=0;j<nsec[i];j++)
                if(!v[i][j])   
                    if(p[i][j].sign=='-')s+=Visit(i,j);
                    else s+=Visit(p[i][j].other/100,p[i][j].other%100);
        cout<<s<<endl;
    }
    return 0;
}