/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string shift(string s,int k){
	string ans(s);
	for(int i=0;i<s.length();i++){
		ans[(i+k)%s.length()] = s[i];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		string s,ans;
		cin>>s;
		for(int i=0;i<s.length();i++){
			ans+='z';
		}
		char smallest(s[0]);
		vector<int> index;
		for(int i=0;i<s.length();i++){
			if(s[i] < smallest){
				smallest = s[i];
				index.clear();
				index.push_back(i);
			}
			else if(s[i] == smallest){
				index.push_back(i);
			}
		}
		for(int i=0;i<index.size();i++){
			string afterShift(shift(s,s.length()-index[i]));
			if(afterShift < ans){
				ans = afterShift;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}