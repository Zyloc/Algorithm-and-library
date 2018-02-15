/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e3+4);
vector<lli> input;
lli dp[MAX][MAX];
lli n,x;
lli magicBox(lli start,lli end){
	if(start > end){
		return 0;
	}
	if(dp[start][end]!=-1){
		return dp[start][end];
	}
	lli year(n-(end-start+1)+1);
	dp[start][end] = max(magicBox(start+1,end)+year*input[start],magicBox(start,end-1)+year*input[end]);
	return dp[start][end];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	memset(dp,-1,sizeof dp);
	input.push_back(0);
	for(int i(0);i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	cout<<magicBox(1,n);
	return 0;
}
