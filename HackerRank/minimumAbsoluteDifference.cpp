/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<lli> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	lli answer(INT_MAX);
	for(int i=1;i<n;i++){
		answer = min(answer,abs(v[i-1]-v[i]));
	}
	cout<<answer<<endl;
	return 0;
}