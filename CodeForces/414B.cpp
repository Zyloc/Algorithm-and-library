/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 2001;
const int MOD = 1e9+7;
int dp[MAX][MAX];
lli n,k;
int solve(lli index,lli number){
	if(index == k){
		return 1;
	}
	if(dp[index][number]!=-1){
		return dp[index][number];
	}
	dp[index][number] = 0;
	for(int i=number;i<=n;i=i+number){
		dp[index][number] = (dp[index][number]%MOD+solve(index+1,i)%MOD)%MOD;
	}
	return dp[index][number]; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		dp[0][i] = solve(1,i)%MOD;
	}
	int ans(0);
	for(int i=1;i<=n;i++){
		if(dp[0][i]!=-1){
			ans = (ans+dp[0][i])%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}