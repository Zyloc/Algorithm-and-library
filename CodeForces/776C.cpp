/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> powers;
const lli MAX = 1e14+1;
void getAllPower(lli k){
	if(k == 1){
		return;
	}
	else if(k == -1){
		powers.push_back(-1);
	}
	else{
		lli pow(k);
		powers.push_back(pow);
		while(abs(pow) < MAX){
			pow  = pow*k;
			powers.push_back(pow);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k,x;
	cin>>n>>k;
	powers.push_back(1);
	getAllPower(k);
	vector<lli> input;
	for(int i=0;i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	lli ans(0),sum(0);
	map<lli,lli> mp;
	mp[0] = 1;
	for(int i=0;i<n;i++){
		sum += input[i]; 
		for(int j=0;j<powers.size();j++){
			ans+=mp[sum-powers[j]];
		}
		mp[sum]++;
	}
	cout<<ans<<endl;
	return 0;
}