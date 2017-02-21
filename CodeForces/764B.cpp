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
	lli  i(0),j(n-1);
	while(i < j){
		lli temp(v[i]);
		v[i] = v[j];
		v[j] = temp;
		i+=2;
		j-=2;
	}
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}