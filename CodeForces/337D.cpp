/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+5);
vector<lli> edge[MAX],effectedSettlement,dummy,ans[MAX];
bool visited[MAX];
int indexi;
void dfs(lli vertex,lli d){
	if(d == -1){
		return;
	}
	visited[vertex] = true;
	dummy.push_back(vertex);
	for(auto x:edge[vertex]){
		if(!visited[x]){
			dfs(x,d-1);
		}
	}
}
bool check(lli x){
	for(int i(0);i<indexi;i++){
		if(!binary_search(ans[i].begin(),ans[i].end(),x)){
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,d,x,y;
	cin>>n>>m>>d;
	for(int i(0);i<m;i++){
		cin>>x;
		effectedSettlement.push_back(x);
	}
	for(int i(0);i<n-1;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	for(auto settelment:effectedSettlement){
		dfs(settelment,d);
		for(auto temp:dummy){
			ans[indexi].push_back(temp);
			visited[temp] = false;
		}
		dummy.clear();
		sort(ans[indexi].begin(),ans[indexi].end());
		indexi++;
	}
	lli answer(0);
	for(auto x:ans[0]){
		if(check(x)){
			answer = x;
			break;
		}
	}
	cout<<answer<<endl;
	return 0;
}
