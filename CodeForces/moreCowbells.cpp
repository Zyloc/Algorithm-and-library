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
int main(){
	lli n,k,x,max = 0;
	cin>>n>>k;
	vi(v);
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
		if (max<x){
			max=x;
		}
	}
	if (n <= k){
		cout<<max;
	}
	else{
		vi(ans);
		loop(i,n-k,n-1){
			ans.pb(v[i]);
		}
		pool(i,n-k-1,0){
			ans[i] += v[n-k-i-1];
		}
		max = 0;
		loop(i,0,k-1){
			if (ans[i]>max){
				max = ans[i];
			}
			//max = 
		}
		cout<<max<<endl;
	}	
    return 0;
}	