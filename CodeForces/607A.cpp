/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
int main(){
	int n,x,y;
	cin>>n;
	vector<pair<int,int> > input;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		input.push_back(make_pair(x,y));
	}
	sort(input.begin(),input.end());
	int dp[n],ans(0);
	for(int i=0;i<n;i++){
		lli search_index(lower_bound(input.begin(),input.end(),make_pair(input[i].first-input[i].second,0))-input.begin());
		search_index--;
		if(search_index < 0){
			dp[i] = 1;
		}
		else{
			dp[i] = 1+dp[search_index];
		}	
		ans = max(ans,dp[i]);

	}
	cout<<n-ans;
	return 0;
}