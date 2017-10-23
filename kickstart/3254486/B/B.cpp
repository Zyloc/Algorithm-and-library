/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	for(int i(1);i<=t;i++){
		lli n,m;
		cin>>n;
		lli dp[n+1][n+1];
		lli red[n+1],blue[n+1];
		memset(dp,-1,sizeof dp);
		for(int i(1);i<=n;i++){
			cin>>red[i];
		}
		for(int i(1);i<=n;i++){
			cin>>blue[i];
		}
		for(int i(1);i<=n;i++){
			for(int j(1);j<=n;j++){
				if(i!=j){
					dp[i][j] = red[i]^blue[j];
				}
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
