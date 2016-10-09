import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer str;
    static int n,m;
    static void ini() throws Exception
    {
        str=new StringTokenizer(br.readLine());
        n=Integer.parseInt(str.nextToken());
        m=Integer.parseInt(str.nextToken());
        if(n==0||m==0)
            System.exit(0);
        if(n>m)
        {
            int t=n;
            n=m;
            m=t;
        }
    }
    static void solve()
    {
        long[] t1=get(n-1),t2=get(m);
        for(int i=0;i<9;i++)
        {
            System.out.print(t2[i]-t1[i]+" ");
        }
        System.out.print(t2[9]-t1[9]);
        System.out.println();
    }
    static long[] get(int a)
    {
        long[] ret=new long[10];
        if(a<10)
        {
            for(int i=0;i<=a;i++)
                ret[i]=1;
            return ret;
        }
        int l=(int)Math.log10(a),temp=a/(int)Math.pow(10,l);
        for(int i=1;i<temp;i++)
        {
            ret[i]+=(int)Math.pow(10,l);
        }
        for(int i=0;i<10;i++)
        {
            ret[i]+=(int)Math.pow(10,l-1)*l*(temp-1);
        }
        ret[temp]+=(a-temp*(int)Math.pow(10,l))+1;
        long[] d1=get((int)Math.pow(10,l)-1),d2=get(a-temp*(int)Math.pow(10,l));
        int count=a-temp*(int)Math.pow(10,l),tt=10,cc=(int)Math.pow(10,l-1);
        while(count>=tt)
        {
            ret[0]+=tt;
            tt*=10;
        }
        int c=count+1;
        if(count==0)
        {
            if(l>1)
            {
                ret[0]+=l-1;
            }
        }
        else
            while(count<cc)
            {
                ret[0]+=c;
                count*=10;
            }

        for(int i=0;i<10;i++)
        {
            ret[i]+=d1[i]+d2[i];
        }
        return ret;
    }
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        while(true)
        {
            ini();
            solve();
        }
    }
    
}

