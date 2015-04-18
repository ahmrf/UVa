#include<cstring>
#include<cstdio>

int main (void)
{
    char n[1000], m[1000];
    int last[][4] = {{0,0,0,0},{1,1,1,1},{6,2,4,8},{1,3,9,7},{6,4,6,4},
                {5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};

    int mod4, lastdigit, leng;
    while(scanf("%s %s", n, m) ==2 && (n[0]!='0' || m[0]!='0'))
    {
        if(m[0] == '0')
        {
            printf("1\n");
            continue;
        }
        leng = strlen(n);
        mod4 = 0;
        lastdigit = n[leng-1] - '0';
        for(int i = 0; m[i]; i++) mod4 = (mod4*10 + m[i]-'0') % 4;
        printf("%d\n", last[lastdigit][mod4]);
    }
    return 0;
}
