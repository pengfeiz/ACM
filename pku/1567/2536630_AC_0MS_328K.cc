#include <iostream.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define barwidth 25
#define maxwidth 1024
#define maxheight 1024

struct win
{
	int top,left,bottom,right;
	int oldtop,oldleft,oldbottom,oldright;
	int fullsize;
	int id;
}window[100];

int numwin=0;

int inwindow(int x,int y)
{
	int i;
	for(i=numwin-1;i>=0;i--)
		if(x>=window[i].left&&x<=window[i].right&&y>=window[i].top&&y<=window[i].bottom)
			return i;
	return -1;
}

int inbar(int x,int y)
{return numwin!=0
&&x>=window[numwin-1].left+barwidth
&&x<=window[numwin-1].right-barwidth
&&y>=window[numwin-1].top
&&y<window[numwin-1].top+barwidth;}
int inclose(int x,int y)
{return numwin!=0
&&x>=window[numwin-1].left
&&x<window[numwin-1].left+barwidth
&&y>=window[numwin-1].top
&&y<window[numwin-1].top+barwidth;}
int inzoom(int x,int y)
{return numwin!=0
&&x>window[numwin-1].right-barwidth
&&x<=window[numwin-1].right
&&y>=window[numwin-1].top
&&y<window[numwin-1].top+barwidth;}


int main()
{
	char ch1,ch2;
	int top,right,bottom,left,x,y,current,savex,savey,id=0,j,i;
	int moving=FALSE,canclose=FALSE,canzoom=FALSE;
	struct win tempwin;
	int done=FALSE;
	while(!done)
	{
		cin>>ch1>>ch2;    
		switch (ch1)
		{
			case 'C':cin>>left>>top>>right>>bottom;
				break;
			case 'R':
				break;
			case 'Z':
				break;
			default :cin>> x >> y;
				break;
		}    
		switch (ch1)
		{
			case 'A':
      			if(moving)
				{
					window[numwin-1].left += (x-savex);
					window[numwin-1].right += (x-savex);
					window[numwin-1].top += (y-savey);
					window[numwin-1].bottom += (y-savey);
					cout<<"Moved window "<<window[numwin-1].id <<" to "<<window[numwin-1].left<<", "<< window[numwin-1].top << ", "<<window[numwin-1].right <<", "<<window[numwin-1].bottom<<endl;
					savex=x;
					savey=y;
				}
				break;        
			case 'C':
				window[numwin].top=top;
				window[numwin].right=right;
				window[numwin].bottom=bottom;
				window[numwin].left=left;
				window[numwin].fullsize=FALSE;
				window[numwin].id=id++;
				cout<<"Created window "<<window[numwin].id<<" at "<<left<<", "<<top<<", "<<right<<", "<<bottom<<endl;
				numwin++;
				break;        
			case 'D':
				current=inwindow(x,y);
				if(current!=-1)
       			{	
					cout<<"Selected window "<<window[current].id<<endl;
					tempwin=window[current];
					for(i=current+1;i<numwin;i++)
						window[i-1]=window[i];
					window[numwin-1]=tempwin;
					moving=inbar(x,y)&&!window[numwin-1].fullsize;
					canclose=inclose(x,y);
					canzoom=inzoom(x,y);
					savex=x;
					savey=y;
				}
				break;        
			case 'R':
				for(j=0;j<numwin;j++)
					cout<<"Window "<<window[j].id<<" at "<<window[j].left<<", "<<window[j].top<<", "<<window[j].right<<", "<<window[j].bottom<<endl;
				break;        
			case 'U':
				if(moving)
				{
					window[numwin-1].left+=(x-savex);
					window[numwin-1].right+=(x-savex);
					window[numwin-1].top+=(y-savey);
					window[numwin-1].bottom+=(y-savey);
					cout<<"Moved window "<<window[numwin-1].id<<" to "<<window[numwin-1].left<<", "<<window[numwin-1].top<<", "<<window[numwin-1].right<<", "<<window[numwin-1].bottom<<endl;
				}
				else if(numwin&&canclose&&inclose(x,y))
				{
					cout<<"Closed window "<<window[numwin-1].id<<endl;
					numwin--;
				}
				else if(numwin&&canzoom&&inzoom(x,y))
				{
					if(window[numwin-1].fullsize)
					{
						window[numwin-1].left=window[numwin-1].oldleft;
						window[numwin-1].right=window[numwin-1].oldright;
						window[numwin-1].top=window[numwin-1].oldtop;
						window[numwin-1].bottom=window[numwin-1].oldbottom;
						window[numwin-1].fullsize=FALSE;
					}
					else
					{
						window[numwin-1].oldleft=window[numwin-1].left;
						window[numwin-1].oldright=window[numwin-1].right;
						window[numwin-1].oldtop=window[numwin-1].top;
						window[numwin-1].oldbottom=window[numwin-1].bottom;
						window[numwin-1].left=0;
						window[numwin-1].right=maxwidth-1;
						window[numwin-1].top=0;
						window[numwin-1].bottom=maxheight-1;
						window[numwin-1].fullsize=TRUE;
					}
					cout<<"Resized window "<<window[numwin-1].id<<" to "<<window[numwin-1].left<<", "<<window[numwin-1].top<<", "<<window[numwin-1].right<<", "<<window[numwin-1].bottom<<endl;
				}
				moving=canclose=canzoom=FALSE;
				break;

			case 'Z':
				done=TRUE;
		}
	}
	return 0;
}
