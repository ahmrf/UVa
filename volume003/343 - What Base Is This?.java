import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext())
        {
            String x = scanner.next().trim();
            String y = scanner.next().trim();
            if(x.equals("0") && y.equals("0"))
            {
                System.out.println("0 (base 2) = 0 (base 2)");
            }
            else if(x.equals("0") || y.equals("0"))
            {
                System.out.println(x +" is not equal to "+ y +" in any base 2..36");
            }
            else
            {
                int xMinBase = minimumBase(x);
                int yMinBase = minimumBase(y);
                
                boolean found = false;
                
                for(int i = xMinBase; i < 37; i++)
                {
                    for(int j = yMinBase; j < 37; j++)
                    {
                        if(new BigInteger(x, i).equals(new BigInteger(y, j)))
                        {
                            found = true;
                            
                            System.out.println(x +" (base "+ i + ") = "+ y +" (base "+ j +")");
                            break;
                        }
                    }
                    if(found) break;
                }
                if(found == false)
                {
                    System.out.println(x +" is not equal to "+ y +" in any base 2..36");
                }
            }
        }
        scanner.close();
    }
    
    static int minimumBase(String number)
    {
        number = number.toUpperCase();
        int length = number.length();
        int max = 0;
        for(int i = 0; i < length; i++)
        {
            max = Math.max(max, digitWeight(number.charAt(i)));
        }
        if(max >= 1) return max+1;
        return 2;
    }
    
    static int digitWeight(char digit)
    {
        if(digit <= 'Z' && digit >= 'A')
        {
            return (digit - 'A')+10;
        }
        return digit - '0';
    }
}
