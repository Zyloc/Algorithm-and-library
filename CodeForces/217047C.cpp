/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e2+2);
lli n,m;
vector<lli> price;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	price.push_back(0);
	lli x,y;
	for(int i(0);i<n;i++){
		cin>>x;
		price.push_back(x);
	}
	set<pair<lli,lli> > st;
	for(int i(0);i<m;i++){
		cin>>x>>y;
		st.insert({x,y});
		st.insert({y,x});
	}
	lli ans(INT_MAX);
	for(int i(1);i<=n;i++){
		for(int j(1);j<=n;j++){
			for(int k(1);k<=n;k++){
				if(i == j or j == k or k==i){
					continue;
				}
				lli temp(0);
				if(st.find({i,j})!=st.end() and st.find({i,k})!=st.end() and st.find({j,k})!=st.end()){
					ans = min(ans,price[i]+price[j]+price[k]);
				}
			}
		}
	}
	if(ans == INT_MAX){
		cout<<-1;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
