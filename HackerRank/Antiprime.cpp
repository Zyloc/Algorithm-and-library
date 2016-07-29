/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
#include <list>  
using namespace std;
#define loop(i,start,end) for (long long int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
map<lli,lli> mp;
void primeFactor(unsigned long long int n){
	while(n%2==0){
		//primeFactors.push_back();
		n/=2;
		mp[2]++;
	}
	for (unsigned long long int i=3;i<sqrt(n);i=i+2){
		if (n%i==0){
			mp[i]++;
			n/=i;
		}
	}
	if (n>2){
		mp[n]++;
	}
	
}
int main(){
	lli q,n;
	cin>>n;
	lli anti[] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400,665280,720720,1081080,1441440,2162160};
	loop(i,0,n-1){
		cin>>q;
		lli noOf(1);
		primeFactor(q);
		map<lli,lli>::iterator it;
		for (it=mp.begin();it!=mp.end();it++){
			noOf = noOf*(it->second+1);
		}
		mp.clear();	
		loop(i,0,40){
			primeFactor(anti[i]);
			lli no(1);
			for (it=mp.begin();it!=mp.end();it++){
				no = no*(it->second+1);
			}
			if (no>=noOf){
				cout<<anti[i]<<endl;
			}
			mp.clear();		
		}
	}
	
	
    return 0;
}	