/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e5+1;
vector<lli> parent(MAX),size(MAX);
lli root(lli x){
	while(parent[x] != x){
		x = parent[parent[x]];
	}
	return x;
}
void unionof(lli x,lli y){
	lli rootX(root(x)),rootY(root(y));
	if(rootX == rootY){
		return ;
	}
	if(size[rootX] > size[rootY]){
		parent[rootY] = rootX;
		size[rootX] += size[rootY]; 
	}
	else{
		parent[rootX] = rootY;
		size[rootY] += size[rootX];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<MAX;i++){
		parent[i] = i;
		size[i]  = 1;
	}
	for(int i=0;i<m;i++){
		cin>>x>>y;
		unionof(x,y);
	}
	for(int i=1;i<=n;i++){
		cout<<size[root(i)]-1<<" ";
	}
	return 0;
}