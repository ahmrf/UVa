#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main (void)
{
    int decimal;
    while(scanf("%d", &decimal) == 1 && decimal != 0)
    {
        vector<char> bin;
        int count = 0;
        while(decimal!=0){
            if(decimal%2==1) count++;
            int rem = decimal%2;
            char ch = rem + '0';
            bin.push_back(ch);
            decimal = decimal/2;
        }

        printf("The parity of ");
        for(int i = bin.size()-1; i >= 0; --i)
        {
            printf("%c", bin[i]);
        }

        printf(" is %d (mod 2).\n", count);
        bin.clear();
    }

}
