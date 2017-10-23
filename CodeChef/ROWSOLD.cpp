/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		lli oneSoFar(0),ans(0),index(0);
		while(index!=s.length() and s[index]!='1'){
			index++;
		}
		while(index != s.length()){
			while(index!=s.length() and s[index]!='0'){
				index++;
				oneSoFar++;
			}
			lli zeroSoFar(0);
			while(index!=s.length() and s[index]!='1'){
				index++;
				zeroSoFar++;
			}
			if(zeroSoFar!=0){
				ans+=(oneSoFar*zeroSoFar)+oneSoFar;	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}	