#include <stdio.h>
#include <math.h>
#define w 4.19
#define i 2.09
#define temp 335
void main()
{ 
	double mw,mi,tw,ti;
	while(scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti)&&(mw||mi||tw||ti))
	{
		if((mw*w*tw)>(mi*i*ti+temp*mi))
			printf("0.0 g of ice and %.1lf g of water at %.1lf C\n",(mw+mi),((mw*w*tw+mi*i*ti-temp*mi)/(mw*w+mi*w)));
		else if((-mi*i*ti)<(mw*w*tw+mw*temp))
        {
            if(mw*w*tw>(-mi*i*ti))  
                printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n",(mi-(mw*w*tw+mi*i*ti)/temp),(mw+(mw*w*tw+mi*i*ti)/temp));
            else  
				printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n",(mi+(-mw*w*tw-mi*i*ti)/temp),(mw+(mw*w*tw+mi*i*ti)/temp));
        }  
        else 
			printf("%.1lf g of ice and 0.0 g of water at %.1lf C\n",(mw+mi),((mw*w*tw+mw*temp+mi*i*ti)/(mi*i+mw*i)));
	}
}


