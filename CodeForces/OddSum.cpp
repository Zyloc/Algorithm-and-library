/*
 * Keep breathing :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,maxOdd(INT_MIN),sumOfPositiveEven(0),sumOfPositiveOdd(0);
	cin>>n;
	vector<lli> positiveOdd,positiveEven,negativeOdd;
	for(int i(0);i<n;i++){
		cin>>x;
		if(x&1){
			maxOdd = max(maxOdd,x);
		}
		if(x > 0){
			if(x&1){
				sumOfPositiveOdd+=x;
				positiveOdd.push_back(x);
			}
			else{
				sumOfPositiveEven+=x;
				positiveEven.push_back(x);
			}
		}
		if(x&1 and x < 0){
			negativeOdd.push_back(x);
		}
	}
	sort(positiveOdd.begin(),positiveOdd.end());
	sort(positiveEven.begin(),positiveEven.end());
	if(positiveOdd.size() == 0){
		cout<<sumOfPositiveEven+maxOdd<<endl;
	}
	else{
		if(positiveOdd.size()&1){
			cout<<sumOfPositiveOdd+sumOfPositiveEven<<endl;
		}
		else{
			lli ans(INT_MIN);
			for(int i(0);i<negativeOdd.size();i++){
				ans = max(ans,sumOfPositiveOdd+sumOfPositiveEven+negativeOdd[i]);
			}
			ans = max(ans,sumOfPositiveOdd+sumOfPositiveEven- positiveOdd[0]);
			cout<<ans<<endl;
		}
	}
	return 0;
}
