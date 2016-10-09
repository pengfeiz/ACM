#include <iostream>
using namespace std;

int upC,dow,pend;
int up,down;

char state;
int thi,last;

int main()
{
    float avgUp,avgDown;
    int done=0;
    while(!done)
    {
        state='S';
        upC=0;dow=0;pend=0;
        up=0;down=0;
        while (1)
        {
            cin>>thi;
            if((state=='S')&&(thi==0))
            {
                done=1;
                break;
            }
            else if(thi==0)
                break;
            switch(state)
            {
                case 'S':
                state = 'N';
                break;
                case 'N':
                if(thi==last)
                    pend++;
                else if(thi<last)
                {
                    state='D';
                    dow=pend+1;
                    down++;
                }
                else if(thi>last)
                {
                    state='U';
                    upC=pend+1;
                    up++;
                }
                break;
                case 'D':
                if(thi<=last)
                     dow++;
                else if(thi>last)
                {
                    state='U';
                    upC++;
                    up++;
                }
                break;
                case 'U':
                if(thi>=last)
                    upC++;
                else if(thi<last)
                {
                    state='D';
                    dow++;
                    down++;
                } 
                break;
            }
        last=thi;
        }
        if(state!='S')
        {
            if(up)
                avgUp=(float)upC/up;
            else
                avgUp=0.0;
            if(down)
                avgDown=(float)dow/down;
            else
                avgDown=0.0;
            cout<<avgUp<<" "<<avgDown<<endl;
        }
    }
}

