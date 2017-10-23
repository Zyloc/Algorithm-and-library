/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(3e5+1);
vector<pair<lli,lli> > edge[MAX];
vector<pair<lli,lli> > topDownCost(MAX),bottomUpCost(MAX);
vector<lli> nodeCost(MAX);
bool visited[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,x,y,z;
	cin>>n>>m;
	for(int i(1);i<=n;i++){
		cin>>nodeCost[i];
	}
	for(int i(0);i<n-1;i++){
		cin>>x>>y>>z;
		edge[x].push_back({y,z});
		edge[y].push_back({x,z});
	}
	return 0;
}
