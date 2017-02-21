/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli lastLevel;
bool lastLevelFound;
vector<int> v;
void solve(lli l,lli r,lli level){
	if(l == r){
		if(!lastLevelFound){
			lastLevelFound = true;
			lastLevel = level;
		}
		if(level == lastLevel){
			v.push_back(l);
		}
		return;
	}
	lli mid((l+r)/2);
	solve(l,mid,level+1);
	solve(mid+1,r,level+1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t,counter(1);
	cin>>t;
	while(t--){
		cout<<"Case "<<counter<<":"<<endl;
		counter++;
		string s;
		cin>>s;
		lastLevelFound = false;
		lastLevel = -1;
		solve(0,s.length()-1,1);
		lli q;
		cin>>q;
		for(int i=0;i<q;i++){
			lli x;
			cin>>x;
			x--;
			cout<<s[v[x]]<<endl;
		}
		v.clear();
	}
	return 0;
}