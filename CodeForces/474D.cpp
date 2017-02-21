/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e5+1;
int dp[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t,k;
	cin>>t>>k;
	dp[0] = 1;
	for(int i=1;i<MAX;i++){
		dp[i] = dp[i-1];
		if(i >= k){
			dp[i]= (dp[i] + dp[i-k])%MOD;
		} 
	}
	for(int i=1;i<MAX;i++){
		dp[i] = (dp[i]+dp[i-1])%MOD;
	}
	while(t--){
		lli x,y;
		cin>>x>>y;
		cout<<(dp[y]-dp[x-1]+MOD)%MOD<<endl;
	}
	return 0;
}