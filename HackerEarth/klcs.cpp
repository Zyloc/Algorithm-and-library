/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
bool cache[2001][2001][6];
lli n,m,k,x;
int ans;
vector<lli> first,second;
lli lcs(lli indexX,lli indexY,lli k,int dp[][2001]){
	if(k < 0){
		return 0;
	}
	if(cache[indexX][indexY][k]){
		return 0;
	}
	cache[indexX][indexY][k] = true;
	for(int i(indexX);i<n;i++){
	    for(int j(indexY);j<m;j++){
	        if(i == 0){
	           if(first[i] == second[j]){
	               dp[i%2][j] = 1;
	           }
	           else{
	           		dp[i%2][j] = 1;
	           		lcs(i+1,j+1,k-1,dp);
	           		dp[i%2][j] = 0;
	           }
	        }
	        else if (first[i] == second[j]){
	            dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
	        }
	        else{
	            dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);
	            dp[i%2][j] = 1+dp[i%2][j];
	            lcs(i+1,j+1,k-1,dp);
	            dp[i%2][j] = dp[i%2][j];
	        }
	    }
	}
	for(int i(0);i<2;i++){
		ans= max(ans,max(dp[0][i],dp[1][i]));
	}
	//ans = max(ans,dp[(n-1)%2][m-1]);
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dp[2][2001];
	cin>>n>>m>>k;
    memset(dp,0,sizeof dp);
	for(int i(0);i<n;i++){
	    cin>>x;
	    first.push_back(x);
	}
	for(int i(0);i<m;i++){
	    cin>>x;
	    second.push_back(x);
	}
	memset(cache,false,sizeof cache);
	lcs(0,0,k,dp);
	cout<<ans<<endl;
	return 0;
}