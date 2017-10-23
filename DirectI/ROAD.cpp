/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e4+5);
lli parent[MAX];
lli sizeOf[MAX];
lli getParent(lli x){
	if(x!=parent[x]){
		parent[x] = getParent(parent[x]);
	}
	return parent[x];
}
void makeUnion(lli x,lli y){
	x = getParent(x);
	y = getParent(y);
	if(x!= y){
		if(sizeOf[x] > sizeOf[y]){
			parent[y] = x;
			sizeOf[x] += sizeOf[y];
		}
		else{
			parent[x] = y;
			sizeOf[y] += sizeOf[x];
		}	
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,x,y,z,cost;
	cin>>n>>m;
	vector<pair<lli,pair<lli,lli> > > input;
	for(int i(0);i<MAX;i++){
		parent[i] = i;
		sizeOf[i] = 1;
	}
	for(int i(0);i<m;i++){
		cin>>x>>y>>z;
		if(z == 1){
			cin>>cost;
			input.push_back({cost,{x,y}});
		}
		else{
			makeUnion(x,y);
		}
	}
	sort(input.begin(),input.end());
	lli ans(0);
	for(int i(0);i<input.size();i++){
		x = input[i].second.first;
		y = input[i].second.second;
		cost = input[i].first;
		if(getParent(x) != getParent(y)){
			makeUnion(x,y);
			ans+= cost;
		}
	}
	cout<<ans<<endl;
	return 0;
}
