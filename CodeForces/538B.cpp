/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	vector<lli> ans;
	while(n){
		lli smallDecimal(0);
		for(int i=64;i>=0;i--){
			lli copy(i),decimal(0);
			while(copy){
				decimal = (decimal+copy%2)*10;
				copy = copy/2;
			}
			decimal/=10;
			if(decimal <= n){
				smallDecimal = decimal;
				break;
			}
		}
		for(int i=0;i<n/smallDecimal;i++){
			ans.push_back(smallDecimal);
		}
		n%=smallDecimal;
	}
	cout<<ans.size()<<endl;
	for(auto x:ans){
		cout<<x<<" ";
	}
	return 0;
}