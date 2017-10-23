/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,x;
	cin>>n>>k;
	lli ans(0);
	priority_queue<pair<lli,lli> > pq;
	vector<lli> input;
	for(lli i(0);i<n;i++){
		cin>>x;
		input.push_back(x);
		//ans-=(i+1LL)*x;
	}
	for(int i(0);i<k;i++){
		pq.push({input[i],i});
	}
	vector<lli> departureTime(n);
	for(int i(k);i<k+n;i++){
		if(i<n){
			pq.push({input[i],i});
		}
		pair<lli,lli> dummy(pq.top());
		departureTime[dummy.second] = i;
		pq.pop();
		ans+= (i-dummy.second)*dummy.first;
	}
	cout<<ans<<endl;
	for(auto x:departureTime){
		cout<<x+1<<" ";
	}
	return 0;
}
