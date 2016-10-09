#include<iostream.h>
#include<string.h> 
int main() 
{ 
    char s[150],c[10000]; 
    int i=0,sin=1,dy=0; 
    while(cin>>s) 
    { 
        if(s[0]=='<'&&s[1]=='b'&&s[2]=='r'&&s[3]=='>') 
		{ 
			c[i]='\n'; 
			dy=0; 
			sin=1; 
			i++; 
			continue; 
		}        
		if(s[0]=='<'&&s[1]=='h'&&s[2]=='r'&&s[3]=='>') 
		{ 
			if(dy%80==0) 
			{ 
				for(int j=0;j<80;j++,i++) 
					c[i]='-'; 
				c[i]='\n';
				dy=0; 
				i++; 
			}          
			else 
			{ 
				c[i]='\n'; 
				dy=0; 
				i++; 
				for(int j=0;j<80;j++,i++) 
				    c[i]='-'; 
				c[i]='\n'; 
				dy=0; 
				i++; 
			} 
			sin=1;
			continue; 
		}        
		if(sin==0 && strlen(s)+dy%80+1<=80) 
		{ 
			c[i]=' '; 
			dy++; 
			i++; 
		} 
	    if(strlen(s)+dy%80+1>80) 
		{ 
			c[i]='\n'; 
			dy=0; 
			i++; 
			for(int k=0;s[k]!='\0';k++,i++,dy++) 
				c[i]=s[k]; 
			sin=0; 
		} 
		else 
		{ 
			for(int k=0;s[k]!='\0';k++,i++,dy++) 
				c[i]=s[k]; 
		    sin=0; 
		} 
	} 
	c[i]='\0'; 
	cout<<c<<endl; 
	return 0;
} 