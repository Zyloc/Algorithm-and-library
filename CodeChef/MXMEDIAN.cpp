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
		lli n,x;
		cin>>n;
		vector<lli> input;
		input.push_back(0);
		for(int i(1);i<=2*n;i++){
			cin>>x;
			input.push_back(x);;
		}
		sort(input.begin(),input.end());
		cout<<input[2*n-n/2]<<endl;
		for(int i(1);i<=n;i++){
			cout<<input[i]<<" "<<input[2*n-i+1]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

0 - k-1
k - 2*k-1
2*k - 3*k - 1