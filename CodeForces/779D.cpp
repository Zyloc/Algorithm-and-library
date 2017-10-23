/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string s1,s2;
vector<int> order;
bool check(lli x){
	bool deleted[s1.length()];
	memset(deleted,false,sizeof deleted);
	for(int i=0;i<=x;i++){
		deleted[order[i]] = true;
	}
	lli index(0),maxIndex(s2.length());
	for(int i=0;i<s1.length();i++){
		if(index == maxIndex){
			return  true;
		}
		if(!deleted[i]){
			if(s1[i] == s2[index]){
				index++;
			}
		}
	}
	return index == maxIndex;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s1>>s2;
	lli x;
	for(int i=0;i<s1.length();i++){
		cin>>x;
		order.push_back(--x);
	}
	lli start(0),end(s1.length()-1),ans(-1);
	while(start <= end){	
		lli mid((start+end)/2);
		if(check(mid)){
			ans = max(mid,ans);
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}