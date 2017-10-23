/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5);
vector<int> input;
lli solve(lli l,lli r,lli height){
	if(l > r){
		return 0;
	}
	lli mini(input[l]),index(l);
	for(int i(l);i<=r;i++){
		if(input[i]<mini){
			mini = input[i];
			index = i;
		}
	}
	return min(r-l+1,solve(l,index-1,mini)+solve(index+1,r,mini)+mini-height);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x,n;
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	cout<<solve(0,n-1,0)<<endl;
	return 0;
}
