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
	vector<pair<lli,lli> > input;
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		input.push_back({x,i});
	}
	sort(input.begin(),input.end());
	lli ans(0),index(0);
	while(index < input.size()){
		lli index2(index),last(input[index].first),dummy;
		while(index2 < input.size() and input[index2].first == last){
			index2++;
		}
		dummy = index2;
		index2--;
		while(index < index2){
			ans+= n-input[index2].second-1;
			index++;
			index2--;
		}
		index = dummy;
	}
	cout<<ans<<endl;
	return 0;
}
