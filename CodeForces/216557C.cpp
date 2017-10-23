/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli getChoose3(lli n){
	return (n*(n-1)*(n-2))/6;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,y,c,a,b,startX,startY;
	cin>>n;
	vector<pair<lli,lli> > input;
	for(int i(0);i<n;i++){
		cin>>x>>y;
		x+=101;
		y+=101;
		input.push_back({x,y});
	}
	lli ans(0);
	set<pair<lli,pair<lli,lli> > >  st;
	for(int i(0);i<n;i++){
		map<pair<lli,lli> ,lli> mp;
		for(int j(i+1);j<n;j++){
			lli a(input[j].first-input[i].first);
			lli b(input[j].second-input[i].second);
			lli gcd(__gcd(a,b));
			a /= gcd;
			b /= gcd;
			if(a == 0){
				b = INT_MAX;
			}
			if(b == 0){
				a = INT_MAX;
			}
			mp[{a,b}]++;
		}
		for(auto x:mp){
			startX = input[i].first;
			startY = input[i].second;
			a = x.first.first;
			b = x.first.second;
			c = startY*a-b*startX;
			if(st.find({c,{a,b}}) == st.end()){
				ans+=getChoose3(x.second+1);
				st.insert({c,{a,b}});	
			}
		}
	}
	cout<<getChoose3(n)-ans<<endl;
	return 0;
}