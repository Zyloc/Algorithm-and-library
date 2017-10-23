/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli  n;
	cin>>n;
	lli maxFromLeft[n+1],maxFromRight[n+1],input[n+1];
	for(int i(0);i<n;i++){
	    cin>>input[i];
	}
	map<lli,lli> fromLeft,fromRight;
	for(int i(2);i<n;i++){
		fromRight[input[i]]++;
	}
	lli ans(0);
	fromLeft[input[0]]++;
	for(int i(1);i<n-1;i++){
		lli x(input[i]);
		auto itFromLeft(fromLeft.lower_bound(x));
		lli ansFromLeft(0);
		if(itFromLeft!=fromLeft.begin()){
			itFromLeft--;
			ansFromLeft = itFromLeft->first;
		}
		lli ansFromRight(0);
		auto itFromRight = --fromRight.end();
		if(itFromRight->first > input[i]){
			ansFromRight = itFromRight->first;
		}
		ans = max(ans,input[i]*ansFromLeft*ansFromRight);
		//cout<<ansFromLeft<<" "<<ansFromRight<<" "<<input[i]<<endl;
		fromLeft[input[i]]++;
		fromRight[input[i]]--;
		if(fromRight[input[i]] == 0){
			fromRight.erase(input[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}	