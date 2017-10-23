/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<pair<lli,lli> > edge[51];
bool visited[51];
bool isInfinitePath[51];
bool dfs(lli source,lli remainingFuel){
	if(isInfinitePath[source]){
		return true;
	}
	visited[source] = true;
	bool ans(false);
	for(auto x:edge[source]){
		if(!visited[x.first]){
			if(x.second < 0 and remainingFuel  >= abs(x.second)){
				ans |= dfs(x.first,remainingFuel+x.second);	
			}
			else if(x.second >= 0){
				ans |= dfs(x.first,remainingFuel+x.second);	
			}
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,e,x,y,cost,source,initialFuel;
	cin>>n>>e;
	lli path[51][51];
	memset(path,-1,sizeof path);
	for(int i(0);i<e;i++){
		cin>>x>>y>>cost;
		edge[x].push_back({y,cost});
		path[x][y] = cost;
	}
	for(int i(1);i<=n;i++){
		for(int j(1);j<=n;j++){
			if(path[i][j] > path[j][i] and path[i][j]!=-1){
				isInfinitePath[i] = true;
			}
		}
	}
	cin>>source>>initialFuel;
	bool check(dfs(source,initialFuel));
	cout<<(check?"LIVES":"DIES")<<endl;
	return 0;
}
