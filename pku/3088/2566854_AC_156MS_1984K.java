import java.util.Scanner;

public class Main{
	static long[][] a;
	static void ini()
	{
		for(int i=1;i<12;i++)
			a[i][1]=1;
		for(int i=2;i<12;i++)
			a[i][i]=a[i-1][i-1]*i;
		for(int i=2;i<12;i++)
			for(int j=2;j<i;j++)
				a[i][j]=(a[i-1][j-1]+a[i-1][j])*j;
		for(int n=1;n<12;n++)
			for(int i=1;i<=n;i++)
			{
				long temp=c(n,i);
				for(int j=1;j<=i;j++)
					a[n][0]+=a[i][j]*temp;
			}
			
	}
	static long c(int a,int b)
	{
		long t=1;
		for(int i=b+1;i<=a;i++)
			t*=i;
		for(int i=1;i<=a-b;i++)
			t/=i;
		return t;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		a=new long[12][12];
		int test=in.nextInt(),t=1;
		ini();
		while(test-->0)
		{
			int n=in.nextInt();
			System.out.println(t+++" "+n+" "+a[n][0]);
		}
	}

}
