#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int MOD = 1e9+7;
lli fast_expo(lli base, lli expo){
    lli res=1;
    while(expo>0){
        if(expo%2==1){
            res=(res*base)%MOD;
        }
        base=(base*base)%MOD;
        expo/=2;
    }
    return res%MOD;
}
void multiply(lli F[2][2], lli M[2][2]){
    lli x = (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD;
    lli y = (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD;
    lli z = (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD;
    lli w = (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(lli F[2][2], lli n){
    if( n == 0 || n == 1)
        return;
    lli M[2][2] = {{1,1},{1,0}};
    power(F, n/2);
    multiply(F, F);
    if (n%2 != 0)
        multiply(F, M);
}
lli fib(lli n){
    lli F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    if(n == 1){
        return 2;
    }
    power(F, n-1);
    return ((F[1][0]*3)%MOD+(F[1][1]*2)%MOD)%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli nthTerm(fib(n)),powerTwo(fast_expo(2,n));
        cout<<(powerTwo-nthTerm+MOD)%MOD<<endl;    
    }
    return 0;
}
