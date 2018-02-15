/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;
lli n,k;
vector<lli> input;
const int MAX(1e5+2);
int dp[MAX][51];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,0,sizeof dp);
	cin>>n>>k;
	lli x;
	for(int i(0);i<n;i++){
	    cin>>x;
	    input.push_back(x);
	}
	for(int i(0);i<51;i++){
		dp[0][i] = 1;
	}
	int ans(0),maxSoFar(input[0]);
	for(int index(1);index<n;index++){
		for(int remaining(0);remaining<=k;remaining++){
			dp[index][remaining] = dp[index-1][remaining];
			for(int last(0);last<=maxSoFar;last++){
				if(remaining >= abs(last-input[index])){
					dp[index][remaining] = max(dp[index][remaining],1+dp[index-1][remaining-abs(last-input[index])]);	
				}
				ans = max(ans,dp[index][remaining]);
			}
		}
		maxSoFar = max(maxSoFar,input[index]);
	}
	cout<<ans<<endl;
	return 0;
}	