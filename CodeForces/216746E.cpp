/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k,x;
	cin>>n>>k;
	vector<lli> input;
	for(int i(0);i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	lli ans(0);
	while(input.size()!=0){
		while(!input.empty() and input.back() == k){
			input.pop_back();
		}
		if(input.empty()){
			break;
		}
		vector<lli> temp;
		for(int i(1);i<k;i++){
			lli index(upper_bound(input.begin(),input.end(),i)-input.begin());
			index--;
			if(index >= 0 and input[index] == i){
				temp.push_back(index);
			}
		}
		for(auto x:temp){
			input[x]++;
		}
		ans++;
		sort(input.begin(),input.end());
	}
	cout<<ans<<endl;
	return 0;
}
