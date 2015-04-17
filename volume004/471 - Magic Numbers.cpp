#include <cstdio>
#include <cstring>

const long long MAXN = 9876543210;

int test, visited[10];
long long n, num;

bool check(long long num)
{
    memset(visited, 0, sizeof(visited));
    while (num)
    {
        if (visited[num % 10]) return false;
        visited[num % 10]++;
        num /= 10;
    }
    return true;
}

int main()
{
    scanf("%d", &test);
    while (test--)
    {
        scanf("%lld", &n);
        for (long long i = 1; i <= MAXN; i ++)
        {
            num = n * i;
            if (num > MAXN) break;
            if (check(num) && check(i)) printf("%lld / %lld = %lld\n", num, i, n);
        }
        if (test) printf("\n");
    }
    return 0;
}
