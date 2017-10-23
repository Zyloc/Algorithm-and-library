/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<pair<lli,lli> > counter;
const int MAX(202);
lli n,k,x;
pair<lli,lli> sumi(pair<lli,lli> p1,pair<lli,lli> p2){
	return {p1.first+p2.first,p1.second+p2.second};
}
lli mini(pair<lli,lli> p1){
	return min(p1.first,p1.second);
}
pair<lli,lli> maxi(pair<lli,lli> p1,pair<lli,lli> p2){
	if(mini(p1) < mini(p2)){
		return p2;
	}
	return p1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i(0);i<n;i++){
		cin>>x;
		lli countTwo(0),countFive(0);
		while(x > 0 and x%2 == 0){
			x/=2;
			countTwo++;
		}
		while(x > 0 and x%5 == 0){
			x/=5;
			countFive++;
		}
		counter.push_back({countTwo,countFive});
	}
	vector<vector<pair<lli,lli > > > dp(MAX,vector<pair<lli,lli > >(MAX,{0,0}));
	for(lli i(1);i<=n;i++){
		for(lli j(0);j<=min(i,k);j++){
			if(j == 0){
				dp[i][j] = {0,0};
				continue;
			}
			dp[i][j] = maxi(sumi(counter[i-1],dp[i-1][j-1]),dp[i-1][j]);
		}
	}
	lli ans(0);
	cout<<mini(dp[n][k])<<endl;
	return 0;
}
