/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+5);
lli dp[MAX][2];
lli input[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		input[x]+=x;
	}
	for(int i(1);i<MAX;i++){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = input[i]+dp[i-1][0];
	}
	cout<<max(dp[MAX-1][0],dp[MAX-1][1]);
	return 0;
}
