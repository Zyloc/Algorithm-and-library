/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MOD = 1e9+7;
const int MAX_SIZE = 2001;
lli dp[MAX_SIZE][MAX_SIZE];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		dp[1][i] = 1;
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k+=j){
				dp[i][k] = (dp[i][k] + dp[i-1][j])%MOD;
			}
		}
	} 
	int ans(0);
	for(int i=1;i<=n;i++){
		ans  = (ans+dp[k][i])%MOD;
	}
	cout<<ans<<endl;
	return 0;
}