/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		lli freq[26] = {0};
		for(auto x:s){
			freq[x-'a']++;
		}
		lli countOdd(0);
		for(int i(0);i<26;i++){
			if(freq[i]&1){
				countOdd++;
			}
		}
		if(countOdd < 2){
			vector<lli> adj[26];
			lli iterator(1);
			lli length(s.length());
			for(int i(0);i<26;i++){
				lli current(freq[i]/2),remainder(freq[i]%2);
				while(current--){
					adj[i].push_back(iterator);
					adj[i].push_back(length-iterator+1);
					iterator++;
				}
				if(remainder){
					adj[i].push_back(length/2+length%2);
				}
			}
			string ans(length,'x');
			for(auto x:s){
				cout<<adj[x-'a'].back()<<" ";
				ans[adj[x-'a'].back()-1] = x;
				adj[x-'a'].pop_back();
			}
			cout<<endl;
			//cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
