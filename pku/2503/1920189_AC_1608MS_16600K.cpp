#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std ;
int main()
{
     char buf[200],buf1[200],buf2[200];
     map<string, string> m1;
     map<string, string>::iterator p;
     while(gets(buf))
     {
          if(strcmp(buf,"")==0) 
			  break ;
          sscanf(buf,"%s%s",buf1,buf2) ;
          m1[buf2]=buf1;
     }
     while(gets(buf))
     {
          p=m1.find(buf) ;
          if(p!=m1.end())
              cout<<m1[buf]<<endl;
          else
              cout<<"eh"<<endl;
     }
     return 0 ;
}