import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s = "";
        while((s = br.readLine()) != null)
        {
            String[] tokens = s.split(" ");
            int t = Integer.parseInt(tokens[0]);
            int a = Integer.parseInt(tokens[1]);
            int b = Integer.parseInt(tokens[2]);
            
            String output = "("+t+"^"+a+"-1)/("+t+"^"+b+"-1) ";
            
            if(a < b || a%b!=0 || t == 1)
            {
                output = output + "is not an integer with less than 100 digits.";
            }
            else if(a == b)
            {
                output = output + "1";
            }
            else
            {
                if((a-b)*Math.log10(t) > 99)
                {
                    output = output + "is not an integer with less than 100 digits.";
                }
                else
                {
                    BigInteger ret = (BigInteger.valueOf(t).pow(a).subtract(BigInteger.ONE)).divide((BigInteger.valueOf(t).pow(b).subtract(BigInteger.ONE)));
                    output = output + ret;
                }
            }
            
            System.out.println(output);
        }
            
        br.close();
    }
    
    
}