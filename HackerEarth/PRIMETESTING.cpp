#include <iostream>
using namespace std;
 
bool IsPrime(int number)
{
 
    if (number == 2 || number == 3)
        return true;
 
    if (number % 2 == 0 || number % 3 == 0)
        return false;
 
    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {
 
        if (number % (divisor - 1) == 0)
            return false;
 
        if (number % (divisor + 1) == 0)
            return false;
 
        divisor += 6;
 
    }
 
    return true;
 
}
 
int NextPrime(int a)
{
 
    while (!IsPrime(++a)) 
    { }
    return a;
 
}
int main(){
    int test=0;
    cin>>test;
    for (int i=0;i<test;i++){
         int n;
        cin>>n;
        int count=0,a;
        for (int j=0;j<n;j++){
               cin>>a;
               int l=NextPrime(a-1);
               if ((l==a) && a!=1){
               	    count++;
               }
        }
        cout<<count<<endl;
    }
}