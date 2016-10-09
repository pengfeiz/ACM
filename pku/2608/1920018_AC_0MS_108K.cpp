#include <iostream>
using namespace std;
int main()
{
    char c;
    int t=0,time=0;
    while(time<10000)
    {
            time++;
            c=getchar();
            if(c=='\n')
            {
                 if(t==-1)
                 break;
                 cout<<'\n';
                 t=-1;
            }      
            else if(c=='B'||c=='F'||c=='P'||c=='V')
            {
                 if(t!=1)
                 cout<<1;
                 t=1;
            }
            else if(c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z')
            {
                 if(t!=2)
                 cout<<2;
                 t=2;
            }
            else if(c=='D'||c=='T')
            {
                 if(t!=3)
                 cout<<3;
                 t=3;
            }
            else if(c=='L')
            {
                 if(t!=4)
                 cout<<4;
                 t=4;
            }
            else if(c=='M'||c=='N')
            {
                 if(t!=5)
                 cout<<5;
                 t=5;
            }
            else if(c=='R')
            {
                 if(t!=6)
                 cout<<6;
                 t=6;
            }
            else
            t=0;
    }
    return 0;
}
                                      
    
