import java.util.Scanner;

public class Main{

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		for(int k=1;k<=t;k++)
		{
			System.out.println("Scenario #"+k+":");
			int time=in.nextInt(),n=in.nextInt();
			int[] a=new int[n];
			int[] b=new int[n];
			int n2=0,t2=time,s2=0;
			for(int i=0;i<n;i++)
				a[i]=in.nextInt();
			int h;
			for(h=1;h<=(n-2)/9;h=3*h+1);
			for(;h>0;h/=3)
				for(int i=h;i<n;i++)
				{
					int j=i;
					int v=a[i];
					while(j>=h&&v<a[j-h])
					{
						a[j]=a[j-h];
						j-=h;
					}
					a[j]=v;
				}
			b[0]=a[0];
			for(int i=1;i<n;i++)
				b[i]=b[i-1]+a[i];
			for(int i=0;i<n;i++)
			{
				if(t2<a[i])
					break;
				t2-=a[i];
				s2+=b[i];
				n2++;
			}
			System.out.println("Steve wins with "+n2+" solved problems and a score of "+s2+".\n");
		}
	}

}
