/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	map<lli,lli> mp;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s == "Push"){
			lli x;
			cin>>x;
			mp[x]++;
		}
		else if(s == "CountHigh"){
			if(mp.size() == 0){
				cout<<-1<<endl;
			}
			else{
				auto it=mp.end();
				it--;
				cout<<it->second<<endl;	
			}
		}
		else if(s == "Diff"){
			if(mp.size() == 0){
				cout<<-1<<endl;
			}
			else{
				auto it1= mp.begin();
				auto it2=mp.end();
				it2--;
				cout<<(it2->first-it1->first)<<endl;
				it1->second--;
				it2->second--;
				lli first(it1->first);
				if(it1->second <= 0){
					mp.erase(it1);
				}
				if(first!= it2->first and it2->second <= 0){
					mp.erase(it2);
				}
			}	
		}
		else{
			if(mp.size() == 0){
				cout<<-1<<endl;
			}
			else{
				cout<<mp.begin()->second<<endl;
			}	
		}
	}
	return 0;
}