#include<map>
#include<cstring>
#include<cstdio>

using namespace std;
int countC, countH, countN, countO;

void update(char atom, int noa)
{
    if(atom=='C') countC+=noa;
    else if(atom=='H') countH+=noa;
    else if(atom=='N') countN+=noa;
    else countO+=noa;
}

int main (void)
{
    char formula[1000], sign;
    int cases, sl;
    double molarMass;
    scanf("%d\n", &cases);
    while(cases--)
    {
        gets(formula);
        sl = strlen(formula);
        countH = 0;
        countO = 0;
        countN = 0;
        countC = 0;
        for(int i = 0; i<sl; i++)
        {
            if(formula[i]<=90 && formula[i]>=65)
            {
                bool found = false;
                int noa = 0;
                for(int j=i+1; j<sl; j++)
                {
                    if(formula[j]>=48 && formula[j]<=57)
                    {
                        if(found)
                        {
                            noa*=10;
                            noa+=formula[j]-'0';
                        }
                        else
                        {
                            noa += formula[j]-'0';
                            found = true;
                        }

                    }
                    else break;
                }
                if(!found) noa=1;
                update(formula[i], noa);
            }
        }

        molarMass = countH*1.008+countC*12.01+countN*14.01+countO*16.00;
        printf("%.3lf\n", molarMass);
    }
    return 0;
}
