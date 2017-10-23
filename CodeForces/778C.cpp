/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 2e5+1;
bool visited[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k,x;
	cin>>n>>k;
	vector<int>first,second;
	vector<pair<lli,lli> > diff;
	for(int i=0;i<n;i++){
		cin>>x;
		first.push_back(x);
	}
	for(int i=0;i<n;i++){
		cin>>x;
		second.push_back(x);
		diff.push_back(make_pair(first[i]-x,i));
	}
	sort(diff.begin(),diff.end());
	lli ans(0);
	for(int i=0;i<k;i++){
		visited[diff[i].second] = true;
		ans+=first[diff[i].second];
	}
	for(int i=k;i<n;i++){
		if(diff[i].first < 0){
			visited[diff[i].second]= true;
			ans+=first[diff[i].second];
		}
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			ans+=second[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}