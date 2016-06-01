#include<stdio.h>

#include<math.h>

void twosq(long long int x)

{

    long long int i,j=0;

    i= sqrt(x);

    while(i>0) {

    if(j*j>x)

      {



        printf("No\n");

         break;

      }

    else if(i*i + j*j == x)

        {

          //printf("%d %d",i,j);

         printf("Yes\n");

         break;

        }

    else if(i*i + j*j <x)

         j++;

    else

        i--;

    }





}

int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        long long int n;

        scanf("%lld",&n);

        twosq(n);

    }

    return 0;



}
