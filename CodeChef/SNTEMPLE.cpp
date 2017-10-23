/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,x,totalSum(0);
		cin>>n;
		vector<lli> input;
		for(int i(0);i<n;i++){
			cin>>x;
			input.push_back(x);
			totalSum += x;
		}
		int increasingFromLeft[n],increasingFromRight[n];
		increasingFromLeft[0] = 1;
		increasingFromRight[n-1] = 1;
		for(int i(1);i<n;i++){
			if(input[i] > increasingFromLeft[i-1]){
				increasingFromLeft[i] = increasingFromLeft[i-1] + 1;
			}
			else{
				increasingFromLeft[i] = input[i];
			}
		}
		for(int i(n-2);i>=0;i--){
			if(input[i] > increasingFromRight[i+1]){
				increasingFromRight[i] = increasingFromRight[i+1]+1;
			}
			else{
				increasingFromRight[i] = input[i];
			}
		}
		lli ans(1e18);
		for(int i(0);i<n;i++){
			lli minLength(min(increasingFromLeft[i],increasingFromRight[i]));
			ans= min(ans,totalSum-(minLength)*(minLength));
		}
		cout<<ans<<endl;
	}
	return 0;
}
