#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int MAX = 5e4+1;
bool dp[MAX];
long long getMaximumProduct (vector<int> A) {
   lli n(A.size()),totalSum(0);
   dp[0] = true;
   for(int i(0);i<A.size();i++){
       totalSum += A[i];
       for(int j(MAX-1);j>= A[i];j--){
           dp[j] = (dp[j] or dp[j-A[i]]); 
       }
   }
   lli ans(0);
   for(int i(0);i<MAX;i++){
       if(dp[i]){
           ans = max(ans,(totalSum-i)*i);
       }
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i_A=0; i_A<n; i_A++)
    {
    	cin >> A[i_A];
    }

    long long out_;
    out_ = getMaximumProduct(A);
    cout << out_;
}