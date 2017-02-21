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
	bool flag(false);
	set<lli> st;
	for(int i=1;i<=n;i++){
		cin>>x;
		st.insert(x);
		if(x!=i){
			flag = true;
		}
	}
	if(st.size() == 1){
		cout<<1<<endl;
		for(int i=0;i<n;i++){
			cout<<1<<" ";
		}
		cout<<endl;
		for(int i=0;i<1;i++){
			cout<<x<<" ";
		}
	}
	else if(!flag){
		cout<<n<<endl;
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}