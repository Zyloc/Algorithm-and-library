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
#define loop(i,start,end) for (int i=start;i<=end;i++)
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
lli factorial(lli n){
	int i=1;
	lli fact=1;
	for(i;i<=n;i++){
		fact=(fact*i)%MOD;
	}
	return fact%MOD;	
}
int main(){
	zyloc(){
		string s;
		cin>>s;
		map<char,lli> mp;
		loop(i,0,s.length()-1){
			mp[s[i]]++;
		}
		lli ans(1);
		ans = factorial(mp.size())%MOD;
		map<char,lli>::iterator it;
		for (it=mp.begin();it!=mp.end();it++){
			ans = (ans%MOD*factorial(it->second)%MOD)%MOD;
		}
		cout<<ans%MOD<<endl;
	}
    return 0;
}	