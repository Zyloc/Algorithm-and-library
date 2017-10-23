/*
 * Everyting happens for a reason . Hold tight everything is gonna ok :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> height,cost;
lli n,x,maxHeight(0);
lli check(lli h){
	lli dummy(0);
	for(int i(0);i<n;i++){
		dummy += abs(height[i]-h)*cost[i];
	}
	return dummy; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i(0);i<n;i++){
			cin>>x;
			height.push_back(x);
			maxHeight = max(maxHeight,x);
		}
		for(int i(0);i<n;i++){
			cin>>x;
			cost.push_back(x);
		}
		lli left(0),right(maxHeight),ans(0);
		while(left <= right){
			lli mid((left+right)/2);
			lli temp1(check(mid-1));
			lli temp2(check(mid));
			lli temp3(check(mid+1));
			if(temp2 < temp1 ){
				ans = mid;
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		cout<<ans<<endl;
		height.clear();
		cost.clear();
	}
	return 0;
}

