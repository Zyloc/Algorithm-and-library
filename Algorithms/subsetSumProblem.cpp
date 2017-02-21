/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
 *
 * Question: whether it is possible to divide given array in two parts such that sum of each parts are equal
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
/*
 * bit mask approach
 * Time complexity O(2^n)
 * space complexity O(2^n)
*/
int bitSubsetSumProblem(){	
	lli n,x;
	cin>>n;
	vector<lli> v;
	for(lli i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	map<lli,bool> mp;
	for(lli i=0;i<(1<<n);i++){
		lli sum(0);
		for(lli j=0;j<n;j++){
			if(i&(1<<j)){
				sum+=v[j];
			}
		}
		mp[sum]=true;
	}
	return 0;
}	
