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
		string s;
		set<string> st;
		for(int i=0;i<8;i++){
			cin>>s;
			st.insert(s);
		}
		if(st.size() <= 6){
			cout<<"similar"<<endl;
		}
		else{
			cout<<"dissimilar"<<endl;
		}
	}
	return 0;
}	