/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,total(0);
	vector<lli> input;
	cin>>n;
	lli prefix[51]={0};
	for(int i(0);i<n;i++){
		cin>>x;
		input.push_back(x);
		if(i == 0){
			prefix[i] =x;
		}
		else{
			prefix[i] = x+prefix[i-1];
		}
		total += x;
	}
	lli dp[51][51]={0};
	for(lli len(1);len<=n;len++){
		for(int i(0);i<=n-len;i++){
			lli j(i+len-1);
			dp[i][j] = max(input[i]+p	rfefix[j]-prefix[i]-dp[i+1][j],dp[i+1][j]);
		}
	}
	cout<<total-dp[0][n-1]<<" "<<dp[0][n-1]<<endl;
	return 0;
}
