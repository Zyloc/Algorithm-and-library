/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli magicBox(lli index,string a,string b){
	if(index == a.length()){
		set<char> s1,s2;
		for(auto x:a){
			s1.insert(x);
		}
		for(auto x:b){
			s2.insert(x);
		}
		return max(s1.size(),s2.size());
	}
	lli ans(magicBox(index+1,a,b));
	swap(a[index],b[index]);
	ans = min(ans,magicBox(index+1,a,b));
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		cout<<magicBox(0,a,b)<<endl;
	}
	return 0;
}
