/*
 * Everyting happens for a reason . Hold tight everything is gonna ok :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n;
const int MAX(1e5+10);
lli input[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	string s;
	cin>>s;
	for(int i(0);i<n;i++){
		if(s[i]=='0'){
			input[i] = -1;
		}
		else{
			input[i] = 1;
		}
	}
	map<lli,lli> mp;
	lli ans(0),sum(0);
	for(int i(0);i<n;i++){
		sum+=input[i];
		if(sum == 0){
			ans = i+1;
		}
		if(mp.find(sum)!=mp.end()){
			ans = max(ans,i-mp[sum]);
		}
		else{
			mp[sum] = i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
