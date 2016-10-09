#include"stdio.h"
#include"math.h"
#define cw 4.19
#define ci 2.09
#define temp 335

void main()
{ double mw,mi,tw,ti;
  
  scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti);
 while(mw||mi||tw||ti)
 {
    if((mw*cw*tw)>((-mi*ci*ti)+temp*mi))
         printf("0.0 g of ice and %.1lf g of water at %.1lf C\n",(mw+mi),
                           ((mw*cw*tw+mi*ci*ti-temp*mi)/(mw*cw+mi*cw)));
  else if((-mi*ci*ti)<(mw*cw*tw+mw*temp))
             {               if(mw*cw*tw>(-mi*ci*ti))  
                printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n",(mi-(mw*cw*tw+mi*ci*ti)/335),(mw+(mw*cw*tw+mi*ci*ti)/335));
                else  printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n",(mi+(-mw*cw*tw-mi*ci*ti)/335),(mw-(-mw*cw*tw-mi*ci*ti)/335));
                }  
       else printf("%.1lf g of ice and 0.0 g of water at %.1lf C\n",(mw+mi),
                           ((mw*cw*tw+mw*temp+mi*ci*ti)/(mi*ci+mw*ci)));
   scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti);

 }
}
