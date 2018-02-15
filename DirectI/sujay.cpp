/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	lli leftToRight[n+2],rightToLeft[n+2];
	// initialise all the arrays with INT_MIN
	for(int i(1);i<=n;i++){
		leftToRight[binary[i]] = binary[i]*input[i] + leftToRight[i-1][binary[i-1]];
		leftToRight[1^binary[i]] =  ((1^binary[i])*input[i])+leftToRight[i-1][1^binary[i-1]];
	}
	for(int i(n);i>=1;i--){
		rightToLeft[i][binary[i]] = (binary[i]*input[i])+rightToLeft[i+1][binary[i+1]];
		rightToLeft[i][1^binary[i]] = ((1^binary[i])*input[i])+rightToLeft[i+1][1^binary[i+1]];
	}
	lli ans(0);
	for(int i(2);i<n;i++){
		ans = max(ans,max(leftToRight[i][binary[i]]+rightToLeft[i][binary[i]],max(leftToRight[i][1^binary[i]]+rightToLeft[i][binary[i]],leftToRight[i][binary[i]]+rightToLeft[i][1^binary[i]])));
	}
	cout<<ans<<endl;
	return 0;
}
