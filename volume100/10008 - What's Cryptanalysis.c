#include<stdio.h>
#include<string.h>

struct content
{
    char ch;
    int count;
}arr[26];

int main (void)
{
    int n, i, j, k;
    char sentence[10000], c = 'A';
    for(i = 0; i < 26; i++)
    {
        arr[i].ch = c+i;
        arr[i].count = 0;
    }
    scanf("%d", &n);
    getchar();
    while(n-- && gets(sentence))
    {
        int len = strlen(sentence);
        for(i = 0; i < len; i++)
        {
            if((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122))
            {
                int index;
                if((sentence[i] >= 65 && sentence[i] <= 90))
                {
                    index = sentence[i] - 65;
                }
                else index = sentence[i] - 97;
                arr[index].count++;
            }
        }

    }

    for(i = 0; i < 26; i++)
    {
        for(j = i+1; j < 26; j++)
        {
            if(arr[j].count > arr[i].count)
            {
                c = arr[j].ch;
                k = arr[j].count;

                arr[j].count = arr[i].count;
                arr[j].ch = arr[i].ch;

                arr[i].count = k;
                arr[i].ch = c;
            }

            if(arr[j].count == arr[i].count)
            {
                if(arr[i].ch > arr[j].ch)
                {
                    c = arr[j].ch;
                    arr[j].ch = arr[i].ch;
                    arr[i].ch = c;
                }
            }
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(arr[i].count) printf("%c %d\n", arr[i].ch, arr[i].count);
    }
    return 0;
}
