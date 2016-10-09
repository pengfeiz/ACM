#include <stdio.h> 
#include <iostream.h>

char ch[10][15],color[10][15]; 

int place(int x,int y,int num) 
{ 
    int ret=1; 
    color[x][y]=num; 
    if (y<14&&color[x][y+1]==0&&ch[x][y]==ch[x][y+1]) 
        ret+=place(x,y+1,num); 
    if (y>0&&color[x][y-1]==0&&ch[x][y]==ch[x][y-1]) 
        ret+=place(x,y-1,num); 
    if (x<9&&color[x+1][y]==0&&ch[x][y]==ch[x+1][y]) 
        ret+=place(x+1,y,num); 
    if (x>0&&color[x-1][y]==0&&ch[x][y]==ch[x-1][y]) 
        ret+=place(x-1,y,num); 
    return ret; 
} 

int main() 
{ 
    int n,i,j,k,max,x,y,num,m,score,u,v; 
    int size[150]; 
	cin>>n;
    for(i=0;i<n;i++) 
    { 
        printf("Game %d:\n\n",i+1); 
        for(j=0;j<10;j++)
			for(k=0;k<15;k++) 
                cin>>ch[j][k];
        m=score=0; 
        while(1) 
        { 
            for(j=0;j<10;j++) 
                for(k=0;k<15;k++) 
                    color[j][k]=0; 
            num=max=0; 
            for(k=0;k<15&&ch[9][k]!=0;k++) 
                for(j=9;j>=0&&ch[j][k]!=0;j--) 
                    if(color[j][k]==0) 
                    { 
                        size[num]=place(j,k,num+1); 
                        if(max<size[num]) 
                        { 
                            max=size[num]; 
                            x=j; 
							y=k; 
                        } 
                        num++; 
                    } 
            if(max==1||max==0) 
                break; 
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",m+1,10-x,y+1,max,ch[x][y],(max-2)*(max-2)); 
			m++;
            score+=(max-2)*(max-2); 
            for(j=0;j<10;j++) 
                for(k=0;k<15;k++) 
                    if(color[j][k]==color[x][y]) 
                        ch[j][k]=0; 
            for(k=j=0;k<15;k++) 
            { 
                u=v=9; 
                while(v>=0) 
                { 
                    while(v>=0&&ch[v][k]==0) 
                        v--; 
                    while(v>=0&&ch[v][k]!=0) 
                    { 
                        if(u>v||j<k) 
                        { 
                            ch[u][j]=ch[v][k]; 
                            ch[v][k]=0; 
                        } 
                        u--;  
						v--; 
                    } 
                } 
                if(u<9) 
                    j++; 
            } 
        } 
        if (max==0) 
            score+=1000; 
        printf("Final score: %d, with %d balls remaining.\n\n",score,num); 
    }
	return 0;
} 