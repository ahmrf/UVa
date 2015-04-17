#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string main_word, guess;
    int round;
    while(cin >> round, round != -1)
    {
        cin >> main_word >> guess;
        int stroke = 0, sz = guess.size();
        for(size_t i = 0; i<sz && !main_word.empty() && stroke <= 6; i++)
        {
            if(main_word.find(guess[i]) != string ::npos)
            {
                main_word.erase(remove(main_word.begin(), main_word.end(), guess[i]), main_word.end());
            }
            else ++stroke;
        }
        cout << "Round " << round << '\n';
        if(stroke == 7) puts("You lose.");
        else if(main_word.empty()) puts("You win.");
        else puts("You chickened out.");
    }
    return 0;
}
