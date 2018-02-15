/*
 * Richie Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	vector<lli> input(n),dummy(n);
	for(int i(0);i<n;i++){
		cin>>input[i];
		dummy[i] = input[i];
	}
	sort(dummy.begin(),dummy.end());
	bool ans(true);
	string s;
	cin>>s;
	set<lli> st1,st2;
	for(int i(0);i<n-1;i++){
		st1.insert(input[i]);
		st2.insert(dummy[i]);
		if(s[i] == '0'){
			for(auto x:st1){
				if(st2.find(x) == st2.end()){
					ans = false;
				}
			}
			st1.clear();
			st2.clear();
		}
	}
	if(ans){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}
