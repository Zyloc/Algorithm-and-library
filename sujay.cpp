/*
 * Richie who's not Rich 
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
		lli n,c,x;
		cin>>n>>c;
		vector<lli> input;
		for(int i(0);i<n;i++){
			cin>>x;
			input.push_back(c-x);
		}
		lli max_so_far(0), curr_max(0);
		for (int i(0); i < n; i++){
			curr_max = max(input[i], curr_max+input[i]);
			max_so_far = max(max_so_far, curr_max);
		}
		cout<<max_so_far<<endl;
	}
	return 0;
}
