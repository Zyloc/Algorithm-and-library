/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,x,k,counter;
lli getNext(){
	return counter++;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<lli> v;
	cin>>n>>k;
	for(int i(0);i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	lli ans(0),pointer1(getNext()),pointer2(getNext());
	while(pointer1 < n and pointer2 < n){
		lli z(min(v[pointer1]/k,v[pointer2]/k));
		ans += z;
		v[pointer1]-= k*z;
		v[pointer2]-= k*z;
		if(v[pointer1] <= 0){
			pointer1 = getNext();
		}
		if(v[pointer2] <= 0){
			getNext();
		}
	}
	if(pointer1 < n){
		ans+=v[pointer1]/k+(v[pointer1]%k == 0?0:1);
	}
	if(pointer2 < n){
		ans+=v[pointer2]/k+(v[pointer2]%k == 0?0:1);
	}
	cout<<ans<<endl;
	return 0;
}	