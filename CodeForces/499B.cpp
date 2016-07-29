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
#include <unordered_map> 
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

int main(){
	lli n,m;
	cin>>n>>m;
	string s1,s2;
	map<string,string> mp;
	loop(i,0,m-1){
		cin>>s1>>s2;
		mp.insert(mp(s1,s2));
	}
	loop(i,0,n-1){
		cin>>s1;
		s2=mp[s1];
		if (s2.length()<s1.length()){
			cout<<s2<<" ";
		}
		else{
			cout<<s1<<" ";
		}
	}
    return 0;
}