/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x == 1){
			v.push_back(i+1);
		}
	}
	if(v.size() == 0){
		cout<<0;
		return 0;
	}
	else if(v.size() == 1){
		cout<<1;
		return 0;
	}
	else{
		lli ans(1);
		for(int i=1;i<v.size();i++){
			ans = ans*(v[i]-v[i-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}