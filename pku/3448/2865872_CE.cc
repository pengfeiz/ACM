import java.io.*;
import java.util.*;
public class Main {
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static boolean[] mark=new boolean[12];
    static int[] value=new int[12];
    static HashMap<Integer,Integer> h=new HashMap<Integer,Integer>();
    static void ini()
    {
        h.put('I'+'0',1);
        h.put('V'+'0',5);
        h.put('X'+'0',10);
        h.put('L'+'0',50);
        h.put('C'+'0',100);
        h.put('D'+'0',500);
        h.put('M'+'0',1000);
    }
    static void solve() throws Exception
    {
        outside:
        while(true)
        {
            String s=br.readLine().trim();
            if(s.equals("RESET"))
            {
                Arrays.fill(mark,false);
                System.out.println("Ready");
                continue;
            }
            if(s.equals("QUIT"))
            {    
                System.out.println("Bye");
                return;
            }
            StringTokenizer str=new StringTokenizer(s,"=");
            int k=Integer.parseInt(str.nextToken());
            int temp=0;
            s=str.nextToken();
            String ss="";
            int size=s.length();
            boolean add=true;
            for(int i=0;i<size;i++)
            {
                if(s.charAt(i)=='+')
                {
                    if(ss.charAt(0)>='0'&&ss.charAt(0)<='9')
                    {
                        int kk=Integer.parseInt(ss);
                        if(!mark[kk])
                        {
                            System.out.println("Error");
                            continue outside;
                        }
                        if(add)
                            temp+=value[kk];
                        else
                            temp-=value[kk];
                    }
                    else
                    if(add)
                        temp+=get(ss);
                    else
                        temp-=get(ss);
                    add=true;
                    ss="";
                    continue;
                }
                if(s.charAt(i)=='-')
                {
                   
                    if(ss.charAt(0)>='0'&&ss.charAt(0)<='9')
                    {
                        int kk=Integer.parseInt(ss);
                        if(!mark[kk])
                        {
                            System.out.println("Error");
                            continue outside;
                        }
                        if(add)
                            temp+=value[kk];
                        else
                            temp-=value[kk];
                    }
                    else
                    if(add)
                        temp+=get(ss);
                    else
                        temp-=get(ss);
                    ss="";
                    add=false;
                    continue;
                }
                ss+=s.charAt(i);
            }
            if(ss.charAt(0)>='0'&&ss.charAt(0)<='9')
            {
                int kk=Integer.parseInt(ss);
                if(!mark[kk])
                {
                        System.out.println("Error");
                        continue outside;
                }
                if(add)
                        temp+=value[kk];
                else
                        temp-=value[kk];
            }
            else
                if(add)
                        temp+=get(ss);
                else
                        temp-=get(ss);
            if(temp<0||temp>10000)
                System.out.println("Error");
            else
            {
                System.out.println(k+"="+put(temp));
                mark[k]=true;
                value[k]=temp;
            }
        }
       
    }
    static int get(String ss)
    {
        int v=0;
        int size=ss.length();
        for(int i=0;i<size;i++)
        {
            char c=ss.charAt(i);
            if(c=='O')
            {   
                v+=0;
                continue;
            }
            if(c=='I')
            {
                if(i<size-1)
                {
                    char cc=ss.charAt(i+1);
                    if(cc=='V')
                    {
                        v+=4;
                        i++;
                        continue;
                    }
                    if(cc=='X')
                    {
                        v+=9;
                        i++;
                        continue;
                    }
                }
                v+=1;
                continue;
           }
           if(c=='V')
           {
                v+=5;
                continue;
           }
           if(c=='X')
           {
                if(i<size-1)
                {
                    char cc=ss.charAt(i+1);
                    if(cc=='L')
                    {
                        v+=40;
                        i++;
                        continue;
                    }
                    if(cc=='C')
                    {
                        v+=90;
                        i++;
                        continue;
                    }
                }
                v+=10;
                continue;
           }
           if(c=='L')
           {
                v+=50;
                continue;
           }
           if(c=='C')
           {
                if(i<size-1)
                {
                    char cc=ss.charAt(i+1);
                    if(cc=='D')
                    {
                        v+=400;
                        i++;
                        continue;
                    }
                    if(cc=='M')
                    {
                        v+=900;
                        i++;
                        continue;
                    }
                }
                v+=100;
                continue;
           }
           if(c=='D')
           {
                v+=500;
                continue;
           }
           if(c=='M')
           {
                v+=1000;
                continue;
           }
        }
        return v;
    }
    static String put(int v)
    {
        String s="";
        if(v==0)
        {
            return "O";
        }
        while(v>=1000)
        {
            s+="M";
            v-=1000;
        }
        while(v>=900)
        {
            s+="CM";
            v-=900;
        }
        while(v>=500)
        {
            s+="D";
            v-=500;
        }
        while(v>=400)
        {
            s+="CD";
            v-=400;
        }
        while(v>=100)
        {
            s+="C";
            v-=100;
        }
        while(v>=90)
        {
            s+="XC";
            v-=90;
        }
        while(v>=50)
        {
            s+="L";
            v-=50;
        }
        while(v>=40)
        {
            s+="XL";
            v-=40;
        }
        while(v>=10)
        {
            s+="X";
            v-=10;
        }
        while(v>=9)
        {
            s+="IX";
            v-=9;
        }
        while(v>=5)
        {
            s+="V";
            v-=5;
        }
        while(v>=4)
        {
            s+="IV";
            v-=4;
        }
        while(v>=1)
        {
            s+="I";
            v-=1;
        }
        return s;
    }
    public static void main(String[] args) throws Exception{
        ini();
        solve();
    }

}
