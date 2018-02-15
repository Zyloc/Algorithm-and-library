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
	string s;
	cin>>s;
	lli k;
	cin>>k;
	map<char,lli> mp;
	for(auto x:s){
		mp[x]++;
	}
	priority_queue<pair<lli,char> > pq;
	for(auto x:mp){
		pq.push({-x.second,x.first});
	}
	while(k and !pq.empty()){
		if(k >= abs(pq.top().first)){
			k+=pq.top().first;
			pq.pop();
		}
		else{
			break;
		}
	}
	set<char> st;
	lli length(0);
	while(!pq.empty()){
		st.insert(pq.top().second);
		length+=abs(pq.top().first);
		pq.pop();
	}
	cout<<st.size()<<endl;
	string ans(length,'x');
	lli index(0);
	for(int i(0);i<s.length();i++){
		if(st.find(s[i])!=st.end()){
			ans[index++] =  s[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
