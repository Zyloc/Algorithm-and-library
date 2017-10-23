/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e2+2);
vector<lli> edge[MAX];
lli n,x,y,z;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli totalCost(0);
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x>>y>>z;
		totalCost+=z;
		edge[x].push_back({y,z});
	}
	
	return 0;
}
