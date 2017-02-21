/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i+=2){
		v[i] = i/2+1;
	}
	for(int i=1;i<n;i+=2){
		v[i] = n-i/2;
	}
	if(k&1){
		for(int i=k;i<n;i++){
			v[i] = v[i-1]+1;
		}
	}
	else{
		for(int i=k;i<n;i++){
			v[i] = v[i-1]-1;
		}
	}
	for(auto x:v){
		cout<<x<<" ";
	}
	return 0;
}