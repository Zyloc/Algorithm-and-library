/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
#include <list>  
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 10000
#define MODE 1000000007
#define PI  3.14159265358979323846
#define MAX 15001
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli f[MAX];
lli sume[MAX]={0};
lli fib(lli n){
/* Declare an array to store Fibonacci numbers. */
    lli i;
    /* 0th and 1st number of the series are 0 and 1*/
    f[1] = 0;
    f[2] = 1;

    for (i = 3; i <= n; i++){
        /* Add the previous 2 numbers in the series
            and store it */
        f[i] = (f[i-1]%MOD + f[i-2]%MOD)%MOD;
    }

    return f[n];
}
lli sumUpto(lli n){
    loop(i,1,n){
        sume[i] = (sume[i-1]%MODE + f[i]%MODE)%MODE;
    }
    return 0;
}
int main(){
    lli l,r;
    fib(15000);
    sumUpto(15000);
    zyloc(){
        lli start(0),end(0),repi(0),oneFoldSum(sume[15000]),ans(0);
        scanf("%lld%lld",&l,&r);
        repi = (r-l)/150    00;
        ans += ((oneFoldSum%MODE*repi%MODE)%MODE);
        start = l%15000;
        end = r%15000;
        ans += ((sume[end]-sume[start-1])%MODE);
        printf("%lld\n",ans%MODE);
        //printf("%lld\n",sume[r]-sume[l-1]);
    }
    return 0;
}   