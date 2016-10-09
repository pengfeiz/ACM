import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main{
	static void solve(int t,int a,int b)
	{
		System.out.print("("+t+"^"+a+"-1)/("+t+"^"+b+"-1) ");
		if(t==1||a%b!=0)
		{
			System.out.println("is not an integer with less than 100 digits.");
			return;
		}
		if(a==b)
		{
			System.out.println(1);
			return;
		}
		if((a-b)*Math.log(t)/Math.log(10)<102)
		{
			int k=a/b;
			BigInteger tot=BigInteger.ONE;
			BigInteger temp=BigInteger.valueOf(t).pow(b);
			tot=temp.pow(k).subtract(BigInteger.ONE).divide(temp.subtract(BigInteger.ONE));
			if(tot.toString().length()<100)
			{
				System.out.println(tot);
				return;
			}
		}
		System.out.println("is not an integer with less than 100 digits.");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str;
		try{
			while(true)
			{
				str=new StringTokenizer(br.readLine());
				int t=Integer.parseInt(str.nextToken()),a=Integer.parseInt(str.nextToken()),b=Integer.parseInt(str.nextToken());
				solve(t,a,b);
			}
		}
		catch(Exception e)
		{
			
		}
		
	}

} 