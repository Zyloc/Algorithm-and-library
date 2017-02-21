/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e3+1;
int check[MAX];
vector<int> v;
int dp[MAX];
int solve(lli index,lli value){
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m;
	cin>>n>>m;
	lli input[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
		input[i]%=m;
	}
	if(n > m){
		cout<<"YES"<<endl;
	}
	else{
		bool dp[n+1][m+1];
		memset(dp,false,sizeof dp);
		for(int i=0;i<=n;i++){
			dp[i][0] = true; 
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i][j] = (dp[i-1][j] or dp[i-1][(j+input[i-1])%m]);
			}
		}
		if(dp[n][m]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}