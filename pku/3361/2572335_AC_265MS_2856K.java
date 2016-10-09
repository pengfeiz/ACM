import java.io.*;
import java.util.*;

public class Main{
	static int n,k=1;
	static int[] prime,f=new int[5000];
	static int ps,p;
	static ArrayList<factor> a=new ArrayList<factor>();
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static void ini()
	{
		try {
			n=Integer.parseInt(br.readLine().trim());
		} catch (Exception e) {
			System.exit(0);
		}
		a.clear();
		p=0;
	}
	static void solve()
	{
		int temp=n;
		for(int i=0;i<ps&&prime[i]<=temp;i++)
			if(temp%prime[i]==0)
			{
				f[p++]=prime[i];
				while(temp%prime[i]==0)
					temp/=prime[i];
			}
		if(temp!=1)
			f[p++]=temp;
		for(int i=0;i<p;i++)
		{
			if(f[i]==2||f[i]%4==1)
			{
				int b=1,c;
				while(true)
				{
					c=(int)Math.sqrt(f[i]-b*b);
					if(b*b+c*c==f[i])
					{
						a.add(new factor(b,c));
						a.add(new factor(b,-c));
						break;
					}
					b++;
				}
			}
			else
				a.add(new factor(f[i],0));
		}
		Collections.sort(a);
		System.out.print("Case #"+k+++": ");
		factor ff=a.get(0);
		System.out.print(ff);
		
		for(int i=1;i<a.size();i++)
		{
			factor fa=a.get(i);
			if(fa.a==ff.a&&fa.b==ff.b)
				continue;
			else
				System.out.print(", "+fa);
			ff=fa;
		}
		System.out.println();
	}
	static void set()
	{
		prime=new int[500000];
		prime[0]=2;
		prime[1]=3;
		ps=2;
		for(int n=5;n<=500000;n+=2)
		{
			int i;
			for(i=1;prime[i]<=Math.sqrt(n)&&n%prime[i]!=0;i++);
			if(prime[i]*prime[i]>n)
				prime[ps++]=n;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		set();
		while(true)
		{
			ini();
			solve();
		}
	}

}
class factor implements Comparable<factor>{
	int a,b;
	factor(int x,int y)
	{
		a=x;
		b=y;
	}
	public String toString()
	{
		if(b==0)
			return ""+a;
		else
			if(b==1)
				return ""+a+"+j";
			else
				if(b==-1)
					return ""+a+"-j";
				else
					if(b>0)
						return ""+a+"+"+b+"j";
					else
						return ""+a+""+b+"j";
	}
	public int compareTo(factor o) {
		// TODO Auto-generated method stub
		if(a>o.a)
			return 1;
		if(a==o.a&&Math.abs(b)>Math.abs(o.b))
			return 1;
		if(a==o.a&&Math.abs(b)==Math.abs(o.b)&&b<o.b)
			return 1;
		return 0;
	}
	
}
