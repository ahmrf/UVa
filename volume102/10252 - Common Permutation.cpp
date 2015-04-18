#include<map>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int main ()
{
    char a[1010], b[1010];
    int sa, sb;
    while(gets(a) && gets(b))
    {
        sa = strlen(a);
        sb = strlen(b);

        sort(a, a+sa);
        sort(b, b+sb);

        map<char, int>m;
        for(int i=0; i<sa; i++)
        {
            m[a[i]]++;
        }
        for(int i=0; i<sb; i++)
        {
            if(m[b[i]])
            {
                printf("%c", b[i]);
                m[b[i]]--;
            }
        }
        printf("\n");

    }
    return 0;
}
