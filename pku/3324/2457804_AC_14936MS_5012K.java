import java.math.*;
import java.util.Scanner;
public class Main{
	static BigInteger c=BigInteger.valueOf(-2);
	static BigInteger[] u=new BigInteger[8300];
	static BigInteger get(int x,BigInteger p,int t)
	{
		BigInteger a=BigInteger.valueOf(4).mod(p);
		for(int i=0;i<x;i++)
		{
			BigInteger b=a.multiply(a).add(c);
			BigInteger temp=b.and(p);
			a=b.shiftRight(t).add(temp);			
            temp=a.and(p);
            a=a.shiftRight(t).add(temp);
		}
		return a;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		while(in.hasNext())
		{
			int p=in.nextInt();
			if(u[p]==null)
				u[p]=BigInteger.valueOf(2).pow(p).add(BigInteger.valueOf(-1));
			System.out.println(get(p-2,u[p],p).mod(u[p]).toString(16));
			
		}
	}

} 