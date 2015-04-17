#include<iostream>
#include<string>
#include<cmath>

using namespace std;

unsigned long long int skewBinaryToDecimal(string str)
{
    unsigned long long int sum = 0;
    int power = str.size();

    for(int i = 0; i < str.length(); i++)
    {
        int digit = str[i] - '0';
        sum += (digit * ((int)pow(2, power) -1));
        power--;
    }

    return sum;

}

int main (void)
{

    while(1)
    {
        string bin;
        getline(cin, bin);
        if(bin == "0") break;

        unsigned long long int decimal = skewBinaryToDecimal(bin);
        cout << decimal << endl;
    }
    return 0;
}
