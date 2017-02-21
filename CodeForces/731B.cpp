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
	bool flag(false);
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		if(i!=0 and x == 0){
			if(v[i-1]&1){
				flag = true;
			}
		}
		if(i>0){
			v[i] = v[i]+v[i-1]%2;
		}
	}
	if(flag or v[n-1]&1){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}
	return 0;
}