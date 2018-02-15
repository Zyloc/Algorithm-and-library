/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli l,r,c;
	cin>>l>>r>>c;
	lli n(max(l,r));
	vector<lli> sumOfDigit; 
	for(int i(1);i<=n;i++){
		lli iterator(i),sum(0);
		while(iterator){
			sum+= iterator%10;
			iterator/=10;
		}
		if(sumOfDigit.empty())
			sumOfDigit.push_back(sum*2);
		else{
			sumOfDigit.push_back(sumOfDigit.back()+sum*2);
		}
	}
	lli dif(sumOfDigit[r-1]-sumOfDigit[l-1]);
	if(dif >= 0){
		cout<<dif%c<<endl;
	}
	else{
		while(dif >= 0){
			dif+=c;
		}
		cout<<dif<<endl;
	}
	return 0;
}
