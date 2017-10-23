/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,k;
		cin>>n>>k;
		set<lli> input;
		bool flag(false);
		for(int i(0);i<n;i++){
			lli x,y;
			cin>>x;
			lli prevSize(input.size());
			for(int j(0);j<x;j++){
				cin>>y;
				input.insert(y);
			}
			if(input.size() == prevSize){
				flag = true;
			}
		}
		if(input.size() < k){
			cout<<"sad"<<endl;
		}
		else if(flag){
			cout<<"some"<<endl;
		}
		else{
			cout<<"all"<<endl;
		}
	}
	return 0;
}	