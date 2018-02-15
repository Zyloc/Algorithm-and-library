/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(2e3+5);
lli ones[MAX],twos[MAX],lis[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x;
	cin>>n;
	vector<lli> input;
	input.push_back(0);
	for(int i(1);i<=n;i++){
		cin>>x;
		input.push_back(x);
		ones[i]+=ones[i-1];
		if(x == 1){
			ones[i]+=1;
		}
		lis[i] = 1;
	}
	for(int i(n);i>0;i--){
		twos[i]+=twos[i+1];
		if(input[i] == 2){
			twos[i]+=1;
		}
	}
	for (int i = 1; i <= n; i++ )
        for (int j = 1; j < i; j++ ) 
            if ( input[i] >= input[j] && lis[i] <= lis[j] + 1)
                lis[i] = lis[j] + 1;
	lli ans(INT_MIN);
	for(int i(1);i<=n;i++){
		ans =max(ans,lis[i]);
	}
	for(int i(n);i>0;i--){
		for(int j(i-1);j>0;j--){
			lli count(twos[i]+ones[j]+ones[])
		}
	}
	cout<<ans<<endl;
	return 0;
}
