/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MOD = 1e9+7;
const int MAXSIZE = 1e5+1;
lli dp[MAXSIZE][3];
lli sum[MAXSIZE];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,threshold[3];
		cin>>n>>threshold[0]>>threshold[1]>>threshold[2];
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		sum[0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
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