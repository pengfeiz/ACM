#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char s[50001];
char c[50001];
char ss[50001];
int m;


int main()
{
 //   freopen("01.in","r",stdin);
    int i,j,l,ll;
    bool f=true,ff;
    gets(s);
    m=0;
    l=strlen(s);
    for(i=0;i<l&&f;i++)
    {
        if(s[i]=='%')
        {
            i++;
            if(s[i]=='%')
            {
                ss[m++]='%';
                continue;
            }            
            if(!gets(c))
                f=false;
            if(s[i]=='d')
            {
                ll=strlen(c);
                if(ll==0)
                    f=false;
                for(j=0;j<ll;j++)
                    if(c[j]>'9'||c[j]<'0')
                        break;
                if(j<ll)
                {
                    f=false;
                    break;
                }
                ff=true;
                for(j=0;j<ll;j++)
                {
                    if(c[j]=='0'&&ff)
                        continue;
                    if(c[j])
                        ff=false;
                    ss[m++]=c[j];
                }
                if(ff)
                    ss[m++]='0';
            }
            else if(s[i]=='s')
            {
                ll=strlen(c);
                for(j=0;j<ll;j++)
                    ss[m++]=c[j];
            }
            else
                f=false;
        }
        else
            ss[m++]=s[i];
    }
    while(gets(c))
        f=false;
    ss[m]='\0';
    if(f)
        printf("%s\n",ss);
    else
        printf("ERROR\n");
    return 0;
}
