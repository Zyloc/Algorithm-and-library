/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	map<char,int> mp;
	for(int i=0;i<s.length();i++){
		mp[s[i]]++;
	}
	cout<<min(mp['B'],min(mp['u']/2,min(mp['l'],min(mp['b'],min(mp['a']/2,min(mp['s'],mp['r']))))));
	return 0;
}