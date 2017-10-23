/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(5e4+5);
vector<lli> leaf,parent(MAX),value(MAX),addUp(MAX),subTreeSum(MAX);
bool isParent[MAX],visited[MAX];
lli n,m,q;
vector<lli> edge[MAX];
lli dfs(lli vertex){
	visited[vertex] = true;
	subTreeSum[vertex] = value[vertex];
	for(auto x:edge[vertex]){
		if(!visited[x]){
			subTreeSum[vertex] += dfs(x);
		}
	}
	return subTreeSum[vertex];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		leaf.clear();
		memset(isParent,false,sizeof isParent);
		memset(visited,false,sizeof visited);
		for(int i(0);i<MAX;i++){
			parent[i] = 0;
			value[i] = 0;
			addUp[i] = 0;
			edge[i].clear();
			subTreeSum[i] = 0;
		}
		lli x,y;
		string s;
		cin>>n>>m>>q;
		for(int i(1);i<=n;i++){
			cin>>parent[i];
			isParent[parent[i]] = true;
			edge[i].push_back(parent[i]);
			edge[parent[i]].push_back(i);
		}
		for(int i(0);i<m;i++){
			cin>>s;
			if(s == "ADD"){
				cin>>x>>y;
				value[x] += y;  
			}
			else {
				cin>>x>>y;
				addUp[x] += y;
			}
		}
		for(int i(1);i<=n;i++){
			if(!isParent[i]){
				leaf.push_back(i);
			}
		}
		for(auto x:leaf){
			lli temp(x),upValue(0);
			while(temp != 0){
				if(!visited[temp]){
					upValue += addUp[temp];
				}
				visited[temp] = true;
				value[temp] += upValue;
				temp = parent[temp];
			}
		}
		visited[0] = true;
		memset(visited,false,sizeof visited);
		dfs(1);
		for(int i(0);i<q;i++){
			cin>>s;
			if(s == "VAL"){
				cin>>x;
				cout<<value[x]<<endl;
			}
			else{
				cin>>x;
				cout<<subTreeSum[x]<<endl;
			}
		}
	}	
	return 0;
}
