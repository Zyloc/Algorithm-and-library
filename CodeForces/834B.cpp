/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,k;
vector<pair<lli,lli> > data;
lli check(lli checkTime){
	lli counter(0);
	for(int i(0);i<data.size();i++){
		if(data[i].first <= checkTime and data[i].second >= checkTime){
			counter++;
		}
	}
	return counter;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string input;
	cin>>n>>k;
	cin>>input;
	map<char,lli> start,end;
	set<char> inputChars;
	for(int i(0);i<n;i++){
		inputChars.insert(input[i]);
		if(start.find(input[i]) == start.end()){
			start[input[i]] = i;
		}
		end[input[i]] = i;
	}
	
	for(auto it:inputChars){
		data.push_back({start[it],end[it]});
	}
	for(int i(0);i<n;i++){
		if(check(i) > k){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO"; 
	return 0;
}
