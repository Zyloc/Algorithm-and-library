/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
int dp[(1<<15)][15];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int input[n];
	for(int i=0;i<n;i++)
		cin>>input[i];
	for(int mask=0;mask<(1<<n);mask++){
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){
				for(int j=0;j<n;j++){
					if(!(mask&(1<<j))){
						int newMask((mask|(1<<j)));
						dp[newMask][j] = max(dp[newMask][j],dp[mask][i]+__gcd(input[i],input[j]));
					}
				}
			}
		}
	}
	int ans(0);
	for(int i=0;i<n;i++){
		ans = max(ans,dp[(1<<n)-1][i]);
	}
	cout<<ans<<endl;
	return 0;
}	