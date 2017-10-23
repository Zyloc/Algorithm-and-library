/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> career,love;
lli cost(lli k){
	lli totalCost(0);
	for(auto x:career){
		totalCost += min(k-x,0);
	}
	for(auto x:love){
		totalCost += max(x-k,0);
	}
	return totalCost;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,x;
	cin>>n>>m;
	for(int i(0);i<n;i++){
		cin>>x;
		career.push_back(x);
	}
	for(int i(0);i<n;i++){
		cin>>x;
		love.push_back(x);
	}
	lli left(0),right(1e18),ans(0);
	while(left <= right){
		lli mid(left+(right-left)/2);
		lli costOfMid(cost(mid));
		if(cost(mid+1) <= cost(mid) and cost(mid-1) >= cost(mid)){
			ans = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
