/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(5e6+1);
const int TREE_SIZE(5e6+1);
lli n,q;
bool visited[MAX];
vector<lli> edge[MAX];
lli segmentTree[TREE_SIZE];
lli segmentTreeInput[TREE_SIZE];
lli timer;
lli parent[MAX];
lli firstFound[MAX];
lli pathSum[MAX];
lli weight[MAX];
lli timeToIndexMapping[MAX];
lli weightBit[MAX];
lli lastFound[MAX];
vector<lli> eulerPath;
vector<lli> oppositeOfEulerPath;
lli eulerStart[MAX];
lli eulerEnd[MAX];
lli eulerTimer;
lli in[MAX];
lli out[MAX];
lli createTree(lli l,lli r,lli index){
	if(l == r){
		segmentTree[index] = firstFound[segmentTreeInput[l]];
		return segmentTree[index];
	}
	lli mid((l+r)/2);
	segmentTree[index] = min(createTree(l,mid,2*index+1),createTree(mid+1,r,2*index+2));
	return segmentTree[index];
}
lli getMinimum(lli l,lli r,lli index,lli qStart,lli qEnd){
	if(qStart > r or qEnd < l){
		return INT_MAX;
	}
	if(qStart <= l and qEnd >= r ){
		return segmentTree[index];
	}
	lli mid((l+r)/2);
	return min(getMinimum(l,mid,2*index+1,qStart,qEnd),getMinimum(mid+1,r,2*index+2,qStart,qEnd));
}
void dfs(lli index,lli weightSoFar,lli ancesstor){
	if(firstFound[index] == -1){
		firstFound[index] = timer;
		timeToIndexMapping[timer] = index;	
	}
	eulerPath.push_back(index);
	parent[index] = ancesstor; 
	segmentTreeInput[timer++] = index;
	visited[index] = true;
	pathSum[index] = weightSoFar;
	in[index] = eulerTimer++;
	for(auto x:edge[index]){
		if(!visited[x]){
			dfs(x,weightSoFar+weight[x],index);
			segmentTreeInput[timer++] = index;
			lastFound[index] = timer; 
		}
	}
	out[index] = eulerTimer++;
	eulerPath.push_back(index);
}
lli getLCA(lli x,lli y){
	lli a(firstFound[x]),b(firstFound[y]);
	if(a > b){
		swap(a,b);
	}
	return timeToIndexMapping[getMinimum(0,timer,0,a,b)];
}

void update(lli index,lli change){
	for(lli i(index);i<=eulerPath.size();i+=(i&-i)){
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
	return weightQuery(in[temp])-weightQuery(in[temp]-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	timer = 1;
	eulerTimer = 1;
	memset(firstFound,-1,sizeof firstFound);
	lli x,y,z;
	cin>>n>>q;
	for(lli i(1);i<=n;i++){
		cin>>weight[i];
	}
	for(int i(0);i<n-1;i++){
		cin>>x>>y;
		edge[x].push_back(y); 
		edge[y].push_back(x);
	}
	dfs(1,weight[1],0);
	createTree(0,timer,0);
	for(lli i(0);i<eulerPath.size();i++){
		update(i+1,pathSum[eulerPath[i]]);
	}
	for(int i(0);i<q;i++){
		cin>>x;
		if(x == 1){
			cin>>y>>z;
			lli lca(getLCA(y,z));
			cout<<getTotalWeight(y)+getTotalWeight(z)-2*getTotalWeight(lca)+weight[lca]<<endl;
		}
		else{
			cin>>x>>y>>z;
			stack<lli> leftStack,rightStack;
			lli current(x);
			lli lca(getLCA(x,y));
			while(current!=lca){
				leftStack.push(current);
				current = parent[current];
			}
			current = y;
			while(current!=lca){
				rightStack.push(current);
				current = parent[current];
			}
			if(getTotalWeight(lca)){
				lli currentWeight(weight[lca]);
				lli newWeight(currentWeight/z);
				lli changeInWeight(newWeight- currentWeight);
				//cout<<changeInWeight<<endl;
				update(in[lca],changeInWeight);
				//update(out[lca]+1,-changeInWeight);
				weight[lca] /= z;
			}
			/*while(!leftStack.empty()){
				current  = leftStack.top();
				lli currentWeight(weight[current]);
				lli newWeight(currentWeight/z);
				lli changeInWeight(newWeight- currentWeight);
				update(eulerStart[current],changeInWeight);
				update(eulerEnd[current]+1,-changeInWeight);
				weight[current] /= z;
				current = parent[current];
				leftStack.pop();
			}
			while(!rightStack.empty()){
				current  = rightStack.top();
				lli currentWeight(weight[current]);
				lli newWeight(currentWeight/z);
				lli changeInWeight(newWeight- currentWeight);
				update(eulerStart[current],changeInWeight);
				update(eulerEnd[current]+1,-changeInWeight);
				weight[current] /= z;
				current = parent[current];
				rightStack.pop();
			}*/
		}	
	}
	return 0;
}