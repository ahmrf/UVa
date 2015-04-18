#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>

using namespace std;

int main (void)
{
    long long num, i = 1, rem;
    while(scanf("%lld", &num) != EOF)
    {
        if(num == 0) printf("%4d. 0\n", i++);
        else
        {
            string kothay;
            rem = num % 100;
            num /= 100;
            if(rem > 0)
            {
                string a;
                stringstream ss;
                ss << rem;
                ss >> a;
                kothay = a;
            }

            rem = num % 10;
            num /= 10;
            if(rem > 0)
            {
                string a;
                stringstream ss;
                ss << rem;
                ss >> a;
                kothay = a + " shata " + kothay;
            }
            rem = num % 100;
            num /= 100;
            if(rem > 0)
            {
                string a;
                stringstream ss;
                ss << rem;
                ss >> a;
                kothay = a + " hajar " + kothay;
            }
            rem = num % 100;
            num /= 100;
            if(rem > 0)
            {
                string a;
                stringstream ss;
                ss << rem;
                ss >> a;
                kothay = a + " lakh " + kothay;
            }

            if(num > 0)
            {
                kothay = " kuti " + kothay;
                rem = num%100;
                num/=100;
                if(rem > 0)
                {
                    string a;
                    stringstream ss;
                    ss << rem;
                    ss >> a;
                    kothay = a + kothay;
                }

                rem = num%10;
                num /= 10;
                if(rem > 0)
                {
                    string a;
                    stringstream ss;
                    ss << rem;
                    ss >> a;
                    kothay = a + " shata " + kothay;
                }
                rem = num % 100;
                num /= 100;
                if(rem > 0)
                {
                    string a;
                    stringstream ss;
                    ss << rem;
                    ss >> a;
                    kothay = a + " hajar " + kothay;
                }
                rem = num % 100;
                num /= 100;
                if(rem > 0)
                {
                    string a;
                    stringstream ss;
                    ss << rem;
                    ss >> a;
                    kothay = a + " lakh " + kothay;
                }

                if(num > 0)
                {
                    string a;
                    stringstream ss;
                    ss << num;
                    ss >> a;
                    kothay = a + " kuti " + kothay;
                }
            }

            int s = kothay.length();
            int m = s;
            for(int j = s-1; j>=0; j--)
            {
                if(kothay[j] == ' ') m--;
                else break;
            }
            printf("%4d. ", i++);
            bool flag = false;
            for(int j = 0; j < m; j++)
            {
                if(kothay[j] == ' ')
                {
                    if(flag == false){
                        printf(" ");
                        flag = true;
                    }
                }
                else {
                    printf("%c", kothay[j]);
                    flag = false;
                }
            }
            cout << endl;
        }
    }


    return 0;
}
