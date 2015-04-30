#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

int main (void)
{
    map<char, char>m;
    m['-'] = '-';
    m['1'] = '1';
    m['0'] = '0';
    m['A'] = m['B'] = m['C'] = '2';
    m['D'] = m['E'] = m['F'] = '3';
    m['G'] = m['H'] = m['I'] = '4';
    m['J'] = m['K'] = m['L'] = '5';
    m['M'] = m['N'] = m['O'] = '6';
    m['P'] = m['Q'] = m['R'] = m['S'] = '7';
    m['T'] = m['U'] = m['V'] = '8';
    m['W'] = m['X'] = m['Y'] = m['Z'] = '9';


    char tele[100];
    int n, i;
    while(gets(tele))
    {
        n = strlen(tele);
        for(i = 0; i<n; i++) printf("%c", m[tele[i]]);
        printf("\n");
    }
}
