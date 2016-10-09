import java.util.Arrays;

public class Main{
	static int[][] map=new int[110][110];
	static int n,m,k=1,inf=99999999;
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
		m=ni();
		n=ni();
//		System.out.println(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				map[i][j]=ni();
				if(map[i][j]==-1)
					map[i][j]=inf;
			}
	}
	static void solve()
	{
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(map[i][k]<inf&&map[k][j]<inf)
						if(map[i][j]>map[i][k]+map[k][j])
							map[i][j]=map[i][k]+map[k][j];
		int[] a=new int[n*(n-1)];
		int p=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j&&map[i][j]>-1)
					a[p++]=map[i][j];
		Arrays.sort(a,0,p);
		double d=Math.ceil(m*1.0/100.0*p);
		int t=(int)d;
		System.out.println("Scenario #"+k+++":");
		System.out.println(a[t-1]+"\n");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int t=ni();
		while(t-->0)
		{
			ini();
			solve();
		}
	}

}
