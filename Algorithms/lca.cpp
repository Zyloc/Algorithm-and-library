/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const lli MAX = 3e5+2;
const lli MAX_LOG = 22;
struct dataType{
	lli start,end,costSoFar,clientId;
};
lli	level[MAX];
lli parent[MAX];
lli bit[MAX][MAX_LOG];
vector<lli> tree[MAX];
vector<dataType> upQuery[MAX],downQuery[MAX];
lli ans[MAX];
void dfs(lli from,lli processing,lli depth){
	parent[processing] = from;
	level[processing] = depth;
	for(auto x:tree[processing]){
		if(x == from) continue;
		dfs(processing,x,depth+1);
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
	lli n,x,y,m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(1, 1, 1);
	lcaInit(n);
	for (int i=0;i<m;i++){
		cin>>x>>y;
		lli lca(lca_query(x,y));
		dataType temp1,temp2;
		temp1.start = x;
		temp1.end = lca;
		temp1.clientId = i;
		temp1.costSoFar = 0;
		upQuery[x].push_back(temp1);
		temp2.start = lca
	}
	return 0;
}