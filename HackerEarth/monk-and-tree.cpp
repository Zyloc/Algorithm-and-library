/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+1);
lli n,m,totalCost;
vector<pair<lli,lli> >graph[MAX];
vector<pair<lli,lli> > mstEdges;
vector<lli> key(MAX,1e18);
bool visited[MAX];
lli prims(lli source){
	set<pair<lli,lli> > pq;
	for(int i(0);i<n;i++){
		pq.insert({key[i],i});
	}
	pq.erase({key[source],source});
	pq.insert({0,source});
	lli minimumCost(0);
	while(!pq.empty()){
		pair<lli,lli> processing(*pq.begin());
		pq.erase(pq.begin());
		visited[processing.second] = true;
		if(processing.second != source){
			minimumCost+=processing.first;
			mstEdges.push_back(processing);
		}
		for(int i(0);i<graph[processing.second].size();i++){
			if(!visited[graph[processing.second][i].second]){
				if(key[graph[processing.second][i].second] > graph[processing.second][i].first){
					pq.erase({key[graph[processing.second][i].second],graph[processing.second][i].second});
					key[graph[processing.second][i].second] = graph[processing.second][i].first;
					pq.insert({key[graph[processing.second][i].second],graph[processing.second][i].second});
				}
			}
		}
	}
	return minimumCost;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y,cost;
	cin>>n>>m;
	for(int i(0);i<m;i++){
	    cin>>x>>y>>cost;
	    x--,y--;
	    graph[x].push_back({cost,y});
	    graph[y].push_back({cost,x});
	}
	cout<<prims(0)<<endl;
	return 0;
}	