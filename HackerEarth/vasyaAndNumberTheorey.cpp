/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli dp[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,x;
    cin>>n;
    vector<lli> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    lli ans(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]%v[j] == 0){
                dp[i] = max(dp[i],1+dp[j]);    
            }
        }
        ans = max(ans,1+dp[i]);
    }
    if(ans == 1){
        ans = -1;
    }
    cout<<ans<<endl;
    return 0;
}