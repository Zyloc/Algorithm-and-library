/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+1);
vector<lli> graph[MAX];
lli n;
//vector<lli> levels(MAX,0);
lli level[MAX];
lli remaining[MAX];
bool visited[MAX];
void dfs(lli processing,lli level){
	visited[processing] = true;
	levels[processing] = (level);
	remaining[processing] = 1;
	for(auto x:graph[processing]){
		if(!visited[x]){
			dfs(x,level+1);
			remaining[processing]+=remaining[x];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(	false);
	cin.tie(NULL);
	lli a,b;
	cin>>n;
	vector<pair<lli,lli> > input;
	for(int i(0);i<n-1;i++){
		cin>>a>>b;
		input.push_back({a,b});
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1,0);
	double totalSum(0);
	for(int i(1);i<=n;i++){
		totalSum+=level[i];
		remaining[i] = n- remaining[i];
		//cout<<remaining[i]<<" ";
	}
	double ans(0);
	for(int i(1);i<=n-1;i++){
		ans+=(1.0/totalSum)*double(max(levels[input[i].first],levels[input[i].second]))*double()
	}
	return 0;
}
