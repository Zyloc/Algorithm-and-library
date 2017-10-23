/*
 * Keep breathing :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
bool cmp(pair<lli,lli> p1,pair<lli,lli> p2){
	if(p1.second > p2.second){
		return true;
	}
	if(p1.second == p2.second){
		return p1.first > p2.first;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,y;
	vector<pair<lli,lli> > input;
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x>>y;
		input.push_back({x,y});
	}
	sort(input.begin(),input.end(),cmp);
	lli ans(0),iterator(1),index(0);
	while(iterator and index < n){
		iterator--;
		ans+=input[index].first;
		iterator+=input[index].second;
		index++;
	}
	cout<<ans<<endl;
	return 0;
}
