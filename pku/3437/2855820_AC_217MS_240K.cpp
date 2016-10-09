#include <iostream>
using namespace std;

int b[10001][2];
int f[10001];

char s[30001];

int main()
{
    int i,l,maxx,d,q,tim=0,dd,p;
    while(scanf("%s",s),strcmp(s,"#"))
    {
        tim++;
        maxx=d=q=p=dd=0;
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='d')
            {
                d++;
                if(d>dd)
                    dd=d;
                q++;
                f[q]=p;
                b[q][0]=b[p][0]+b[p][1]+1;
                b[p][1]++;
                p=q;
            }
            else
            {
                d--;
                p=f[p];
            }
        }
        for(i=0;i<=l/2;i++)
            if(b[i][0]>maxx)
                maxx=b[i][0];
        printf("Tree %d: %d => %d\n",tim,dd,maxx);
    }        
    return 0;
}

