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
	vector<lli> small,large;
	for(int i=0;i<n;i++){
		cin>>x;
		small.push_back(x);
		large.push_back(x);
	} 
	sort(small.begin(),small.end());
	sort(large.begin(),large.end(),greater<lli>());
	lli q;
	cin>>q;
	for(int i=0;i<q;i++){
		char c;
		cin>>x>>c;
		if(c == 'S'){
			cout<<small[x-1]<<endl;
		}
		else{
			cout<<large[x-1]<<endl;
		}
	}
	return 0;
}