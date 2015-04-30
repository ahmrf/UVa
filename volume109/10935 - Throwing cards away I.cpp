#include<vector>
#include<iostream>
#include<cstdio>


using namespace std;

int main (void)
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        if(n == 1)
        {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
        }

        else
        {
            vector<int>deck;
            for(int i = 1; i <= n; i++)
                deck.push_back(i);

            int f = 0;
            printf("Discarded cards: ");
            while(deck.size() > 1)
            {
                if(f == 1) printf(", ");
                f = 1;
                int card = deck[0];
                deck.erase(deck.begin());
                printf("%d", card);
                card = deck[0];
                deck.erase(deck.begin());
                deck.push_back(card);

            }

            printf("\nRemaining card: %d\n", deck[0]);
        }
    }
    return 0;
}
