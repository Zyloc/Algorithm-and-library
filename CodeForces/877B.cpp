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
	lli n(s.length());
	lli prefixA[n+3],suffixA[n+3],prefixB[n+3];
	memset(prefixA,0,sizeof prefixA);
	memset(suffixA,0,sizeof suffixA);
	memset(prefixB,0,sizeof prefixB);
	for(int i(1);i<=n;i++){
		if(s[i-1] == 'a'){
			prefixA[i] = 1;
		}
		if(s[i-1] == 'b'){
			prefixB[i] = 1;
		}
		prefixA[i] += prefixA[i-1];
		prefixB[i] += prefixB[i-1];
	}
	for(int i(s.length()-1);i>=0;i--){
		if(s[i] == 'a'){
			suffixA[i+1] = 1;
		}
		suffixA[i+1] += suffixA[i+2];
	}
	lli ans(0);
	for(int i(0);i<=s.length();i++){
		for(int j(i);j<=s.length();j++){
			ans  = max(ans,prefixA[i]+prefixB[j]-prefixB[i]+suffixA[j+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
