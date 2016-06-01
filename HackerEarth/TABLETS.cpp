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
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
 
int main(){
	lli n,x;
	cin>>n;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	int sum=0;
	lli dp[MAX]={0};
	dp[0]=1;
	loop(i,1,n-1){
		if (v[i]>v[i-1]){
			dp[i]=dp[i-1]+1;
		}
		else{
			dp[i]=1;
		}
	}
	pool(i,n-2,0){
		if(v[i]>v[i+1] && dp[i]<=dp[i+1]){
			dp[i]=dp[i+1]+1;
			//sum+=dp[i];
		}
	}
	loop(i,0,n-1){
		sum+=dp[i];
	}
	cout<<sum<<endl;		
    return 0;
}
Language: C++