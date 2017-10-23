/*
 * Keep breathing :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MOD(1e9+7);
const int MAX(1e3+1);
const int MAX_REPEAT(5e3+1);
lli n,m,k;
lli dp[MAX][MAX_REPEAT];
lli count;
lli magicBox(lli index,lli remaning,lli height){
	if(height == n){
		return 1;
	}
	if(index == 0 or remaning == 0){
		return 0;
	}
	if(dp[index][remaning]!=-1){
		return dp[index][remaning];
	}
	dp[index][remaning] = magicBox(index-1,k,height)%MOD;
	dp[index][remaning] = (dp[index][remaning]%MOD+magicBox(index,remaning-1,height+1)%MOD)%MOD;	
	return dp[index][remaning]%MOD;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k;
	cout<<magicBox(3,k,0)<<endl;
	return 0;
}
