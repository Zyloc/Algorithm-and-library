/*
 * Everyting happens for a reason . Hold tight everything is gonna ok :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e4+1);
lli n;
string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli x;
		lli dp[27];
		vector<lli> cost;
		cin>>s;
		n = s.length();
		for(int i(0);i<s.length();i++){
			cin>>x;
			cost.push_back(x);
		}
		for(int i(0);i<27;i++){
			dp[i] = 1e18;
		}
		dp[0] = 0;
		for(int i(0);i<n;i++){
			dp[(s[i]-'a')+1] = min(dp[(s[i]-'a')+1],cost[i]+dp[(s[i]-'a')]);
		}
		if(dp[26]!=1e18){
			cout<<dp[26]<<endl;
		}
		else{
			cout<<"Not Possible."<<endl;
		}
	}
	return 0;
}
