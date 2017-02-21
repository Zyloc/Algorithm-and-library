/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	map<char,set<int> > mp;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		mp[s[i]].insert(i);
	}
	while(q--){
		int type,x;
		char c,dummy;
		cin>>type;
		if(type==1){
			cin>>x>>c;
			x--;
			dummy = s[x];
			s[x] = c;
			mp[c].insert(x);
			mp[dummy].erase(x);
		}
		else{
			cin>>x;
			x--;
			c = mp.begin()->first;
			for(auto it2:mp){
				if(x >= 0){
					x-=it2.second.size();
					c = it2.first;
				}
				else{
					cout<<c<<endl;
					break;
				}
			}	
		}
	}
	return 0;
}