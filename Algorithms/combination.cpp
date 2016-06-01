#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <iomanip>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n); 
#define MOD 1000000007
lli combination( lli n, lli k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    lli result = n;
    for( lli i = 2; i <= k; ++i ) {
        result = ((result)%MOD*(n-i+1)%MOD)%MOD;
        result /= i;
    }
    return result%MOD;
}
int main(){
	lli n,r;
	cin>>n>>r;
	cout<<combination(n,r);	
    return 0;
}