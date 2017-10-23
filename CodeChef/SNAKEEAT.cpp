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
	while(t--){
		lli n,q,x;
		cin>>n>>q;
		vector<lli> v;
		for(int i(0);i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		lli prefixSum[n];
		prefixSum[0] = v[0];
		for(int i(1);i<n;i++){
			prefixSum[i] = prefixSum[i-1]+v[i];
		}
		while(q--){
			cin>>x;
			lli index(lower_bound(v.begin(),v.end(),x)-v.begin());
			lli left(0),right(index-1),ans(n-index);
			while(left <= right){
				lli mid((left+right)/2);
				lli requiredSum;
				if(mid!=0){
					requiredSum = x*(index-mid)- prefixSum[index-1]+prefixSum[mid-1];
				}
				else{
					requiredSum = x*(index-mid) - prefixSum[index-1];
				}
				if(requiredSum <= mid){
					cout<<left<<" "<<right<<" "<<mid<<endl;
					right = mid - 1;
					ans = n-mid;
				}
				else{
					left = mid + 1;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
