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
		lli n,q,x,y;
		cin>>n>>q;
		set<pair<lli,lli> > st;
		for(int i=0;i<q;i++){
			cin>>x>>y;
			st.insert(make_pair(x,y));
		}
		st.insert(make_pair(n+1,1));
		st.insert(make_pair(n+1,2));
		st.insert(make_pair(n+1,3));
		bool flag(false);
		for(auto it=st.begin();it!=st.end();it++){
			auto it2(next(it,1));
			auto it3(next(it,2));
			if(it->first == it2->first and it3->first == it->first){
				cout<<it->first-1<<endl;
				break;
			}
			else if(it->first == it2->first){
				if(it->second == 1 and it2->second == 2){
					st.insert(make_pair(it->first+1,1));
				}
				if(it->second == 2 and it2->second == 3){
					st.insert(make_pair(it->first+1,3));
				}
			}
		}	
	}
	return 0;
}