/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
bool IsPrime(long long int number){
 
    if (number == 2 || number == 3)
        return true;
 
    if (number % 2 == 0 || number % 3 == 0)
        return false;
 
    long long int divisor = 6;
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
 
long long int NextPrime(long long int a)
{
 
    while (!IsPrime(--a)) 
    { }
    return a;
 
}
int main(){
    lli x;
    cin>>x;
    cout<<NextPrime(x+1);	
	return 0;
}	