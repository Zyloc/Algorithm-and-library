#include <stdio.h>
int A[100],X;
void subset(int s,int k,int r)
{
 if(s+A[k]==X)

 {
  printf("True");
  return;
 }
 else if(s+A[k]+A[k+1]<=X)
  subset(s+A[k+1],k+1,r-A[k]);
 if((s+r-A[k]>=X) && (s+A[k+1]<=X))
  subset(s,k+1,r-A[k]);
}
int main()
{
 int N,i,j,temp,r=0;
 scanf("%d",&N);
 if(N<4)
 {
  printf("Constraint Valiated");
  exit(0);
 }
 for(i=0;i<N;i++)
 {
  scanf("%d",&A[i]);
  r+=A[i];
  }
  scanf("%d",&X);
  for(i=0;i<N;i++)
   for(j=i;j<N;j++)
    if(A[i]>A[j])
    {
     temp=A[i];
     A[i]=A[j];
     A[j]=temp;
    }
  subset(0,0,r);
  printf("False");
  return 0;
}
