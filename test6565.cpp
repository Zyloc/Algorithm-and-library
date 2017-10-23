#include <bits/stdc++.h>

using namespace std;
const int MAX(1e6+5);
vector<int> graph[MAX];
bool visited[MAX];
int size;
void dfs(int vertex){
    size++;
    visited[vertex] = true;
    for(auto x:graph[vertex]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    int degree[n+1];
    memset(degree,0,sizeof degree);
    for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<pair<int,int> > sizeOfGraph;
    for(int i(1);i<=n;i++){
        if(!visited[i]){
            size = 0;
            dfs(i);
            sizeOfGraph.push_back({size,i});
        }
    }
    sort(sizeOfGraph.begin(),sizeOfGraph.end());
    long long int ans(0);
    for(int i(0);i<sizeOfGraph.size();i++){
        ans+= (sizeOfGraph[i].first*(sizeOfGraph[i].first-1));
    }
    cout<<ans<<endl;
    return 0;
}
