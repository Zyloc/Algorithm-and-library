#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int gcd(int n,int m)
    {
    if (m == 0)
        return n;
    return gcd (m, n%m);
}
int calculate(int x, int y)
    {
    
    if (y == 0)
        return -1;
    return calculate (y, x%y) + x/y;
}
void solve(int n) {
   int x=0;
    int min=n,i,ans;
   for (i=1;i<n;i++)
       {
        if (gcd(n,i)==1)
            {
            ans=calculate(n,i);
            if (ans<min)
                {
                min=ans;
                x=i;
            }
        }
   }
    cout<<min<<endl;
 
}
int main() {
   int t,i,l;
    cin>>t;
    for (i=0;i<t;i++)
        {
          int l;
          cin>>l;
          if (l==1)
              {
               cout<<"0"<<endl;
              return 0;
          }
          solve(l);
    }
  return 0;
}