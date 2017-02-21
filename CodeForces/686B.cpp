/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n;
vector<int> v,dummy;
vector<pair<lli,lli> > ans;
lli sorted(){
	for(int i=0;i<n;i++){
		if(v[i]!=dummy[i]){
			return i;
		}
	}
	return n;
}
void magicBox(lli index){
	for(int i=index;i<n;){
		lli start(i),upto(i);
		while(start < n-1 and v[start] >= v[start+1]){
			swap(v[start],v[start+1]);
			upto = start+1;
			start+=2;
		}
		if(start != i){
			ans.push_back(make_pair(i,min(start,upto)));
		}
		i = start+1;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		dummy.push_back(x);
	}
	sort(dummy.begin(),dummy.end());
	int count(0);
	while(1){
		lli index(sorted());
		if( index == n){
			break;
		}
		magicBox(index);
	}
	for(auto x:ans){
		cout<<x.first+1<<" "<<x.second+1<<endl;
	}
	return 0;
}