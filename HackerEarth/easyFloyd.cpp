#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,m,x,y,z,s,k;
		cin>>n>>m;
		vector<pair<lli,lli> > edge[n+1];
		lli inDegree[n+1];
		memset(inDegree,0,sizeof inDegree);
		for(int i(0);i<m;i++){
			cin>>x>>y>>z;
			edge[x].push_back({y,z});
			inDegree[y]++;
		}
		cin>>s>>k;
		queue<lli> pq;
		for(int i(1);i<=n;i++){
			if(inDegree[i] == 0){
				pq.push(i);
			}
		}
		vector<lli> topologicalSort;
		while(!pq.empty()){
			lli processing(pq.front());
			pq.pop();
			topologicalSort.push_back(processing);
			for(auto a:edge[processing]){
				inDegree[a.first]--;
				if(inDegree[a.first] == 0){
					pq.push(a.first);
				}
			}
		}
		vector<lli> distance(n+1,1e16);
		distance[s] = 0;
		for(auto a:topologicalSort){
			for(auto b:edge[a]){
				distance[b.first] = min(distance[b.first],distance[a]+b.second);
			}	
		}
		sort(distance.begin(),distance.end());
		lli ans(0),sum(0);
		for(int i(0);i<=n;i++){
			if(k >= distance[i]){
				ans++;
				k -= distance[i];
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
