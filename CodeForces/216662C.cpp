/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	stack<lli> st;
	map<lli,lli> mp;
	st.push(0);
	for(int i(1);i<=s.length();i++){
		if(s[i-1] == '('){
			st.push(i);
		}
		else{
			if(st.size() == 1 or st.top() <= 0){
				st.push(-i);
			}
			else{
				st.pop();
				mp[i-abs(st.top())]++;
			}
		}	
	}
	if(mp.empty()){
		cout<<0<<" "<<1<<endl;
		return 0;
	}
	auto it = mp.end();
	it--;
	cout<<it->first<<" "<<it->second<<endl;
	return 0;
}
