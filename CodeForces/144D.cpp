/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+5);
lli n,m;
vector<pair<lli,lli> > edge[MAX];
vector<lli> minimumDistance(MAX,1e18);
void dijkstra(lli source){
	minimumDistance[source] = 0;
	set<pair<lli,lli> > activeVertices;
	for(int i(0);i<n;i++){
		activeVertices.insert({1e18,i});	
	}
	activeVertices.erase({1e18,source});
	activeVertices.insert({0,source});
	while(!activeVertices.empty()){
		pair<lli,lli> processing(*activeVertices.begin());
		activeVertices.erase(activeVertices.begin());
		for(int i(0);i<edge[processing.second].size();i++){
			pair<lli,lli> current(edge[processing.second][i]);
			if(minimumDistance[current.second] > minimumDistance[processing.second]+current.first){
				activeVertices.erase({minimumDistance[current.second],current.second});
				minimumDistance[current.second] = minimumDistance[processing.second]+current.first;
				activeVertices.insert({minimumDistance[current.second],current.second});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y,weight,k,totalLength,capital;
	cin>>n>>m>>capital;
	capital--;
	for(int i(0);i<m;i++){
		cin>>x>>y>>weight;
		x--,y--,weight;
		edge[x].push_back({weight,y});
		edge[y].push_back({weight,x});
	}
	cin>>totalLength;
	dijkstra(capital);
	lli ans(0);
	for(int i(0);i<n;i++){
		//cout<<minimumDistance[i]<<" ";
		if(minimumDistance[i] == totalLength){
			ans++;
		}
		else if(minimumDistance[i] < totalLength){
			for(int j(0);j<edge[i].size();j++){
				lli from(i);
				lli to(edge[i][j].second);
				lli edgeWeight(edge[i][j].first);
				if(minimumDistance[i] + edgeWeight > totalLength){
					lli firstPart(totalLength-minimumDistance[from]);
					lli secondPart(minimumDistance[to] + edgeWeight- firstPart );
					if(secondPart < totalLength){
						continue;
					}
					if(secondPart == totalLength and from < to){
						continue;
					}
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
