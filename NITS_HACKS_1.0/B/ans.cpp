/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,k;
	cin>>n>>k;
	vector<lli> inputA,inputB,setA,setB;
	for(int i(0);i<n/2;i++){
		cin>>x;
		inputA.push_back(x);
	}
	for(int i(n/2);i<n;i++){
		cin>>x;
		inputB.push_back(x);
	}
	for(int i(0);i<(1LL<<inputA.size());i++){
		lli temp(0);
		for(int j(0);j<inputA.size();j++){
			if(i&(1<<j)){
				temp^=inputA[j];
			}
		}
		setA.push_back(temp);
	}
	
	for(int i(0);i<(1LL<<inputB.size());i++){
		lli temp(0);
		for(int j(0);j<inputB.size();j++){
			if(i&(1<<j)){
				temp^=inputB[j];
			}
		}
		setB.push_back(temp);
	}
	sort(setA.begin(),setA.end());
	sort(setB.begin(),setB.end());
	lli ans(0);
	for(int i(0);i<setA.size();i++){
		lli left(k^setA[i]);
		if(binary_search(setB.begin(),setB.end(),left)){
			lli minIndex(lower_bound(setB.begin(),setB.end(),left)-setB.begin());
			lli maxIndex(upper_bound(setB.begin(),setB.end(),left)-setB.begin());
			maxIndex--;
			ans+= maxIndex- minIndex+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
