/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e4+1;
const int MOD = 1e9+7;
int maxBox;
int dp[1001][10001];
int magicBox(int n,int m,int put,int countBox){
    if(n < put and m < put){
    	if(countBox == maxBox){
        	return 1;
    	}
    	else{
    		return 0;
    	}
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    dp[n][m] = 0;
    if(n >= put){
        dp[n][m] = (magicBox(n-put,m,put+1,countBox+1)%MOD)%MOD;
    }
    if(m >= put){
        dp[n][m] = (dp[n][m]+magicBox(n,m-put,put+1,countBox+1)%MOD)%MOD;
    }
    return dp[n][m];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
	    memset(dp,-1,sizeof dp);
	    lli n,m;
	    cin>>n>>m;
	    maxBox = (-1+sqrt(1+8*(n+m)))/2;
	    cout<<maxBox<<endl;
	    lli ans(magicBox(n,m,1,0));
	    if(ans == -1){
	       cout<<0<<endl;
	    }
	    else{
	        cout<<ans<<endl;
	    }
	}
	return 0;
}