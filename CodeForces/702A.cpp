#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000ll
#define sit set<ll>::iterator
#define SIZE 100009
int main(){
	set<ll> towers;
	int n,m,citpos[SIZE], ri[SIZE],r= 0;

	cin>>n>>m;
	for(int i =0; i< n; i++){
		cin>>citpos[i];
	}
	for(int i =0; i< m; i++){
		int a; 
		cin>>a;
		towers.insert(a);
	}
	for(int i =0; i< n;i++){
		int r1=INF, r2=INF;
		if( towers.lower_bound(citpos[i])!=towers.end()){
			r2 = *towers.lower_bound(citpos[i]) - citpos[i];
		}
		if(towers.lower_bound(citpos[i])!=towers.begin()){
			sit it = towers.lower_bound(citpos[i]);
			it--;
			r1 =citpos[i] - *it;
		}
		r= max(r, min(r1,r2));
	}
	cout<<r<<endl;
	return 0;
}