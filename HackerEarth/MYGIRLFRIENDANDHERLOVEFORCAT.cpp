#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define MOD 1000000007
int main(){
	lli n,x;
	vector <lli> cs,fc;
	cin>>n;
	loop(i,n){
		cin>>x;
		cs.push_back(x);
	}
	loop(j,n){
		cin>>x;
		fc.push_back(x);
	}
	sort(cs.begin(),cs.end());
	sort(fc.begin(),fc.end());
	lli sum=0;
	loop(k,n){
		sum+=cs[k]*fc[k];
	}
	cout<<sum;
	return 0;
}