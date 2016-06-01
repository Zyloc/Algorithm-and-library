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
#define MAX 10005
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
lli n,k;
lli dp[MAX];
vi(v);
lli zombi(lli start){
	if (start>=n){
		return 0;
	}
	if(dp[start]!=-1){
		return dp[start];
	}
	lli ans=INT_MIN;
	ans=max(v[start]+zombi(start+k+1),max(ans,zombi(start+1)));
	return dp[start]=ans;
}
int main(){
	zyloc(){
		lli x;	
		cin>>n>>k;
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
		}
		fill(dp,-1);
		cout<<zombi(0)<<endl;
		v.clear();
	}	
    return 0;
}
Language: C++