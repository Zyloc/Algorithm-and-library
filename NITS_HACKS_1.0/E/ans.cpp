/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e2+2);
lli n,k,z;
vector<lli> jump,coins; 
lli dp[MAX][MAX][MAX];
lli ans;
lli magicBox(lli index,lli currentPosition,lli steps,lli coinsSoFar){
	if(currentPosition == k){
		ans = max(ans,steps*z+coinsSoFar*(10-z));
		return coinsSoFar;
	}
	if(index == n){
		return 0;
	}
	if(dp[index][steps][currentPosition]!=-1){
		return dp[index][steps][currentPosition];
	}
	dp[index][steps][currentPosition] = 0;
	dp[index][steps][currentPosition] = magicBox(index+1,currentPosition,steps,0);
	if(jump[index] + currentPosition <= k){
		dp[index+1][steps+1][jump[index] + currentPosition] = max(dp[index+1][steps+1][jump[index] + currentPosition],magicBox(index+1,currentPosition+jump[index],steps+1,coins[index]));
	}
	return coinsSoFar+dp[index][steps][currentPosition]; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y;
	ans = -1;
	memset(dp,-1,sizeof dp);
	cin>>n>>k>>z;
	for(int i(0);i<n;i++){
		cin>>x>>y;
		jump.push_back(x);
		coins.push_back(y);
	}
	magicBox(0,1,0,0);
	cout<<ans<<endl;
	return 0;
}
