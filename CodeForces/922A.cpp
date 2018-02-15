/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int isPrime[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	set<lli> st;
	lli maxi(1e7);
	for(int i(1);i<=min(maxi,k);i++){
		int size(st.size());
		st.insert(n%i);
		if(st.size() == size){
			cout< <"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
