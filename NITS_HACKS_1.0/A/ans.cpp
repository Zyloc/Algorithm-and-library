/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli  int
using namespace std;
const int MAX(5e6+1);
const int TREE_SIZE(5e6+1);
vector<lli> edge[MAX];
lli inDegree[MAX];
lli tree[TREE_SIZE];
lli treeInput[TREE_SIZE];
lli n,q;
bool visited[MAX];
lli treeInputIterator;
lli parent[MAX];
lli firstFound[MAX];
lli change[MAX];
lli level[MAX];
lli initialValue[MAX];
lli timeToIndexMapping[MAX];
lli createTree(lli l,lli r,lli index){
	if(l == r){
		tree[index] = firstFound[treeInput[l]];
		return tree[index];
	}
	lli mid((l+r)/2);
	tree[index] = min(createTree(l,mid,2*index+1),createTree(mid+1,r,2*index+2));
	return tree[index];
}
lli getMinimum(lli l,lli r,lli index,lli qStart,lli qEnd){
	if(qStart > r or qEnd < l){
		return INT_MAX;
	}
	if(qStart <= l and qEnd >= r ){
		return tree[index];
	}
	lli mid((l+r)/2);
	return min(getMinimum(l,mid,2*index+1,qStart,qEnd),getMinimum(mid+1,r,2*index+2,qStart,qEnd));
}
void dfs(lli index,lli ancesstor,lli lvl){
	level[index] = lvl;
	if(firstFound[index] == -1){
		firstFound[index] = treeInputIterator;
		timeToIndexMapping[treeInputIterator] = index;	
	}
	parent[index] = ancesstor; 
	treeInput[treeInputIterator++] = index;
	visited[index] = true;
	for(auto x:edge[index]){
		if(!visited[x]){
			dfs(x,index,lvl+1);
			treeInput[treeInputIterator++] = index;
		}
	}
}
lli getLCA(lli x,lli y){
	lli a(firstFound[x]),b(firstFound[y]);
	if(a > b){
		swap(a,b);
	}
	return timeToIndexMapping[getMinimum(0,treeInputIterator,0,a,b)];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(firstFound,-1,sizeof firstFound);
	lli x,y,z;
	cin>>n>>q;
	for(int i(0);i<n-1;i++){
		cin>>x>>y;
		inDegree[x]++;
		inDegree[y]++;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i(1);i<=n;i++){
		cin>>initialValue[i];
	}
	dfs(1,0,1);
	createTree(0,treeInputIterator,0);
	for(int i(0);i<q;i++){
		cin>>x>>y>>z;
		lli lca(getLCA(x,y));
		lli parentOfLca(parent[lca]);
		change[x] += z;
		change[y] += z;
		change[lca] -= z;
		change[parentOfLca] -= z;
	}
	priority_queue<pair<lli,lli> >pq;
	for(int i(1);i<=n;i++){
		pq.push({level[i],i});
	}
	while(!pq.empty()){
		lli top(pq.top().second);
		lli parentofCurrent(parent[top]);
		initialValue[top]+=change[top];
		change[parentofCurrent]+=change[top];
		pq.pop();	
	}
	for(int i(1);i<=n;i++){
		cout<<initialValue[i]<<" ";
	}
	return 0;
}
