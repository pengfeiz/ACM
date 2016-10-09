#include<iostream.h>
#include<string.h>
#define MAX 330

void plus(char * num1,char * num2,char * result)
{
	int i,x,y;
	y=1;
	for(i=MAX-1;i>=0;i--)
	{
		x=num1[i]-'0'+num2[i]-'0'+y;
		y=x/10;
		x=x%10;
		result[i]=x+'0';
	}
}


int main()
{
	int total;
	char s[1000],c[MAX+1],temp[MAX+1],B[2][MAX+1],A[2][MAX+1];
	int i,j,length;
	cin>>total;
	c[MAX]=B[0][MAX]=A[0][MAX]=B[1][MAX]=A[1][MAX]='\0';
	while(cin)
	{
 		for(i=0;i<MAX;i++)
			B[0][i]=B[1][i]=c[i]='0';
        c[MAX-1]='1';
		length=-1;
		for(i=0;i<total;i++)
		{
		    cin>>s[i];
            if(s[i]=='1')
			    length=i+1;
		}
	    if(length==-1)
		    cout<<0<<endl;
	    else
		{
        if(s[0]=='0') 
		    B[1][MAX-1]='1';
	    else 
		    B[0][MAX-1]='1';
        for(i=1;i<length;i++)
		{
		    if(s[i]=='0')
			{
			    plus(B[1],c,A[1]);
                strcpy(B[1],A[1]);
			}
		    else 
			{   
				strcpy(temp,B[0]);
			    plus(B[1],c,A[0]);
			    strcpy(B[0],A[0]);
			    strcpy(B[1],temp);
		    }
		    for(j=0;j<MAX;j++)
				temp[j]='0';
			plus(c,c,temp);
			strcpy(c,temp);
		}
		i=0;
		while(B[0][i]=='0')
			i++;
		while(i<MAX)
		{	 
			cout<<B[0][i];i++;}
			cout<<endl;	
		}
		cin>>total;
	}

}