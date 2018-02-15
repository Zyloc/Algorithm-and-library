/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define lli int
const lli MAX(1e5+5);
const lli EULER_MAX(1e6);
const lli MAX_LOG = 22;
lli	level[MAX];
lli parent[MAX];
lli bit[MAX][MAX_LOG];
lli inTime[MAX];
lli outTime[MAX];
lli pathSum[MAX];
lli updatedWeightOfNode[MAX];
lli weight[MAX];
lli timer;
lli n,q;
lli weightBit[EULER_MAX];
bool visited[MAX];
vector<lli> eulerPath;
vector<lli> tree[MAX];

void dfs(lli from,lli processing,lli depth,lli weightSoFar){
	visited[processing] = true;
	parent[processing] = from;
	level[processing] = depth;
	eulerPath.push_back(processing);
	pathSum[processing] = weightSoFar;
	if(inTime[processing] == -1 ){
		inTime[processing] = timer++;
	}
	for(auto x:tree[processing]){
		if(!visited[x]){
			dfs(processing,x,depth+1,weight[x]+weightSoFar);
		}
	}
	//eulerPath.push_back(processing);
	outTime[processing] = timer;
}
lli lca_query(lli u,lli v){
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
	for(lli i=1;i<size;i++){
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

void update(lli index,lli change){
	for(lli i(index);i<=n;i+=(i&-i)){
		weightBit[i]+=change;
	}
}

lli weightQuery(lli index){
	lli ans(0);
	for(lli i(index);i>0;i-=(i&-i)){
		ans+=weightBit[i];
	}
	return ans;
}

lli getTotalWeight(lli temp){
	return weightQuery(inTime[temp])-weightQuery(inTime[temp]-1);
}

lli main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,y,k;
	cin>>n>>q;
	timer = 1;
	memset(inTime,-1,sizeof inTime);
	for(lli i(1);i<=n;i++){
		cin>>weight[i];
	}
	for(lli i=0;i<n-1;i++){
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	//inTime[1] = 0;
	dfs(0, 1, 1,weight[1]);
	lcaInit(n+1);
	for(lli i(0);i<eulerPath.size();i++){
		update(i+1,pathSum[eulerPath[i]]);
	}
	/*for(lli i(1);i<=n;i++){
		cout<<getTotalWeight(i)<<endl;
	}*/
	for(lli i(0);i<q;i++){
		cin>>x;
		if(x == 1){
			cin>>x>>y;
			lli lca(lca_query(x,y));
			cout<<lca<<endl;
			cout<<getTotalWeight(x)+getTotalWeight(y)-2*getTotalWeight(lca)+weight[lca]<<endl;
		}
		else{
			cin>>x>>y>>k;
			lli lca(lca_query(x,y));
			//left part only if sum is not 0
			if(getTotalWeight(x)-getTotalWeight(parent[lca])){
				lli current(x);
				while(current!=lca){
					lli currentNodeWeight(getTotalWeight(current));
					lli newWeight(currentNodeWeight/k);
					lli change(newWeight-currentNodeWeight);
					lli inTimeOfCurrentNode(inTime[current]);
					lli outTimeOfCurrentNode(outTime[current]);
					update(inTimeOfCurrentNode,change);
					update(outTimeOfCurrentNode,-change);
					weight[current] = newWeight;
					current = parent[current];
				}
			}
			if(getTotalWeight(y)-getTotalWeight(parent[lca])){
				lli current(y);
				while(current!=lca){
					lli currentNodeWeight(getTotalWeight(current));
					lli newWeight(currentNodeWeight/k);
					lli change(newWeight-currentNodeWeight);
					lli inTimeOfCurrentNode(inTime[current]);
					lli outTimeOfCurrentNode(outTime[current]);
					update(inTimeOfCurrentNode,change);
					update(outTimeOfCurrentNode,-change);
					weight[current] = newWeight;
					current = parent[current];
				}
			}
			if(getTotalWeight(lca)){
				lli currentNodeWeight(getTotalWeight(lca));
				lli newWeight(currentNodeWeight/k);
				lli inTimeOfCurrentNode(inTime[lca]);
				lli outTimeOfCurrentNode(outTime[lca]);
				lli change(newWeight - currentNodeWeight);
				update(inTimeOfCurrentNode,change);
				update(outTimeOfCurrentNode,-change);
				weight[lca] = newWeight;
			}
		}
	}	
	return 0;
}
