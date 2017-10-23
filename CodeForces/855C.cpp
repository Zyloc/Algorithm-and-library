/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,m,k;
const int MAX(1e5+1);
const int MOD(1e9+7);
vector<lli> edge[MAX];
lli dfs[MAX][3][11];
lli dfs(lli vertex,lli color,lli left){
	lli code(0);
	if(color < k){
		if(color > 0 ){
			code = 0;
		}
		else{
			return 0;
		}
	}
	if(color > k){
		if(color <= m){
			code = 2;
		}
		else{
			return 0;
		}
	}
	if(color == k){
		if(color >= 1){
			code = 1;
		}
		else{
			return 0;
		}
	}
	if(left == 0){
		return 1;
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	lli x,y;
	for(int i(0);i<n;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(dp,-1,sizeof dp);
	cin>>k>>x;
	lli ans(0);
	ans = dfs(1,k,x-1)%MOD;
	ans = (ans + dfs(1,k-1,x)%MOD)%MOD;
	ans = (ans + dfs(1,k+1,x))%MOD;
	return 0;
}
