/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const lli MOD = 1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,e;
		cin>>n>>e;
		lli dp[n+1][e+1];
		lli sum[n+1];
		lli threshold[e];
		for(int i=0;i<e;i++){
			cin>>threshold[i];
		}
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		sum[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<e;j++){
				dp[i][j] = sum[i-1];
				if(i > threshold[j]){
					dp[i][j] = (dp[i][j]-sum[i-threshold[j]-1]+dp[i-threshold[j]-1][j]+MOD)%MOD;
				}
				sum[i] = (sum[i]+dp[i][j])%MOD;
			}
		}
		cout<<sum[n]<<endl;
	}
	return 0;
}