/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1e5+1;
const lli MOD = 1000000007;
int main(){	
	lli n,m,x,u,v,minColor(MAX);
	cin>>n>>m;
	set<lli> st[MAX];
	lli color[n];
	for(lli i=0;i<n;i++){
		cin>>x;
		color[i] = x;
		minColor = min(minColor,x);
	}
	for(lli i=0;i<m;i++){
		cin>>u>>v;
		u--;
		v--;
		if(color[u] == color[v]) continue;
		st[color[u]].insert(color[v]);
		st[color[v]].insert(color[u]);
	}
	lli maxNeighbour(0),ans(minColor);
	for(lli i=0;i<MAX;i++){
		if(st[i].size() > maxNeighbour){
			maxNeighbour = st[i].size();
			ans = i;
		}		 
	}
	cout<<ans<<endl;
	return 0;
}	