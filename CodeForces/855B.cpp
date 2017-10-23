#include<bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define ll long long int
ll dp[100001][3];
ll A[100001];
ll pqr[3];
int n;

ll solve(int idx, int idx2){
	if(idx==n and idx2==3 ){ return  0; }
    if(idx == n ){ return -1e18*4;}
    if(idx2==3){ return  0; }
    if(dp[idx][idx2]!=-1){ return  dp[idx][idx2]; }
    cout<<idx<<" "<<idx2<<endl;
    
    ll ans = -1e18*4;
    ans = max( ans , A[idx]*pqr[idx2]+ solve(idx,idx2+1));
    ans = max( ans, solve(idx+1,idx2));

    return  dp[idx][idx2]= ans;
}
int main() {
    gearchange();
    //memset(dp,-1,sizeof(dp));
    for(int i(0);i<100001;i++){
    	dp[i][0] = ;
    	dp[i]
    }
    cin>>n;
    cin>>pqr[0]>>pqr[1]>>pqr[2];
    for (int i = 0; i <n; ++i) {
        cin>>A[i];
    }

    cout<<solve(0,0)<<endl;
    return 0;
}
