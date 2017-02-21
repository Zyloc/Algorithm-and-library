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
	map<char,lli>mp;
	int lastPos(-1);
	for(char c='a';c<='z';c++){
		for(int i=0;i<s.length();i++){
			if(s[i] == c){
				mp[c] = i;
				break;
			}
		}
	}
	char c('a');
	for(auto it:mp){
		if(c != it.first){
			cout<<"NO"<<endl;
			return 0;
		}
		c++;
		if(c > 'z'){
			if(mp.size() != 26){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	for(auto it:mp){
		if(it.second < lastPos){
			cout<<"NO";
			return 0;
		}
		lastPos = it.second;
	}
	cout<<"YES"<<endl;
	return 0;
}