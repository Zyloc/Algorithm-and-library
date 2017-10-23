/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e5+1;
vector<lli> roadParent(MAX),railwayParent(MAX),roadSize(MAX),railwaySize(MAX);
lli roadRoot(lli x){
	while(roadParent[x] != x){
		x = roadParent[roadParent[x]];
	}
	return x;
}
void unionOfRoad(lli x,lli y){
	lli rootX(roadRoot(x)),rootY(roadRoot(y));
	if(rootX == rootY){
		return ;
	}
	if(roadSize[rootX] > roadSize[rootY]){
		roadParent[rootY] = rootX;
		roadSize[rootX] += roadSize[rootY]; 
	}
	else{
		roadParent[rootX] = rootY;
		roadSize[rootY] += roadSize[rootX];
	}
}
lli railwayRoot(lli x){
	while(railwayParent[x] != x){
		x = railwayParent[railwayParent[x]];
	}
	return x;
}
void unionOfRailway(lli x,lli y){
	lli rootX(railwayRoot(x)),rootY(railwayRoot(y));
	if(rootX == rootY){
		return ;
	}
	if(railwaySize[rootX] > railwaySize[rootY]){
		railwayParent[rootY] = rootX;
		railwaySize[rootX] += railwaySize[rootY]; 
	}
	else{
		railwayParent[rootX] = rootY;
		railwaySize[rootY] += railwaySize[rootX];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,q;
	cin>>n>>q;
	for(int i(0);i<=n;i++){
	    roadParent[i] = i;
	    roadSize[i] = 1;
	    railwayParent[i] = i;
	    railwaySize[i] = 1;
	}
	lli type,x,y;
	stack<pair<lli,lli> > roadNotRailway,railwayNotRoad;
	while(q--){
	    cin>>type>>x>>y;
	    if(type == 1){
	        unionOfRailway(x,y);
	        if(roadRoot(x) != roadRoot(y)){
	            railwayNotRoad.push({x,y});
	        }
	    }
	    else{
	        unionOfRoad(x,y);
	        if(railwayRoot(x) != railwayRoot(y)){
	            roadNotRailway.push({x,y});
	        }
	    }
	    while(!railwayNotRoad.empty()){
	        pair<lli,lli> top(railwayNotRoad.top());
	        if(roadRoot(top.first) != roadRoot(top.second)){
	            break;
	        }
	        railwayNotRoad.pop();
	    }
	    while(!roadNotRailway.empty()){
	        pair<lli,lli> top(roadNotRailway.top());
	        if(railwayRoot(top.first) != railwayRoot(top.second)){
	            break;
	        }
	        roadNotRailway.pop();
	    }
	    cout<<(roadNotRailway.empty() and railwayNotRoad.empty()?"YES":"NO")<<endl;
	}
	return 0;
}