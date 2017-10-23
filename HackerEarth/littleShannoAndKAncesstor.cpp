/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+1);
lli n,k;
vector<lli> adj[MAX],edge[MAX];
lli ans[MAX];
bool visited[MAX];
lli color[MAX];
void dfs(lli vertex){
	visited[vertex] =  true;
	if(adj[color[vertex]].size() >= k){
		ans[vertex]  = adj[color[vertex]][adj[color[vertex]].size()-k];
	}
	adj[color[vertex]].push_back(vertex); 
	for(auto x:edge[vertex]){
		if(!visited[x]){
			dfs(x);
		}
	}
	adj[color[vertex]].pop_back();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(ans,-1,sizeof ans);
	lli x,y;
	cin>>n>>k;
	for(int i(1);i<=n;i++){
		cin>>color[i];
	}
	for(int i(0);i<n-1;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1);
	for(int i(1);i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
