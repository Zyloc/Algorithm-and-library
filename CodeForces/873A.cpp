/*
 * Everyting happens for a reason . Hold tight everything is gonna ok :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k,x,z;
	vector<lli> input;
	cin>>n>>k>>x;
	for(int i(0);i<n;i++){
		cin>>z;
		input.push_back(z);
	}
	sort(input.begin(),input.end(),greater<lli> ());
	lli ans(k*x);
	for(int i(k);i<n;i++){
		ans+=input[i];
	}
	cout<<ans<<endl;
	return 0;
}
