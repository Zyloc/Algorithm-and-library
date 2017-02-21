/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 2001;
lli nC3[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	lli x[n],y[n];
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		x[i]+= 101;
		y[i]+= 101;
	}
	map<pair<int,int>,lli > mp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(x[i] != x[j]){
					lli temp(__gcd(y[i]*(x[j]-x[i])-x[i]*(y[j]-y[i]),x[j]-x[i]));
					if(y[i]*(x[j]-x[i])-x[i]*(y[j]-y[i]) != 0){
						mp[make_pair(abs(y[i]*(x[j]-x[i])-x[i]*(y[j]-y[i])/temp),abs(x[j]-x[i])/temp)]++;	
					}
					else{
						mp[make_pair(0,0)]++;
					}
				}
				else{
					mp[make_pair(x[i],INT_MAX)]++;
				}
			}
		}
	}
	lli ans((n*(n-1)*(n-2))/6);
	for(auto x:mp){
		x.second = x.second/2;
		ans-= (x.second*(x.second-1)*(x.second-2))/6;
	}
	cout<<ans<<endl;
	return 0;
}