/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	lli ans(0);
	for(int i(1);i<=n;i++){
		lli temp(i);
		vector<lli> dummy;
		while(temp){
			dummy.push_back(temp%10);
			temp = temp/10;
		}
		reverse(dummy.begin(),dummy.end());
		lli length(dummy.size());
		for(int i(0);i<length;i++){
			dummy.push_back(dummy[length-i-1]);
		}
		lli temp2(0);
		for(int j(0);j<dummy.size();j++){
			temp2 = ((temp2*10)%k+dummy[j]%k)%k;
		}
		ans = (ans%k+temp2%k)%k;
	}
	cout<<ans<<endl;
	return 0;
}
