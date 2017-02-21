/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	string s;
	cin>>s;
	set<char> st;
	for(int i=0;i<s.length();i++){
		st.insert(s[i]);
	}
	if(s.size() > 26){
		cout<<-1;
	}
	else{
		cout<<s.length()-st.size();
	}
	return 0;
}