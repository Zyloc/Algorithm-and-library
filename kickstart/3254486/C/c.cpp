/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	for(int i(1);i<=t;i++){
		lli n,m,x;
		cin>>n>>m;
		priority_queue<pair<lli,pair<lli,lli> >,vector<pair<lli,pair<lli,lli> > >,greater<pair<lli,pair<lli,lli> > > > pq;
		for(int i(1);i<=n;i++){
			for(int j(1);j<=n;j++){
				cin>>x;
				pq.push({x,{i,j}});
			}
		}
		lli counter(0);
		while(counter <= n*m){
			
		}
	}
	return 0;
}
