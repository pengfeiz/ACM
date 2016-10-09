import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static String[] temp;
	static int maxn=50010,maxlen=6,n,ttail,xtail;
	static int[] q=new int[maxn],t=new int[maxn],x=new int[maxn];
	static HashMap<Integer,Integer> h=new HashMap<Integer,Integer>();
	static BigInteger[][] f=new BigInteger[maxlen][maxn];
	static BigInteger[] a=new BigInteger[maxn];
	static void ini()
	{
		
		try {
			n=Integer.parseInt(br.readLine().trim());
//			n=50000;
			temp=br.readLine().split(" ");
			ttail=0;
			for(int i=1;i<=n;i++)
			{
				q[i]=Integer.parseInt(temp[i-1]);
//				q[i]=i;
				ttail++;
				t[ttail]=q[i];
			}
			h.clear();
			Arrays.sort(t,1,ttail+1);
			xtail=0;
			x[0]=Integer.MAX_VALUE;
			for(int i=1;i<=ttail;i++)
				if(t[i]!=x[xtail])
				{
					xtail++;
					h.put(t[i], xtail);
				}
			for(int i=1;i<=n;i++)
				q[i]=h.get(q[i]);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.exit(0);
		}
		
	}
	static int lowbit(int t)
	{
		return t&(-t);
	}
	static BigInteger sum(int	i)
	{
		BigInteger ret;
		ret=BigInteger.ZERO;
//		System.out.println(i);
		for (;i>0;i-=lowbit(i))
		{
//			System.out.println(i);
			ret=ret.add(a[i]);
		}
		return(ret);
	}
	static void	update(int i,BigInteger d)
	{
		for (;i<=n;i+=lowbit(i))
			a[i]=a[i].add(d);
	}
	static void solve()
	{
		int	i,j;
		BigInteger ans;
		for(i=0;i<maxlen;i++)
			Arrays.fill(f[i], BigInteger.ZERO);
		for (i=1;i<=n;i++)
			f[1][i]=BigInteger.ONE;

		
		for (i=2;i<=5;i++)
		{
			Arrays.fill(a, BigInteger.ZERO);
			for (j=1;j<=n;j++)
			{
				f[i][j]=sum(q[j]-1);			
				update(q[j],f[i-1][j]);
			}		
		}
				
		ans=BigInteger.ZERO;
		for (i=1;i<=n;i++)
			ans=ans.add(f[5][i]);
		System.out.println(ans);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		while(true)
		{
			ini();
			solve();
		}
	}

}
