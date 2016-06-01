#include <math.h>
#include <stdio.h>
int main()
{
	int r;
	r=1;
	int i=0;
	while (r!=0)
	{
		if (i==0){
		scanf ("%d",&r);
		printf ("%.2f \n",r*r/(2*M_PI));
		
		i++;
		}
		else 
		 printf ("%.2f \n",r*r/(2*M_PI));
		scanf ("%d",&r);
	}
	return 0;
	}