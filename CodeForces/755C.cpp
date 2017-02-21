/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
int visited[10001];
vector<int> graph[10001];
void dfs(int start){
	visited[start] = true;
	for(auto x:graph[start]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
int main(){
	int x,y,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		visited[i] = false;
		graph[x].push_back(i);
		graph[i].push_back(x);
	}
	int ans(0);
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}