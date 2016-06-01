#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define vi(v) vector <int> v;
#define pb(n) push_back(n); 
#define MOD 1000000007
bool IsPrime(lli number)
{
 
    if (number == 2 || number == 3)
        return true;
 
    if (number % 2 == 0 || number % 3 == 0)
        return false;
 
    lli divisor = 6;
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
int main(){
    cout<<bool(IsPrime(6))<<endl;
    return 0;
}
