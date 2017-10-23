/*
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
	set<lli> st;
	lli hash[n+1];
	memset(hash,0,sizeof hash);
	lli x;
	std::vector<lli> input;
	for(int i(0);i<n;i++){
		cin>>x;
		hash[x]++;
		st.insert(x);
		input.push_back(x);
	}
	cout<<n-st.size()<<endl;
	set<lli> dummy;
	for(int i(1);i<=n;i++){
		dummy.insert(i);
	}
	for(int i(1);i<=n;i++){
		if(hash[input[i-1]] > 1){
			while
			auto it = dummy.begin();
			cout<<*it<<" ";
			dummy.erase(dummy.begin());
			hash[input[i-1]]--;
		}
		else{
			dummy.erase(input[i-1]);
			cout<<input[i-1]<<" ";
		}
	}
	return 0;
}
