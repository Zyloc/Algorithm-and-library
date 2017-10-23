#include<bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define ll long long int
#define MOD 1000000007LL
int A[65];
int vis[65];
ll dp[65][2][65];
ll solve(int idx,int flag,int k){
    if(idx==-1){ if(vis[k]){ return 0; }
        return 1; }
    if(dp[idx][flag][k]!=-1){ return dp[idx][flag][k]; }
    ll ans = 0;

    if(flag){
        ans+= solve(idx-1,flag,k);
        ans+= solve(idx-1,flag,k+1);
    }else{
        if(A[idx]){
            ans +=solve(idx-1,1,k);
            ans +=solve(idx-1,flag,k+1);
        } else{
            ans += solve(idx-1,flag,k);
        }
    }
    return dp[idx][flag][k] = ans;
}

int main() {
    gearchange();
    vis[0]=1;
    vis[1]=1;
    for (int i = 2; i <=64; i++) {
        for (int j = i*2; j <=64; j+=i) {
            vis[j] = 1;
        }
    }
    int t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        int id = 0;
        l--;
        while(r){
            A[id++]= r&1;
            r>>=1;
        }
        memset(dp,-1,sizeof(dp));
        r = solve(id-1,0,0);

        id = 0;
        while(l){
            A[id++]= l&1;
            l>>=1;
        }
        memset(dp,-1,sizeof(dp));
        if(id!=0){l = solve(id-1,0,0); }
        cout<<r-l<<endl;
    }
    return 0;
}

