import java.util.*;

public class Main{
	static long[] a;
	static HashSet<Long> h=new HashSet<Long>();
	static long n,s;
	static int c,l;
	static void solve(long x)
	{
		if(x==0)
			return;
		if(x%11<10)
		{
			long temp=(x-x/11)*(long)Math.pow(10,l)+s;
			if(!h.contains(temp))
			{
				h.add(temp);
				a[c++]=(temp);
			}
		}
		if(x%2==0&&x>9)
		{
			long y=x%10/2;
			l++;
			s+=y*(int)Math.pow(10, l-1);
			solve(x/10);
			s+=5*(int)Math.pow(10, l-1);
			solve(x/10-1);
			l--;
			s%=(long)Math.pow(10, l);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		l=0;
		c=0;
		s=0;
		a=new long[1000];
		solve(n=in.nextLong());
		Arrays.sort(a,0,c);
		System.out.println(c);
		for(int i=0;i<c;i++)
		{
			System.out.print(a[i]+" + ");
			int t=(""+a[i]).length()-1,e=(""+(n-a[i])).length();
			while(e++<t)
				System.out.print(0);
			System.out.println((n-a[i])+" = "+n);
		}
	}

}