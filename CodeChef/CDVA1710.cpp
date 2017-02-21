/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const lli MAX = 1e5+1;
const lli MAX_LOG = 22;
lli	level[MAX];
lli parent[MAX];
lli bit[MAX][MAX_LOG];
vector<pair<lli,lli> > tree[MAX];
lli distanceFromRoot[MAX];
void dfs(lli from,lli processing,lli depth,lli distanceSoFar){
	parent[processing] = from;
	level[processing] = depth;
	for(auto x:tree[processing]){
		if(x.first == from) continue;
		distanceFromRoot[x.first] = distanceSoFar+x.second;
		dfs(processing,x.first,depth+1,distanceFromRoot[x.first]);
	}
}
lli lca_query(lli size,lli u,lli v){
	if(level[u] < level[v]){
		swap(u,v);
	}
	lli log(1);
	while(1){
		lli next(log+1);
		if((1<<next)>level[u])break;
		log++;
	}
	for(lli i=log;i>=0;i--){
		if (level[u] - (1 << i) >= level[v]){
			u = bit[u][i];
		}
	}
	if(u == v){
		return  u;
	}
	for(lli i = log;i>=0;i--){
		if(bit[u][i]!=-1 and bit[u][i]!=bit[v][i]){
			u = bit[u][i];
			v = bit[v][i];
		}
	}
	return parent[u];
}
void lcaInit(lli size){
	memset(bit,-1,sizeof bit);
	for(lli i=0;i<size;i++){
		bit[i][0]=parent[i];
	}
	for(lli j=1;(1<<j)<size;j++){
		for(lli i=0;i<size;i++){
			if(bit[i][j-1]!=-1){
				bit[i][j] = bit[bit[i][j-1]][j-1];
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,y,weight,q;
	//cin>>n>>q;
	scanf("%lld %lld",&n,&q);
	for(int i=0;i<n-1;i++){
		scanf("%lld %lld %lld",&x,&y,&weight);
		//cin>>x>>y>>weight;
		x--;y--;
		tree[x].push_back(make_pair(y,weight));
		tree[y].push_back(make_pair(x,weight));
	}
	dfs(0, 0, 0,0);
	lcaInit(n);
	vector<lli> cab;
	cab.push_back(0);
	for (int i=0;i<q;i++){
		lli type;
		//cin>>type;
		scanf("%lld",&type);
		if(type == 1){
			scanf("%lld",&x);
			//cin>>x;
			x--;
			cab.push_back(x);
		}
		else{
			scanf("%lld",&x);
			//cin>>x;
			x--;
			lli ans(INT_MAX);
			for(int i=0;i<cab.size();i++){
				ans = min(ans,distanceFromRoot[cab[i]]+distanceFromRoot[x]-2*distanceFromRoot[lca_query(n,x,cab[i])]);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}