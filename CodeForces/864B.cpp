/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
	string s;
bool notCapital(char c){
	if(c >= 'a' and c <='z'){
		return true;
	}
	return false;
}
lli isSafe(lli i,lli j){
	set<char> st;
	for(int x(i);x<=j;x++){
		if(notCapital(s[x])){
			st.insert(s[x]);
		}
		else{
			return -1;
		}
	}
	return st.size();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	cin>>s;
	lli ans(0);
	for(lli i(0);i<n;i++){
		for(lli j(i);j<n;j++){
			lli temp(isSafe(i,j));
			if(temp!=-1){
				ans = max(ans,temp);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
