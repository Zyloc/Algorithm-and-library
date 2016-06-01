#include <stdio.h>
 
int main()
{
	unsigned long long int  i,j,k,l,n,max=0,l1,l2,max1,sum=0;
	  scanf("%d%d",&n,&k);
	    int A[n];
	    max1=0;
	  for(j=0; j<k; j++){
	   	
	  
	   for(i=0; i<n; i++){
	   	scanf("%d",&A[i]);
	   }
	    l1=n/2;
	      l2=0;
	      max=0;
	   for(i=0; i<n/2; i++){
	      
	     
	      sum=0;
	      for(l=0; l<l2; l++){
	      	sum= sum+A[l];
	      }
	      for(l=l1; l<n; l++){
	      	sum= sum+A[l];
	      }
	      if(max<sum){
	      	max=sum;
	      }
	      l1++;
	      l2++; 
	      
	   }
	      if(max1<max){
	      	max1=max;
	      }
	     
	   
	   
	  }
    printf("%lld",max1);
    return 0;
}