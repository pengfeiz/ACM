#include <iostream.h> 
#include <string.h> 
char c[101][101],d[101][101]; 
bool a[27],b[101][101]; 

void solve(int x,int y,int fromx,int fromy) 
{ 
    if(c[x][y]=='-') 
    { 
        b[x][y]=b[fromx][fromy]; 
        c[x][y]=32; 
        solve(x,2*y-fromy,x,y);
    } 
	else if(c[x][y]==124) 
    { 
        b[x][y]=b[fromx][fromy]; 
        c[x][y]=32; 
        solve(2*x-fromx,y,x,y);
    } 
	else if(c[x][y]=='+') 
    { 
        b[x][y]=b[fromx][fromy]; 
        c[x][y]=32; 
        if(x>0&&(x-1!=fromx||y!=fromy)&&c[x-1][y]==124) 
            solve(x-1,y,x,y); 
        if(x<99&&(x+1!=fromx||y!=fromy)&&c[x+1][y]==124) 
            solve(x+1,y,x,y); 
        if(y>0&&(x!=fromx||y-1!=fromy)&&c[x][y-1]=='-') 
            solve(x,y-1,x,y); 
        if(y<99&&(x!=fromx||y+1!=fromy)&&c[x][y+1]=='-') 
            solve(x,y+1,x,y);
    } 
	else if(c[x][y]=='o') 
    { 
        b[x][y]=!b[fromx][fromy]; 
        c[x][y]=32;
            solve(x,y+1,x,y);
    } 
	else if(c[x][y]=='?') 
    { 
        b[x][y]=b[fromx][fromy]; 
        c[x][y]=32;
    } 
	else if(c[x][y]==')') 
    { 
        b[x][y]=b[x-1][y-1]&&b[x+1][y-1]; 
        c[x][y]=32; 
        solve(x,y+1,x,y);
    } 
	else if(c[x][y]=='>') 
    { 
        b[x][y]=b[x-1][y-1]||b[x+1][y-1]; 
        c[x][y]=32; 
        solve(x,y+1,x,y);
    } 
	else if(c[x][y]==':') 
    { 
        b[x][y]=b[fromx][fromy]; 
        c[x][y]=32; 
        solve(x,y+1,x,y);
    } 
	else if(c[x][y]=='\\'||c[x][y]=='/') 
    { 
        b[x][y]=b[fromx][fromy]; 
        c[x][y]=32;
    }
    else if(c[x][y]>='A'&&c[x][y]<='Z') 
    { 
        b[x][y]=a[c[x][y]-'A']; 
        c[x][y]=32;  
        if(x>0&&c[x-1][y]==124) 
            solve(x-1,y,x,y); 
        if(x<99&&c[x+1][y]==124) 
            solve(x+1,y,x,y); 
        if(y>0&&c[x][y-1]=='-') 
            solve(x,y-1,x,y); 
        if(y<99&&c[x][y+1]=='-') 
            solve(x,y+1,x,y);
    } 
} 

int main() 
{ 
    int i,l,j,xx,yy; 
    char q[80]; 
    for(i=0;i<=100;i++) 
        for(j=0;j<=100;j++) 
            d[i][j]=0; 
    cin.getline(d[0],101); 
    while(cin) 
    {
		i=0; 
		while(d[i][0]!='*') 
		{ 
			i++; 
			cin.getline(d[i],101); 
			l=strlen(d[i]); 
			for(j=0;j<l;j++) 
				if(d[i][j]=='?')
				{ 
					xx=i; 
					yy=j; 
				} 
		} 
		l=i-1; 
		cin.getline(q,80); 
		while(q[0]!='*') 
		{ 
			for(i=0;i<=l;i++) 
				for(j=0;j<100;j++) 
					c[i][j]=d[i][j]; 
			for(i=0;i<26;i++) 
				if(*(q+i)=='0') a[i]=false; 
				else a[i]=true; 
			for(j=0;j<100;j++) 
				for(i=0;i<=l;i++) 
				{ 
					if((c[i][j]>='A'&&c[i][j]<='Z')||c[i][j]==')'||c[i][j]=='>') //continue; 
					solve(i,j,0,0); 
				} 
			cout<<b[xx][yy]<<endl; 
			cin.getline(q,80); 
		} 
		cout<<endl; 
		cin.getline(d[0],101); 
    }
	return 0;
}