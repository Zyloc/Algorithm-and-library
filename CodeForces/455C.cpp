/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(3e5+6);
lli sizeOf[MAX];
lli parent[MAX];
lli diameter[MAX];
lli distance[MAX];
lli n,m,q,x,y;
vector<lli> edge[MAX];
vector<lli> connected;
bool visited[MAX];
bool bfsVisited[MAX][2];
lli maxi(lli x,lli y){
	return max(x,y);
}
lli rootOf(lli vertex){
	lli x(vertex);
	if( x != parent[x]){
		parent[x] = rootOf(parent[x]);
	}
	return parent[x];
}
void merge(lli u,lli v){
	u = rootOf(u);
	v = rootOf(v);
	if (u != v){
		if(sizeOf[u] >= sizeOf[v]){
			parent[v] = u;
			sizeOf[u] += sizeOf[v];
			diameter[u] = maxi(diameter[u],maxi(diameter[v],ceil((diameter[u]*1.0)/2)+ceil((diameter[v]*1.0)/2)+1));
		}
		else{
			parent[u] = v;
			sizeOf[v] += sizeOf[u];
			diameter[v] = maxi(diameter[u],maxi(diameter[v],ceil((diameter[u]*1.0)/2)+ceil((diameter[v]*1.0)/2)+1));
		}
	}
}
pair<lli,lli> maxi(pair<lli,lli> p1,pair<lli,lli> p2){
	if(p1.second >= p2.second){
		return p1;
	}
	return p2;
}
void printPair(pair<lli,lli> p){
	cout<<p.first<<" "<<p.second<<" ";
}
pair<lli,lli> bfs(lli root,lli flag){
	queue<pair<lli,lli> > q;
	q.push({root,0});
	bfsVisited[root][flag] = true;
	pair<lli,lli> ans(q.front());
	while(!q.empty()){
		pair<lli,lli> processing(q.front());
		for(auto x:edge[processing.first]){
			if(!bfsVisited[x][flag]){
				q.push({x,processing.second+1});
				ans = maxi(ans,{x,processing.second+1});
				bfsVisited[x][flag] = true;
			}
		}
		q.pop();
	}
	return ans;
}
void dfs(lli vertex){
	visited[vertex] = true;
	connected.push_back(vertex);
	for(auto x:edge[vertex]){
		if(!visited[x]){
			dfs(x);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>q;
	for(int i(0);i<=n;i++){
		parent[i] = i;
		sizeOf[i] = 1;
	}
	for(int i(0);i<m;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i(1);i<=n;i++){
		if(!visited[i]){
			connected.clear();
			dfs(i);
			pair<lli,lli> u(bfs(i,0));
			pair<lli,lli> v(bfs(u.first,1));	
			for(auto x:connected){
				parent[x] = v.first;
			}
			diameter[v.first] = v.second;
		}
	}
	for(int i(0);i<q;i++){
		cin>>x;
		if(x == 1){
			cin>>x;
			cout<<diameter[rootOf(x)]<<endl;
		}
		else{
			cin>>x>>y;
			merge(x,y);
		}
	}
	return 0;
}
