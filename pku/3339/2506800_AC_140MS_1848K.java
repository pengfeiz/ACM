import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer str;
	static player[] per=new player[22];
	static int[][] tot=new int[5][40];
	static int[] goal=new int[5];
	static void ini() throws Exception
	{
		String sss=br.readLine().trim();
		if(sss.charAt(0)=='0')
			System.exit(0);
		int year=0,num;
		String name,pos;
		str=new StringTokenizer(sss," -");
		num=Integer.parseInt(str.nextToken());
		name=str.nextToken();
		pos=str.nextToken();
		while(str.hasMoreTokens())
			year-=Integer.parseInt(str.nextToken())-Integer.parseInt(str.nextToken())-1;
		per[0]=new player(num,name,pos,year);
		for(int i=1;i<22;i++)
		{
			str=new StringTokenizer(br.readLine()," -");
			num=Integer.parseInt(str.nextToken());
			name=str.nextToken();
			pos=str.nextToken();
			year=0;
			while(str.hasMoreTokens())
				year-=Integer.parseInt(str.nextToken())-Integer.parseInt(str.nextToken())-1;
			per[i]=new player(num,name,pos,year);
		}
		str=new StringTokenizer(br.readLine()," -");
		goal[1]=1;
		goal[2]=Integer.parseInt(str.nextToken());
		goal[3]=Integer.parseInt(str.nextToken());
		goal[4]=Integer.parseInt(str.nextToken());
		Arrays.sort(per);
		tot[1][0]=tot[2][0]=tot[3][0]=tot[4][0]=1;
	}
	static void solve()
	{
		for(int i=0;i<22;i++)
			tot[per[i].pnum][tot[per[i].pnum][0]++]=i;
		for(int i=1;i<5;i++)
			if(tot[i][0]<=goal[i])
			{
				System.out.println("IMPOSSIBLE TO ARRANGE\n");
				return;
			}
		int y=0,k=0,n=0;
		for(int i=1;i<5;i++)
			for(int j=1;j<=goal[i];j++)
			{
				int p=tot[i][j];
				if(per[p].year>y||per[p].year==y&&per[y].num>n)
				{
					y=per[p].year;
					n=per[p].num;
					k=p;
				}
			}
		System.out.println(per[k]);
		for(int i=1;i<5;i++)
			for(int j=1;j<=goal[i];j++)
			{
				int p=tot[i][j];
				if(p==k)
					continue;
				System.out.println(per[p]);
			}
		System.out.println();
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		while(true)
		{
			ini();
			solve();
		}
		
	}

}
class player implements Comparable<player>{
	int num,pnum;
	String name,p;
	int year;
	public player(int n,String na,String pp,int ynum)
	{
		num=n;
		name=na;
		p=pp;
		year=ynum;
		if(pp.equals("G"))
			pnum=1;
		else
			if(pp.equals("D"))
				pnum=2;
			else
				if(pp.equals("M"))
					pnum=3;
				else
					pnum=4;
	}
	public String toString()
	{
		return num+" "+name+" "+p;
	}
	public int compareTo(player o) {
		// TODO Auto-generated method stub
		if(num>o.num)
			return 1;
		return 0;
	}
	
}
