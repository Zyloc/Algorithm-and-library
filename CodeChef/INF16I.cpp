/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 1;
const int MAX_COPIES = 1e5 + 1;
vector<int> graph(MAX);
vector<int> copies,ultraSpecialSoftware;
bool dfs(int start){
	if(graph[start] != -1){
		if(copies[start] > 0 and dfs(graph[start])){
			copies[start]--;
			return true;
		}
		return false;
	}	
	else{
		if(copies[start] > 0){
			copies[start]--;
			return true;
		}
		return false;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,x,y;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			graph[x] = y;
		}
		copies.push_back(0);
		for(int i=0;i<n;i++){
			cin>>x;
			copies.push_back(x);
		}
		for(int i=0;i<k;i++){
			cin>>x;
			ultraSpecialSoftware.push_back(x);
		}
		int ans(0);
		for(int i=0;i<k;i++){
			if(dfs(ultraSpecialSoftware[i])){
				ans++;
			}
		}
		cout<<ans<<endl;
		graph.clear();
		copies.clear();
		ultraSpecialSoftware.clear();	
	}
	return 0;
}