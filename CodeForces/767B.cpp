/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli start,end,interval,n,upto,x,wait(INT_MAX),ans(0);
	cin>>start>>end>>interval;
	upto = start;
	cin>>n;
	bool flag(false);
	vector<int> v,uptoVector;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		if(i == 0){
			if(x <= start){
				if(x >= 1){
					ans = x - 1;
					wait = start - x + 1;
				}
			}
			else{
				ans = start;
				cout<<ans;
				return 0;
			}
		}
		else{
			if(x > upto){
				ans = upto;
				cout<<ans;
				return 0;
			}
		}
		upto = max(upto+interval,x+interval);
		uptoVector.push_back(upto);
	}
	if(upto < end){
		cout<<upto;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(wait > uptoVector[i-1]-v[i]+1){
			wait = uptoVector[i-1]-v[i]+1;
			ans = v[i]-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}