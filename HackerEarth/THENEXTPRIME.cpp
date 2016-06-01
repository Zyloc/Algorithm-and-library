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
    int count=0;
    cin>>count;
    for (int i=0;i<count;i++){
         unsigned long long int n;
        cin>>n;
            cout<<NextPrime(n)<<endl;   
        }
}