#include <iostream>
#include <string>
using namespace std;

int Group[256]={0};

void Shift(string& str);
void Init();
int main()
{
    int k[3];
    
    Init();
    
    cin>>k[0]>>k[1]>>k[2];
    while (k[0]!=0 || k[1]!=0 || k[2]!=0)
    {
        string msg;
        string groups[3];
        cin>>msg;
        
        int i, j, len=msg.length();
        
        for (i=0; i<len; i++)
        {
            groups[Group[msg[i]]]+=(msg[i]);
        }
        
        for (i=0; i<3; i++)
        {
            int t=groups[i].length();
			for(j=0;j<k[i];j++)
			  Shift(groups[i]);
        }
        
        k[0]=0;k[1]=0;k[2]=0;
        for (i=0; i<len; i++)
        {
            cout<<groups[Group[msg[i]]][k[Group[msg[i]]]];
            k[Group[msg[i]]]++;
        }
        cout<<endl;
        cin>>k[0]>>k[1]>>k[2];
    }

    return 0;
}

void Init()
{
    char i;
    for (i='a'; i<='i'; i++)
    {
        Group[i]=0;
    }
    for (i='j'; i<='r'; i++)
    {
        Group[i]=1;
    }
    for (i='s'; i<='z'; i++)
    {
        Group[i]=2;
    }
    Group['_']=2;
    
}

void Shift(string& str)
{
    int i, len=str.length();
    if (len>1)
    {
        char c=str[len-1];
        for (i=len-1; i>0; i--)
        {
            str[i]=str[i-1];
        }
        str[0]=c;
    }
}
