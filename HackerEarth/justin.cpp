/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> input,prefixXor,answerPrefix;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,m,k,x,last(0),l,r;
	cin>>n>>m>>k;
	input.push_back(0);
	prefixXor.push_back(0);
	for(int i(1);i<=n;i++){
	    cin>>x;
	    input.push_back(x);
	    prefixXor.push_back(x^prefixXor[i-1]);
	}
	map<lli,lli > frequency;
	answerPrefix.push_back(0);
	for(int i(1);i<=n;i++){
	    if(prefixXor[i] == prefixXor[i-1]){
	    	answerPrefix.push_back(answerPrefix[i-1]*2);
	    	continue;
	    }
	    lli find(k^prefixXor[i]);
	    answerPrefix.push_back(frequency[find]);
	    if(prefixXor[i] == k){
	        answerPrefix[i]++;
	    }
	    frequency[prefixXor[i]]++;
	}
	for(int i(1);i<=n;i++){
		answerPrefix[i] = answerPrefix[i-1]+answerPrefix[i];
		cout<<answerPrefix[i]<<" ";
	}
	cout<<endl;
	for(int i(0);i<m;i++){
	    cin>>l>>r;
	    cout<<answerPrefix[r]- answerPrefix[l-1	]<<endl;
	}
	return 0;
}	