/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli bitDifference(lli x){
	lli count(0);
	while(x){
		count+= x&1;
		x = x>>1;
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,k,x,count(0);
	cin>>n>>m>>k;
	vector<lli> v;
	for(int i=0;i<m+1;i++){
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<m;i++){
		if(bitDifference(v[m]^v[i]) <= k){
			count++;
		}
	}	
	cout<<count<<endl;
	return 0;
}