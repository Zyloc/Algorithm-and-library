/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
string shiftedString(string s,lli shift){
	string newString(s);
	for(lli i=0;i<s.length();i++){
		newString[(i+shift)%s.length()] = s[i];
	}
	return newString;
}
int main(){	
	string s;
	cin>>s;
	set<string> st;
	for(lli i=0;i<s.length();i++){
		st.insert(shiftedString(s,i));
	}
	cout<<st.size();
	return 0;
}	