/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+5);
vector<int> graph[MAX],processing;
bool visited[MAX];
string input;
void dfs(int vertex){
	visited[vertex] = true;
	processing.push_back(vertex);
	for(auto x:graph[vertex]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		memset(visited,false,sizeof visited);
		for(int i(0);i<MAX;i++){
			graph[i].clear();
		}
		cin>>input;
		int n,x,y;
		cin>>n;
		for(int i(0);i<n;i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		for(int i(0);i<input.size();i++){
			if(!visited[i]){
				processing.clear();
				dfs(i);
				sort(processing.begin(),processing.end());
				string dummyString;
				for(int j(0);j<processing.size();j++){
					dummyString += input[processing[j]];
				}
				sort(dummyString.begin(),dummyString.end());
				for(int j(0);j<processing.size();j++){
					input[processing[j]] = dummyString[j];
				}
			}
		}
		cout<<input<<endl;
		
	}
	return 0;
}
