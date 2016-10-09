import java.util.Scanner;

public class Main{

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		long a=in.nextLong(),b=in.nextLong(),d=in.nextLong();
		while(a!=0&&b!=0&&d!=0)
		{
		
			long x1=0,y1=0;
			outside1:
			while(true)
			{
				if (a*x1<b*y1+d)
				{
					if (y1==0&&(d-a*x1)%b==0)
					{
						y1=(d-a*x1)/b;
						break outside1;
					}
					++x1;
					continue outside1;
				}
				if (a*x1==(b*y1+d))
				{
					break outside1;
				}
				else
					++y1;
			}
			
			
			long x2=0,y2=0;
			outside2:
			while(true)
			{
				if (b*y2<a*x2+d)
				{
					if (x2==0&&(d-b*y2)%a==0)
					{
						x2=(d-b*y2)/a;
						break outside2;
					}
					++y2;
					continue outside2;
				}
				if ((a*x2+d)==b*y2)
				{
					break outside2;
				}
				else
					++x2;
			}
			
			if((x1+y1)<(x2+y2)||((x2+y2)==(x1+y1)&&(x1*a+y1*b)<(x2*a+y2*b)))
				System.out.println(x1+" "+y1);
			else
				System.out.println(x2+" "+y2);
			a=in.nextLong();
			b=in.nextLong();
			d=in.nextLong();
		}
	}

}
