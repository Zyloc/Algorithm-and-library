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
vector<lli> tree[MAX];
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
	lli n,x,y;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		x--;y--;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(0, 0, 0);
	lcaInit(n);
	for (int i=0;i<1;i++){
		cin>>x>>y;
		x--,y--;
		printf("%lld\n",lca_query(n,x,y)+1);
	}
	return 0;
}