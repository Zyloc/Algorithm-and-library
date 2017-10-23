/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli  long long int
using namespace std;
lli n,k;
map<double,lli> dp;
vector<lli> input;
vector<double> logOf;
double maxK;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	maxK = log(k);
	lli x;
	for(int i(0);i<n;i++){
		cin>>x;
		logOf.push_back(log(x));
		dp[log(x)] = 0;
	}
	dp[0] = 1;
	sort(logOf.begin(),logOf.end());
	for(auto x:logOf){
		auto startIterator(dp.begin()),endIterator(--dp.end());
		while(startIterator != endIterator){
			dp[x+startIterator->first] += startIterator->second;
			startIterator++;
		}
	}
	lli count(0);
	for(auto x:dp){
		if(x.first < maxK){
			count+=x.second;
		}
		else{
			break;
		}
	}
	cout<<count-1<<endl;
	return 0;
}
