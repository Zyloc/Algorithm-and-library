/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
int main(){
	int n,x,y;
	cin>>n;
	vector<int> index,power;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		index.pb(x);
		power.pb(y);
	}
	int dp[n],ans(0);
	memset(dp,-1,sizeof dp);
	dp[0] = 1;
	for(int i=1;i<n;i++){
		lli search_index(lower_bound(index.begin(),index.end(),index[i]-power[i])-index.begin());
		if(search_index!=0){
			search_index-=1;
			dp[i] = max(dp[i-1],1+dp[search_index]);
		}
		else{
			dp[i] = dp[i-1];
		}
	}
	cout<<n-dp[n-1];
	return 0;
}