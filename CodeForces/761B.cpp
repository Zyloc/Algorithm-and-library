/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<int> v1,v2,v3,v4;
bool processed[1000];
lli n,l,x;
bool check(lli vertex){
	for(int i=0;i<n;i++){
		if(v4[i] != v3[(i+vertex)%n]){
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>l;
	for(int i=0;i<n;i++){
		cin>>x;
		v1.push_back(x);
	}
	map<lli,lli> mp1,mp2;
	lli sum(0);
	for(int i=1;i<n;i++){
		sum+=v1[i]-v1[i-1];
		v3.push_back(v1[i]-v1[i-1]);
	}
	//mp1[l-sum]++;
	v3.push_back(l-sum);
	sum = 0;
	for(int i=0;i<n;i++){
		cin>>x;
		v2.push_back(x);
	}
	for(int i=1;i<n;i++){
		sum+=v2[i]-v2[i-1];
		v4.push_back(v2[i]-v2[i-1]);
	}
	v4.push_back(l-sum);
	for(int i=0;i<n;i++){
		if(check(i)){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;	
	return 0;
}