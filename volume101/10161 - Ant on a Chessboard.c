#include<stdio.h>
#include<math.h>

int main (void)
{
    long long int diagonal, light, root, column, row;
    while(scanf("%lld", &light), light)
    {
        root = (long long int)sqrt(light);
        diagonal = root*root + root + 1;
        if(light == 1) {
            column = 1;
            row = 1;
        }

        else if(light == diagonal){
            row = root +1;
            column = row;
        }
        else if(root*root == light && root%2== 1){
            column = 1;
            row = root;
        }

        else if(root*root == light && root%2== 0){
            column = root;
            row = 1;
        }

        else if((long long int)sqrt(diagonal) % 2 == 1){
            if(light<diagonal){
                row = sqrt(diagonal)+1;
                column = row - abs(diagonal - light);
            }

            if(light>diagonal){
                column = sqrt(diagonal)+1;
                row = column - abs(diagonal - light);
            }


        }

        else if((long long int)sqrt(diagonal) % 2 == 0){
            if(light<diagonal){
                column = sqrt(diagonal)+1;
                row = column - abs(diagonal - light);
            }

            if(light>diagonal){
                row = sqrt(diagonal)+1;
                column = row - abs(diagonal - light);
            }


        }

        printf("%lld %lld\n", column, row);
    }

    return 0;
}

