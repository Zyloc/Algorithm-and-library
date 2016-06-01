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
#define zyloc() int t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b) 
#define MOD 1000000007
#define MAXN 1000002
#define PI  3.14159265358979323846
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
int dp[MAXN];
void solve(){
	loop(i,0,MAXN){
		dp[i]=MAXN;
	}
	dp[2]=1;	
	dp[3]=1;
	dp[5]=1;
	dp[7]=1;
	int pr[]={2,3,5,7};
	loop(i,1,MAXN){
		loop(j,0,4){
			if ((i-pr[j])>=0){
				dp[i]=min(dp[i],1+dp[i-pr[j]]);
			}
		}
	}
	loop(i,0,MAXN){
		if (dp[i]>=MAXN){
			dp[i]=-1;
		}
	}
}
int main(){
	solve();
	int t;
	cin>>t;
	while(t--){
		lli x;
		cin>>x;
		cout<<dp[x]<<endl;
	}
    return 0;
}
Language: C++