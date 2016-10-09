#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
char month1[19][8]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char month2[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int compare(char *ch)
{
	int i; 
	for(i=0;i<20;i++)
		if(strcmp(ch,month1[i])==0)
			break;
	return i;
}

int main()
{
	 long i,n,n1,n2,tt;
	 char ch[10];
	 cin>>n;
	 cout<<n<<endl;
	 for(i=0;i<n;i++)
	 {
		 cin>>n1;
		 getchar();
		 cin>>ch>>n2;
		 tt=n2*365+compare(ch)*20+n1;
		 cout<<(tt%13+1)<<" "<<month2[tt%20]<<" "<<tt/260<<endl;
	 }
	return 0;
}
