#include <stdio.h>
int main ()
{
    int t,i;
    scanf ("%d",&t);
    for (i=0;i<t;i++)
        {
         int n,k;
         scanf ("%d %d",&n,&k);
         int a[1002],j,count=0;
         for(j=0;j<n;j++)
         {
             scanf ("%d",&a[j]);
             if (a[j]<=0)
                {
                    count=count+1;
 
                }
         }
         
 
         if (count<k)
         {
 
             printf("YES\n");
         }
         else
            printf("NO\n");
 
 
 
        }
 
    return 0;
}