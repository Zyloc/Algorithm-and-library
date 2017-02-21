/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli left,n,x,right,a,ans(0);
	cin>>n>>a;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	a--;
	left = a-1;
	right = a+1;
	if(v[a] == 1){
		ans++;
	}
	while(left >= 0 and right < n){
		if(v[left] and v[right]){
			ans+=2;
		}
		left--;
		right++;
	}
	while(left >= 0){
		if(v[left]){
			ans++;
		}
		left--;
	}
	while(right < n){
		if(v[right]){
			ans++;
		}
		right++;
	}
	cout<<ans<<endl;
	return 0;
}