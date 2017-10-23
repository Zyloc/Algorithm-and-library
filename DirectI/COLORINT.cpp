/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e2+2);
lli n,m,k;
vector<lli> weight;
vector<lli> category[MAX];
lli dp[MAX][MAX];
lli magicBox(lli index,lli remainingWeight){
	if(index == m){
		return remainingWeight;
	}
	if(dp[index][remainingWeight]!=-1){
		return dp[index][remainingWeight];
	}
	dp[index][remainingWeight] = INT_MAX;
	for(auto x:category[index]){
		if(weight[x] <= remainingWeight){
			dp[index][remainingWeight] = min(dp[index][remainingWeight],magicBox(index+1,remainingWeight-weight[x]));
		}
	}
	return dp[index][remainingWeight];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		weight.clear();
		for(int i(0);i<MAX;i++){
			category[i].clear();
		}
		memset(dp,-1,sizeof dp);
		cin>>n>>m>>k;
		lli x;
		for(int i(0);i<n;i++){
			cin>>x;
			weight.push_back(x);
		}
		for(int i(0);i<n;i++){
			cin>>x;
			x--;
			category[x].push_back(i);
		}
		lli ans(magicBox(0,k));
		cout<<(ans == INT_MAX ? -1:ans)<<endl;
	}
	return 0;
}
