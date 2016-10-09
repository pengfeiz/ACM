#include<iostream>
using namespace std;
int main(){
	char s[81],c;int i,j,n=0;
	s[0]=getchar();
	while(s[0]!=EOF){
		for(i=0;s[i]!=' '&&s[i]!='<'&&s[i]!='\n';)
			s[++i]=getchar();
		if(s[i]==' '){
			n+=i+1;if(n>79){if(n!=80){cout<<endl;}n=0;}
			for(j=0;j<i+1;j++)
				cout<<s[j];
			c=getchar();
			if(c==' '){
				while(c==' '){
					c=getchar();
				}
			}
			if(c=='<'){
				c=getchar();
				if(c=='b'){n=0;cout<<endl;}
				if(c=='h'){
					n=0;
					if(i!=79)cout<<endl;
					for(j=0;j<80;j++)
						cout<<'-';
					cout<<endl;
				}
				c=getchar();c=getchar();c=getchar();
				if(c==' '){
					while(c==' '){
						c=getchar();
					}
				}
			}
			s[0]=c;
			continue;
		}
		if(s[i]=='<'){
			for(j=0;j<i-1;j++)
				cout<<s[j];
			c=getchar();
			if(c=='b'){n=0;cout<<endl;}
			if(c=='h'){
				n=0;
				if(i>1&&i!=79)cout<<endl;
				for(j=0;j<80;j++)
					cout<<'-';
			}
			c=getchar();c=getchar();c=getchar();
			if(c==' '){
				while(c==' '){
					c=getchar();
				}
			}
			s[0]=c;
			continue;
		}
		if(s[i]=='\n'){
			n+=i;if(n>79){if(n!=80){cout<<endl;}n=0;}
			for(j=0;j<i;j++)
				cout<<s[j];
			c=getchar();
			if(c=='\n'){
				while(c=='\n'){
					c=getchar();
				}
			}
			if(i>1&&s[i-1]!=' ')cout<<' ';
			s[0]=c;
		}
	}
	cout<<endl;
return 0;
}