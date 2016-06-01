#include<stdio.h>
int main()
{int t,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{   unsigned long long int n,j,a=1,b=2,c=3,sum=2;
    scanf("%llu",&n);
    while(c<n)
    {
        if(c%2==0)
        {
            sum=sum+c;
        }
        c=a+b;
        a=b;
        b=c;
    }
    printf("%llu\n",sum);
}
return 0;
}