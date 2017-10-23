/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+1);
int freq[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,x;
		cin>>n;
		memset(freq,0,sizeof freq);
		for(int i(0);i<n;i++){
			cin>>x;
			freq[x]++;
		}
		lli ans(0);
		for(int i(0);i<MAX;i++){
			ans+=(freq[i]*(freq[i]-1));
		}
		cout<<ans<<endl;
	}
	return 0;
}	