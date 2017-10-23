/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e4+2);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m;
	cin>>n>>m;
	bool flag2(false);
	for(int i=0;i<m;i++){
		lli k;
		cin>>k;
		set<lli> st;
		bool flag(false);
		for(int j(0);j<k;j++){
			lli x;
			cin>>x;
			if(st.find(-x)!=st.end()){
				flag = true;
			}
			st.insert(x);
		}
		if(!flag){
			flag2 = true;
		}
	}
	if(flag2){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;;
	}
	return 0;
}	