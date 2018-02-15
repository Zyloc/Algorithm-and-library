/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+1);
bool visited[MAX];
vector<lli> edge[MAX];
vector<pair<lli,lli> > input;
lli n,m;
void dfs(lli processing){
	visited[processing] = true;
	for(auto x:edge[processing]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y;
	cin>>n>>m;
	for(int i(1);i<=n;i++){
		cin>>x;
		input.push_back({x,i});
	}
	sort(input.begin(),input.end());
	for(int i(0);i<m;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	lli ans(0);
	for(int i(0);i<n;i++){
		if(!visited[input[i].second]){
			dfs(input[i].second);
			ans+=input[i].first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
