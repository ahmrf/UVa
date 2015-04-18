#include<cstdio>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

int main (void)
{
    while(1)
    {
        string a, b;
        cin >> a >> b;
        if(a == "0" && b == "0") break;

        int carry = 0;

        if(a.length()>b.length())
        {
            int lim = a.length()-b.length();
            for(int i = 0; i < lim; ++i)
            {
                b = '0' + b;
            }
        }

        else if(b.length()>a.length())
        {
            int lim = b.length()-a.length();
            for(int i = 0; i < lim; ++i)
            {
                a = '0' + a;
            }
        }



        int sum, temp = 0;

        for(int i = a.length()-1; i >= 0; --i)
        {
            sum = (a[i] - '0') + (b[i] - '0') + temp;
            if(sum > 9) {
                carry++;
                temp = 1;
            }
            else temp = 0;
        }




        if(carry == 0) printf("No carry operation.\n");
        else if(carry == 1) printf("1 carry operation.\n");
        else if(carry > 1)printf("%d carry operations.\n", carry);

    }

    return 0;
}
