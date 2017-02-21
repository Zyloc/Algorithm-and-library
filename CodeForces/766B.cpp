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
	for(int i=0;i<n-2;i++){
		if(v[i]+v[i+1] > v[i+2]){
			cout<<"YES";
			return  0;
		}
	}
	cout<<"NO";
	return 0;
}