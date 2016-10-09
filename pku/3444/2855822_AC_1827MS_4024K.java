public class Main{
	static int n;
	static int[] a=new int[300],b=new int[300];
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
			System.exit(0);
		}
		return neg ? -v : v;
	}
	static void ini()
	{
		n=ni();
		if(n==0)
			System.exit(0);
		for(int i=0;i<n;i++)
			a[i]=ni();
	}
	static void solve()
	{
		solve(1);
		for(int i=0;i<n;i++)
			System.out.print(a[i]+" ");
		System.out.println();
	}
	static void solve(int k)
	{

		if(k>=n)
			return;
		int t=0;
		for(int i=0;i<k;i++)
		{
			int a1=a[i]+a[i+k],a2=a[i]-a[i+k];
			b[t++]=a1>>1;
			b[t++]=a2>>1;
		}

		
		for(int i=0;i<t;i++)
			a[i]=b[i];

		solve(k<<1);
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
