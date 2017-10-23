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
		lli n,x;
		cin>>n;
		vector<int> v;
		bool flag(false);
		lli index(n/2-1);
		for(int i(1);i<=n;i++){
			cin>>x;
			v.push_back(x);
			if(i <= (n+1)/2 and x!= i){
				flag = true;
			}
			if(i > (n+1)/2 and v[index]!=x){
				flag = true;
			}
			if(i > (n+1)/2){
				index--;
			}
		}
		if(n&1 and !flag){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
