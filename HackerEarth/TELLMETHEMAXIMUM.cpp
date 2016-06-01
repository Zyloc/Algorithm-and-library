#include <stdio.h>
 
int main()
{
	int a[100002],i=0,t;
	scanf ("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf ("%d",&a[i]);
	}
	int q,d,b,large,j,k;
	scanf ("%d",&q);
	for (j=0;j<q;j++)
	{
		scanf ("%d %d",&d,&b);
		large=a[d];
		for (k=d;k<=b;k++)
		{
			if (a[k]>large)
			large=a[k];
		}
		printf ("%d \n",large);
	}
    
    return 0;
}