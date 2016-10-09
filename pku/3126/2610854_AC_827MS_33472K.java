import java.util.Arrays;

public class Main{
	static int m=10000,s,e;
	static int[] prime=new int[m];
	static boolean[] mark=new boolean[m];
	static int[][] q=new int[1000000][2];
	static int ni() {
		int v = 0;
		char t = 0;
		boolean neg = false;
		try {
			while (!Character.isDigit(t = (char) System.in.read()) && t != '-')
				;
			if (t == '-') {
				neg = true;
				t = '0';
			}
			do {
				v *= 10;
				v += t - '0';
			} while (Character.isDigit(t = (char) System.in.read()));
		} catch (Exception e) {
		}
		return neg ? -v : v;
	}
	static void set()
	{
		for(int i=1;i<m;i++)
			prime[i]=i;
		for(int i=2;i<=Math.sqrt(m);i++)
			if(prime[i]!=0)
			{
				int j=i*i;
				while(j<m)
				{
					prime[j]=0;
					j+=i;
				}
			}
	}
	static void ini()
	{
		s=ni();
		e=ni();
		Arrays.fill(mark,false);
	}
	static void solve()
	{
		if(s==e)
		{
			System.out.println(0);
			return;
		}
		int qs=0,qe=0;
		q[qe][0]=s;
		q[qe++][1]=0;
		mark[s]=true;
		int t1,t2,t3,t4;
		while(qs<qe)
		{
			int temp1=q[qs][0],temp2=q[qs++][1]+1,temp=temp1;
			t1=temp/1000;
			temp%=1000;
			t2=temp/100;
			temp%=100;
			t3=temp/10;
			temp%=10;
			t4=temp;
			for(int i=1;i<10;i++)
			{
				int k=temp1-t1*1000+i*1000;
//				System.out.println(k);
				if(mark[k]||prime[k]==0)
					continue;
				mark[k]=true;
				if(k==e)
				{
					System.out.println(temp2);
					return;
				}
				q[qe][0]=k;
				q[qe++][1]=temp2;
			}
			for(int i=0;i<10;i++)
			{
				int k=temp1-t2*100+i*100;
				if(mark[k]||prime[k]==0)
					continue;
				mark[k]=true;
				if(k==e)
				{
					System.out.println(temp2);
					return;
				}
				q[qe][0]=k;
				q[qe++][1]=temp2;
			}
			for(int i=0;i<10;i++)
			{
				int k=temp1-t3*10+i*10;
				if(mark[k]||prime[k]==0)
					continue;
				mark[k]=true;
				if(k==e)
				{
					System.out.println(temp2);
					return;
				}
				q[qe][0]=k;
				q[qe++][1]=temp2;
			}
			for(int i=0;i<10;i++)
			{
				int k=temp1-t4+i;
				if(mark[k]||prime[k]==0)
					continue;
				mark[k]=true;
				if(k==e)
				{
					System.out.println(temp2);
					return;
				}
				q[qe][0]=k;
				q[qe++][1]=temp2;
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		set();
		int t=ni();
		while(t-->0)
		{
			ini();
			solve();
		}
	}

}
