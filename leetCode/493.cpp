/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX_SIZE(5e4+3);
int update(int index){
	for(;i)
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n;
	vector<int> input;
	for(int i(0);i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	int ans(0);
	for(int i(0);i<n;i++){
		ans+=query(2*input[i]+1);
		update(input[i]);
	}
	return 0;
}
