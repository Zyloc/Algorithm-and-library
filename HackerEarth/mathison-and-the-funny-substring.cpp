/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+5);
lli first[MAX],last[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<lli> input;
	for(int i(0);i<n;i++){
		cin>>x;
		last[x] = i;
		input.push_back(x);
	}
	for(int i(n-1);i>=0;i--){
		first[input[i]] = i;
	}
	lli ans(0);
	for(int i(0);i<n;i++){
		ans = max(ans,last[input[i]]-first[input[i]]+1);
	}
	cout<<ans<<endl;
	return 0;
}
