/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
class NumbersChallenge{
public:
	int MinNumber(vector<lli> v){
		lli n(v.size());
		set<lli> st;
		for(lli i=0;i<(1<<n);i++){
			lli sum(0);
			for(lli j=0;j<n;j++){
				if(i&(1<<j)){
					sum+=v[j];
				}
		}
			st.insert(sum);
		}
		lli start(1);
		while(st.find(start)!=st.end()){
			start++;
		}
		return start;
	}
};
int main(){
	lli x,n;
	cin>>n;
	vector<lli> v;
	for(lli i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	NumbersChallenge obj;
	cout<<obj.MinNumber(v);
}