import java.util.Arrays;
import java.util.HashSet;

public class Main{
	static int[][] g;
	static int[] l,c;
	static boolean[] ok,okok;
	static HashSet<Integer>[] way,wayway;
	static HashSet<Integer>[] s;
	static int n;
	
	static void floodfill(int x,int v)
	{
		if(l[x]+v==3)
		{
			System.out.println("No solution");
			System.exit(0);
		}
		if(l[x]==v)
			return;
		l[x]=v;
		c[v]++;
		s[v].add(x);
		for(int i=1;i<=n;i++)
			if(g[x][i]>0)
				floodfill(i,3-v);
	}
	@SuppressWarnings("unchecked")
	static void way()
	{
		Arrays.fill(okok,false);
		for(int i=1;i<=2;i++)
			if(n/2>=c[i])
				for(int j=0;j<=n/2-c[i];j++)
					if(ok[j]&&!okok[j+c[i]])
					{
						okok[j+c[i]]=true;
						wayway[j+c[i]]=(HashSet<Integer>) way[j].clone();
						wayway[j+c[i]].addAll(s[i]);
					}
		for(int i=0;i<okok.length;i++)
			ok[i]=okok[i];
		way=wayway.clone();
	}
	static void ini()
	{
		n=ni();
		int max=101;
		g=new int[max][max];
		l=new int[max];
		int nn=(max+1)/2+1;
		ok=new boolean[nn];
		okok=new boolean[nn];
		way=new HashSet[nn];
		wayway=new HashSet[nn];
		c=new int[3];
		s=new HashSet[3];
		for(int i=0;i<=n;i++)
			Arrays.fill(g[i], 2);
		for(int i=0;i<nn;i++)
		{
			way[i]=new HashSet<Integer>();
			wayway[i]=new HashSet<Integer>();
		}
		for(int i=0;i<3;i++)
			s[i]=new HashSet<Integer>();
		for(int i=1;i<=n;i++)
			g[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			while(true)
			{
				int x=ni();
				if(x==0)
					break;
				g[i][x]--;
				g[x][i]--;
			}	
		}
		
	}
	static void solve()
	{
		ok[0]=true;
		for(int i=1;i<=n;i++)
		{
			if(l[i]==0)
			{
				c[1]=c[2]=0;
				for(int j=0;j<3;j++)
					s[j].clear();
				floodfill(i,1);
				way();
			}
		}
		int x=n/2;
		while(!ok[x])
			x--;
		System.out.print(x);
		for(int i=1;i<=n;i++)
			if(way[x].contains(i))
				System.out.print(" "+i);
		System.out.println();
		System.out.print(n-x);
		for(int i=1;i<=n;i++)
			if(!way[x].contains(i))
				System.out.print(" "+i);
		System.out.println();
	}
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
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ini();
		solve();
	}

}