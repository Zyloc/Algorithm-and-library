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
map<lli,lli> mp;
map<lli,lli>::iterator it; 
lli magicBox(lli coinValue){
	if (coinValue<=4){
		return coinValue;
	}
	it=mp.find(coinValue);
	if(it!=mp.end()){
		return it->second;
	}
	return (mp[coinValue]=max(coinValue,(magicBox(coinValue/4)+magicBox(coinValue/3)+magicBox(coinValue/2))));
}
int main(){
	int coinValue;
	while(cin>>coinValue){
		cout<<magicBox(coinValue)<<endl;
	}	
    return 0;
}